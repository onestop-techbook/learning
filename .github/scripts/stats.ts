import { parse, stringify } from "jsr:@std/yaml";

// catalogファイルのチャプターをカウントする関数
function countChapters(data: unknown): number {
  if (Array.isArray(data)) {
    return data.reduce((count, item) => count + countChapters(item), 0);
  } else if (typeof data === "object" && data !== null) {
    return Object.values(data).reduce((count, value) => count + countChapters(value), 0);
  } else if (typeof data === "string" && data.endsWith(".re")) {
    return 1;
  }
  return 0;
}

function buildMessage(prevCount: number, currentCount: number) {
  const diff = currentCount - prevCount
  const diffMessage = diff > 0 ? `（前日比 +${diff}）` : ''
  return {
    "blocks": [
      {
        "type": "context",
        "elements": [
          {
            "type": "mrkdwn",
            "text": `『<https://github.com/onestop-techbook/learning|ワンストップ学び>』の執筆状況: 現在 *${currentCount}* 章 ${diffMessage} :books: <https://oyakata-techbook.slack.com/canvas/CDS3UGG75|執筆の手引き>`
          }
        ]
      },
      {
        "type": "context",
        "elements": [
          {
            "type": "plain_text",
            "text": `${':page_with_curl:'.repeat(currentCount - diff)}${':new:'.repeat(diff)}`,
            "emoji": true
          }
        ]
      }
    ]
  }
}

// Slack通知を送信する関数
async function sendSlackNotification(webhookUrl: string, message: any) {
  const response = await fetch(webhookUrl, {
    method: "POST",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify(message),
  });

  if (!response.ok) {
    console.error("Failed to send Slack notification:", await response.text());
    Deno.exit(1);
  }
}

async function main(statsFile: string, yamlFile: string) {
  const webhookUrl = Deno.env.get("SLACK_WEBHOOK_URL");
  if (!webhookUrl) {
    console.error("SLACK_WEBHOOK_URL is not set.");
    Deno.exit(1);
  }

  // 前回のデータを読み込む
  let previousStats: { chapterCount: number } = { chapterCount: 0 };
  try {
    const statsText = await Deno.readTextFile(statsFile);
    previousStats = JSON.parse(statsText);
  } catch {
    console.warn("No previous stats found, using defaults.");
  }

  // catalogファイルから現在のチャプター数を取得
  const yamlText = await Deno.readTextFile(yamlFile);
  const yamlData = parse(yamlText);
  const currentChapterCount = countChapters(yamlData);

  console.log(`Previous chapter count: ${previousStats.chapterCount}`);
  console.log(`Current chapter count: ${currentChapterCount}`);

  // 比較と通知
  if (currentChapterCount > previousStats.chapterCount) {
    console.log("Change detected. Sending notification...");
    const message = buildMessage(previousStats.chapterCount, currentChapterCount)
    // await sendSlackNotification(webhookUrl, message);
  } else {
    console.log("No increase in chapter count.");
  }

  // 新しいデータを保存
  const newStats = { ...previousStats, chapterCount: currentChapterCount };
  await Deno.writeTextFile(statsFile, JSON.stringify(newStats, null, 2));
  console.log("Updated stats saved.");
}

// スクリプトの引数からファイル名を取得
if (Deno.args.length !== 2) {
  console.error("Usage: deno run --allow-read --allow-env --allow-net stats.ts <statsFile> <catalogFile>");
  Deno.exit(1);
}

const [statsFile, catalogFile] = Deno.args;
await main(statsFile, catalogFile);

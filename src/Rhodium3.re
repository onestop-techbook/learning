= 夏休み・春休みに高度情報試験を取った話
大学生をしていると、夏休みや春休みは授業がなくなるので多くの時間が取れるようになります。
せっかくまとまった勉強時間が取れたので、その他の領域の知識について体系だった勉強をしたいと思いました。
一つの目安として「資格取得」を設け、2か月という短期集中で高度情報試験を受験したことを共有します。

== バックグラウンド

IT業界外で働く私にとって、サブスキルのITを学ぶことはあくまでも趣味です。
以下の資格は主業務で取り扱うものではなく、もちろん昇格要件ではありません。

ただ、ITに詳しいポジションにいるため時々頼られます。
頼られたのに応えられないというのも悲しいので、
自己啓発として以下の2つの資格を受けました。

=== データベーススペシャリスト(DB)
仕事で職場でノーコードデータベースを触るのですが、
実際に理論だって学習をしたことが無く、オレオレ実装になっていました。

思いつく範囲で最良の構造にしているつもりではありますが、
自分の知らない構造があるかもしれないという思いがありました。

これまで数多のDBエンジニアがこの問題にチャレンジし理論として体系化してきたはずと信じ、
データベースの勉強をしたいという思いがありました。

とはいえ、申し込みは放送大学学期中であり、すぐに対策を始められません。
また、Twitter(現:X)などで無為に時間を過ごしてしまい、
しばらくは勉強を開始しませんでした。

2022年の夏コミ、東待機列に並んでいる最中におすすめの参考書@<fn>{DBref}を教えてもらい、
勉強を始めました。

//footnote[DBref][翔泳社さんの情報処理教科書シリーズ。この参考書は試験に合格することに強めにフォーカスしているので、好き嫌いが分かれるかもしれません。]

コミケに並んでいる時点でのスキルは以下のような感じです。
良くこれで受けようと思ったなと言われそうですが、そもそも問題集をここまで見ていないので
ダメダメということすら知りません。

//table[DBskill][DBの領域と修得状況]{
分野	修得状況
------------
運用経験	PHPからMySQLを触ったことがある。
SQL	SELECT、COUNTとCREATEは知ってる。JOIN、DISTINCT分からん。
概念データモデル	ER図を見て「どういうこと？」というレベル。
関係スキーマ	初めて聞いた。
//}

DBを取得したい理由が、会社のデータベースを効率よく使いたいという理由のため、
以下のように方針を立てました。

 * SQLは業務では触らないので、試験に合格できる最低限にする。午後でぶち当たった時は合格をあきらめよう。
 * 概念データモデル、関係スキーマはしっかりやる。特にビジネスロジックは使えそうなのでしっかり理解すること。
 * 午前は記憶力で何とかする。

平日はまとまった時間が取れないため、通勤の行き帰りに過去問道場を解区習慣づけを行い、
午前の対策を行いました。

過去問道場は大体80%ぐらいの正答率になったと思います。(最後のあたりは問題自体を記憶し始めた)
土日は午後2なら2問/日、午後1なら3問/日で週5問程度を目安に解きました。

=== 情報処理安全確保支援士(SC)

同人誌でアンケートやりたいなとなった時に、個人情報を守るのは必須技術と思います。
できないなら「アンケートをやらない」などを検討・決定しなければいけません。

また、仕事では「メールのFromは詐称可能か」などのフィッシング、
パスワードの奪取などのリスクにさらされ、ITに強いと思われているためかよく質問を受けます。

正しく理解し答えることができるようになりたいと感じることが多々あります。
DBと同様に、学ぶことを強制するように何かしらの資格を取ろうと思い、
それっぽい名前をしているこの資格を受けてみることにしました。

PHPなどを触っていた関係から、SQLインジェクション、XSS、DoSなどの攻撃は知っていました。
ただ、それ以外はかかわったことが無いので、学ばないといけない状況です。
DBに対してセキュリティはかかわる領域が広く、何から手を付けるかすら決まりませんでした。

DBは例年どの分野が出るか傾向があったのですが、SCはどこが出るのかわからなかったので、
テキスト(DBのが良かったので、今回も翔泳社さんの対策本)を総なめして、過去問を解きまくりました。

午前1が無かったのでその分楽でした。
どうしても攻撃の実感が持てないと覚えにくかったので、
攻撃の事例とそれに対する防衛法をネットで調べたりしながら進めた気がします(うろ覚え)。

== 結果
両試験に共通しますが、受験日までにどの問題を解くなどのスケジュールを
立てて挑んでいました。
それが自分がサボらないようにする抑止力になっていたと思います。

また、長期休みではあるものの2か月程度のうちに一気に仕上げるため、
中だるみしにくかったのも良かったと感じます。
鉄は熱いうちに打ったほうがきれいに良く伸びます。

また、勉強するモチベーションとして、何に役立つのかわからないと他の誘惑に負けやすいです。
私の一つの解は、無心になることです。

通勤するときは過去問道場を繰り返し行うこと、土日になったら午前に1つ午後に1つ解くこと、
というのを徹底してこれに疑問を覚えないようにします。
家に帰ったら手洗いうがいをするのと同レベルに過去問を解くという生活サイクルを作るとよいと思います。
(この点で通勤という定例作業があるのは良いかもしれません。)

残念ながら、私の会社では一緒に受けようという機運などが無かったため、
完全な独学での受験となりました。

前項の認定心理士課程ではスクーリングで同志に会うことができる楽しみがありましたが、
高度情報試験ではまるで機械のように問題を解くだけでした。

どちらがいいかは人にもよるかもしれませんが、「遠くに行きたいのならば仲間と行きなさい、
早く行きたいのならば一人で行きなさい」という言葉のように、
短期集中で行うならば一人の方が良いかと思いました。

試験はゴールではなく、そのあとにいかに使うかが重要です。
会社のDBは完全なRDBではなく、まだアンケートを取るようなこともしていません。

しかし、SCを取ったことをきっかけにそういったニュースを見ることに興味を持つようになりました。
どちらかというと、DB取っているのだから知っているべきではなど、
技術を追いかけるという業を背負いこんだ気がします。

それもまた、強制力を持った学びの入り口かもしれません。

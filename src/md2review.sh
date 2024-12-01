for file in `ls ./*.md`
do
  echo "Converting $file to ${file%.md}.re"
  md2review "$file" > "${file%.md}.re"
done

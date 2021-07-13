echo "pandoc latex to docx"

cd "$PWD/../thesis"

# # iterate through all .tex files in thesis/
find "$PWD" -iname "*.tex" | while read f
do
  # retrieve basename
  base=$(basename "$f" .tex)
  # delete original docx file
  rm -f "$PWD/docx/$base.docx"
  # create new docx file with pandoc
  pandoc -s -o "$PWD/docx/$base.docx" "$f"
done

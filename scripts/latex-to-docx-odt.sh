echo "pandoc latex to docx and odt"

cd "$PWD/../thesis"

# # iterate through all .tex files in thesis/
find "$PWD" -iname "*.tex" | while read f
do
  # retrieve basename
  base=$(basename "$f" .tex)
  # delete original docx dile
  rm -f "$PWD/docx/$base.docx"
#   # delete original odt dile
  rm -f "$PWD//odt/$base.odt"
  # create new docx file with pandoc
  pandoc -s -o "$PWD/docx/$base.docx" "$f"
  # create new odt file with pandoc
  pandoc -s -o "$PWD/odt/$base.odt" "$f"
done

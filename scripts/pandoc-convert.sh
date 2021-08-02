echo "pandoc latex to docx"

cd "$PWD/../thesis"

# iterate through all .tex files in thesis/
find "$PWD" -iname "*.tex" | while read f
do
  # retrieve basename
  base=$(basename "$f" .tex)
  # delete original docx file
  rm -f "$PWD/docx/$base.docx"
  # create new docx file with pandoc
  pandoc -s -o "$PWD/docx/$base.docx" "$f"
done

# do all the files manually, and with bibliography
pandoc -o "$PWD/docx/aaron-thesis.docx" "$PWD/chap1.tex" "$PWD/chap2.tex" "$PWD/chap3.tex" "$PWD/chap4.tex" "$PWD/chap5.tex" "$PWD/chap6.tex" "$PWD/appa.tex" "$PWD/appb.tex" "$PWD/appc.tex" "$PWD/appd.tex" "$PWD/appe.tex" --bibliography "$PWD/main.bib"
 
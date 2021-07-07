echo "latex odt with pandoc"

# iterate through all .tex files in thesis/
find "$PWD/../thesis" -iname "*.tex" | while read f
do
  # convert file from tex to odt
  pandoc "*.tex" -o "*.odt"
done

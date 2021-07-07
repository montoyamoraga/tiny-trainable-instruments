echo "latex odt with pandoc"

# iterate through all .odt files in thesis/dot
find "$PWD/../thesis" -iname "*.odt" | while read f
do
  # delete original odt file
  rm "$f"
done

# iterate through all .tex files in thesis/
find "$PWD/../thesis" -iname "*.tex" | while read f
do
  # retrieve basename
  base=$(basename "$f" .tex)
  # delete original pdf dile
  rm -f "$PWD/../thesis/$base.odt"
  # create new odt file with pandoc for odt to pdf
  pandoc -s -o "$PWD/../thesis/$base.odt" "$f"
done

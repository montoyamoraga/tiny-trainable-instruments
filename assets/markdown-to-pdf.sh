echo "markdown to pdf with pandoc"
# iterate through all files in docs/md
find "$PWD/../docs/md" -iname "*.md" | while read f
do
  # retrieve basename
  base=$(basename "$f" .md)
  # pandoc for md to pdf
  pandoc -s -o "$PWD/../docs/pdf/$base.pdf" "$f"
done

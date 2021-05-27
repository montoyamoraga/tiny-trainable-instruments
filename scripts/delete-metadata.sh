echo "deleting metadata from images with exiftool"
find "$PWD/../docs/images" -iname "*.png" | while read f
do
  exiftool -all= -overwrite_original "$f"
  echo "formatted $f"
done
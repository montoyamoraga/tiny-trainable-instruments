echo "deleting metadata from images with exiftool"

# docs folder
find "$PWD/../docs/images" -iname "*.jpg" | while read f
do
  exiftool -all= -overwrite_original "$f"
  echo "formatted $f"
done

# certification folder
find "$PWD/../certification/images" -iname "*.jpg" | while read f
do
  exiftool -all= -overwrite_original "$f"
  echo "formatted $f"
done

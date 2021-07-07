echo "deleting metadata from images with exiftool"

# certification/
find "$PWD/../certification/images" -iname "*.jpg" | while read f
do
  exiftool -all= -overwrite_original "$f"
  echo "formatted $f"
done


# docs/
find "$PWD/../docs/images" -iname "*.jpg" | while read f
do
  exiftool -all= -overwrite_original "$f"
  echo "formatted $f"
done

# thesis/
find "$PWD/../thesis/images" -iname "*.jpg" | while read f
do
  exiftool -all= -overwrite_original "$f"
  echo "formatted $f"
done

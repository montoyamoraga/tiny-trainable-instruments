# clear command line
"clear"

# directory name
DIR_MEDIA="media"

# extension of files
EXT_ORIGINAL="jpg"

# announce start running script
echo "start running " $PWD/$0

echo "looking for files with extension $EXT_ORIGINAL in $DIR_MEDIA/"

# check if directory exists
if [ -d "$DIR_MEDIA/" ];

# if directory exists then
then

  # announce directory exists
  echo "success, $DIR_MEDIA/ exists"

  find ".$DIR_NAME" -iname "*.$EXT_ORIGINAL" | while read f
    do
      exiftool -all= -overwrite_original "$f"
      echo "formatted $f"
    done

# end of if statemement for existence of directory
fi

# announce finished running script
echo "finished running " $PWD/$0

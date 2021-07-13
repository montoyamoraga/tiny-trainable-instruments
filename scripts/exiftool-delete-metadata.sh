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
if [ -d $DIR_MEDIA/ ];

# if directory exists then
then

  # announce directory exists
  echo "success, $DIR_MEDIA/ exists"

  # check if in directory some files match the extension
  if [ -f $DIR_MEDIA/*.$EXT_ORIGINAL ];

    # if there are matching files then
  then

      echo "successs, there are matching files"

    find ".$DIR_NAME" -iname "*.$EXT_ORIGINAL" | while read f
    do
      exiftool -all= -overwrite_original "$f"
      echo "formatted $f"
    done

  else
    echo "no $EXT_ORIGINAL files in $DIR_MEDIA/"

  fi

fi

# announce finished running script
echo "finished running " $PWD/$0
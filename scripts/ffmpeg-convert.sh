# clear command line
"clear"

# directory name
DIR_MEDIA="media"

# extension of original files
EXT_ORIGINAL="mp3"

# extension of desired files
EXT_DESIRED="ogg"

# announce start running script
echo "start running " $PWD/$0

# check if files/ exists
if [ -d "$DIR_MEDIA" ];

# if files/ exists then
then

  echo "success, $DIR_MEDIA/ exists"

  # check if there are .mp3 files in files/
  if [ -f $DIR_MEDIA/*.$EXT_ORIGINAL ];
    
    # if there are files with $EXTENSION in directory
    then

      echo "successs, there are matching $EXT_ORIGINAL files"

      # iterate over every matching file in directory
      for i in $DIR_MEDIA/*.$EXT_ORIGINAL;

        # pipe the filename into cut
        # -d is delimiter of '.'
        # -f is the field number, indexed in 1
        # it retrieves the filename without the extension
        do name=`echo "$i" | cut -d'.' -f1`

        echo convert "$i" $EXT_ORIGINAL to $EXT_DESIRED

        # ffmpeg conversion
        ffmpeg -i "$i" "${name}.$EXT_DESIRED"

        echo converted "$i" to $EXT_DESIRED

        # delete original  file
        rm "$i"

        echo deleted "$i"

      # finish iteration
      done

    # if there are no matching files in directory
    else
      echo "fail, no  $EXT_ORIGINAL files in $DIR_MEDIA/"

  # end of if statement for matching files
  fi

# if directory does not exist
else
  echo "fail, $DIR_MEDIA/ does not exist"

# end of if statement for existence of directory
fi

# announce finished running script
echo "finished running " $PWD/$0

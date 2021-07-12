# iterate over every .mp3 in files/
for i in files/*.mp3;
  # pipe the filename into cut
  # -d is delimiter of '.'
  # -f is the field number, indexed in 1
  # this assigns to name the filename without the extension
  do name=`echo "$i" | cut -d'.' -f1`
  # print name
  echo "$name"
  # ffmpeg input original mp3 and convert to .ogg
  ffmpeg -i "$i" "${name}.ogg"
  # delete original .mp3 file
  rm "$i"
# finish iteration
done

echo "compiling code with arduino-cli"
arduino-cli core update-index
arduino-cli board list
find "$PWD/../TinyTrainable/examples/hello" -type d | while read f
do  
  arduino-cli compile --fqbn arduino:mbed:nano33ble "$f"
  echo "compiled $f with arduino"
done

echo "formatting with clang"
find ./src ./examples -iname "*.cpp" -o -iname "*.h" -o -iname "*.ino" | while read f
do
  clang-format -i "$f"
  echo "formatted $f"
done

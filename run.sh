mkdir -p obj

set -x

CFLAGS="-Iinclude `pkg-config --cflags raylib`"
LDFLAGS="`pkg-config --libs raylib`"

for i in src/*.c;do
  FILE=$(basename -s .c $i)
  clang $i $CFLAGS $LDFLAGS -c -o obj/$FILE.o
done

clang obj/*.o $CFLAGS $LDFLAGS -o obj/main && obj/main
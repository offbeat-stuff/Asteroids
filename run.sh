mkdir -p obj

set -x

CFLAGS="$(pkg-config --cflags raylib)"
LDFLAGS="$(pkg-config --libs raylib)"

for i in *.c;do
  clang $i $CFLAGS $LDFLAGS -c -o obj/$i.o
done

clang obj/*.o $CFLAGS $LDFLAGS -o main && ./main
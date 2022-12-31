#include <stdio.h>

int main(int argc, char **argv) {
#ifdef __clang_major__
    printf ("clang version %d.%d\n", __clang_major__, __clang_minor__);
#endif

#ifdef __GNUC__
    printf ("gcc version %d.%d\n", __GNUC__, __GNUC_MINOR__);
#endif
}

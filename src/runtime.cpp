#include <stdio.h>

#include "prims/jvm.h"
#include "jemalloc/jemalloc.h"

#include "runtime.h"

int main(UNUSED int argc, UNUSED char **argv) {
    printf("Hello %p\n", je_malloc(1000));
    return 0;
}

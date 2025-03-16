#include "arrobejct_alloc.h"
#include "mem/array_mem.h"

/* Expand the allocator macro for int and double array objects */
MAKE_ALLOC(int, intArrayObject)
MAKE_ALLOC(double, doubleArrayObject)


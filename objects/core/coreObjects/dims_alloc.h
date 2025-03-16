#ifndef DIMS_ALLOC 
#define DIMS_ALLOC
#include "uintarrobejct.h"
#include <stdlib.h>
extern TypeObject UintArrObject_Type ; 
Dims* Dims_NEW() {
    Dims* dims = (Dims*)malloc(sizeof(Dims));
    dims->ob_base.ob_base.ob_type = &UintArrObject_Type;
    dims->ob_base.ob_base.rf_cnt = 1;
    dims->ob_base.size = 0;
    return dims;
}

#define MAKE_DIMS(arr) ({ \
    Dims* _d = Dims_NEW(); \
    _d->ob_data.size = (digit)(sizeof(arr) / sizeof((arr)[0])); \
    __builtin_memcpy(_d->ob_data.digits, (arr), sizeof(arr)); \
    _d; \
})
#endif

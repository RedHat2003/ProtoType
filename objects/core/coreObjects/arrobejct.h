#ifndef ARROBJECT_H
#define ARROBJECT_H

#include "core_object.h"
#include "uintarrobejct.h"

#define MAKE_ARR_OBJECT(D)              \
    typedef struct D##ArrayObject {     \
        VarObject_HEAD                  \
        UintArrObject ob_shape;         \
        D ob_data;                      \
    } D##ArrayObject;                   \
    DEFINE_STRUCT_HEADER_SIZE(D##ArrayObject, ob_data);

MAKE_ARR_OBJECT(int)
MAKE_ARR_OBJECT(double)
#endif



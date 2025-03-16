#ifndef ARROBJECT_H
#define ARROBJECT_H

#include "core_object.h"
#include "uintarrobejct.h"

/* Macro to define an array object type with a flexible array member */
#define MAKE_ARR_OBJECT(D)              \
    typedef struct D##ArrayObject {     \
        VarObject_HEAD                  \
        UintArrObject ob_shape;         \
        D ob_data[];                    \
    } D##ArrayObject;                   \
    DEFINE_STRUCT_HEADER_SIZE(D##ArrayObject, ob_data);

/* Define array objects for specific types */
MAKE_ARR_OBJECT(int)
MAKE_ARR_OBJECT(double)

#endif  /* ARROBJECT_H */


#ifndef ARRAY_MEM_H
#define ARRAY_MEM_H

#include <stdlib.h>
#include "uintarrobejct.h"
#define externn(OBJ_STRUCT) extern TypeObject OBJ_STRUCT##_Type;

/* Macro to define an allocator function for a given array object type */
#define MAKE_ALLOC(D, OBJ_STRUCT)   \
    externn(OBJ_STRUCT)               \
    OBJ_STRUCT* OBJ_STRUCT##_NEW(Dims* dims) {                     \
        if (!dims || dims->ob_data.size == 0) return NULL;         \
                                                                   \
        ssize_t count = 1;  /* Calculate total number of elements */\
        for (ssize_t i = 0; i < dims->ob_data.size; i++) {         \
            count *= dims->ob_data.digits[i];                      \
        }                                                          \
                                                                   \
        OBJ_STRUCT* obj = (OBJ_STRUCT*)malloc(                     \
            OBJ_STRUCT##_HEADER_SIZE + sizeof(D) * count           \
        );                                                         \
        if (!obj) return NULL; /* Allocation failure */           \
                                                                   \
        obj->ob_shape = *dims;                                     \
        obj->ob_base.ob_base.ob_type = &OBJ_STRUCT##_Type;          \
                                                                   \
        return obj;                                              \
    }

#endif  /* ARRAY_MEM_H */


#ifndef CT_ARR_OBJECTS_H
#define CT_ARR_OBJECTS_H

#include "core_object.h"       // Contains VarObject_HEAD, etc.
#include "uintarrobejct.h"     // Contains UintArrObject and Dims definitions
#include <stdlib.h>

/* Helper macros for stringification */
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)
#define MAKE_ARRAY_OBJECT(TYPE)                                    \
    typedef struct TYPE##ArrayObject {                                   \
        VarObject_HEAD                                                 \
        UintArrObject ob_shape;                                          \
        TYPE ob_data[];                                                 \
    } TYPE##ArrayObject;                                                 \
    DEFINE_STRUCT_HEADER_SIZE(TYPE##ArrayObject, ob_data);               \
                                                                         \
    static TypeObject TYPE##ArrayObject##_Type = {                       \
        .ob_base = {                                                    \
            .ob_base = {                                                \
                .rf_cnt = 1,                                            \
                .ob_type = &TypeObject_Type,                            \
            },                                                          \
            .size = 0,                                                  \
        },                                                              \
        .tp_name = STR(TYPE)"Arr",                                       \
    };                                                                   \
                                                                         \
    static inline TYPE##ArrayObject* TYPE##ArrayObject##_NEW(Dims* dims) { \
        if (!dims || dims->ob_data.size == 0) return NULL;               \
        ssize_t count = 1;                                               \
        for (ssize_t i = 0; i < dims->ob_data.size; i++) {               \
            count *= dims->ob_data.digits[i];                            \
        }                                                                \
        TYPE##ArrayObject* obj = (TYPE##ArrayObject*)malloc(             \
            TYPE##ArrayObject##_HEADER_SIZE + sizeof(TYPE) * count       \
        );                                                               \
        if (!obj) return NULL;                                           \
        obj->ob_shape = *dims;                                           \
        obj->ob_base.ob_base.ob_type = &TYPE##ArrayObject##_Type;         \
        return obj;                                                      \
    }

#endif /* CT_ARR_OBJECTS_H */


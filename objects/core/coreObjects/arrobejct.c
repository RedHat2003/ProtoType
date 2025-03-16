#include "core_object.h"
#include "typeobject.h"
#include "helper.h"

TypeObject intArrayObject_Type = {
    .ob_base = {
        .ob_base = {
            .rf_cnt = 1, 
            .ob_type = &TypeObject_Type ,
        },
        .size = 0 
    },
    .tp_name = "IntArr"
};
TypeObject doubleArrayObject_Type = {
    .ob_base = {
        .ob_base = {
            .rf_cnt = 1, 
            .ob_type = &TypeObject_Type ,
        },
        .size = 0 
    },
    .tp_name = "DoubleArr"
};

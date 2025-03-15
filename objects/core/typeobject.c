#include "typeobject.h" 


TypeObject TypeObject_Type = {
    .ob_base= {
        .ob_base = {
            .rf_cnt = 1 ,
            .ob_type = &TypeObject_Type 
        },
        .size = 0 
    },    
    .tp_name = "Type"
};


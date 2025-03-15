#ifndef UINTARROBJECT_H
#define UINTARROBJECT_H

#include "core_object.h"  
#include <stdint.h>

typedef uint32_t digit ;

typedef struct uintarrobject UintArrObject  ; 

typedef struct {
   int8_t flags ; 
   uint32_t digit[1] ; 
}ob_uintValue ;

struct uintarrobject {
    VarObject_HEAD
    ob_uintValue ob_data; 
}; 

DEFINE_STRUCT_HEADER_SIZE(UintArrObject,ob_data.digit) ; 
#endif


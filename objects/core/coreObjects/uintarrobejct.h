#ifndef UINTARROBJECT_H
#define UINTARROBJECT_H

#include "core_object.h"  
#include <stdint.h>

typedef uint64_t digit ;
#define MAX_DIMNUM 4
typedef struct uintarrobject UintArrObject  ; 

typedef struct {
   ssize_t size ; 
   digit digits[MAX_DIMNUM] ; 
}ob_uintValue ;

struct uintarrobject {
    VarObject_HEAD
    ob_uintValue ob_data; 
}; 
typedef UintArrObject Dims; 

DEFINE_STRUCT_HEADER_SIZE(UintArrObject,ob_data.digits) ; 
#endif


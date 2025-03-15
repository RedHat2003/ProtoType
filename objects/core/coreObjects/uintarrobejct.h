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

#endif


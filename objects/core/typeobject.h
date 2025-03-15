#ifndef TYPEOBJECT_H
#define TYPEOBJECT_H

#include "core_object.h"

struct typeobject {
    VarObject_HEAD 
    char* tp_name ; 
};
DEFINE_STRUCT_HEADER_SIZE(TypeObject , tp_name) ; 
#endif

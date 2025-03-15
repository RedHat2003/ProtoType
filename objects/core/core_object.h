#ifndef CORE_OBJECT_H
#define CORE_OBJECT_H

#include <stddef.h>    // for offsetof
#include <sys/types.h> // for ssize_t

// Forward declaration for TypeObject
typedef struct typeobject TypeObject;

// Macros for computing struct header sizes
#define HEADER_SIZE(struct_type, field_name) \
    offsetof(struct_type, field_name)

#define DEFINE_STRUCT_HEADER_SIZE(typedef_name, field_name) \
    enum { typedef_name##_HEADER_SIZE = HEADER_SIZE(typedef_name, field_name) }

// A basic Object with a reference count and pointer to its type.
typedef struct _object {
    ssize_t     rf_cnt;
    TypeObject *ob_type;
} Object;

// Optional offset measurement (this is purely for demonstration)
DEFINE_STRUCT_HEADER_SIZE(Object, ob_type);

// A "variable-size" object: it has an Object plus a 'size' field.
typedef struct {
    Object  ob_base;
    ssize_t size;
} VarObject;

// Another offset measurement
DEFINE_STRUCT_HEADER_SIZE(VarObject, size);

// Macro sometimes used to embed a VarObject as "VarObject_HEAD"
#define VarObject_HEAD VarObject ob_base;

#endif /* CORE_OBJECT_H */


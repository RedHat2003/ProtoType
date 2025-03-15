#include <stdio.h>
#include "../typeobject.h"

extern TypeObject TypeObject_Type;

void TypeObject_Type_TEST (TypeObject* tp) {
    char* type_name = tp->tp_name ;
    printf("this is type object with type : %s\n" , type_name) ; 
    printf("this is type object with header size : %d\n" , TypeObject_HEADER_SIZE) ; 
}

int main (void){
    TypeObject_Type_TEST(&TypeObject_Type) ; 
    return 0;
}

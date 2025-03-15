#include "typeobject.h"


extern TypeObject TypeObject_Type ; 

TypeObject UintArrObject_Type ={
   .ob_base = {
       .ob_base= {
           .rf_cnt = 1  ,
           .ob_type = &TypeObject_Type  
       },
       .size = 0
   } ,
   .tp_name = "UintArr"
};

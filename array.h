#ifndef __ARRAY_H
#define __ARRAY_H
#include "Resolve.h"

typedef struct A_Array{
	r_type** Contents;
} Array;

typedef struct A_Array_Fac{
	r_type* size;
} Array_Fac;

void Array_Fac_Init(Array_Fac** A, r_type_ptr I);
void Array_Init(r_type_ptr A);
void Array_Final(r_type_ptr A);
void Array_Swap_Entry(r_type_ptr A, r_type_ptr E, r_type_ptr I);
void Array_Assign_Entry(r_type_ptr A, r_type_ptr Exp, r_type_ptr I);

#endif

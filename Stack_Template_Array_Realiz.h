#ifndef __STACK_TEMPLATE_ARRAY_REALIZ_H
#define __STACK_TEMPLATE_ARRAY_REALIZ_H
#include "Resolve.h"
#include "Stack_Template.h"
/**
* A resolve realization of stack
*/
typedef struct A_Stack_Template_Array_Realiz{
  r_type* Cont;
  r_type* top;
} Stack_Template_Array_Realiz;

/**
* A struct of Stack_Template concept parameters
*/
/*typedef struct A_Stack_Template_Fac{
	r_type_ptr Max_Depth;
} Stack_Template_Fac;*/

void Stack_Template_Array_Realiz_Init(r_type* S);
void Stack_Template_Array_Realiz_Final(r_type* S);
void Stack_Template_Array_Realiz_Push(r_type* S, r_type* ent);
void Stack_Template_Array_Realiz_Pop(r_type* S, r_type* ent);
r_type* Stack_Template_Array_Realiz_Depth(r_type* S);
r_type* Stack_Template_Array_Realiz_Rem_Capacity(r_type* S);
r_type* Stack_Template_Array_Realiz_Clear(r_type* S);
#endif

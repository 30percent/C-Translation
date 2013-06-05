#ifndef __INTEGER_TEMPLATE_INT_H
#define __INTEGER_TEMPLATE_INT_H
#include "Resolve.h"
#include "Integer_Template.h"


/*
r_type* (* Is_Zero)();
	r_type* (* Is_Not_Zero)();
	r_type* (* Is_Zero)();
    void (* Increment)();
    void (* Decrement)();
	r_type* (* Less_Or_Equal)();
	r_type* (* Less)();
	r_type* (* Greater_Or_Equal)();
	r_type* (* Greater)();
	r_type* (* Sum)();
	r_type* (* Difference)();
	r_type* (* Product)();
	r_type* (* Divide)();
	*/

/*static r_type_ptr Integer_Template_Int_Is_Zero(r_type_ptr I);
static r_type_ptr Integer_Template_Int_Is_Not_Zero(r_type_ptr I);
static void Integer_Template_Int_Increment(r_type_ptr I);
static void Integer_Template_Int_Decrement(r_type_ptr I);
static r_type_ptr Integer_Template_Int_Less_Or_Equal(r_type_ptr I, r_type_ptr J);
static r_type_ptr Integer_Template_Int_Less(r_type_ptr I, r_type_ptr J);
static r_type_ptr Integer_Template_Int_Greater_Or_Equal(r_type_ptr I, r_type_ptr J);
static r_type_ptr Integer_Template_Int_Greater(r_type_ptr I, r_type_ptr J);
static r_type_ptr Integer_Template_Int_Sum(r_type_ptr I, r_type_ptr J);
static r_type_ptr Integer_Template_Int_Difference(r_type_ptr I, r_type_ptr J);
static r_type_ptr Integer_Template_Int_Product(r_type_ptr I, r_type_ptr J);
static r_type_ptr Integer_Template_Int_Divide(r_type_ptr I, r_type_ptr J);



void instan_Int();
void Integer_Template_Int_Init(r_type* I);
void Integer_Template_Int_Final(r_type* I);
r_type* Integer_Template_Int_Make(long int I);
long int Integer_Template_Int_Get(r_type* I);
void Integer_Template_Int_Set(r_type* I, r_type* A);
void Integer_Template_Int_Write(r_type* I);

Integer_Template_Fac* stdIntFac;
proc_struct* stdIntProc;*/



extern Integer_Template* new_Std_Integer_Realiz_for_Integer_Template();
extern void free_Std_Integer_Realiz_for_Integer_Template(Integer_Template* toFree);

#endif

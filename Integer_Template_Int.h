#ifndef __INTEGER_TEMPLATE_INT_H
#define __INTEGER_TEMPLATE_INT_H
#include "Resolve.h"

/**
* A resolve realization of Integer
*/
typedef struct A_Integer_Template_Int{
  long int* value;
} Integer_Template_Int;

/**
* Struct of Integer_Template_Integer_Template Concept Parameters
*/
typedef struct A_Integer_Template_Fac{
	//EMPTY
} Integer_Template_Fac;

void instan_Int();
void Integer_Template_Fac_Init(Integer_Template_Fac** I);
void Integer_Template_Int_Init(r_type* I);
void Integer_Template_Int_Final(r_type* I);
r_type* Integer_Template_Int_Make(long int I);
long int Integer_Template_Int_Get(r_type* I);
void Integer_Template_Int_Set(r_type* I, r_type* A);
void Integer_Template_Int_Write(r_type* I);

Integer_Template_Fac* stdIntFac;
proc_struct* stdIntProc;
#endif

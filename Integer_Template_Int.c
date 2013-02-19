#include "Integer_Template_Int.h"

void instan_int(){
	Integer_Template_Fac_Init(&stdIntFac);
	proc_init(&stdIntProc, Integer_Template_Int_Init, Integer_Template_Int_Final, stdIntFac, nullProc);
}

void Integer_Template_Fac_Init(Integer_Template_Fac** I){
	*I = malloc(sizeof(Integer_Template_Fac));
}


/**
* Initializes integer with value 0.
* Called from r_type_init *only*
*/
void Integer_Template_Int_Init(r_type* I){
  I->ptr = malloc(sizeof(Integer_Template_Int));
  Integer_Template_Int* tem = I->ptr;
  tem->value = malloc(sizeof(long int));
  *(tem->value) = 0;
}

/**
* Frees up malloc-ed space from Integer_Template_Int_init.
* Called from r_type_final *only*
*/
void Integer_Template_Int_Final(r_type* I){
	Integer_Template_Int* temp = I->ptr;
	free(temp->value);
	free(temp);
}
/**
* Assigns integer A to I
*/
void Integer_Template_Int_Set(r_type* I, r_type* A){
	Integer_Template_Int* tempI, *tempA;
	tempI = I->ptr;
	tempA = A->ptr;
	*(tempI->value) = *(tempA->value);
}

/**
* Creates long int copy of Integer_Template_Int in I.
*/
long int Integer_Template_Int_Get(r_type* I){
	Integer_Template_Int* temp = I->ptr;
	return *(temp->value);
}

/**
* Generates an r_type of Integer_Template_Int
* from I.
*/
r_type* Integer_Template_Int_Make(long int I){
  r_type* ret;
  r_type_init(&ret, stdIntProc);
  Integer_Template_Int_Init(ret);
  Integer_Template_Int* temp = ret->ptr;
  *(temp->value) = I;
  return ret;
}

/**
* Prints the value to stdout.
*/
void Integer_Template_Int_Write(r_type* I){
	Integer_Template_Int* temp = I->ptr;
	printf("%ld\n", *(long int*)(temp->value));
}


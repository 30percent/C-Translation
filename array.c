#include "array.h"
#include "Integer_Template_Int.h"

/**
* Creates Facility of Array with concept parameter set (Size).
*/ 
void Array_Fac_Init(Array_Fac** A, r_type* I){
	*A = malloc(sizeof(Array_Fac));
	(*A)->size = I;
}

/**
* Initializes Array at A->ptr.
* Called from r_type_init *only*
*/
void Array_Init(r_type* A){
	A->ptr = malloc(sizeof(Array));
	Array* tempArray = A->ptr;
	r_type** tempContents;
	long int tempSize = Integer_Template_Int_Get(((Array_Fac*)(A->proc->facStruct))->size);
	tempContents = malloc(sizeof(r_type*) * tempSize);
	int i = 0;
	for(i = 0; i < tempSize; i++){
		tempContents[i] = malloc(sizeof(r_type));
		tempContents[i]->proc = A->proc->subset;
		tempContents[i]->proc->init(tempContents[i]);
	}
	tempArray->Contents = tempContents;
}

void Array_Final(r_type* A){
	Array* tempArray = A->ptr;	
	long int tempSize = Integer_Template_Int_Get(((Array_Fac*)(A->proc->facStruct))->size);
	
	int i = 0;
	for(i = (tempSize - 1); i>=0; i--){
		tempArray->Contents[i]->proc->final(tempArray->Contents[i]);
		free(tempArray->Contents[i]);
	}
	free(tempArray);
}

/**
* Swaps Entry in Array A at I with E.
* A(I) = #E, E = #A(i)
*/
void Array_Swap_Entry(r_type_ptr A, r_type_ptr E, r_type_ptr I){
	Array* tempArray = A->ptr;
	long int tempInt = Integer_Template_Int_Get(I);
	swap(tempArray->Contents[tempInt], E);
}

/**
* Does the same thing as Swap_Entry as Replica
* is an unknown function.
*/
void Array_Assign_Entry(r_type_ptr A, r_type_ptr Exp, r_type_ptr I){
	Array* tempArray = A->ptr;
	long int tempInt = Integer_Template_Int_Get(I);
	swap(tempArray->Contents[tempInt], Exp);
}

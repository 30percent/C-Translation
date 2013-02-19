#include "Resolve.h"

/**
* Initilizes the procedure struct: storing the init and final
* procedures; the facility information, and pointer to the 
* generic's procedures.
*/
void proc_init(proc_struct** P, void (*init)(r_type*), void (*final)(r_type*), void* fac, proc_struct* subP){
	*P = malloc(sizeof(proc_struct));
	(*P)->init = init;
	(*P)->final = final;
	(*P)->subset = subP;
	(*P)->facStruct = fac;
}

/**
* Initializes the r_type based on the init procedure
* within P.
*/
void r_type_init(r_type** R, proc_struct* P){
	*R = malloc(sizeof(r_type));
	(*R)->proc = P;
	((*R)->proc->init)((*R));
}

/**
* Frees space based on final procedure of R->proc.
*/
void r_type_final(r_type* R){
	R->proc->final(R);
	free(R);
}

/**
* Swaps ptr values of A and B such that:
* A = #B, B = #A.
*/
void swap(r_type* A, r_type* B){
  void* temp;
  r_type* t1 = A;
  r_type* t2 = B;
  temp = t1->ptr;
  t1->ptr = t2->ptr;
  t2->ptr = temp;
}

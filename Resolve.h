#ifndef __COMMON_H
#define __COMMON_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#define r_type_ptr r_type*
struct A_generic;
struct A_proc_struct;
typedef struct proc_struct proc_struct;
typedef struct r_type r_type;

/**
* Struct stores init and final procedures, it's Facility Structure
* as well as pointer to struct of its 'generic'.
*/

struct proc_struct{
	void (*init)(r_type_ptr);
	void (*final)(r_type_ptr);
	void* facStruct;
	proc_struct* subset;
};

/**
* Most generic type. Contains pointer to actual resolve type
* and a pointer to it's procedure structure.
*/
struct r_type{
  void* ptr;
  proc_struct* proc;
};

void proc_init(proc_struct** P, void (*init)(r_type*), void (*final)(r_type*), void* fac, proc_struct* subP);
void r_type_init(r_type** R, proc_struct* P);
void swap(r_type* A, r_type* B);

proc_struct* nullProc;
#endif

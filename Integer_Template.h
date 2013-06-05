#ifndef INTEGER_TEMPLATE
#define INTEGER_TEMPLATE
#include "Resolve.h"

/**
* Struct of Integer_Template_Integer_Template Concept Parameters
*/
typedef struct A_Integer_Template_Fac{
	//EMPTY
	r_type* (* Is_Zero)();
	r_type* (* Is_Not_Zero)();
    void (* Increment)();
    void (* Decrement)();
	r_type* (* Less_Or_Equal)();
	r_type* (* Less)();
	r_type* (* Greater_Or_Equal)();
	r_type* (* Greater)();
	r_type* (* Sum)();
	r_type* (* Negate)();
	r_type* (* Difference)();
	r_type* (* Product)();
	r_type* (* Divide)();
	r_type* (* Are_Equal)();
	r_type* (* Are_Not_Equal)();
	r_type* (* Replica)();
	void (* Read)();
	void (* Write)();
	void (* Write_Line)();
	r_type* (*Max_Int)();
	r_type* (*Min_Int)();
	r_type* (*Clear)();
	type_info* IntTypeInfo;
} Integer_Template_Fac;


long int _Integer_Get(r_type* I);
r_type* _Integer_Make(long int I);
extern void Integer_Template_Fac_Init(Integer_Template_Fac** I);
extern Integer_Fac* new_Integer_Fac();
extern void free_Integer_Fac(Integer_Fac* toFree);

#endif

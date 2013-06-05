#include "Integer_Template_Int.h"


/**
* Initializes integer with value 0.
* Called from r_type_init *only*
*/
static r_type_ptr init(type_info* ti){

    long int* _temp = calloc(1, sizeof(long int));
    *_temp = 0;
    long int** _temp2 = calloc(sizeof(long int*));
    *_temp2 = _temp;
    return (r_type_ptr)_temp2;
}

/**
* Frees up malloc-ed space from init.
* Called from r_type_final *only*
*/
static void final(r_type* r, type_info* ti){
    free(*r);
    free(r);
}

/**
* Prints the value to stdout.
*/
static void Write(r_type_ptr* I){
	printf("%ld\n", **(long int**)I);
}

static void Increment(r_type_ptr I){
    long int _temp = **(long int **) I;
	_temp = _temp + 1;
}
static void Decrement(r_type_ptr I){
    long int _temp = **(long int **) I;
	_temp = _temp - 1;
}
static r_type_ptr Sum(r_type_ptr I, r_type_ptr J){
    long int _temp = **(long int**) I;
    long int _temp2 = **(long int**) J;
    long int _temp3 = _temp + _temp2;
    long int **returnSum = &&_temp3;
	return returnSum;
}
static r_type_ptr Difference(r_type_ptr I, r_type_ptr J){
	r_type* Difference;
	r_type_init(&Difference, stdIntProc);
	Integer_Template_Int *tempI, *tempJ, *tempDifference;
	tempI = I->ptr;
	tempJ = J->ptr;
	tempDifference = Difference->ptr;
	*(tempDifference->value) = (*(tempI->value)) - (*(tempI->value));
	return tempDifference;
}
static r_type_ptr Product(r_type_ptr I, r_type_ptr J){
	r_type* Product;
	r_type_init(&Product, stdIntProc);
	Integer_Template_Int *tempI, *tempJ, *tempProduct;
	tempI = I->ptr;
	tempJ = J->ptr;
	tempProduct = Product->ptr;
	*(tempProduct->value) = (*(tempI->value)) * (*(tempI->value));
	return tempProduct;
}
static r_type_ptr Divide(r_type_ptr I, r_type_ptr J){
	r_type* Divide;
	r_type_init(&Divide, stdIntProc);
	Integer_Template_Int *tempI, *tempJ, *tempDivide;
	tempI = I->ptr;
	tempJ = J->ptr;
	tempDivide = Divide->ptr;
	*(tempDivide->value) = (*(tempI->value)) / (*(tempI->value));
	return tempDivide;
}

static newIntTypeInfo(){
    type_info* _temp = calloc(1, sizeof(type_info));
    _temp->init = init;
    _temp->final = final;
    return _temp;
}

extern Integer_Fac* new_Std_Integer_Realiz_for_Integer_Template(){

    Integer_Fac* I = calloc(sizeof(Integer_Fac));
	I->Increment = Increment;
	I->Decrement = Decrement;
	I->Sum = Sum;
	I->Difference = Difference;
	I->Product = Product;
	I->Divide = Divide;
	I->IntTypeInfo = newIntTypeInfo();
	/*r_type* (* Is_Zero)();
	r_type* (* Is_Not_Zero)();
	r_type* (* Less_Or_Equal)();
	r_type* (* Less)();
	r_type* (* Greater_Or_Equal)();
	r_type* (* Greater)();
	r_type* (* Negate)();
	r_type* (* Are_Equal)();
	r_type* (* Are_Not_Equal)();
	r_type* (* Replica)();
	void (* Read)();
	void (* Write)();
	void (* Write_Line)();
	r_type* (*Max_Int)();
	r_type* (*Min_Int)();
	r_type* (*Clear)();*/
	return I;
}

extern void free_Std_Integer_Realiz_for_Integer_Template(Integer_Fac* toFree){
    free(toFree->IntTypeInfo);
    free(toFree);
}

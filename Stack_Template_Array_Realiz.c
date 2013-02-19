#include "Stack_Template_Array_Realiz.h"
#include "Integer_Template_Int.h"
#include "array.h"

/**
* Creates a Facility of Stack_Template setting concept parameters (Max_Depth).
*/
void Stack_Template_Fac_Init(Stack_Template_Fac** S, r_type_ptr I){
	*S = malloc(sizeof(Stack_Template_Fac));
	(*S)->Max_Depth = I;
}

/**
* Initializes contents of Stack at S->ptr.
* Called from r_type_init *only*
*/
void Stack_Template_Array_Realiz_Init(r_type* S){
	S->ptr = malloc(sizeof(Stack_Template_Array_Realiz));
	Stack_Template_Array_Realiz* tempStack = S->ptr;
	Array_Fac* tempArrayFac;
	proc_struct* tempArrayProcStruct;

	Array_Fac_Init(&tempArrayFac, ((Stack_Template_Fac*)(S->proc->facStruct))->Max_Depth);
	proc_init(&tempArrayProcStruct, Array_Init, Array_Final, tempArrayFac, S->proc->subset);
	r_type_init(&((tempStack)->Cont), tempArrayProcStruct);
	r_type_init(&((tempStack)->top), stdIntProc);
}

/**
* Frees up malloc-d space from Stack_Template_Array_Realiz_init
* Called from r_type_final *only*.
*/
void Stack_Template_Array_Realiz_Final(r_type* S){
	Stack_Template_Array_Realiz* tempStack = S->ptr;
	r_type_final(tempStack->top);
	r_type_final(tempStack->Cont);
	free(S->ptr);
}


/**
* T points to initialized stack, ent points to desired input entry.
* T = #T o <#ent>
*/
void Stack_Template_Array_Realiz_Push(r_type* T, r_type* ent){
	Stack_Template_Array_Realiz* S = T->ptr;
	Integer_Template_Int* sInt = S->top->ptr;
	long int* t = sInt->value;
	Array_Swap_Entry(S->Cont, ent, S->top);

	*t += 1;
}

/**
* T points to initialized stack, ent points to desired output entry.
* #T = T o <ent>
*/
void Stack_Template_Array_Realiz_Pop(r_type* T, r_type* ent){
	Stack_Template_Array_Realiz* S = T->ptr;
	Integer_Template_Int* sInt = S->top->ptr;
	long int* t = sInt->value;
	*t -= 1;
	Array_Swap_Entry(S->Cont, ent, S->top);
}

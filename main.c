#include "Resolve.h"
#include "Stack_Template_Array_Realiz.h"
#include "Integer_Template_Int.h"

/*
* Still attempting to figure out this.
*/
//#define ISF_Array_Realiz Stack_Template_Array_Realiz
//#define SSF_Array_Realiz Stack_Template_Array_Realiz
//#define IF_Int Integer_Template_Int

int main(){
	instan_int(); //Called to make standard int facility. (All base types will have one of these.)

	/*Facility IF is Integer
		realized by Int*/
	Integer_Template_Fac* IF_Fac;
	proc_struct* IF_proc;
	Integer_Template_Fac_Init(&IF_Fac);
	proc_init(&IF_proc, Integer_Template_Int_Init, Integer_Template_Int_Final, IF_Fac, nullProc);

	/*Facility ISF is Stack(Integer, 10)
		realized by Array_Realiz*/
	Stack_Template_Fac* ISF_Fac;
	proc_struct* ISF_proc;
	Stack_Template_Fac_Init(&ISF_Fac, Integer_Template_Int_Make(10));
	proc_init(&ISF_proc, Stack_Template_Array_Realiz_Init, Stack_Template_Array_Realiz_Final,ISF_Fac, IF_proc);

	/*Facility SSF is Stack(Stack, 2)
		realized by Array_Realiz */
	Stack_Template_Fac* SSF_Fac;
	proc_struct* SSF_proc;
	Stack_Template_Fac_Init(&SSF_Fac, Integer_Template_Int_Make(2));
	proc_init(&SSF_proc, Stack_Template_Array_Realiz_Init, Stack_Template_Array_Realiz_Final, SSF_Fac, ISF_proc);

	/* 	Var A, B: IF;
		Var S: ISF;
		Var SS: SSF; */
	r_type* A, *B;
	r_type_init(&A, IF_proc);
	r_type_init(&B, IF_proc);
	r_type* S;
	r_type_init(&S, ISF_proc);
	r_type* SS;
	r_type_init(&SS, SSF_proc);

	/*	write(A);
		A := 6;
		B := 2;
		write(A);*/
	
	Integer_Template_Int_Set(A, Integer_Template_Int_Make(6));
	Integer_Template_Int_Set(B, Integer_Template_Int_Make(2));
	
	/*	push(S, A);
		write(A);
		pop(S, A);
		write(A);
		push(S, A);*/
	Stack_Template_Array_Realiz_Push(S, A);
	Integer_Template_Int_Write(A);
	Stack_Template_Array_Realiz_Pop(S, A);
	Integer_Template_Int_Write(A);
	Stack_Template_Array_Realiz_Push(S, A);

	/* 	push(SS, S);
		push(S, B);
		write(B);
		pop(S, B);
		write(B);
		pop(SS, S);
		pop(S, B);
		write(B);*/
	Stack_Template_Array_Realiz_Push(SS, S);
	Stack_Template_Array_Realiz_Push(S, B);
	Integer_Template_Int_Write(B);
	Stack_Template_Array_Realiz_Pop(S, B);
	Integer_Template_Int_Write(B);
	Stack_Template_Array_Realiz_Pop(SS, S);
	Stack_Template_Array_Realiz_Pop(S, B);
	Integer_Template_Int_Write(B);

	/* clear memory */
	r_type_final(SS);
	r_type_final(S);
	r_type_final(B);
	r_type_final(A);
	return 0;
}

//#undef ISF_Array_Realiz
//#undef SSF_Array_Realiz
//#undef IF_Int

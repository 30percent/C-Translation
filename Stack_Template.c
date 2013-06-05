#import Stack_Template.h

void Stack_Template_Fac_Init(Stack_Template_Fac** S, r_type_ptr I){
    *S = malloc(sizeof(Stack_Template_Fac));
	(*S)->Max_Depth = I;
}

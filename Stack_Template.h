#ifndef STACK_TEMPLATE
#define STACK_TEMPLATE
typedef struct A_Stack_Template_Fac{
    void* Entry;  // Generic type
    r_type_ptr  Max_Depth;
    void (* Push)();
    void (* Pop)();
    r_type* (* Depth)();
    r_type* (* Rem_Capacity)();
} Stack_Template_Fac;

void Stack_Template_Fac_Init(Stack_Template_Fac** S, r_type_ptr I);

#endif // STACK_TEMPLATE

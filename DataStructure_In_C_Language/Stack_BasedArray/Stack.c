/************Include*************/
#include "Stack.h"
/*********** Defines *************/  
#define NULL  (void*)0 
/*********** Data Types  *************/  

/*********** Static function prototypes ********/


/*********** Static function implemention  ********/


/*********** Interface function Impelementation  ****************/
Err_t Is_Full(stack_t * Stack){
    if(Stack->top >= Stack_size ){
        return S_full ;
    }
    return Ok ; 
}
Err_t Is_Empty(stack_t * Stack) {
    if(Stack->top < Stack_size ){
        return S_empty ; 
    }
    return Ok ; 
} 
Err_t CreatEmptyStack(stack_t* Stack  ) {
    if (Stack != NULL){
        Stack -> top  = -1 ; 
    }
    else {
        return Null_Err ; 
    }
    return Ok ; 
} 
Err_t PushInStack(stack_t * Stack , int Data ) {
    if(Stack != NULL && Is_Empty(Stack)){
        Stack-> top++ ;
        Stack->Stack_d[Stack->top] = Data ;
    } 
    else {
        return S_full ; 
    }
}
Err_t PopFormStack(stack_t * Stack , int* Data ) {

    if(Stack != NULL && Data != NULL ){
       
        if(!Is_Full(Stack)){
            
            *Data = Stack->Stack_d[Stack->top] ;  
           Stack->top-- ; 
        }
        else{
            return Nok ; 
        }
    }
    return Ok ; 
}
Err_t PrintStack(stack_t * Stack) {
    if(Stack != NULL ){
        int i = Stack->top ; 
        while(i != -1 ){
            printf("%d\n", Stack->Stack_d[i]) ; 
            i-- ; 
        }
    }
    else {
        return Null_Err ; 
    }
    return Ok; 
}
Err_t GetStackTop(stack_t * Stack , int * Data ) {
    if(Stack != NULL && Data != NULL ){
        *Data = Stack->Stack_d[Stack->top] ; 
    }
    else {
        return Null_Err ; 
    }
    return Ok ; 
} 

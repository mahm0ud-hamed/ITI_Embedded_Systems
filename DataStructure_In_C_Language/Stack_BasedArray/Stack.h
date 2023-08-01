/*****************Includes ********/
#include <stdio.h>

/*********** Defines *************/  
#define Stack_size   10 

/************ Data types ************/
typedef struct {
   int Stack_d [Stack_size] ; 
    int top ; 
}stack_t ; 

typedef enum {
    Ok , 
    Nok ,
    S_full , 
    S_empty, 
    Null_Err 
}Err_t ; 

/*************function prototypes ********/
Err_t Is_Full(stack_t * Stack) ; 
Err_t Is_Empty(stack_t * Stack) ; 
Err_t CreatEmptyStack(stack_t* Stack  ) ; 
Err_t PushInStack(stack_t * Stack , int Data ) ; 
Err_t PopFormStack(stack_t * Stack , int* Data ) ;
Err_t PrintStack(stack_t * Stack) ; 
Err_t GetStackTop(stack_t * Stack , int * Data ) ; 






/***********Includes*********/
#include<stdio.h>
#include<stdlib.h>


/************Data Types******/
typedef int StackEntry  ;

typedef struct Stack{
    StackEntry Data  ; 
    struct Stack * Next ; 
}Stack_t;


/**********Interface functions prototypes  ******/
void CreatStack(Stack_t * Stack) ;  
char PushStack(Stack_t * Stack , StackEntry Data ) ; 
char PopStack (Stack_t * Stack , StackEntry * Data ) ; 
void PrintStack(Stack_t * Stack ) ; 
void GetStackTop(Stack_t * Stack , StackEntry * Top ) ; 
char IsEmptyStack(Stack_t * Stack ) ; 


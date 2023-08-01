/***********Includes*********/
#include "linked_stack.h"

/************Data Types******/
enum {
    Notempty   ,
    Empty , 
    OK  , 
    Nok 
};

/**********Static functions prototypes  ******/
Stack_t * CreatNode(void) ; 

/**********Interface functions impelementation ******/
/***************Creat Stack ******************/
void CreatStack(Stack_t * Stack ) {
    Stack->Next = NULL ; 
}
/*********************************************/

/********Check Stack is Empty or Not ********/
char IsEmptyStack(Stack_t * Stack ) {
    if(Stack->Next == NULL){
        return Empty; 
    }
    return Notempty ; 
}
/*********************************************/

/**********Push Node Into Stack **************/
char PushStack(Stack_t * Stack, StackEntry Data ) {
    //check if the pushed node is the first node in stack 
    Stack_t * NodePtr = CreatNode() ; 
    if(IsEmptyStack(Stack)){
        Stack->Next= NodePtr ; 
        NodePtr->Next = NULL ; 
    }else {
        NodePtr->Next = Stack->Next ; 
        Stack->Next = NodePtr ; 
    }
    NodePtr->Data = Data ; 
    return OK ; 
} 
/**********************************************/
/****************POP Node from Stack **********/
char PopStack (Stack_t * Stack , StackEntry * Data ) {
    /*temp pointer to help in poping */
    char Sate = OK ; 
    Stack_t * Temp ; 
    /*check if Stack empty or not*/
    if (IsEmptyStack(Stack)){
        Sate =  Nok ; 
    }
    else {
        *Data = Stack->Next->Data ; 
        Temp = Stack -> Next ; 
        Stack->Next = Stack->Next->Next ;
        free(Temp) ; 
    }
    return Sate  ;
}
/**********************************************/
/************** Print Stack *******************/
void PrintStack(Stack_t * Stack ){
    Stack_t * Temp = Stack ;
    if( !IsEmptyStack(Stack)){
        while(Temp->Next != NULL){
            printf( " %d\n ",Temp->Next -> Data ) ; 
            Temp = Temp->Next ;
        }
    } else{
        printf(" printted Stack is empty\n"); 
    } 
}
void GetStackTop(Stack_t * Stack , StackEntry * StackTop ){
    *StackTop = Stack->Data;
}


/**********Static functions impelementation  ******/
/**********Creat New Node ********************/
Stack_t * CreatNode(void) {
    return (Stack_t*)malloc(sizeof(Stack_t)) ; 
} 
/********************************************/

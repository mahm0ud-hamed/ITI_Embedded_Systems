#include"linked_stack.h"

 
int main(void){
    Stack_t * Top ;
    StackEntry x ; 
    
   if( PopStack(Top , &x)  == 3){
    printf("empty stack ya m3lm \n\n\n\n"); 
   } 

    PrintStack(Top);

 return 0 ; 
}
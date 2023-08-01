#include <stdio.h>
#include "Stack.h" 
int main(){
stack_t my_stack ;  
int my_var =0 ; 
CreatEmptyStack(&my_stack) ; 
PushInStack(&my_stack , 12); 
PushInStack(&my_stack , 10);
PushInStack(&my_stack , 23);
GetStackTop(&my_stack,&my_var); 
printf("Stack toop  %d \n " , my_var ); 
printf("not pooping\n "); 
PrintStack(&my_stack);  
PopFormStack(&my_stack ,&my_var );
printf("my var is now %d \n " , my_var ); 
printf("poooooped \n"); 
PrintStack(&my_stack); 
GetStackTop(&my_stack,&my_var); 
printf("Stack toop  %d \n " , my_var ); 

 return 0 ; 
}

/*main*/
#include "Queue_linked.h" 



int main(){
    P_Queue * Qptr ; 
    CreatQueue(Qptr) ; 
    AppendQueue(Qptr , 5 ) ; 
   // AppendQueue(Qptr , 88 ) ;
    int y = 0 ; 
    int x = SizeQueue(Qptr); 
    printf("the size is %d \n", x);
    PrintQueue(Qptr) ;
    printf("i will Dequeue \n"); 

    DeQueue(Qptr , &y);

    printf("Dequeued element is %d\n", y ) ;  
    PrintQueue(Qptr) ;  
    x = SizeQueue(Qptr); 
    printf("the size Dequeued %d \n", x);
     
 

}
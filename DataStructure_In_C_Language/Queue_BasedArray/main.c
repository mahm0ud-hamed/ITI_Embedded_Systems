#include"Queue_array.h"

int main(){
    Queue_t My_Q ; 
    Queue_t * Q_Ptr = &My_Q  ; 
    int x = 0 ;
    Queue_Init(Q_Ptr) ; 
    printf("%d \n" , My_Q.Front) ;
    printf("%d \n" , My_Q.Rear) ;
    printf("%d \n" , My_Q.size) ;

    AppendQueue(Q_Ptr , 5 ) ; 
    AppendQueue(Q_Ptr , 8 ) ; 

    printf("size_AP %d \n" , Q_Ptr->size) ;
    printf("Front_AP%d \n" , Q_Ptr->Front) ;
    printf("Rear_AP%d \n" , Q_Ptr ->Rear) ;
    PrintQueue(Q_Ptr) ;

    DeQueue(Q_Ptr , &x ) ; 
     printf("X=  %d \n" , Q_Ptr->size) ;
    printf("size_AD %d \n" , Q_Ptr->size) ;
    printf("Front_AD%d \n" , Q_Ptr->Front) ;
    printf("Rear_AD%d \n" , Q_Ptr ->Rear) ;
    PrintQueue(Q_Ptr) ;
}
/* include */
#include"Queue_array.h"

/* defines */

/* Data Types */

/* Static Function Prototypes */


/* Interface Function Implementation */
void Queue_Init(Queue_t * Queue) {
    Queue ->Front = 0 ; 
    Queue ->Rear = -1 ; 
    Queue ->size = 0 ; 
} 
void AppendQueue(Queue_t * Queue , QueueEntry AppendData){
    if(Queue->Rear == Queue_Max-1){
        printf("Iam on size == maxQue") ; 
        Queue ->Rear = 0 ;
    }
    else{
        Queue ->Rear ++ ; 
    }
    /*append data on Rear index */
    Queue->Data[Queue ->Rear] = AppendData ; 
    Queue->size ++ ; 
}
void DeQueue(Queue_t * Queue , QueueEntry* DeQueueData){
    * DeQueueData = Queue->Data[Queue->Front] ;
    Queue->size -- ; 
    if(Queue ->Front == Queue_Max-1 ){
        Queue ->Front = 0 ; 
    }
    else{
        Queue ->Front ++; 
    }
}
int IsFull(Queue_t * Queue){
    return (Queue -> size == Queue_Max) ; 
}
int IsEmpty(Queue_t * Queue) {
    return (Queue -> size != Queue_Max) ;
}
int QueueSize(Queue_t * Queue){
    return Queue->size ; 
}
void ClearQueue(Queue_t * Queue){
    Queue ->Front = 0 ; 
    Queue ->Rear = -1 ; 
    Queue ->size = 0 ; 
}
void PrintQueue(Queue_t * Queue){
    int i = Queue->Front ; 
    while(i < Queue->size){
        printf("%d \n" , Queue->Data[i] ) ; 
        i++ ; 
    }
}

/* Static Function Impelementation */
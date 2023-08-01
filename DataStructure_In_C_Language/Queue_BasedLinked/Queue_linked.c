
/*linked_queu.h*/

/* Includes */
#include "Queue_linked.h"

/* Defines */

/* Data Types */

/* Sataic function Prototypes */


/* Interface function Impelementation */
Queue_t* CreatNode(void) {
    return (Queue_t*)malloc(sizeof(Queue_t)) ; 
}
void CreatQueue(P_Queue* Queue){
    Queue->Front = NULL ; 
    Queue->Rear  = NULL ;
    Queue->size = 0 ;  
}
void AppendQueue(P_Queue* Queue , QueueEntry Data ) {
    Queue_t* Qnode = CreatNode(); 
    Qnode->Next = NULL ; 
    Qnode->Data = Data ; 

    if( Queue->Rear == NULL ){
        Queue->Rear  = Qnode ;
        Queue->Front = Qnode ;
    }
    else {
        Queue->Rear->Next = Qnode ; 
        Queue->Rear = Qnode ;
    }
    Queue->size ++ ; 
 
}
void DeQueue(P_Queue* Queue , QueueEntry* Dta ){

    Queue_t *temp = Queue->Front ;

   printf("On deque func \n"); 
   if(Queue->Front == NULL){
    printf("Null pointer\n");
    return ;
   }
    else if(Queue->Front == Queue->Rear){
        printf("only one Node \n"); 
        Queue->Front =NULL ; 
        Queue->Rear = NULL ;  
    } 
    else {
         printf(" on many nodes  \n"); 

         Queue->Front = Queue->Front->Next ; 
    }
   *Dta = temp->Data ;
    free(temp) ;
    Queue->size -- ;  
}

int IsEmpty(P_Queue* Queue){
    return !Queue->size ; 
} 
int SizeQueue(P_Queue* Queue){
    return Queue->size ;
}

void ClearQueue(P_Queue* Queue){
    while(Queue->Front){
        Queue->Rear = Queue->Front->Next ; 
        free(Queue->Front); 
        Queue->Front = Queue->Rear ; 
    }
    Queue->size = 0 ; 
}
void PrintQueue(P_Queue* Queue){
    Queue_t* temp = Queue->Front ;
    while (temp)
    {
        printf(" %d \n" , temp->Data )  ;
        temp = temp->Next ; 
    }
}
/* Static function Impelementation */
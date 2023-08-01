/*linked_queu.h*/

/* Includes */
#include <stdio.h>
#include <stdlib.h>
/* Defines */

/* Data Types */
typedef int QueueEntry ; 

typedef struct QueueNode {
    QueueEntry Data ; 
    struct QueueNode * Next ; 
}Queue_t;

typedef struct {
    Queue_t *Front ; 
    Queue_t *Rear  ;
    int size ;  
}P_Queue;

/* Interface function prototype */
Queue_t* CreatNode(void) ; 
void CreatQueue(P_Queue* Queue) ; 
void AppendQueue(P_Queue* Queue , QueueEntry Data ) ; 
void DeQueue(P_Queue* Queue , QueueEntry* Dta ) ;
int IsEmpty(P_Queue* Queue) ;
int SizeQueue(P_Queue* Queue) ; 
void ClearQueue(P_Queue* Queue) ;
void PrintQueue(P_Queue* Queue);





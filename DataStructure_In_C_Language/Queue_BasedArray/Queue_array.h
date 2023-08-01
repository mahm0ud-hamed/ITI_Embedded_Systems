/* inclueds */
#include <stdio.h>
#include <stdlib.h>

/*defines*/
#define Queue_Max    10 

/* data types */
typedef int QueueEntry ;

typedef struct {
    QueueEntry Data[Queue_Max] ; 
    int Front  ; 
    int Rear ;
    int size ;  
}Queue_t;

/* functions prototypes */

void Queue_Init(Queue_t * Queue) ; 
void AppendQueue(Queue_t * Queue , QueueEntry AppendData); 
void DeQueue(Queue_t * Queue , QueueEntry* DeQueueData); 
int IsFull(Queue_t * Queue) ; 
int IsEmpty(Queue_t * Queue) ;
int QueueSize(Queue_t * Queue) ;
void ClearQueue(Queue_t * Queue) ;
void PrintQueue(Queue_t * Queue);

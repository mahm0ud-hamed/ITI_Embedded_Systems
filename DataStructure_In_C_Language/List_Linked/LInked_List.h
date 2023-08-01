 /* Includes */
#include <stdio.h>
#include <stdlib.h>

 /* Defines */

 /* Data Types */
typedef  int ListEntry ; 

typedef struct node{
    ListEntry Data ; 
    struct node * Next ; 
}ListNode_t ; 
 
 typedef struct {
    int size ; 
    ListNode_t * Head ; 
 }List_t ; 
 /* interface function Interface */

void CreatList(List_t * List ) ;  
int ListIsFull(List_t* List) ; 
int ListIsEmpty(List_t* List) ;
int ListSize(List_t* List) ;
int GetNodeData( int pos , ListEntry *GetValue , List_t* List) ; 
void ReplaceNodData(int pos ,ListEntry NewData ,List_t* List ) ; 
void InsertList(int pos , ListEntry Entry , List_t * List ) ; 
void DeleteList(int pos , ListEntry* Delete  , List_t * List ) ; 
 


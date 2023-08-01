/* Includes */
#include <stdio.h>
#include <stdlib.h>
/* Defines */
#define Max_list  100  

/* Data Types */
typedef int ListEntry ; 

typedef struct list{
    ListEntry Data[Max_list] ; 
    int size ; 
}List_t ; 

/* Inteface function Impelementation */
void CreatList(List_t * List ) ; 
int IsEmpty(List_t * List ) ;
int IsFull(List_t * List ) ;
int SizeList(List_t * List ) ;
void DestroyList(List_t * List ) ;
void InsertList(int pos , ListEntry Ins , List_t * List ) ; 
void DeleteList(int pos , ListEntry * Ins , List_t * List ) ; 
void ReplaceList(int pos , ListEntry Data , List_t * List ) ; 
void PrintList( List_t * List ); 




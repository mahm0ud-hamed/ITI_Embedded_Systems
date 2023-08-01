/* Includes */
#include "LInked_List.h"


/* Static function prototype */
ListNode_t * CreatNode(void) ;
/****************************/
/* interface function impelementation */
void CreatList(List_t * List ){
    List->Head = NULL ; 
    List->size = 0    ;  
} 
int ListIsFull(List_t* List){
    return 0 ; 
}
int ListIsEmpty(List_t* List){
    return (! List->size ) ; 
}
int ListSize(List_t* List){
    return List->size ; 
}
int GetNodeData( int pos , ListEntry *GetValue , List_t* List){
    int Indx =0 ;
    ListNode_t *Temp ; 
    if(List->Head){
        if(pos == 0 ){
            *GetValue = List->Head->Data ; 
        }
        else {
            for (Temp = List->Head , Indx = 0 ; Indx<= pos ; Indx ++ ){
                 Temp= Temp->Next ; 
            }
            * GetValue = Temp->Data ; 
        }

    }  
} 
void ReplaceNodData(int pos ,ListEntry NewData ,List_t* List ){
    int Indx = 0 ; 
    ListNode_t *Temp ; 
    if(List->Head){
        for (Temp = List->Head , Indx =0 ; Indx<=pos ; Indx++){
            Temp = Temp->Next ; 
        }
        Temp->Data = NewData ; 
    }
} 
void InsertList(int pos , ListEntry Entry , List_t * List ){
    ListNode_t *Temp   ; 
    int Indx = 0  ; 
    ListNode_t * NewNode = CreatNode() ;
    
    NewNode->Next = NULL ; 
    NewNode->Data = Entry ; 

    if ((pos == 0) && (List -> Head == NULL)){
        printf("iam here empty list append 5 \n");
        List ->Head = NewNode ; 
    }
    else if((pos == 0) && !(List -> Head == NULL)){
        printf("iam here one node append 8 \n ");

        NewNode->Next = List->Head ; 
        List->Head = NewNode ; 
    }
    else {
        for( Temp = List->Head , Indx = 0 ; Indx < pos-1 ; Indx++ ){
            Temp = Temp ->Next ; 
        }
        NewNode->Next = Temp->Next ; 
        Temp->Next = NewNode ; 
    }
    List->size ++ ; 
} 
void DeleteList(int pos , ListEntry* Delete  , List_t * List ){
    ListNode_t *Temp = List -> Head; 
    ListNode_t *Temp2 = List -> Head;
    int Indx ; 
    if(pos == 0 ){
        *Delete = List -> Head -> Data ; 
        List->Head = List->Head->Next ; 
        free(Temp) ; 
    }
    else {
        for(Indx = 0 ; Indx < pos-1 ; Indx ++){
            Temp =Temp->Next ; 
        }
        *Delete = Temp -> Next -> Data ; 
        Temp2 = Temp -> Next -> Next ; 
        Temp->Next = Temp2 -> Next ;
        free(Temp -> Next ); 
        Temp-> Next = Temp2 ;
    }
    List->size -- ; 
} 
/***********************************************/

/* Static Function Impelementation */
ListNode_t * CreatNode(void){
    return (ListNode_t *)malloc(sizeof(ListNode_t)) ;
}
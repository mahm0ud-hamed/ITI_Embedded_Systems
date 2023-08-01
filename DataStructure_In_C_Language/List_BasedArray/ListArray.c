/* includes */
#include"ListArray.h" 

/* Defines */

/* Data Types */

/* Static function prototype */

/* interface function impelementation */
void CreatList(List_t * List ){
    List->size = 0 ; 
}
int IsEmpty(List_t * List ){
    return !List->size ; 
}
int IsFull(List_t * List ){
    return (List->size == Max_list) ; 
}

int SizeList(List_t * List ){
    return List->size ; 
}
void DestroyList(List_t * List ) {
    List->size = 0 ; 
}
void InsertList(int pos , ListEntry Ins , List_t * List ){
    /*check if position is on size */
    int Indx =0 ; 
    if(pos <= List->size){
        for( Indx = List->size-1 ; Indx >= pos ; Indx-- ){
            List->Data[Indx+1] = List->Data[Indx+1] ;  
        }
        List->Data[pos] = Ins ; 
        List->size ++ ; 
    }
}
void DeleteList(int pos , ListEntry * Ins , List_t * List ){
    /*check if the deleted elment on list size*/
    int Indx =0 ;
 
    if( pos <= List->size-1 ){
        /*Return Data */
        *Ins = List->Data[pos] ;
        for( Indx = pos+1 ; Indx <= List->size-1 ; Indx++ ){
            List->Data[Indx-1] = List->Data[Indx] ; 
        }
        List->size -- ; 
    }
} 
void ReplaceList(int pos , ListEntry Data , List_t * List ){
    if(pos <= List->size-1 ){
        List->Data[pos] = Data ; 
    }
}

void PrintList( List_t * List ){
    int Indx ; 
    for( Indx = 0 ; Indx <= List->size-1 ; Indx++  ){
        printf("indx-> %d= [%d]\n",Indx , List->Data[Indx]); 
    }
}


/* Static function impelementation  */

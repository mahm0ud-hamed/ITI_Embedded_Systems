#include"LInked_List.h"


int main(){
    List_t * ListPtr ; 
    int x =0 ; 
    CreatList(ListPtr) ; 
    printf("list is empty %d \n", ListIsEmpty(ListPtr)) ; 
    printf("list is Full %d \n" , ListIsFull(ListPtr)) ; 
    printf("list is Size %d \n" , ListSize(ListPtr)) ; 
    InsertList(0 , 5 , ListPtr); 
    InsertList(0 , 8 , ListPtr); 
    InsertList(0, 2 , ListPtr); 
    InsertList(0, 4 , ListPtr); 

    printf("list is Size %d \n" , ListSize(ListPtr)) ; 
    GetNodeData(0 , &x , ListPtr ); 
    printf("the node data is %d \n", x ); 
    GetNodeData(1 , &x , ListPtr ); 
    printf("the node data is %d \n", x ); 




}
#include"ListArray.h"


int main(){

    int x = 0 ;
    List_t My_List ; 
    CreatList(&My_List); 
    printf("the list is empty = %d\n" , IsEmpty(&My_List)) ; 

    InsertList( SizeList(&My_List) , 4 , &My_List ) ; 
    InsertList( SizeList(&My_List) , 5 , &My_List ) ; 
    InsertList( SizeList(&My_List) , 6 , &My_List ) ; 
    InsertList( SizeList(&My_List) , 7 , &My_List ) ; 
    PrintList(&My_List); 
    DeleteList( 2 , &x , & My_List );
    printf("------------*after deleting*----------\n") ;   
    PrintList(&My_List); 
    printf("---------*the delete element*----------\n") ; 
    printf("the deleyed elemnt is %d \n" , x ); 
    printf("the list is empty = %d\n" , IsEmpty(&My_List)) ; 
    printf("---------*Destroy List*----------\n") ; 
    DestroyList(&My_List) ; 
    printf("the list is empty = %d\n" , IsEmpty(&My_List)) ; 

        printf("the size of void is %d\n" ,size) ; 

}
#include<stdio.h>

void SWAP_PTR(int ** ptr1 , int ** ptr2) ; 


int main(){

    int x  = 5 ; 
    int y  = 7 ; 
    int *ptr1 = &x ; 
    int *ptr2 = &y ; 
    SWAP_PTR(&ptr1 , &ptr2 ); 
    printf("%d------------%d",*ptr1 , *ptr2); 
    return 0 ; 
}

void SWAP_PTR(int **ptr1 , int ** ptr2) {

    int **temp ;
    *temp = *ptr1 ; 
    *ptr1 = *ptr2 ; 
    *ptr2 = *temp ; 
}
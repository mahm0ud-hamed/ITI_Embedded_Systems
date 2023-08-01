#include<stdio.h>

int  LONG_CONS(int *arr , int size ) ;

#define MAX 14 
int main(){

    int arr[MAX] = {1,1,2,2,2,2,3,3,4,4,4,5,5,5} ; 
    int x = LONG_CONS(arr , MAX) ;
}

int  LONG_CONS(int *arr , int size ){

    int i =0 ; 
    int count=0 ; 
    int oldcount =0 ; 
}
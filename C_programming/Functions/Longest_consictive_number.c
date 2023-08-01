#include <stdio.h>

#define MAX 14 

  int  FIND_LONGEST_CONS(int *arr , int size  , int num  ); 

int main(){

    int arr[MAX]={1,1,1,2,2,2,3,3,3,3,1,3,3,3,} ; 
    int x = FIND_LONGEST_CONS(arr , MAX , 1 ); 
    printf("the longest cons of 1 is %d",x); 
}

  int  FIND_LONGEST_CONS(int *arr , int size  , int num  ){
    int i ; 
    int count = 0; 
    int oldcount = 0;
    for(i =0 ; i < size ; i++){
        if(arr[i] == num ){
            count++ ; 
        }
        else {
            if(count > oldcount){
                oldcount = count ; 
                count = 0 ; 
            }
        }
    } 
    return oldcount ; 
  } 

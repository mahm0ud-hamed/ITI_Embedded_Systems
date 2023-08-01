#include<stdio.h>

void Rev_arr(int * arr , int size );

int main(){
 
 int arr[10] = {1,2,3,4,5,6,7,8,9,10}; 
 Rev_arr(arr , 10 );

}

void Rev_arr(int * arr , int size ){

    int i =0 ; int temp =0 ; 

    for(i =0 ; i < size/2 ; i++){
        temp = arr[i] ; 
        arr[i] = arr[size -1 -i]; 
         arr[size -1 -i] = temp ; 
    }

    /*print array */
    for(int i = 0 ; i < size ; i++){
        printf("%d\n" ,arr[i]);
    }
}
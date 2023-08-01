#include<stdio.h>

#define MAX 10  
int * SORT(int *arr , int size) ;

int main(){
    int arr[MAX] = {10,9,8,7,6,5,4,3,2,1};
    int *ptr = SORT(arr,MAX) ; 
    for(int i =0 ; i < 0 ; i++){
        printf("%d",ptr[i]);
    }

}

int * SORT(int *arr , int size) {
    int i  , j , temp ; 
    for (i =0  ; i < size  ; i++){
        for(j = 0 ; j< size -i ; j++){
            if(arr[j] > arr[j+1]){
                arr[j]= arr[j] ^ arr[j+1]; 
                arr[j+1] = arr[j+1]^ arr[j] ;
                arr[j]= arr[j] ^ arr[j+1];
            }
        }
    }
    return arr ; 
}
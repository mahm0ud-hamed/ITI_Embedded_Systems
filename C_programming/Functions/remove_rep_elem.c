#include<stdio.h>

#define MAX  10 
int* SORT(int * arr , int size ); 
void REM_REP(int *arr , int size ); 
int main(){
    int i ; 
    int arr[MAX]={2,2,8,4,4,10,10,1,7,6} ;
    int *ptr = arr; 
    ptr = SORT(arr , MAX); 

    /*print sorted the arry*/
    for(i =0 ; i < MAX ; i++){
        printf("%d",ptr[i]); 
    }
    REM_REP(ptr , MAX );
}

int* SORT(int * arr , int size ){
    int i  , j; 
    int temp ; 

    for(i =0 ; i < size ; i++){
        for( j =0 ; j <size-i ; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j+1]; 
                arr[j+1] = arr[j]; 
                arr[j]  = temp ; 
            }
        }
    }
    return arr ; 
}
void REM_REP(int *arr , int size ){
    int i =0 , j =0 ; 
    int k ; 
    for(i =0 ; i <size-1 ; i++){
        for(j = i+1 ; j < size ; j++ ){
            if(arr[i] == arr[j]){
                for(k = j ; k < size ; k++){
                    arr[k] = arr[k+1] ; 
                }
                size -- ; 
                j-- ; 
            }
        }
    }
    /*print array after remove */
    printf("array after remove \n");
    for(i =0 ; i < size ; i++){
        printf("%d" ,arr[i]);
    }
}
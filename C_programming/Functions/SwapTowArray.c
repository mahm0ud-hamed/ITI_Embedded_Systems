#include<stdio.h>
#define MAX 5 

   void  SWAP(int *arr1 ,int  size1  , int *arr2  , int size2  );


int main(){


    int arr1[MAX]= {1,2,3,4,5} ; 
    int arr2[MAX]= {6,7,8,9,10} ; 
    int i ; 
    printf("array 1 before swapping\n "); 
    for(i =0 ; i < MAX ; i++){
        printf("%d\n",arr1[i]); 
    }

        printf("array 2 before swapping\n "); 
        for(i =0 ; i < MAX ; i++){
        printf("%d\n",arr2[i]); 
    }

    SWAP(arr1 , MAX , arr2 , MAX );
}

void  SWAP(int *arr1 ,int  size1  , int *arr2  , int size2  ){
    int i =0 ; 
    int temp =0 ; 
    
    for(i = 0 ; i < size1 ; i++){
        temp = arr1[i]; 
        arr1[i] = arr2[i] ;
        arr2[i] = temp ; 
    }
    /*print the first array after swapping */
        printf("array 1 after swapping\n "); 

    for(i =0 ; i < MAX ; i++){
        printf("%d\n",arr1[i]); 
    }
    printf("array 2 after swapping\n ");  
        for(i =0 ; i < MAX ; i++){
         
        printf("%d\n",arr2[i]); 
    }
}

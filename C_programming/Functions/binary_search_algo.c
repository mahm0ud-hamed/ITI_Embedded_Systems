#include <stdio.h>

#define MAX  10 
 void Bin_srch(int *arr , int s );


int main(){

int arr[MAX] = {1,2,3,4,5,6,7,8,9,10}; 

int s  ; 
printf("enter the number need for search \n"); 
scanf("%d",&s); 

    Bin_srch(arr , s ); 

}
 void Bin_srch(int * arr , int s ){
    int end = MAX -1 ; 
    int strt = 0 ; 
    int mid = 0 ; 
    while( end >= strt ){

        mid = (end + strt) / 2 ; 
        if( arr[mid] == s ){
            printf("the number is exist\n  ");
            break ; 
        }
         if( s > arr[mid] ){
            strt = mid + 1 ; 
        }
         if( s < arr[mid]  ){
            end = mid - 1 ; 
        }
       
    }
    
 }
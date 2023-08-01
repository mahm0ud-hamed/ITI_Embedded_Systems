
#include <stdio.h>
#include <stdlib.h>
#define max 250 

   void find_most_rep(char * arr , int size );
    const int x  ; 

int main(){
    char arr[] = {1,2,2,2,2,2,4,2,2,4,2,2,2,2,0,2,2,2,4,3,2,3,4,4,2,2,2,2 ,2,5} ; 
    int size = sizeof(arr)/sizeof(arr[0]); 
   // printf("%d",size) ;
    find_most_rep(arr , size );
    return 0 ;
}
   void find_most_rep(char * arr , int size ){
    int max_num  = 0 ; 
    int max_rep ;
    int i ; 
    // find the max number of array 
    for(i =0 ; i < size ; i++){
        if(arr[i] > max_num){
            max_num =arr[i] ;  
        }
    }
    // allocate memory for count freq of element 
     char * freq = (char*)malloc(sizeof(char)*max_num); 
     //loop to count freq 
    for(i =0 ; i < size ; i++){
        ++freq[arr[i]]; 
    }
    // find the most repeated 
    max_rep = freq[0];
    for(i =1 ; i <max_num ; i++ ){
        if( max_rep < arr[i]){
            max_rep = arr[i];
        }
    }
        printf("the max repeated is %d",max_rep);
   }
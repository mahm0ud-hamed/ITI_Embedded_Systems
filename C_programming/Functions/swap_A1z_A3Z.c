#include<stdio.h>
#define MAX    1000000 
int* SWAP_AFZ(int * arr); 
int main(){

    unsigned char x = 256;
    printf("%d\n\n",x);

    int arr[] = {1,2,3,4,0,1,2,3,0,5,6,7,9,7}; 
    int *ptr =NULL ; 

    ptr = SWAP_AFZ(arr); 
    for(int i =0 ; i < sizeof(arr)/sizeof(arr[0]) ; i++){
        printf("%d",arr[i]);
    }
}

int* SWAP_AFZ(int * arr){

    int i =0 ; 
    int temp ; 
    int _1stZero  = 0 ;
    int _2ndZero  = 0 ; 
   for(i =0 ; i < 10000 ; i++){

    if(arr[i] == 0 && _1stZero>0 ){
        _2ndZero = i ;
        break ;  
    }
    else if(arr[i] == 0 && _2ndZero == 0){
       _1stZero = i ; 
    }
   }
    
// int arr[] = {1,2,3,4,0,1,2,3,0,5,6,7,9,7};
   for(i =1 ; i<4 ; i++){
     temp = arr[_1stZero +i] ;
     arr[_1stZero + i ] = arr[_2ndZero+i] ;
     arr[_2ndZero+i] = temp ; 

   }
   return arr ;
   // for(i =0 ; i < ) ()
}
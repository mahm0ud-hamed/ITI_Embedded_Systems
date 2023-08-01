
#include<stdio.h>

void MAX_MIN_INDX(char * arr , int size , int *Max , int * Min ,
                  int * Max_Indx , int * Min_Indx ); 


int main(){
    char arr[]={2,1,3,4,8,9,2,10}; 
    int Max = arr[0]; 
    int Min = arr[0]; 
    int Max_indx=0 , Min_indx =0  ; 

    MAX_MIN_INDX(arr , 8 , &Max , &Min , &Max_indx , &Min_indx); 

    printf("the max is : %d\nthe min is %d\n " ,Max  , Min ); 
    printf("the max INdex  is : %d\nthe min Index  is %d\n " ,Max_indx  , Min_indx ); 
    
}

void MAX_MIN_INDX(char * arr , int size , int *Max , int * Min ,
                  int * Max_Indx , int * Min_Indx ){

                    int i =0 ; 
                    for(i =0 ; i < size ; i++){
                        if(arr[i] < *Min){
                            *Min = arr[i]; 
                            *Min_Indx = i ; 
                        }
                        if(arr[i] > *Max){
                            *Max = arr[i]; 
                            *Max_Indx = i ; 
                        }
                    }
                  }
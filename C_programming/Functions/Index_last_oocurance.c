#include <stdio.h>
#include <string.h>
int Last_occurance(char * arr , int num  , int size ); 

int main(){

    char arr[]= {1 ,2 ,3,4,1,4,5} ;
    int n =8 ;
   
    int x = Last_occurance(arr , n , 7 ); 
    printf("the last inddex of %d on array is: %d",n , x); 
}

int Last_occurance(char * arr , int num , int size ){
    int last_indx  = 0 ; 
    int len = strlen(arr);  
    int i =0  ,flag = 0; 

    for(i = 0 ;i< size ; i++){
        if(arr[i] == num ){
            last_indx = i ; 
            flag =1 ; 
        }
    }
    if(flag == 0 ){
        return -1 ; 
    }
    return last_indx;   ; 

}
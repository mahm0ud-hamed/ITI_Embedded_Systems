#include<stdio.h> 
#define MAX 5 

int Most_rep(int *arr , int size );

int main(){

    int arr[] = {0,0,1,1,4,4,4,3,3,2,2}; 
    int size = 11 ; 
    int x = Most_rep(arr , size ); 
    printf("the most repeated is %d",x); 
}


int Most_rep(int *arr , int size ){

    int i =0 ; 
    
    int Freq[MAX] ={0} ;
    int rep_max = 0 ;

    for(int i =0 ; i < size ; i++){
        ++Freq[arr[i]]; 
    }

    /*print the aarray freq*/
    for (int i = 0 ; i < MAX ; i++){
        printf("%d\n",Freq[i]);
    }
    /*check the most repeated */
    for(i =0 ; i < MAX ; i++){
        if(Freq[i] > rep_max){
            rep_max = i ; 
        }
    }

    return rep_max ; 
}
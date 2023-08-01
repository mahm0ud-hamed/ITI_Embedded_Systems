#include <stdio.h>
#include <stdlib.h>


char* Array_between_2_num(int x , int y ); 

int main(){

    int x =0 ; int y =0 ; 
    printf("enter the first number \n"); 
    scanf("%d",&x); 
    printf("enter the second number \n"); 
    scanf("%d",&y); 
    char * diff = Array_between_2_num(x, y); 
    printf("--------------------------------\n");
    for(int i =0 ; i < (y-x)-1 ; i++){
        printf("%d\n",diff[i]);
    }

}
char* Array_between_2_num(int x , int y ){
    int size = (y - x) -1 ; 
    char *arr = (char*)malloc(sizeof(char)*size); 
    int i =0 ; 
    for(i = 0 ; i < size ; i++){
        arr[i]= x+1+i ; 
    }
    return arr ; 
}
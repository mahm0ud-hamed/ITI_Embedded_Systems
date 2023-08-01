#include<stdio.h>

#define MAX 10
 /*************bubble sort prototype******************/
char * BUB_SORT(char * arr , int size); 
/**************main function *******************/
int main(){

int a =2 , b = 4 ; 
    printf(a/b?"a is bigger": "b is bigger "); 
    char arr[10] = {8 , 4 , 2 , 7 , 1 , 3 , 9 , 5 ,6 , 10} ;
	char *x ; int i ; 
	x = BUB_SORT(arr , MAX); 
    for(i =0 ; i < MAX ; i++){
        printf("%d\n" ,x[i]); 
    }

}
 /*****************bubble sort implementation*****************/
char * BUB_SORT(char * arr , int size){
	int  i , j , temp ;
	
    for(i =0 ; i< MAX-1 ; i++){
        for(j = 0 ; j< MAX-i ; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j] ; 
                arr[j] = arr[j+1]; 
                arr[j+1]= temp ; 
            }
        }
    }
	
	return arr ; 
}
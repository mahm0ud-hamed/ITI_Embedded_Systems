#include <stdio.h>

#define MAX  10 

int main(){
	
	int arr[MAX] = {1 , 2 , 3 , 4 ,5 ,6 ,7 , 8 , 9 , 10 }; 
	
	int mid = 0 ; 
	int Start = arr[0] ; 
	int End =arr[MAX] ; 
	int need ; 
	printf("enter the number for search\n"); 
	scanf("%d",&need); 
	
	while(End >=Start){
		mid = (Start + End )/ 2 ; 
		if(need == arr[mid]){
			
			printf("the needed number is exist \n"); 
			break ; 
		}
		else if (need < arr[mid]){
			End = mid-1 ; 
		}
		else if (need > arr[mid]){
			Start = mid+1 ; 
		}
		
	}
	return  0 ; 
}
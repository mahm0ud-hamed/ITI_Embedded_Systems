#include<stdio.h>
#define MAX 10 
int main ()
{
	int i , index , num ; 
	
	int max = 10 ; 
	
	int arr[MAX] = {0};
	// print array before adding element 
	for(i=0 ; i < max ; i++ )
	{
		printf("arr[%d]=%d\n",i,arr[i]); 
	}
	printf("enter the index you need to insert in from 0 to 9 \n");
	scanf("%d",&index); 
	
	printf("enter the value you need \n");
	scanf("%d",&num); 
	 max++ ;// increasr array size by one 
	 
	for(i = max  ; i > index; i-- )
	{
		arr[i]= arr[i-1]; // shoft all element after nedded index to right 
	}
	
	arr[index]= num ; // assign value in neded index 
	for(i=0 ; i < max ; i++ )
	{
		printf("arr[%d]=%d\n",i,arr[i]); 
	}
}
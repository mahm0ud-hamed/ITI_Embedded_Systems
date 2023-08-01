#include<stdio.h>
#define MAX 10 
int main ()
{
	int i , index , num ; 
	
	char max = 10 ; 
	
	int arr[MAX] = {1,2,3,4,5,6,7,8,9,10};
	// print array before adding element 
	for(i=0 ; i < max ; i++ )
	{
		printf("arr[%d]=%d\n",i,arr[i]); 
	}
	printf("enter the index you need to insert in from 0 to 9 \n");
	scanf("%d",&index); 
	
	// got to index and shift left all arry by one 
	
	for(i = index ; i < MAX ; i++)
	{
		arr[i]= arr[i+1];
	}
	
	// decrese size of arry be one 
	for(i = 0 ; i< MAX-1 ;i++)
	{
		printf("arr[%d]=%d\n",i,arr[i]);
	}
	
	
	
}	
	
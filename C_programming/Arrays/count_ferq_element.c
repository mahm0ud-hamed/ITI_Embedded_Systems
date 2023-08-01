#include<stdio.h>
#define MAX 10 

int main()
{
	int i ; 
	int freq[20]={0}; 
	int arr[MAX]; 
	
	printf("enter the element of array \n"); 
	for(i=0 ; i<MAX ; i++)
	{
		scanf("%d",&arr[i]);
	}
	// print array after scanning 
	for(i=0 ; i<MAX ; i++)
	{
		printf("arr[%d]=%d\n",i,arr[i]);
	}
	
	for(i =0 ; i <MAX ;i++)
	{
		++freq[arr[i]];
	}
	
	// print frequency of each number 
	for(i=0 ; i<MAX ; i++)
	{
		printf("arr[%d] -> %d\n",i,freq[i]);
	}
	
}
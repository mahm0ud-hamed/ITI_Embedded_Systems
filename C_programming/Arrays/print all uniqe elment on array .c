#include<stdio.h>
#define MAX 10 

int main()
{
	int i ; 
	int freq[20]={0}; 
	int arr[MAX]; 
	// scanelement from user 
	
	printf("enter the element of array \n"); 
	for(i=0 ; i<MAX ; i++)
	{
		scanf("%d",&arr[i]);
	}
	
	for(i =0 ; i <MAX ;i++)
	{
		++freq[arr[i]]; // check the freq of elements
	}
	
	// print frequency of each number 
	for(i=0 ; i<MAX ; i++)
	{
		if(freq[i] == 1)
		{
			printf("%d\n", arr[i]); 
		}
	}
	
}
	
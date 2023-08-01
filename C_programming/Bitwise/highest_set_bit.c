#include<stdio.h>
#define BITS_NUM  8*sizeof(int) 
int main ()
{
	int counter =0, higest=0; 
	int num =0; 
	int i; 
	printf("enter the nymber\n"); 
	scanf("%d",&num);
	
	for( i =0 ; i < BITS_NUM ; i++)
	{
		  
		if((num &(1<<i)))
		{
			higest= i; 
			
		}
		
	}
	printf("%d",higest);
	
	
}
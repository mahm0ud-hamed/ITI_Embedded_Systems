#include<stdio.h>
#define BITS_NUM  8*sizeof(int) 
int main ()
{
	int Lowest =0 ; 
	int i = 0 ; 
	int num ; 
	printf("enter the number \n"); 
	scanf("%d",&num); 
	for(i=0 ; i < BITS_NUM ;i++)
	{
		if(num&(1<<i))
		{
			Lowest = i ; 
			break ; 
		}
	}
	
	printf("the lowest bit is %d",Lowest); 
}

#include<stdio.h>
#define BITS_NUM  8*sizeof(int) 
int main ()
{
	int num ;
	int total_ones =0;
	int total_zeros =0 ; 
	int i ; 
	printf("enter th number\n"); 	
	scanf("%d",&num); 
	
	for(i=0 ; i < BITS_NUM ; i++)
	{
		if((num&(1<<i))==0)
		{
			total_zeros ++ ;
		}
		else
		{
			total_ones++ ;
		}
	}
	printf("total zeros %d\ntotal ones%d\n",total_zeros,total_ones); 
}
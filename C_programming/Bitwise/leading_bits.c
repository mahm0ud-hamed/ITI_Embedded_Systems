#include<stdio.h>
#define BITS_NUM  8*sizeof(int) 
int main ()
{
	int num ;
	int leading_Bits =0;
	int i ; 
	printf("enter th number\n"); 	
	scanf("%d",&num); 
	for(i=0 ; i< BITS_NUM ; i++)
	{
		if((num&(1<<i)))
		{
			leading_Bits =0 ; 
		}
		else
		{
			leading_Bits++ ; 
		}
	}
	printf("leading zeros %d",leading_Bits);
	
}
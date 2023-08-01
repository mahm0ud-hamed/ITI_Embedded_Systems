#include<stdio.h>
#define BITS_NUM  8*sizeof(int) 
int main ()
{
	int num ;
	int i	;
	int checker =0; 
	printf("enter th number\n"); 	
	scanf("%d",&num); 
	for(i=0 ; i<BITS_NUM ;i++)
	{
		checker = (num&1<<BITS_NUM-1-i); 
		checker = checker>>(BITS_NUM-1-i); 
		printf("%d",checker);
	}
}
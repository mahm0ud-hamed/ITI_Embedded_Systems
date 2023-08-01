#include<stdio.h>
#define BITS_NUM  8*sizeof(int) 
int main ()
{
	int num ;
	int leading_Bits =0;
	int num_rotation=0; 
	int i ; 
	printf("enter th number\n"); 	
	scanf("%d",&num);
	printf("enter the number of rotation\n"); 	
	scanf("%d",&num_rotation);
	for(i=0 ; i < num_rotation;i++)
	{
		if(num&1)
		{
			num=num>> 1; 
			num=num|(1<<(BITS_NUM)-1); 
		}
		else 
		{
			num=num>>1;
		}
	}
	printf("%d",num); 
}	
	
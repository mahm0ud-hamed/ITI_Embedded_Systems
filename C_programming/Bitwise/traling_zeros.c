#include<stdio.h>
#define BITS_NUM  8*sizeof(int) 
int main ()
{
	int count =0 ,oldcount=0; 
	int i = 0 ; 
	int num ; 
	printf("enter the number \n"); 
	scanf("%d",&num);
	for(i=0 ; i < BITS_NUM ;i++)
	{
		if((num&(1<<i))== 0)
		{
			 oldcount++ ;
			if(oldcount>count)
			{
				count=oldcount; 
			}
		}
		else 
		{
			oldcount= 0 ; 
		}
	}
	
	printf("%d",count); 
}
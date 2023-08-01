#include<stdio.h>

void Is_Prime(int x);
void Is_Armsrong(int x);
void Is_Perfect(int x);

int main()
{
	int x ; 
	printf("enter the number\n"); 
	scanf("%d",&x); 
	Is_Prime(x);
	Is_Armsrong(x);
	Is_Perfect(x); 
	
}

void Is_Prime(int x)
{
	int i ;
	int flag =0 ;
	for(i=2 ; i<x/2 ; i++)
	{
		if(x%i==0)
		{
			flag++ ;
		}
	}
	if(flag>0)
	{
		printf("%d is not prime\n",x); 
	}
	else
		printf("%d is prime\n",x);
		
}
void Is_Armsrong(int x)
{
	int checker =0 ;
	int mod = 0; 
	while(x>0)
	{
		mod = x%10 ; 
		checker+=(mod * mod * mod); 
		x/=10 ; 
	}
	if(checker==x)
	{
		printf("%d is armstrong\n",x); 
	}
	else 
	{
		printf("%d is not armstrong\n",x);
	}
}
void Is_Perfect(int x)
{
	int checker=0;
	int i ;
	
	for(i=1 ; i<=x ; i++)
	{
		
		if((x%i)== 0)
		{
			checker+=i;
		}
	}
	if(checker==x)
	{
		printf("%d is perfect",x); 
	}
	else
		printf("%d is not perfect",x);
}
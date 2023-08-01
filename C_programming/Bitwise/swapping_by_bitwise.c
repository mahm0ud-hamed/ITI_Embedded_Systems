#include<stdio.h>
#define BITS_NUM  8*sizeof(int) 
int main ()
{
	int num1;
	int num2; 
	printf("enter the first number\n"); 	
	scanf("%d",&num1);
	printf("enter the first number\n"); 	
	scanf("%d",&num2);
	
	printf("number1=%d\n",num1);
	printf("number2=%d\n",num2);
	
	num1^=num2 ; 
	num2^=num1;
	num1^=num2; 
	printf("number11=%d\n",num1);
	printf("number22=%d",num2);
}	
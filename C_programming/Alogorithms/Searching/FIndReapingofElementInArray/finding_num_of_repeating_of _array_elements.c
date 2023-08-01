#include<stdio.h>

#define size 8 
#define max 10 // must be grater than the greatest element of searched array 

int main() 
{
	int arr[size] = {5,6,8,6,6,7,8,9}; // array of some numbers 
	int frquency[max]={0}; // aray to check number of repeating element of arr array 
	int i ;// counter for arrays 
	for(i = 0 ; i < size ; i++)
	{
		++frquency[arr[i]]; // increment index of freq array wihch is equal to arr[i] 
	}
	// printing the frequency array 
	for(i=0 ; i< max ; i++)
	{
		printf("arr[%d]=%d\n",i,frquency[i]); 
	}
	
}
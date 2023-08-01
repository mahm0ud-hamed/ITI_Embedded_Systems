#include<stdio.h>

#define MAX_SIZE  10 
int main()
{
	/*array that carry members that need to to the operation on it */
	int arr[MAX_SIZE]={1,2,3,4,5,6,7,8,9,10};
	/*array to store the whole Even numbers*/
	int EvenArray[MAX_SIZE]={0};
	/*array to store the whole Odd numbers*/
	int OddArray[MAX_SIZE]={0};
	
	int i ;  // for looping iteration 
	int k=0; // for count the total Odd numbers im array 
	int v=0; // for count the total Even numbers im array 
	
	/*loop on the wole array */
	for(i =0 ; i < MAX_SIZE ; i++)
	{
		if(arr[i]&1)// check for odd numbers
		{
			OddArray[k]= arr[i]; 
			k++ ;
		}
		else if (!(arr[i]&1))// check for the Even numbers
		{
			EvenArray[v]= arr[i]; 
			v++ ;
		}
	}
	
	/*printing the even array and odd array*/
	printf("OddArray\n\n");
	/*print odd array */
	for (i=0 ; i < k ; i++)
	{
		printf("OddArray[%d]=%d\n",i,OddArray[i]);
	}
	printf("EvenArray\n\n");
	/*print odd array */
	for (i=0 ; i < v ; i++)
	{
		printf("EvenArray[%d]=%d\n",i,EvenArray[i]);
	}
}
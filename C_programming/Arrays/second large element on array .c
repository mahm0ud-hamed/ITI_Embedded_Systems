#include <stdio.h>
#include <stdlib.h>
 #define MAX 10 
int main ()
{
	// array to find the second bigest element on array
	int arr[MAX]= {1,2,3,7,9,10,6,5,4,8} ; 
	
	int oldbig ; // store the second big 
	int newnig;// storev the biggest 
	int i ;// array counter 
	int j ;// internal loop counter 
	  oldbig = newnig =  arr[0]; 
	  
	for(i =0 ; i < MAX ; i++)
	{
		if(arr[i]> newnig)
		{
			oldbig = newnig;
			newnig = arr[i];
			
		}
		else if(arr[i] > oldbig && arr[i]< newnig )
		{
			oldbig = arr[i]; 
		}
	}
	printf("the bigest is %d\n",newnig); 
	printf("the seconf big is %d",oldbig);
	
}
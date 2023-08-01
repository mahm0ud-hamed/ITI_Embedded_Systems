#include "binary_search_algo.h"

int Binary_search_int(int * arr , int element ,int size ) //function to search on int nimber
{
	int mid   =0;
	int start = arr[0] ; 
	int end   = arr[size-1]; 
	while(end > start)
	{
		mid = (start+end)/2; // calculate mid of array
		if(element == arr[mid])
		{
			return arr[mid]; // element is found and return its avlue 
		}
		else if (element > arr[mid])
		{
			start = arr[mid+1]; // change the start to the second haalf of array 
		}
		else if (element < arr[mid])
		{
			end = arr[mid-1];  // change the end to the first half of array 
		}
	}
	return -1 ;// which mean not found
}

/*char Binary_search_char(char * arr , char element ,int size ) // function to serch on char number
{
	
}*/
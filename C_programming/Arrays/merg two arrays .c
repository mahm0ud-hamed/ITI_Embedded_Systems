#include <stdio.h>
#include <stdlib.h>
/*function that merg two arry and return the adrees of new array*/
int * arr_merg(int* arr_1 ,int size_1 ,int*arr_2 ,int size_2);

int main()
{
	int arr_1[5]={2,4,6,8,10};  /*first array */
	int arr_2[5]={1,3,5,7,9};   /*second array */
	int *ptr = NULL ;           /*pointer to recive */
	ptr = arr_merg(arr_1,5,arr_2,5); 
		
	for(int i =0 ; i< 10 ; i++)
	{
	printf("arr[%d]=%d\n",i,ptr[i]);
	}
}

int * arr_merg(int* arr_1 ,int size_1 ,int*arr_2 ,int size_2)
{
	int *new_arr = (int *)malloc(sizeof(int)*(size_1+size_2)); 
	int k =0 , j = 0 ; 
	int i ; 
	for(i =0 ; i <(size_1+size_2) ; i++)
	{
		if(i%2==0)
		{
			new_arr[i]=arr_2[k]; 
			k++ ;
		}
		else 
		{
			new_arr[i]= arr_1[j];
			j++ ; 
		}
	
	}
	return new_arr ;
}
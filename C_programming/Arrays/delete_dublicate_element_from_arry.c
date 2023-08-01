#include<stdio.h>

int main()
{
	/*array to do process on it */
	int arr[10]={2,2,5,4,6,4,7,8,7,9};
	/*another array to check dublicated element*/
	//int freq[10]={0};
	int i ,size =10 ; 
	for(i= 0; i< size ; i++)
	{
		for(int j=i+1 ; j< size ; j++)
		{
			if(arr[i] == arr[j])
			{
				for(int k = j ; k<10 ;k++)
				{
					arr[k]=arr[k+1]; 
				}
				size -- ; 
			}
			
		}
	}
	
	for(i=0 ; i < size ; i++)
	{
		printf("arr[%d]=%d\n",i,arr[i]);
	}
	
}

#include <stdio.h>

int main()
{
	int arr[10]={2,2,7,6,7,8,5,8,9,9}; 
	int freq[10]={0}; 
	
	int i ; 
	for (i=0 ; i < 10 ; i++)
	{
		++freq[arr[i]];
		if(freq[arr[i]]>1)
		{printf("%d",arr[i]);}			
	}
	
}
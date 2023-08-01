#include"linear_search.h"

int  Linear_search_int(int * arr , int element,int size)
{
	int i ; 
	for(i=0 ; i< size ; i++)
	{
		if(element == arr[i])
		{
			return arr[i];
		}
	}
	return -1 ;
} 
char linera_search_char(char * arr , char element ,int size) 
{
	int i ; 
	for(i=0 ; i< size ; i++)
	{
		if(element == arr[i])
		{
			return arr[i];
		}
	}
	return -1 ;
}
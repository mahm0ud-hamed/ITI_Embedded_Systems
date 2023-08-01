#include <stdio.h>
#include"STD_TYPES.h"
#include"double_linked_list.h"

int main()
{
	u8 op ; 
	u8 id ;
	StudentNode* Searc_std =(void*)0 ;	
	while(1)
	{
		printf("enter the opertaiom\n"); 
		scanf("%d",&op); 
		switch(op)
		{
			
			
			case 1 :Add_node(); 
			break ; 
			
			case 2 :
					printf("enter student id \n"); 
					scanf("%d",&id); 
					Delete_node(id);
			break; 
			
			case 3 : 
					printf("enter student id \n"); 
					scanf("%d",&id);
					Searc_std =Search_node(id);
					printf("Id=%d\n",Searc_std->ID); 
					printf("Id=%d\n",Searc_std->Age);
			break ;
			case 4 : 
					Print_List();
			break ;		
		}
	}
}
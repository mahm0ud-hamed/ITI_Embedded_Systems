#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "double_linked_list.h"

/*creat pointer form node type that Will pint to the hard of list */
StudentNode * top = NULL ;
 
/*function to create node 
   return type : StudentNode* addres of the created node 
   parameter   : void 
 */
StudentNode* Creat_Node(void)
{
	return (StudentNode*)malloc(sizeof(StudentNode*)); 
	
}

 /*function to Add node 
   return type : void 
   parameter   : void
 */ 
void Add_node(void)// add node to the end of list 
{
	/*creat pinter that will carry the adress of new node*/
	StudentNode* New_Node = Creat_Node(); 
	/*take the data from user*/
	printf("enter the ID\n");
	scanf("%d",&New_Node->ID); 
	printf("enter the Age\n");
	scanf("%d",&New_Node->Age); 
	New_Node->next =NULL ; // make the next pinter on new node point to null 
	
	/*check if list ie empty*/
	if(top == NULL)
	{
		top = New_Node ;
		New_Node->prev =NULL; 
	}
	/*if list is already exist*/
	else
	{
		StudentNode* temp = top ;
		while(temp->next != NULL)/*loop until we reach the end of list*/
		{
			temp = temp->next;   /*move one step */
		}
		temp->next = New_Node ;  /*link last node with new node*/
		New_Node->prev = temp ;  /*assign new node prev with the last element of list */
		
	}
	
	
} 
/*function to delete node 
   return type : void 
   parameter   : u8 id to search using student id  
 */
void Delete_node(u8 id)
{
	 
	if(top)/*check if list is exisit*/
	{
		/*send id to search function for srerch */
		StudentNode* temp = Search_node(id);
		if(temp!= NULL)
		{
			/*if the list has one node only*/
			if(temp == top && temp->next == NULL && temp -> prev == NULL)
			{
				top ->next = NULL ; 
				top-> prev = NULL ; 
			}
			/*if deleted element is the last element on list */
			else if (temp->next == NULL)
			{
				temp->prev->next = NULL ;
			}
			/*if the deleted element is the first element on list */
			else if (temp->prev == NULL)
			{
				top = temp->next ; 
				top->prev = NULL ; 
			}
		}
		free(temp);
	}

} 
/*function to search  node 
   return type : StudentNode* addres of the searched node 
   parameter   : u8 id searching using student id  
 */
StudentNode* Search_node(u8 id)
{
	/*temp for store head address */
	StudentNode* temp = top ;
	/*loop until find the searched id */
	while(temp->ID != id )
	{
		/*check if the pointer reach the end of list */
		if(temp==NULL)
		{
			return NULL; /* if it rech the end of list retutn null*/
		}
		temp=temp->next; /*increase pointer by one step */
	}
	return temp ; /*return the adrees of searched id */
} 

/*function to Print list
   return type : void 
   parameter   : void
 */
void Print_List(void)
{
	StudentNode* temp = top ; 
	if(top)
	{
		while(temp != NULL)
		{
			printf("student id:%d\n",temp->ID); 
			printf("student age:%d\n",temp->Age); 
			temp=temp->next ;
		}
	}
	
}
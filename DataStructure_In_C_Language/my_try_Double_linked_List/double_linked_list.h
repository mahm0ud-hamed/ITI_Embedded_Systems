#ifndef DOUBLE_LINKED_LIST_H_
#define DOUBLE_LINKED_LIST_H_


/*strcut that carry all node information*/
typedef struct node
{
	u8 ID; 					/*student id */
	u8 Age ; 				/*student age */
    struct node * next  ; 	/*pointer to the next student node */
	struct node * prev  ;   /*pointer to the prev element on list*/
}StudentNode;

 /*function to create node 
   return type : StudentNode* addres of the created node 
   parameter   : void 
 */
StudentNode* Creat_Node(void);

 /*function to Add node 
   return type : void 
   parameter   : void
 */ 
void Add_node(void); 
/*function to delete node 
   return type : void 
   parameter   : u8 id to search using student id  
 */
void Delete_node(u8 id); 
/*function to search  node 
   return type : StudentNode* addres of the searched node 
   parameter   : u8 id searching using student id  
 */
StudentNode* Search_node(u8 id); 

/*function to Print list
   return type : void 
   parameter   : void
 */
void Print_List(void);
#endif
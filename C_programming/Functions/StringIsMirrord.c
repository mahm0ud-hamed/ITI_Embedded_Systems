#include <stdio.h>
#include <string.h>
void is_mirrord(char* name ) ;
int main(){

    char *name = "sdhmds" ; 
    is_mirrord(name);
}

void is_mirrord(char* name ){
   int len = strlen(name); 
   printf("%d",len); 
   int flag = 0 ; 
   for( int i=0 ; i < len/2 ; i++ ){
    if(name[i] != name[len-1-i] ){
        flag = 1 ; 
    }
   }

   if(flag == 1 ){
    printf("the name is not mirrord \n"); 
   }
   else{
    printf("the name is mirrord \n"); 

   }

}
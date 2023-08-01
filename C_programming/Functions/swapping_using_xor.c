#include <stdio.h>

char arr[] = "mahmoud hamed "; 
int main(){


    arr[0]= 'a'; 
    printf("%s\n",arr); 

    int a = 3 ; 
    int b = 2 ; 
    a = a^b ; 
    b = a^b ; 
    a = a^b ; 

    printf("%d    %d",a,b);
}
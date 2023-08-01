#include<stdio.h>

int IsPowerOfThree(int x ); 
int main(){

    int x  ; 
    printf("enter the number you need \n"); 
    scanf("%d",&x); 

    int y = IsPowerOfThree(x); 
    if( y == 0 ){
        printf("the number is power of three \n"); 
    }
    else{
        printf("the numebr is NOT power of three\n"); 
    }


}
int IsPowerOfThree(int x ){
    while(x > 0 ){
        if(x%3 == 0 ){
            if(x == 3 ) {
                return 0 ; 
            }
            x/=3 ; 
        }
        else{
            return 1 ; 
        }
    }
    return 0 ; 
}

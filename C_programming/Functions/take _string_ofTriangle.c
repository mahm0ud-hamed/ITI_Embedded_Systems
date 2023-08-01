#include<stdio.h>
#include<string.h>

char* IS_Traiangle(char* DIM);
char conert_to_Num(char num ); 
int main(){

    char*dim = "2 2 3"; 
    char * ret = IS_Traiangle(dim); 
    int ss = conert_to_Num('3'); 
    printf("%d\n\n\n",ss); 
    printf("%s",ret);
}
char conert_to_Num(char num ){
    return num -48 ; 
}
char* IS_Traiangle(char* arr){
   int  len = strlen(arr) ;
   int counter =0 ;
   char num [3]={0} ; 
   char help = 0 ;
    for(int i =0 ; i < len ; i++){
        if(arr[i] != ' ' && arr[i] != '\0'){
           num[counter] *= 10 ;
           help = conert_to_Num( arr[i]); 
           num[counter] +=help; 
        }
        else if(arr[i] == ' '){
            counter++;
        }
         
    }
    printf("counter == %d\n",counter);
    printf("DIM1 == %d\n",num[0] );
    printf("DIM2 == %d\n",num[1] );
    printf("DIM3 == %d\n",num[2] );

    if(num[0] == num[1] && num[0] == num[2] && num[0] == num[1]){
        return "Eq triangle" ;
    }
    else {
        return "not triangle" ; 
    }
}
#include<stdio.h> 
#include<string.h> 


void Rev_sen(char * sen  , int len ) ; 
int main(){
 char *Sentence = "I Work as Embedded SW engineer for 3 Years" ;
 int len = strlen(Sentence); 
 Rev_sen(Sentence , len );
}

void Rev_sen(char * sen  ,int  len ) {
    int i   , counter = 0  , j ; 
    char arr[100] ={0};
    for(i =0 ; i < len ; i++){
        if(sen[i] != ' ' && sen[i] != '\0'){
            counter++ ;
            arr[i] = sen[i] ;
        }
        else if( sen[i] == ' ' ){
            for(j =0 ; j < counter ; j++){
                sen[j] = sen[counter-j]; 
                sen[len-1-j] = arr[j];
            }
        }
        else if(sen[i] == '\0'){
            break;
        }
        counter =0 ; 
    }
}

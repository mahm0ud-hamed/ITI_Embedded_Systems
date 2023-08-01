#include<stdio.h>
#include<string.h>

void Reverse_sentence(char * my_sent) ; 
int main(){

    char my_sent[] = "I work as an embedded software engineer for 3 years" ;
    Reverse_sentence(my_sent) ; 
    return 0 ; 
}
void Reverse_sentence(char * my_sent){
    int len = strlen(my_sent) , i ;
    char temp = 0 ;  
    for(i =0 ; i < len-1  ; i++){
        temp = my_sent[i] ; 
        my_sent[i] = my_sent[len - 1-i] ; 
        my_sent[len - 1-i] =  my_sent[i];
    }
    printf("%s",my_sent);
    

}
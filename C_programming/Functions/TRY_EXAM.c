#include <stdio.h>

void edit(int * b  ,int n); 
 int get(void){
    return 25 ; 
 } 
int main(){
    const int y = get(); 
    printf("%d\n",y);
    int i ; 
    int d []= {1,3,5,7,9};
    edit(d,5); 
    for(i=0 ; i < 5 ; i++){
        printf("%d",d[i]); 
    } 
    return 0 ; 

}
void edit(int * b  ,int n){
    int i ; 
    for(i=0 ; i < n ; i++){
        *(b+1) = *(b+1)+5; 
    }
}
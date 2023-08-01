#include <stdio.h>
#define P  80  
#define T  84
#define B  66
void tostring(char str[], int num , char gauge); 
char arr[3]; 

struct  mm {
    int x ; 
    int y ; 
    int z 
};

int main(){
   struct  mm abdalla = {.y=2,.x=1 ,.z= 3};
   struct  mm * ptr = &abdalla; 
   int arr[5]={ [0]=1 ,[4]2, [4]3, 4,5};


{
    /* data */
};

tostring(arr , 50 , B);
printf("%s",arr);

}

void tostring(char str[], int num  ,char gauge)
{
    int i, rem, len = 0, n;
    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    ++len;
   
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        if(rem !=0)
        str[len - (i + 1)] = rem + '0';
        else
            str[len - (i + 1)] = 48;
    }
    switch (gauge)
    {
    case 'P' :str[0]='P'; break;
    case 'B' :str[0]='B'; break;
    case 'T' :str[0]='T'; break;
    default:
    // do nothing 
        break;
    }
    str[len] = '\0';
}
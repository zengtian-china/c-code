#include<stdio.h>
union name{
    char a[11];
    double name;
}www;

int main(void){
    printf("%ld",sizeof(www));
}
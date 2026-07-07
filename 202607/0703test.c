#include<stdio.h>

typedef struct da{
    int a; //0~3
    long b; //8~15   =>16
}data;

typedef struct users{
    char name[100];  //0~99
    char pwd[100]; //100~199
    int age;  //200  203
    data pad; // 208 +16


}Users;

int main(void){
    int a = 0x12345678;
    char *p = &a;
    // char *a = (char*) p;
    
printf("%x\n",*p);
printf("%lu",sizeof(Users));
}
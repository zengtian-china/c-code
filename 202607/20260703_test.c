#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void func(char (*wood)[10]){

}

void strtols(char *s, char * p, int ){
    int number = 0;
    for(int i =0; i<strlen(s); i++){
        if( (s[i] -'0') <=9 && s[i]-'0'  >=0){
            number = (s[i] -'0')* pw
        }
    }

};
void hans(int n,char a,char b, char c){
    // n-1 从 a 经过 c 放到 b
    if (n == 0){
        return ;
    }
    hans(n-1,a,c,b);
    printf("%c ======> %c\n",a,c);
    hans(n-1,b,a,c);

}

unsigned long aaa(int n){
    if( n<=2){
        return 1;
    }
    return aaa(n-1) + aaa(n-2);
}
 int digui(int n){
    if (1 == n) return 1;
    return n + digui(n-1);
 }

void main(){

    // char arr[10] ={1,2,3,4,5,6,7,8,9,0};
    // func(&arr);
    // hans(7,'A','B','C');
    // unsigned long number = aaa(50);
    // printf("%ld\n",number);
    int a= digui(100);
    printf("%d\n",a);
     char *endptr;
    long num2 = strtol("33200bvno", &endptr, 10); // 10 表示十进制
}

/*
    char *p = "hello world!";
    printf("%s的长度是%d\n",p,(int)strlen(p));

    char *wood;
    // strcpy(wood,p);
    strncpy(wood,p,6);
    printf("%s的长度是%d\n",wood,(int)strlen(wood));

    char * cc =strstr(p,wood);
    printf("%s的长度是%d\n",wood,(int)strlen(wood));
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main(){
    // 用malloc申请一个能存储10个字符的数组空间， 并且从终端输入一个姓名存储到这个数组中， 通过遍历的方式输出空间里面的内容

    char * p =  malloc(10);
    memset(p,0,10);
    scanf("%9s",p);
    for( int i =0 ;i<10;i++){
        printf("%c",p[i]);
    }
    printf("\n");
    free(p);
    p = NULL;
}
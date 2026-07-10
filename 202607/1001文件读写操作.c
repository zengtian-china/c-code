/*
 * @Author: zengtian
 * @Date: 2026-07-10 08:37:38
 * @LastEditors: zengtian
 * @LastEditTime: 2026-07-10 15:36:07
 * @Description: File Description
 * @FilePath: \202607\1001文件读写操作.c
 * @@file: 
 */

 #include <string.h>
 #include <stdio.h>
 #include <stdlib.h>

struct users
{
    char uname[20];
    int age;
    char add[50];
    long phone;
};

#define MAN_SUN

void push(int **cc, int *p){

    cc[0] = malloc(sizeof(p));
    strcpy(cc[0],p);
    printf("%s",cc[0]);
}



 int main(){
    // 读写文件
    // FILE* fp = fopen("wa.txt","w+");
    // // fwrite(fp,)
    // fputc('w',fp);
    // fputs("author: zengtian\n",fp);
    // fprintf(fp,"hello zengtian");

    // fclose(fp);
    // struct users *user = calloc(1,sizeof(user));
    // FILE *fp = fopen("wa.txt","r");
    // fscanf(fp,"%[^|]|%d|%[^|]|%ld",user->uname,&user->age,user->add,&user->phone);
    // printf("%s %d %s %ld",user->uname,user->age,user->add,user->phone);


    // fclose(fp);
    

    // int i =1;
    // long sum =0;
    
    char **wa = (char **)malloc(sizeof(char *) * 3);

    int **wa = malloc(sizeof(int *) *5);
    char *p = "tian";
    int *wc = {1,2,4,5,6};

    push(wa,wc);
    // printf("%ld",sizeof(wa));
    

 }
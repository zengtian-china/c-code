#include<stdio.h>
typedef struct Perpon{
    char uname[32];
    char sex[4];
    int age;
    char addr[100];
} perpon;

int main(void){
    perpon jack;
    printf("姓名");
    scanf("%s",jack.uname);
    printf("性别");
    scanf("%s",jack.sex);
    printf("年龄");
    scanf("%d",&jack.age);
    printf("地址");
    scanf("%s",jack.addr);
    printf("\n");
    printf("姓名:%s 性别:%s 年龄:%d 地址:%s\n",jack.uname,jack.sex,jack.age,jack.addr);
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct cJSON{
    struct cJSON *next;  //指向链表中下一个兄弟节点
    struct cJSON *prev;  //指向链表中上一个兄弟节点
    struct cJSON *child; //指向第一个子节点（数组和对象）
    int type;
    char *valuestring;
    double valuedouble;
    char *string; //对象的键名(到此节点是对象的属性时使用)


} cJSON;
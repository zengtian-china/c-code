#include<stdio.h>
#include<string.h>
#include<stdlib.h>



//链表
typedef struct _node{
    int value;
    struct _node *next;
}Node;

Node * newNode(const int value){
    Node *node = malloc(sizeof(Node));
    if (node == NULL) return NULL;
    node->value = value;
    node->next = NULL;
    return node;
}


//往node1 后面插入
void push(Node *node1,Node *node2){
//判断 node1是否为空
if(node1 == NULL) return;
node2->next = node1->next;
node1->next = node2;
}

//删除
void pop(Node *node1){
    if (node1->next ==NULL) return ;
    int tmp = node1->next->value;
    Node * tmp_node = node1->next;
    node1->next = node1->next->next;
    free(tmp_node);
    return tmp;
    
}

int find(Node * node1,int value){
    Node * tmp_node = node1;
    while (tmp_node != NULL)
    {
        if(tmp_node->value == value){
            return 1;
        }
        tmp_node = tmp_node->next;
    }
    return -1;
    
}



int number1 = 13;  // number1->.data  13->.data
double number2 = 343; // number2->.data 343->.rodata
char str1 = 's';  // str1->.data   s->.data
char *p = "tian"; // p->.data   tian->.rodata

const int number3 = 423;  //number3-> .rodata  423->.rodata
const double number4 = 43.23; // number4->.rodata number4->.rodata
const str2 = '3'; //str2->.rodata 3->.rodata
const char *fs = "nosn"; // fs->.rodata nosn->.rodata
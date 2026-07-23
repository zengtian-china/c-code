/*
 * @Author: zengtian
 * @Date: 2026-07-16 14:27:38
 * @LastEditors: zengtian
 * @LastEditTime: 2026-07-17 14:01:03
 * @Description: File Description
 * @FilePath: \202607\1601链表队列.c
 * @@file: 
 */
#include <stdlib.h>
#include<stdio.h>
typedef struct _node{
    int value;
    struct _node * next;
}node;

node * newNode(int value){
    node * no = malloc(sizeof(node));
    if (no ==NULL) return NULL;
    no->value = value;
    return no;
}

typedef struct _list{
    //头节点
    node * front;
    node * pear;
    int size;

}nodeList;

nodeList * newNodeList(){
    nodeList *list = malloc(sizeof( *list));
    if (list == NULL) return NULL;

    list->front = NULL;
    list->pear = NULL;
    list->size = 0;
    return list;
}
void delList(nodeList *list){
    node * tmp = list->front;
    while (list->front!=NULL)
    {
        node * tmp = list->front;
        list->front = list->front->next;
        free(tmp);

        //tmp = tmp->//
    }
    
}


void push(nodeList *list, int value){
    node * nod = newNode(value);
    if (list->front == NULL && list->pear == NULL){
        list->front = nod;
        list->pear = nod;
    } else{
        list->pear->next = nod;
        list->pear = nod;
        list->size +=1;
    }

}

/* 访问队首元素 */
int peek(nodeList *queue) {
    assert(size(queue) && queue->front);
    return queue->front->value;
}

int pop(nodeList *list){
    if(list->front == NULL) return NULL;
    node * tmp = list->front;
    list->front = list->front->next;
    int num= peek(list);
    if (list->front == NULL) {
        list->pear = NULL;
    }
    free(tmp);
    list->size --;
    return num;


}
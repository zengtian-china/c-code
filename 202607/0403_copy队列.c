#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct ListNode {
    int val;               // 节点值
    struct ListNode *next; // 指向下一节点的指针
} ListNode;

/* 构造函数 */
ListNode *newListNode(int val) {
    ListNode *node;
    node = (ListNode *) malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

typedef struct{
    ListNode  *start,*end;
    int queSize;

}LinkedListQueue;
LinkedListQueue *newLinkedListQueue(){
    LinkedListQueue *queue = calloc(1,sizeof(LinkedListQueue));
    queue->start = NULL;
    queue->end = NULL;
    queue->queSize =0;
    return queue;
    
}


/* 析构函数 */
void delLinkedListQueue(LinkedListQueue *queue) {
    // 释放所有节点
    while (queue->start != NULL) {
        ListNode *tmp = queue->start;
        queue->start = queue->start->next;
        free(tmp);
    }
    // 释放 queue 结构体
    free(queue);
}

/* 获取队列的长度 */
int size(LinkedListQueue *queue) {
    return queue->queSize;
}

/* 判断队列是否为空 */
bool empty(LinkedListQueue *queue) {
    return (size(queue) == 0);
}


void push(LinkedListQueue * p, int value){
    ListNode * num = newListNode(value);
    if(p->start == NULL){
        p->start = num;
        p->end = num;
    }
    else{
        p->end->next = num;
        p->end = num;
    }
    p->queSize+=1;
}

int peek(LinkedListQueue *queue){
    assert(size(queue) && queue->start);
    return queue->start->val;

}

int pop(LinkedListQueue *queue){
    int num = peek(queue);
    ListNode * tmp = queue->start;
    queue->start = tmp->next;
    free(tmp);
    queue->queSize-=1;
    return num;
}

void printLinkedListQueue(LinkedListQueue *queue){
    int *arr = calloc(queue->queSize,sizeof(int));
    int i;
    ListNode * node;
    for(i=0,node = queue->start; i<queue->queSize;i++){
        arr[i] = node->val;
        node = node->next;
    }
    free(arr);
}
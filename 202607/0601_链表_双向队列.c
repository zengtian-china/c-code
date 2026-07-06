#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//双向链表节点
typedef struct {
    int value;
    struct DoublyListNode *next;
    struct DoublyListNode *prev; //前驱节点

}DoublyListNode;

DoublyListNode * newDoublyListNode(int number){
    DoublyListNode *list = calloc(1,sizeof(DoublyListNode));
    list->value = number;
    list->next = NULL;
    list->prev = NULL;
    return list;
}

void delDoublyListNode(DoublyListNode *p){
    free(p);
}

//双向链表实现的队列
typedef struct{
    DoublyListNode *front;
    DoublyListNode *rear;
    int queSize;
}LinkedListDeque;

LinkedListDeque * newLinkedListDeque(){
    LinkedListDeque *deque = calloc(1,sizeof(LinkedListDeque));
    deque->queSize = 0;
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}

void delLinkedListDeque(LinkedListDeque *deque){
        // 释放所有节点
    for (int i = 0; i < deque->queSize && deque->front != NULL; i++) {
        DoublyListNode *tmp = deque->front;
        deque->front = deque->front->next;
        free(tmp);
    }
    // 释放 deque 结构体
    free(deque);
}

int size(LinkedListDeque *deque){
    return deque->queSize;
}
bool empty(LinkedListDeque *deque){
    return (size(deque) ==0);
}

void push(LinkedListDeque *deque, int number, bool isFront){
    DoublyListNode *node = calloc(1,sizeof(DoublyListNode));
    node->value = number;
    if(empty(deque)){
        deque->front = deque->rear = node;
    }
    if(isFront){
        node->next = deque->front;
        deque->front->prev = node;
        deque->front = node;
    } else{
        node->prev = deque->rear;
        deque->rear->next = node;
        deque->rear = node;
    }

    deque->queSize++;
}

int pop(LinkedListDeque *deque,bool isFront){
    int value;
    if (empty(deque)){
        return -1;
    }
    //队首出队操作
    if (isFront){

        DoublyListNode *tmp = deque->front;
        value = deque->front->value;  //获取出队的值
        deque->front = deque->front->next; //将出队的下一个地址赋值给队首
        // 如果 首节点和尾节点都指向同一个位置
        if(deque->front !=NULL){
            deque->front->prev = tmp->prev; //将出队的是上一个节点的地址赋值给队首的上一个节点的地址
        } else{
            deque->rear = NULL;
        }
        free(tmp);
    } else{
        DoublyListNode *tmp = deque->rear;
        value = deque->rear->value; //取队尾的值
        deque->rear = deque->rear->prev; //将出队的上一个节点的地址
        if(deque->rear !=NULL){
            deque->rear->next = tmp->next;      
        } else{
            deque->front = NULL;
        }

        free(tmp);

    }
    deque->queSize -=1;
    return value;



}   

/* 队首出队 */
int popFirst(LinkedListDeque *deque) {
    return pop(deque, true);
}

/* 队尾出队 */
int popLast(LinkedListDeque *deque) {
    return pop(deque, false);
}

/* 打印队列 */
void printLinkedListDeque(LinkedListDeque *deque) {
    int *arr = malloc(sizeof(int) * deque->queSize);
    // 拷贝链表中的数据到数组
    int i;
    DoublyListNode *node;
    for (i = 0, node = deque->front; i < deque->queSize; i++) {
        arr[i] = node->value;
        node = node->next;
    }
    printArray(arr, deque->queSize);
    free(arr);
}
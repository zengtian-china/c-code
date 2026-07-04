#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct 
{
    int *nums;
    int front;
    int queSize;
    int queCapacity;
}ArrayQueue;

ArrayQueue *newArrayQueue(int capacity){
    ArrayQueue *queue = (ArrayQueue *) malloc(sizeof(ArrayQueue));
    //初始化数组
    queue->queCapacity = capacity;
    queue->nums = malloc(sizeof(int) * capacity);
    queue->front= queue->queSize=0;
    return queue;

}

void delArrayQueue(ArrayQueue *queue){
    free(queue->nums);
    free(queue);
}


int capacity(ArrayQueue *queue){
    return queue->queCapacity;
}

// 获取长度

int size(ArrayQueue *queue){
    return queue->queSize;
}

bool empty(ArrayQueue *queue){
    return queue->queSize ==0;
}


int peek(ArrayQueue *queue){
    assert(size(queue)!=0);
    return queue->nums[queue->front];
}

//入队 从队尾入

void push(ArrayQueue * queue, int value){
        if (size(queue) == capacity(queue)) {
        printf("队列已满\r\n");
        return;
    }
    int rear = (queue->front + queue->queSize) % queue->queCapacity;
        // 将 num 添加至队尾
    queue->nums[rear] = value;
    queue->queSize++;
}

/* 出队 */
int pop(ArrayQueue *queue) {
    int num = peek(queue);
    // 队首指针向后移动一位，若越过尾部，则返回到数组头部
    queue->front = (queue->front + 1) % queue->queCapacity;
    queue->queSize--;
    return num;
}
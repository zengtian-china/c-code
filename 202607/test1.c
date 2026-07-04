#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

/* 1. 补齐：链表节点的定义 */
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

/* 2. 补齐：创建新节点的函数 */
ListNode *newListNode(int val) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

/* 3. 补齐：打印数组的辅助函数 */
void printArray(int *arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

/* 4. 你提供的队列结构体和所有操作（保持不变） */
typedef struct {
    ListNode *front, *rear;
    int queSize;
} LinkedListQueue;

LinkedListQueue *newLinkedListQueue() {
    LinkedListQueue *queue = (LinkedListQueue *)malloc(sizeof(LinkedListQueue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->queSize = 0;
    return queue;
}

void delLinkedListQueue(LinkedListQueue *queue) {
    while (queue->front != NULL) {
        ListNode *tmp = queue->front;
        queue->front = queue->front->next;
        free(tmp);
    }
    free(queue);
}

int size(LinkedListQueue *queue) {
    return queue->queSize;
}

bool empty(LinkedListQueue *queue) {
    return (size(queue) == 0);
}

void push(LinkedListQueue *queue, int num) {
    ListNode *node = newListNode(num);
    if (queue->front == NULL) {
        queue->front = node;
        queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->queSize++;
}

int peek(LinkedListQueue *queue) {
    assert(size(queue) && queue->front);
    return queue->front->val;
}

int pop(LinkedListQueue *queue) {
    int num = peek(queue);
    ListNode *tmp = queue->front;
    queue->front = queue->front->next;
    free(tmp);
    queue->queSize--;
    return num;
}

void printLinkedListQueue(LinkedListQueue *queue) {
    int *arr = malloc(sizeof(int) * queue->queSize);
    int i;
    ListNode *node;
    for (i = 0, node = queue->front; i < queue->queSize; i++) {
        arr[i] = node->val;
        node = node->next;
    }
    printArray(arr, queue->queSize);
    free(arr);
}

/* 5. 补齐：简单的测试主函数 */
int main() {
    LinkedListQueue *queue = newLinkedListQueue();
    
    push(queue, 10);
    push(queue, 20);
    push(queue, 30);
    
    printf("当前队列: ");
    printLinkedListQueue(queue); // 输出: [10, 20, 30]
    
    printf("出队元素: %d\n", pop(queue)); // 输出: 10
    printf("队首元素: %d\n", peek(queue)); // 输出: 20
    
    printf("出队后队列: ");
    printLinkedListQueue(queue); // 输出: [20, 30]
    
    delLinkedListQueue(queue);
    return 0;
}
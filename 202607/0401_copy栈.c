#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode{
    int val;
    struct ListNode *next;
} ListNode;

ListNode *newListNode(int val){
    ListNode *node;
    node = (ListNode *) malloc(sizeof(ListNode));
    memset(node,0,sizeof(ListNode));
    node->val = val;
    node->next =NULL;
    return node;
}

//基于链表实现的栈
typedef struct 
{
    ListNode *top;
    int size;
} LinkedListStack;

LinkedListStack *newLinkedListStack(){
    LinkedListStack *s = calloc(1,sizeof(LinkedListStack));
    s->top = NULL;
    s->size =0;
    return s;
}

void delLinkedListStack(LinkedListStack *s){
    while (s->top)
    {
        ListNode *n = s->top->next;
        free(s->top);
        s->top = n;
    }
    free(s);
    
}

int size(LinkedListStack *s){
    return s->size;
}

bool isEmpty(LinkedListStack *s){
    return size(s) == 0;
}

void push(LinkedListStack *s,int num){
    ListNode *node = (ListNode *) malloc(sizeof(ListNode));
    node->val = num;
    node->next = s->top;
    s->top = node;
    s->size++;

}

int peek(LinkedListStack *s){
    if(s->size ==0){
        printf("栈为空\n");
        return INT_MAX;
    }
    return s->top->val;
}

int pop(LinkedListStack *s){
    int number = peek(s);
    ListNode * tmp = s->top;
    s->top = s->top->next;
    free(tmp);
    s->size -=1;
    return number;
}


void push2(LinkedListStack *p,int number){
    ListNode * node = calloc(1,sizeof(ListNode));
    node->val = number;
    node->next = p->top;
    p->top = node;
    p->size +=1;
}
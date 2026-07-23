#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。*/

typedef struct _node
{
    char name;
    struct _node *next;
}Node;

Node *newNode(char s){
    Node *node = malloc(sizeof(Node));
    if (node == NULL) return NULL;
    node->next = NULL;
    node->name = s;
    return node;
}
typedef struct _stack{
    Node *top;
    int size;
}Stack;


Stack *newStack(){
    Stack *stack = malloc(sizeof(Stack));
    if (stack == NULL) return NULL;
    stack->size = 0;
    stack->top = NULL;
    return stack;
}

void push(Stack *stack,char str){
    Node *node = newNode(str);
    node->next = stack->top;
    stack->top = node;
    stack->size+=1;

}

char pop(Stack *stack){

    if(stack->top == NULL)
    return ' ';
    char s = stack->top->name;

    stack->top = stack->top->next;
    stack->size -=1;
    return s;
}
char getTop(Stack *stack){
    // 防御性判断：栈结构体为空，或者栈内没有元素时，返回一个安全的默认值
    if (stack == NULL || stack->top == NULL) {
        return ' '; 
    }
    return stack->top->name;
}
void defStack(Stack *stack){
    while (stack->top !=NULL)
    {
        Node *tmp = stack->top;
        stack->top = stack->top->next;
        free(tmp);
    }
    free(stack);
    
}
bool isValid(char* s) {
    int i = 0;
    Stack *stack = newStack();
    if (stack == NULL) return false; // 防御性编程

    while (s[i] != '\0') {
        // 1. 遇到左括号，直接入栈
        if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
            push(stack, s[i]);
        } 
        // 2. 遇到右括号，必须先检查栈是否为空
        else if (s[i] == '}' || s[i] == ')' || s[i] == ']') {
            if (stack->size == 0) {
                defStack(stack);
                return false; // 栈空遇到右括号，直接无效
            }
            
            char topChar = getTop(stack);
            // 匹配成功，出栈
            if ((s[i] == '}' && topChar == '{') ||
                (s[i] == ')' && topChar == '(') ||
                (s[i] == ']' && topChar == '[')) {
                pop(stack);
            } else {
                // 匹配失败，直接无效
                defStack(stack);
                return false;
            }
        }
        i++;
    }

    // 遍历结束后，栈必须为空才有效
    bool result = (stack->size == 0);
    defStack(stack); // 无论结果如何，一定要释放内存！
    return result;
}



char pairs(char a) {
    if (a == '}') return '{';
    if (a == ']') return '[';
    if (a == ')') return '(';
    return 0;
}


bool isValid(char* s) {
    int n = strlen(s);
    if (n % 2 == 1) {
        return false;
    }
    int stk[n + 1], top = 0;
    for (int i = 0; i < n; i++) {
        char ch = pairs(s[i]);
        if (ch) {
            if (top == 0 || stk[top - 1] != ch) {
                return false;
            }
            top--;
        } else {
            stk[top++] = s[i];
        }
    }
    return top == 0;
}

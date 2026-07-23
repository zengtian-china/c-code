#include<stdio.h>
#include<string.h>
#include<stdlib.h>


/*
数组 digits 从左到右保存一个非负整数的各位数字，例如 [3, 0, 8] 表示 308。
数字 0 用 [0] 表示；其他输入的第一位均不为 0。
请模拟一次十进制竖式加法，将这个整数增加 1，并把结果仍按相同的数组形式返回。 
可以直接修改 digits；若最前面产生新的进位，可以返回一个更长的数组。
*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    
    for(int i = digitsSize-1;i>=0;i--){
        digits[i] +=1;
        if(digits[i] == 10){
            digits[i] =0;
        }else{
            *returnSize = digitsSize;
            return digits;
        }
    }
    free(digits);
    // [9,9,9] 情况出现
    *returnSize =digitsSize+1;
    int * new_digits = calloc((*returnSize),sizeof(int));
    new_digits[0] = 1;
    return new_digits;

}


/*
2.   反转单向链表¶
给定一个单向链表的头节点 head。每个节点包含一个值和指向下一节点的 next。
请使用迭代方法反转所有节点之间的连接，并返回反转后的头节点。 要求不创建新的链表节点。
*/


// * Definition for singly-linked list.
  struct ListNode {
      int val;
      struct ListNode *next;
 };
 
struct ListNode* reverseList(struct ListNode* head) {
    if(head ->next == NULL) return head;
    struct ListNode *newHead = reverseList(head->next);
    if(head->next !=NULL && head->next->next == NULL){
    head->next->next = head;
    head->next = NULL;
    return newHead;
    }
}





int main(void) {


}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// struct ListNode* reverseList(struct ListNode* head) {
//     if(head  == NULL || head->next == NULL) return head;
//     struct ListNode* newHead = reverseList(head->next);
//     head->next->next = head;
//     head->next = NULL;
//     return newHead;
// }
struct ListNode* reverseList(struct ListNode* head) {
    //当前节点
    struct ListNode * dong = head;
    // 前一个节点
    struct ListNode * qian = NULL;

    while(dong !=NULL){
        struct ListNode *next = dong->next;
        dong->next = qian;
        qian = dong;
        dong = next;
        
        // free(next);
    }
    return dong;
}

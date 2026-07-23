#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _CircListNode{
    int value;
    struct _CircListNode *next;
}CircListNode;


CircListNode * newCircListNode(int value){
    CircListNode *circ_node = calloc(1,sizeof(CircListNode));
    if (circ_node == NULL) return NULL;
    circ_node->value = value;
    circ_node->next =circ_node;
    return circ_node;
}


int push(CircListNode *node1,CircListNode *node2){
    if(node1->next ==NULL || node2->next == NULL) return -1;
    node2->next = node1->next;
    node1->next = node2;
    return 1;

}

int circ_list_pop_after(CircListNode *pos, int *out_value) {
    if (pos == NULL || out_value == NULL) return -1;

    CircListNode *target = pos->next;
    if (target == NULL) return -1;  // 防御性检查

    *out_value = target->value;

    if (target == pos) {
        /* ✅ 修复：环中仅剩一个节点，删除后 pos 自环 */
        pos->next = pos;
    } else {
        pos->next = target->next;
    }

    free(target);
    return 0;
}
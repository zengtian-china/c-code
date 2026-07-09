#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 前向声明
typedef struct _nodes Node;

// 定义一个链表
typedef struct _node
{
    Node *value;
    struct _node *next;
} childrens;

typedef enum {
    DIR,
    FILES
} NodeType;

typedef struct _nodes {
    char name[256];
    NodeType type;
    childrens *children;
    struct _nodes *parent;
} Node;

Node *newDir(const char *new_name, Node *parent) {
    Node *node = (Node *)calloc(1, sizeof(Node));
    strncpy(node->name, new_name, 255);
    node->name[255] = '\0';
    node->type = DIR;
    node->parent = parent;
    return node;
}

Node *newFile(const char *new_name, Node *parent) {
    Node *node = (Node *)calloc(1, sizeof(Node));
    strncpy(node->name, new_name, 255);
    node->name[255] = '\0';
    node->type = FILES;
    node->parent = parent;
    return node;
}

void add_child(Node *node, Node *child) {
    childrens *new_child_node = (childrens *)calloc(1, sizeof(childrens));
    new_child_node->value = child;
    new_child_node->next = NULL;

    if (node->children == NULL) {
        // 修复1：如果为空，直接赋值并返回，避免后续代码执行
        node->children = new_child_node;
    } else {
        // 修复2：如果不为空，才去遍历找末尾
        childrens *tmp = node->children;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new_child_node;
    }
    child->parent = node;
}

void list(Node *node, int depth) {
    if (node == NULL) return;

    // 打印缩进
    for (int i = 0; i < depth; i++) printf("  ");

    if (node->type == DIR) {
        printf("[DIR] %s\n", node->name);
        childrens *child = node->children;
        // 修复3：遍历条件改为判断 child 本身是否为 NULL，防止空指针崩溃
        while (child != NULL) {
            list(child->value, depth + 1);
            child = child->next;
        }
    } else {
        printf("[FILE] %s\n", node->name);
    }
}

int main() {
    Node *root = newDir("/", NULL);
    printf("已创建根目录 '/'\n\n");

    Node *home_dir = newDir("home", root);
    Node *bin_dir = newDir("bin", root);
    add_child(root, home_dir);
    add_child(root, bin_dir);

    Node *user_dir = newDir("user", home_dir);
    add_child(home_dir, user_dir);

    Node *file1 = newFile("a.txt", user_dir);
    Node *file2 = newFile("b.txt", user_dir);
    add_child(user_dir, file1);
    add_child(user_dir, file2);

    Node *file3 = newFile("python.exe", bin_dir);
    add_child(bin_dir, file3);

    printf("=== 文件系统结构 ===\n");
    list(root, 0);

    return 0;
}
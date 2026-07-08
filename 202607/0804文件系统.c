#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef enum {
    TYPE_DIR,
    TYPE_FILE
} NodeType;

typedef struct node{
    char name[256];
    NodeType type; 
    struct node *children;
    struct node *parent;
    struct node* next_sibling;// 指向下一个兄弟节点的指针
}Node;

Node* newNodeDir(char *name, Node* parent){
    Node *no = calloc(1,sizeof(Node));

    strcpy(no->name, name);

    no->children = NULL;
    no->type = TYPE_DIR;
    no->parent =parent;
    no->next_sibling = NULL;
    return no;

}
Node* newNodeFile(const char* name, Node* parent){
        Node* new_file = (Node*)malloc(sizeof(Node));
    if (new_file == NULL) {
        perror("内存分配失败");
        exit(EXIT_FAILURE);
    }
    strcpy(new_file->name, name);
    new_file->type = TYPE_DIR;
    new_file->children = NULL;
    new_file->parent = parent;
    new_file->next_sibling =NULL;
    return new_file;
}


void add_child(Node *parent,Node *child){
    if(parent->type !=TYPE_DIR){
        printf("错误，只有目录才能包含子节点。\n");
    }

    if(parent->children ==NULL){
        parent->children = child;
    } else{
        Node* current = parent->children;
        
        while (current->next_sibling != NULL) {
            current = current->next_sibling;
        }
        current->next_sibling = child;
    }

}

void list(Node* node,int depth){
    if(node->type == TYPE_DIR){
        //打印目录名
        for(int i=0;i<depth;i++) printf("  ");
        printf("[DIR] %s\n",node->name);
        // 递归打印所有子节点
        Node* child = node->children;
        while (child != NULL) {
            list(child, depth + 1);
            child = child->next_sibling;
        }
    }
    else{
        for (int i = 0; i < depth; i++) printf("  ");
        printf("[FILE] %s\n", node->name);
    }
}

void free_tree(Node* node) {
    if (node->type == TYPE_DIR) {
        Node* child = node->children;
        while (child != NULL) {
            Node* next = child->next_sibling; // 先保存下一个兄弟节点
            free_tree(child);                 // 释放当前子树
            child = next;                     // 移动到下一个兄弟节点
        }
    }
    free(node); // 最后释放自己
}


// --- 6. 主函数：模拟文件系统操作 ---

int main() {
    // 1. 创建根目录 '/'
    Node* root = newNodeDir("/", NULL);
    printf("已创建根目录 '/'\n\n");

    // 2. 创建目录和文件，模拟视频中的操作
    // 创建 /home 和 /bin 目录
    Node* home_dir = newNodeDir("home", root);
    Node* bin_dir = newNodeDir("bin", root);
    add_child(root, home_dir);
    add_child(root, bin_dir);

    // 创建 /home/user 目录
    Node* user_dir = newNodeDir("user", home_dir);
    add_child(home_dir, user_dir);

    // 在 /home/user 下创建文件
    Node* file1 = newNodeFile("a.txt", user_dir);
    Node* file2 = newNodeFile("b.txt", user_dir);
    add_child(user_dir, file1);
    add_child(user_dir, file2);

    // 在 /bin 下创建文件
    Node* file3 = newNodeFile("python.exe", bin_dir);
    add_child(bin_dir, file3);

    // 3. 列出整个文件系统结构
    printf("=== 文件系统结构 ===\n");
    list(root, 0);

    // 4. 释放所有分配的内存
    free_tree(root);
    
    return 0;
}





void showNode(Node *no){
    printf("%s",no->name);
}


typedef struct{
Node *root;
Node *now;

}FileSystemTree;

void mkdir(FileSystemTree *fi,char *strs){

}

void ls(FileSystemTree *fi){
    
}

void cd(FileSystemTree *fi,char *strs){

}
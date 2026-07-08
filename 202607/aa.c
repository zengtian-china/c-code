 #include <stdio.h>


// int func( int n){
//     if (1 == n)
//     return 1;
//     return n+ func(n-1);
// }


// void func1(){
//      int arr[2][3] = {{1,2,3}, {4,5,6}};
//      int (*p)[2][3] =  &arr;
//      for (int i=0;i<2;i++){
//         for (int j =0;j<3;j++){
//             printf("%d ",(*p)[i][j]);
//             // (*p)[j]) (*p+1)[j]
//         }
//      }
//      printf("\n");
// }

// void func2(){
//     int num[3]={9,8,7};
//     int (*p)[3] = &num;

//     for(int i=0;i<3;i++){
//         printf("(*p)[%d] ==%d ",i,(*p)[i]);
//         printf(" ===");
//         printf("(p[0][%d]) ==%d \n",i,p[0][i]);
//     }

// }

// int main(){

//     // int number = func(10001);
//     // printf("%d \n",number);
//     func1();
//     func2();

//     return 0;
// }

// float product( float number1,float number2){
//     return number1 * number2;
// }
// void main(){
//     float sum;
//     sum = product(23.1,32.2);
//     printf("%lf \n",sum);
// }

// float get_avg(int* array,int size){
//     int sum = 0;
//     for(int i=0;i<size;i++){
//         sum += array[i];
//     }
    
//     return sum / size;
// }
// void main(){
//     int  array[10] = {32,43,645,123,32,545,23,54,23,54};
//     float avg = get_avg(array,sizeof(array)/sizeof(int));
//     printf("%lf \t",avg);
// }


// void printInfo(char name[],int age){
//     printf("姓名: %s, 年龄: %d\n",name,age);
// }
// void main(){
//     printInfo("zengtian",18);
// }


//4.设计一个函数接收一个正整数n，递归输出n的每一位数字（如输入123，输出1 2 3）  (选做)

// void func1(int n){
//     if (0 ==n){
//         return ;
//     }
//     int next_number = n /10;
    
//     func1(next_number);
//     printf("%d ",n %10);
// }

// void main(){
//     func1(123);
//     printf("\n");
// }

// void main(int argc, char * argv[]){
// //     if (argc <3){
// //         printf("缺失必要的参数\n");
// //         return ;
// //     }
// //     printf("%s%s\n",argv[1],argv[2]);
// // }
    
// }

// float get_avg(int * array,int size){
//     int sum = 0;
//     for(int i=0;i<size;i++){
//         sum += array[i];
//     }
    
//     return (float)sum / size;
// }
// void main(){
//     int  array[12] = {32,43,645,123,32,545,23,54,23,54,32,41};
//     float avg = get_avg(array,sizeof(array)/sizeof(int));
//     printf("%lf \n",avg);
// }




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- 1. 定义节点类型和节点结构体 ---

// 节点类型：区分是目录还是文件
typedef enum {
    TYPE_DIR,
    TYPE_FILE
} NodeType;

// 树节点结构体
typedef struct Node {
    char name[256];           // 节点名称（文件名或目录名）
    NodeType type;            // 节点类型
    struct Node* parent;      // 指向父节点的指针
    struct Node* first_child; // 指向第一个子节点的指针
    struct Node* next_sibling;// 指向下一个兄弟节点的指针
} Node;

// --- 2. 创建新节点的函数 ---

// 创建一个新的目录节点
Node* create_directory(const char* name, Node* parent) {
    Node* new_dir = (Node*)malloc(sizeof(Node));
    if (new_dir == NULL) {
        perror("内存分配失败");
        exit(EXIT_FAILURE);
    }
    strcpy(new_dir->name, name);
    new_dir->type = TYPE_DIR;
    new_dir->parent = parent;
    new_dir->first_child = NULL;
    new_dir->next_sibling = NULL;
    return new_dir;
}

// 创建一个新的文件节点
Node* create_file(const char* name, Node* parent) {
    Node* new_file = (Node*)malloc(sizeof(Node));
    if (new_file == NULL) {
        perror("内存分配失败");
        exit(EXIT_FAILURE);
    }
    strcpy(new_file->name, name);
    new_file->type = TYPE_FILE;
    new_file->parent = parent;
    new_file->first_child = NULL; // 文件没有子节点
    new_file->next_sibling = NULL;
    return new_file;
}

// --- 3. 添加子节点的函数 ---

// 将子节点添加到父节点的子节点列表末尾
void add_child(Node* parent, Node* child) {
    if (parent->type != TYPE_DIR) {
        printf("错误: 只有目录才能包含子节点。\n");
        return;
    }
    
    if (parent->first_child == NULL) {
        // 如果父节点没有子节点，新节点就是第一个子节点
        parent->first_child = child;
    } else {
        // 否则，找到子节点链表的末尾，将新节点接上
        Node* current = parent->first_child;
        while (current->next_sibling != NULL) {
            current = current->next_sibling;
        }
        current->next_sibling = child;
    }
}

// --- 4. 列出目录内容的函数 ---

// 打印节点及其所有子节点，用于显示树形结构
void list(Node* node, int depth) {
    if (node->type == TYPE_DIR) {
        // 打印目录名，前面加上缩进
        for (int i = 0; i < depth; i++) printf("  ");
        printf("[DIR] %s\n", node->name);
        
        // 递归打印所有子节点
        Node* child = node->first_child;
        while (child != NULL) {
            list(child, depth + 1);
            child = child->next_sibling;
        }
    } else {
        // 打印文件名
        for (int i = 0; i < depth; i++) printf("  ");
        printf("[FILE] %s\n", node->name);
    }
}

// --- 5. 释放内存的函数 ---

// 递归释放整个树的内存，防止内存泄漏
void free_tree(Node* node) {
    if (node->type == TYPE_DIR) {
        Node* child = node->first_child;
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
    Node* root = create_directory("/", NULL);
    printf("已创建根目录 '/'\n\n");

    // 2. 创建目录和文件，模拟视频中的操作
    // 创建 /home 和 /bin 目录
    Node* home_dir = create_directory("home", root);
    Node* bin_dir = create_directory("bin", root);
    add_child(root, home_dir);
    add_child(root, bin_dir);

    // 创建 /home/user 目录
    Node* user_dir = create_directory("user", home_dir);
    add_child(home_dir, user_dir);

    // 在 /home/user 下创建文件
    Node* file1 = create_file("a.txt", user_dir);
    Node* file2 = create_file("b.txt", user_dir);
    add_child(user_dir, file1);
    add_child(user_dir, file2);

    // 在 /bin 下创建文件
    Node* file3 = create_file("python.exe", bin_dir);
    add_child(bin_dir, file3);

    // 3. 列出整个文件系统结构
    printf("=== 文件系统结构 ===\n");
    list(root, 0);

    // 4. 释放所有分配的内存
    free_tree(root);
    
    return 0;
}
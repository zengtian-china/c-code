#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1. 学生结构体
typedef struct{
    char uname[16];
    int age;
    float grade;
} Student;

// 2. 学生容器结构体
typedef struct{
    int size;
    int capacity;
    Student *array;
} Students;

// 3. 创建学生容器
Students *newStudents(int capacity){
    Students *stus = (Students *)calloc(1, sizeof(Students));
    if (!stus) return NULL;
    stus->size = 0;
    stus->capacity = capacity;
    // 分配连续内存存放 Student 结构体
    stus->array = (Student *)calloc(capacity, sizeof(Student));
    if (!stus->array) {
        free(stus);
        return NULL;
    }
    return stus;
}

// 4. 录入函数（修复了之前的越界Bug）
void push(Students *stu, const char *name, int age, float grade){
    if (stu->size >= stu->capacity) {
        printf("容量已满，无法添加！\n");
        return;
    }
    // ✅ 修正：存在 size 的位置，而不是 size-1
    strncpy(stu->array[stu->size].uname, name, 15);
    stu->array[stu->size].uname[15] = '\0'; // 确保字符串安全结束
    stu->array[stu->size].age = age;
    stu->array[stu->size].grade = grade;
    
    stu->size += 1;
}

// 5. 显示函数
void displayStudents(const Students *stu){
    printf("\n====== 学生信息列表 ======\n");
    if (stu->size == 0) {
        printf("（暂无学生数据）\n");
    } else {
        for (int i = 0; i < stu->size; i++) {
            printf("姓名: %-10s | 年龄: %-3d | 成绩: %.1f\n", 
                   stu->array[i].uname, 
                   stu->array[i].age, 
                   stu->array[i].grade);
        }
    }
    printf("==========================\n\n");
}

// 6. 查找函数（通过姓名查找）
// 返回找到的学生在数组中的索引，找不到返回 -1
int findByName(const Students *stu, const char *name){
    for (int i = 0; i < stu->size; i++) {
        if (strcmp(stu->array[i].uname, name) == 0) {
            return i; 
        }
    }
    return -1;
}

// 7. 销毁容器（保留你之前写得非常好的释放逻辑）
void delStudents(Students *stu) {
    if (stu == NULL) return;
    if (stu->array != NULL) {
        free(stu->array); 
        stu->array = NULL; 
    }
    free(stu); 
}

// 8. main 函数测试
int main(void){
    // 1. 创建容量为 10 的容器
    Students *st = newStudents(10);
    if (!st) return -1;

    // 2. 录入测试数据
    push(st, "tian", 12, 88.5);
    push(st, "alice", 19, 92.0);
    push(st, "bob", 21, 76.5);
    
    // 3. 测试显示函数
    displayStudents(st);
    
    // 4. 测试查找函数
    char *searchName = "alice";
    int index = findByName(st, searchName);
    
    if (index != -1) {
        printf("🔍 查找 [%s] 成功！\n", searchName);
        printf("姓名: %-10s | 年龄: %-3d | 成绩: %.1f\n\n", 
               st->array[index].uname, 
               st->array[index].age, 
               st->array[index].grade);
    } else {
        printf("❌ 未找到名为 [%s] 的学生。\n\n", searchName);
    }
    
    // 5. 安全释放内存
    delStudents(st);
    
    return 0;
}
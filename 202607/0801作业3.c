#include <stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct{
    char uname[16];
    int age;
    float grade;
}Student;

Student * stus(char *p,int age,float grade){
    Student *stu = calloc(1,sizeof(Student));
    // stu->uname = p;
    strcpy(stu->uname,p);
    stu->age = age;
    stu->grade = grade;
    return stu;
}

typedef struct{
    int size;
    int capacity;
    Student *array;
}students;

students *newStudents(int capacity){
    students *stus = calloc(1,sizeof(students));
    stus->size =0;
    stus->capacity = capacity;
    stus->array = calloc(stus->capacity,sizeof(Student));

    return stus;
}

void delStudent(students *stu) {
    if (stu == NULL) return;
    

    if (stu->array != NULL) {
        free(stu->array); 
        stu->array = NULL;
    }
    free(stu); 
}
//   设计学生信息录入函数， 显示函数， 查找函数（比如通过姓名查找）


void add(students *stu){
    Student *arrays = calloc(stu->capacity*2,sizeof(Student));
    for(int i =0;i<stu->capacity;i++){
        arrays[i] = stu->array[i];
    }
    stu->capacity = stu->capacity*2;
    free(stu->array);
    stu->array = arrays;
}

void push(students *stu){
    if (stu->size >= stu->capacity) {
        printf("容量已满，准备扩容！\n");
        add(stu);

    }
    char tmp_chars[16];
    printf("请输入学生姓名:");
    scanf("%s",tmp_chars);
    strncpy(stu->array[stu->size].uname, tmp_chars, 15);
    stu->array[stu->size].uname[15] = '\0'; // 确保字符串安全结束
    printf("请输入学生年龄:");
    scanf("%d",&stu->array[stu->size].age);
    // stu->array[stu->size].age = age;
    printf("请输入学生成绩:");
    scanf("%f",&stu->array[stu->size].grade);
    // stu->array[stu->size].grade = grade;
    
    stu->size += 1;
}

void show(students *stu){
    printf("===============学生信息================\n");
    for(int i =0; i<stu->size;i++){
        printf("姓名:%-10s 年龄:%-3d 成绩:%.1f\n",
        stu->array[i].uname,stu->array[i].age,stu->array[i].grade);
    }
    printf("===============\n");
}

void find(students *stu){
    char p[16];
    int num = -1;
    printf("请输入需要查找的姓名");
    scanf("%s",p);
    for(int i=0;i<stu->size;i++){
        if(0 ==strcmp(stu->array[i].uname,p)){
            num = i;
        }
    }
    if(num !=-1){
        printf("姓名:%-10s 年龄:%-3d 成绩:%.1f\n",
        stu->array[num].uname,stu->array[num].age,stu->array[num].grade);
    }
    else{
        printf("没有找到");
    }
}
int main(void){
    students *st = (students *)newStudents(1);

    // Student *stus = stu("tian",12,32);
    int status =1;

    // push(st,*stus);
    while (status)
    {
        int a;
        printf("1. 录入学生\n");
        printf("2. 显示所有学生\n");
        printf("3. 按姓名查找学生\n");
        printf("0. 退出系统\n");
        printf("请输入你的选择: ");
        scanf("%d", &a);
    
        switch (a)
        {
        case 1:
            /* code */
            push(st);
            break;
        case 2:
            show(st);
            break;
        case 3:
            find(st);
            break;
        case 0:
            status = 0;
            delStudent(st);
            st = NULL; 
            break;
        default:
            printf("没有该选项,请重新输入\n");
            break;
        }
    }
}
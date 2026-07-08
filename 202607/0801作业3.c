#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char uname[16];
    int age;
    float grade;
}Student;

typedef struct{
    int size;
    int capacity;
    Student *array;
}students;

students *newStudents(int capacity){
    students *stus = calloc(1,sizeof(students));
    stus->size =0;
    stus->capacity = capacity;
    stus->array = calloc(stus->capacity,sizeof(students));

    return stus;
}

void delStudent(s){
    for(int i)
}
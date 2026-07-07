#include <stdio.h>
struct Student{
    char uname[16];
    int age;
    float grade;
} Student;

int main(void){
    struct Student student = {"tian",12,53.1};
    printf("%s %d %lf\n",student.uname,student.age,student.grade);
}
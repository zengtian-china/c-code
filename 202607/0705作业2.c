#include <stdio.h>
typedef struct{
    char uname[16];
    int age;
    float grade;
}Student;



void show(Student *student,int size){
    for(int i=0;i<size;i++){
        printf("第%d个学生的姓名:%s ",i+1,student[i].uname);
        printf("第%d个学生的年龄:%d ",i+1,student[i].age);
        printf("第%d个学生的成绩:%.2f",i+1,student[i].grade);
        printf("\n");
    }

}
void quer(Student *student,int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(student[j].grade > student[j+1].grade){
                Student tmp = student[j];
                student[j] = student[j+1];
                student[j+1] = tmp;
            }
        }
    }
}
int main(void){
    Student student[5];
    for(int i =0; i<5;i++){
        printf("第%d个学生的姓名: ",i+1);
        scanf("%s",(student[i].uname));
        printf("第%d个学生的年龄:",i+1);
        scanf("%d",&(student[i].age));
        printf("第%d个学生的成绩:",i+1);
        scanf("%f",&(student[i].grade));
    }
    show(student,sizeof(student)/sizeof(Student));
    
    printf("===========排序之后==========\n");
    // quer(student,sizeof(student)/sizeof(Student));
    //show(student,sizeof(student)/sizeof(Student));
    int counti = 0;
    float max = 0.0f;
    for(int i =0;i<5;i++){
        if(max < student[i].grade){
            max = student[i].grade;
            counti = i;
        }
    }
    printf("第%d个.姓名:%s,年龄:%d,成绩:%.2f",counti+1, student[counti].uname,student[counti].age,student[counti].grade);
    printf("\n");

}
#include <stdio.h>

void print(int a){
    printf("[%d]\n",a);
}

void show(int a){
    printf("{%d}\n",a);
}

void info(int a){
    printf("<%d>\n",a);
}

typedef void (*def) (int);
int main(int argc, char *argv[]){
    int c = 0;
    scanf("%d",&c);
    def cc[] = {print,show,info};
    cc[c](32);

    return 0;
}
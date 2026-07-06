#include <stdio.h>
#include <string.h>

void show(char p[][10]){
    for(int i=0;i<4;i++){
        printf("%s\n",p[i]);
    }
}

int main(void){
    char str[] = "jack,ros,tom,jay";
    char names[4][10];
    char *p = strtok(str,",");
    int i =0;
    printf("%s\n",p);
    strcpy(names[0],p);
    while(1){
        i++;
        p = strtok(NULL,",");
        if(p ==NULL) break;
        printf("%s\n",p);
        strcpy(names[i],p);

    }
    show(names);


    return 0;
}
#include <stdio.h>
#include <string.h>
int chars(char *array,int size,char p){
    for (int i=0; i<size; i++){
        if (p == array[i]){
            return 0;
        }
    }
    return 1;
}
int main(int argc,char *argv[]) {
    char *arrs = argv[1];
    int len = strlen(arrs);
    char new_array[len+1];
    memset(new_array,0,sizeof(new_array));
    int j =0;
    for(int i =0;i<= strlen(arrs);i++){
        if(chars(new_array,sizeof(new_array),arrs[i])){
            new_array[j] = arrs[i];
            j++;
        }
        else{
            continue;
        }
    }
    new_array[j] = '\0';
    printf("%s\n",new_array);
}
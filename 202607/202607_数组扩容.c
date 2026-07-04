#include <stdio.h>
#include <stdlib.h>


int *list(int *array,int size,int number){
    int *list = malloc(sizeof(int) * (size+number));
    for(int i=0;i<size;i++){
        list[i] = array[i];
    }
    for(int j=size; j<size+number;j++){
        list[j] =0;
    }
    return list;

}

void show_array(int *array,int size){
    for(int i=0;i<size;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

int main(void){
    int arr[10] = {32,43,12,534,12,3,1,4,5,12};
    int * p =list(arr,sizeof(arr)/4,5);
    show_array(p, sizeof(arr)/sizeof(int)+5);
    return 0;
}
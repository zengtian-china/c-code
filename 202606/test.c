#include <stdio.h>
#include <stdlib.h>

void main(){

    int a[10] = {0};
    for( int i=0;i<10;i++){
        a[i] = random() %100;


    }

    for( int i =0;i<10;i++){
        printf("%d ",a[i]);

    }
    printf("\n");
}
#include <stdio.h>
void rhombus(int n){
    for(int i =0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            printf(" ");
        }
        for(int j =0; j<2*i+1;j++){
            printf("*");
        }
        printf("\n");
    }
    for(int i=0;i<n-1;i++){
                for(int j=0; j<i+1;j++){
            printf(" ");
        }
        for(int j=0;j<2*(n-1-i)-1;j++){
            printf("*");
        }
        printf("\n");
    }
    
}
int main(void){
    int n =5;
    rhombus(5);
}
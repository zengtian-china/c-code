#include <stdio.h>
#include <stdlib.h>
#include <time.h> // 1. 必须包含这个头文件
void array_init(int *p,int size){
    for(int i=0;i<size;i++){
        p[i] = random()%100;
    }
}

int Quicksort(int *p,int left,int right){
    int mid = p[left];
    while (left < right)
    {
        while (left <right && mid <= p[right])
        {
            right--;
        }
        p[left] =p[right];

        while (left <right && mid >= p[left])
        {
            left++;
        }
        p[right] = p[left];
        
        
    }
    p[left] =mid;
    return left;
    
}

void sourt(int *p,int left, int right){
    if (left < right){
        int mid = Quicksort(p,left,right);
        sourt(p,mid+1,right);
        sourt(p,left,mid-1);
    }

}
void show(int *p,int size){
    for(int i=0;i<size;i++){
        printf("%d ",p[i]);
    }
    printf("\n");
}

int main(void){
    int array[10] = {0};
    srandom((unsigned int)time(NULL)); // 用当前时间作为种子初始化 random()
    array_init(array,sizeof(array)/sizeof(int));
    show(array,sizeof(array)/sizeof(int));
    printf("排序过后\n");
    sourt(array,0,sizeof(array)/sizeof(int)-1);
    show(array,sizeof(array)/sizeof(int));
    return 0;
}
#include <stdio.h>

int quer(int data[],int left, int right){
    int tmp = data[left];
    
    while (left < right)
    {
        while (left < right && data[right] >= tmp)
        {
            right -= 1;
        }
        data[left] = data[right];

        while (left < right && data[left] <=tmp)
        {
            left +=1;
        }
        data[right] = data[left];
    }
    data[left] = tmp;
    return left;

}


void paixu(int data[],int left, int right){
    if (left < right){
        int mid = quer(data,left,right);
        paixu(data,mid+1,right);
        paixu(data,left,mid-1);
    }
}


int main(){
    int number[12] = {42,53,123,75,-34,4,88,2,4,76,32,77};
    for (int i=0;i<12;i++){
        printf("%d\t",number[i]);
    }
    printf("\n");
    printf("=============\n");
    paixu(number,0,12);

        for (int i=0;i<12;i++){
        printf("%d\t",number[i]);
    }
    printf("\n");
    return 0;

}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
void four(){
     int  a[2][3] = {1,2,3,4,5,6};
     int *p1 = (int*)a;  //a[0][0]地址
     int *p2 = (int*)(a+1); //a[1][0]
     int *p3 = (int*)(&a[0] + 1); //a[1][0]
     int *p4 = (int*)((uintptr_t)a+1); // ox 02 00 00 00 
     printf("%x,%x,%x,%x\n", *p1, *p2, *p3, *p4);
}

void two(){
     int a[5] = {10,20,30,40,50};
     int *p = (int*)(a + 1);  // 20地址
     int *q = (int*)(&a + 1); // a地址的下一个地址

     printf("%d\n", a[1]);  // 20
     printf("%d\n", p[1]);  //30
     printf("%d\n", q[-1]); //50
}


void one(){
         /*
     20 int 的堆空间，存入 10-50间的随机数并且输出，之后再对数组进行升序排序后输出
    */
     srand((unsigned int)time(NULL));
     // int r = rand();
   int *p = malloc(20 * 4);
   for(int i =0; i<20;i++){
     int min = 10;
     int max = 50;
     p[i]= rand() % (max - min + 1) + min;
     printf("%d ",p[i]);
   }
   printf("\n===========\n");
//    排序，升序排序

   for(int i=0; i<19;i++){

     for (int j= 1;j<20-i;j++){

          if( p[j-1] > p[j]){
               int tmp = p[j-1];
               p[j-1] = p[j];
               p[j] = tmp;
          }
     }
   }
   for(int i=0; i<20; i++){
     printf("%d ",p[i]);
   }
   printf("\n");
}

void five(){
     /*
     5.用数组指针完成下面输出：
     int b[6]={3,6,9,12,15,18};
     1. 定义数组指针 pb 指向 b   int (*pb)[6]  = &b;
     2. 用 pb 输出：b[2]=9 和 b[5]=18      pb[0][2], pb[0][5];*/
      int b[6]={3,6,9,12,15,18};
      int (*pd)[6] = &b;
      printf("b[2]= %d \n",*(*pd+2));
      printf("b[5]= %d \n",*(*pd+5));
     //  printf("pd[0][2]= %d \n",*([2]);
      printf("pd[0][5]= %d \n",*pd[5]);


}

int main(){
one();
two();
four();
five();

}
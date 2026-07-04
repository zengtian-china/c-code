#include <stdio.h>
#include "100demo.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>
// void main1(void)
// {
//     unsigned char a, b, c;
//     a = 0x3;    //0000 0011
//     b = a|0x8;  //0000 1000
//     c = b<<1;

//     printf("%d%d\n", b, c);  //11   0001 0110 16+4+2



//     printf("\n");

//     unsigned int data=0x12ff0045;  // 0001 0010 1111 1111 0000 0000 0100 0101
//     unsigned int data1 = 0x6f6000; // 0000 0000 0110 1111 0110 0000 0000 0000                //  11          11
//     unsigned int as = data ^ data1;
//     printf("%x \n",as);
// }
// void main2(){
//     char a;
//     a ='5';
//     switch (a)
//     {
//     case '2':
//         /* code */
//         printf("output %c is 2 \n",a);
//         break;
//       case '3':
//         /* code */
//         printf("output %c  is 3 \n",a);
//         break;
//     default:
//         printf("output is end \n");
//         break;
//     }
// }
// void main3(){
//     int retn;
//     retn = 0;
//     int a;
//     scanf("%d",&a);
//     if (a %2 == 0){
//         printf("输入源为偶数，不符合预期，error \n");
//         retn =1;
//         goto end;
//     } else{
//         retn = 0;
//         goto end;
//     }

//     end:
//         if (1 == retn){

//             printf("this is end ERROR \n");
//             printf("this 45 have Error \n");
//         }
//         else{
//             printf("正常终了 \n");
//         }
// }

// void fetch(int * a){
//     for (int j = 0; j<10;j++){
//         printf("第%d元素 = %d \n",j,a[j]);
//     }
// }

// void three_one(){
//     /*
//     假设有如下数组定义，按照上述对数组整体赋值的思路，分别用初始化、循环和memcpy函数三种办法，将数组整体赋值为 1~10 是个自然数。

//         int fill_me_with_numbers[10];
//     */

//     // 初始化
//     int one[10] = {1,2,3,4,5,6,7,8,9,10};
//     int two[10];
//     int three[10];
//     //循环
//     for (int i = 0; i< 10;i++){
//         two[i] = i+1;
//     }

//     // memcpy
//     memcpy(three,one,sizeof(int) * 10);

//     int j = 1;
//     while (j == 1)
//     {
        
//         int find;
//          scanf("%d",&find);
//         if ( find == 1){
//             fetch(one);
//         }
//         else if (find == 2) {
//             fetch(two);
//         }
//         else if (find == 3 ){
//             fetch(three);
//         }
//         else{
//             break;
//         }
//     }
    
// }
// void one_1(){
//     /*
//     定义一个整形数组存储50个学生C语言成绩， 
//     （用随机数初始化），输入所有成绩（高到低排名输出），
//      查找班级里面有没有学生的成绩是77
//     */
//    int students[50] = {};
//    for (int i=0;i<50;i++){
//         // students[i] = random() % 100;

//    }
   
// }


void qer_1(){
    int a [2][3] = {1,2,3,4,5,6};
    for (int i =0;i<2;i++) {
        for(int j =0;j<3;j++) {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
void qer_2(){
    int datas[3][3] = {32,43,23,654,32,32,54,34,23};
    int number = 0;
    for (int i =0; i<3;i++){
        for(int j=0;j<3;j++){
            number += datas[i][j];
            
        }

    }
    printf("3×3 数组的平均值 = %d\n",number/9);
}
void qer_3(){
      int datas[3][4] = {32,43,23,654,32,32,54,34,23,43,65,123};
      int lnumber[4] ={};
      int hnumber[3] ={};
      for(int i = 0;i<3;i++){
        int number=0;
        for(int j =0; j<4;j++){
            number +=datas[i][j];
        }

        hnumber[i]= number;
        printf("第%d行的和 = %d\n",i+1,hnumber[i]);
      }

    for(int i = 0;i<4;i++){
        int number=0;
        for(int j =0; j<3;j++){
            number +=datas[j][i];
        }
        lnumber[i]= number;
        printf("第%d列的和 = %d\n",i+1,lnumber[i]);
      }


      
}

void qer_4(){
    //求 n×n 数组中最大值及其位置
            int datas[4][4] = {32,43,23,654,32,32,54,34,1231,43,65,131,434,23,565,52};
    int max = datas[0][0];
    int wz [2] = {0,0};

    for (int i =0;i<(int)sqrt(sizeof(datas)/sizeof(int));i++){
    for (int j =0;j<(int)sqrt(sizeof(datas)/sizeof(int));j++){
        if(datas[i][j] > max){
            wz[0] = i;
            wz[1] = j;
            max = datas[i][j];
        }
    }
    }
    printf(" 最大值为%d\t 第%d行第%d列\n",max,wz[0],wz[1]);
}

void qer_5(){
    int datas[4][4] = {32,43,23,654,32,32,54,34,23,43,65,123,434,23,565,52};
    for (int i =0;i<(int)sqrt(sizeof(datas)/sizeof(int));i++){
    for (int j =0;j<(int)sqrt(sizeof(datas)/sizeof(int));j++){
        printf("%d\t",datas[i][j]);
    }
    printf("\n");
    }
    printf("================================\n");
    for (int i =0;i<(int)sqrt(sizeof(datas)/sizeof(int));i++){
    for (int j =i;j<(int)sqrt(sizeof(datas)/sizeof(int));j++){
        int tmp = datas[i][j];
        datas[i][j] = datas[j][i];
        datas[j][i] = tmp;
    }
    }

    for (int i =0;i<(int)sqrt(sizeof(datas)/sizeof(int));i++){
    for (int j =0;j<(int)sqrt(sizeof(datas)/sizeof(int));j++){
        printf("%d\t",datas[i][j]);
    }
        printf("\n");
    }
        printf("================================\n");
}

    void qer_6(){
            int datas[4][4] = {32,43,23,654,32,32,54,34,1231,43,65,131,434,23,565,52};

            for (int i =0;i<4;i++){
                for(int j = 0; j<4;j++){
                    for (int x =0; x<4-1-j;x++){
                        if( datas[i][x] > datas[i][x+1]){
                            int tmp = datas[i][x];
                            datas[i][x] = datas[i][x+1];
                            datas[i][x+1] = tmp;
                    }
                    }

                }
            }

            for (int i =0;i<4;i++){
    for (int j =0;j<4;j++){
        printf("%d\t",datas[i][j]);
    }
        printf("\n");
    }
        printf("================================\n");
    }

void qer(){
    //1. 定义 2 行 3 列数组，赋值后按行列输出
    qer_1();
    //2.求 3×3 数组的平均值
    qer_2();
    //3.求二维数组每一行的和，求二维数组每一列的和
    qer_3();
    //求 n×n 数组中最大值及其位置
    qer_4();

    //求 n×n 数组行列互换
    qer_5();

    //6. 定义一个二维数组， 对每行进行升序排序（选做）--冒泡排序
    qer_6();

}


int main(){
    qer();
    // main1();
    // one_1();
//    demo01();
    // three_one();
    // printf("hello world\n");
    return 0;
}   




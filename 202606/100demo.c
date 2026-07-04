#include <stdio.h>

void demo01(){
    //题目：有 1、2、3、4 四个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
    for(int i = 1; i<5;i++){
        for ( int j =1; j<5;j++){
            for ( int x=1; x<5;x++){
                if( x !=j && x != i && j != i){
                    printf("%d-%d-%d \n",i,j,x);
                }
            }
        }
    }
}

// do
// {
//     /* code */
// } while (condition);

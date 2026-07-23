// /*
//  * @Author: zengtian
//  * @Date: 2026-07-13 10:28:32
//  * @LastEditors: zengtian
//  * @LastEditTime: 2026-07-13 10:43:50
//  * @Description: File Description
//  * @FilePath: \202607\1301.c
//  * @@file: 
//  */
// #include <stdio.h>
// #include<stdlib.h>
// #include<string.h>
// int * quer(int *array,int num,int size){

//  int *new_array = malloc(sizeof(int) *(size+1));
//  memset(new_array,0,size+1);
//  if (new_array == NULL) return 0;
//  int tmp = size;
//  for(int i =0;i<size;i++) new_array[i]=array[i];
//  for(int i=0; i<size;i++){
//  if((new_array[i]>=num)){
//   tmp = i;
//   printf("i =%d \n",i);
//   break;
// } }
// for(int i=size;i>tmp;i--){new_array[i] = new_array[i-1];
// printf("new_array =%d ",new_array[i]);}
// new_array[tmp] = num;
// return new_array;}
// int main(void) {
// int array[10] = {2,6,9,13,15,17,18,20};
// int *new_array = quer(array,16,sizeof(array)/sizeof(int));
// for(int i=0;i<sizeof(array)/sizeof(int)+1;i++){
//     printf("%d ",new_array[i]);
// }
// }
#include<string.h>
#include<stdio.h>
//杨辉三角 int 
//  a[n][n]
//   a[n-1][j-1][j-2]

  int aa(int x,int j){
    if(j ==0 || j ==x -1){
         return 1;
    }
    return aa(x-1,j)+ aa(x-1,j-1);
  }
int main(){

 int n =10;
  for(int i=1;i<=n;i++){
    for (int j =0; j<i;j++){
 printf("%d ",aa(i,j));

    }
    printf("\n");
  }
//  char x[] ="12345";
//  char y[] = {'1','2','3','4','5'};
//  printf("%d %d",strlen(x),strlen(y));
}
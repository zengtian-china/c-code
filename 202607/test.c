// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>




// void mainWindow(){
//     printf("***************************\n");
//     printf("\n");
//     printf("          1.登录\n");
//     printf("          2.注册\n");
//     printf("\n");
//     printf("***************************\n");
// }

// int getInt(){
//  // 10 ~50
//     return random()%41+10;
// }
// void insert_data(int *data,int size){
//     for(int i =0; i<size;i++){
//         data[i] = getInt();
//     }
// }
// void show_data(int number){
//     printf("%d ",number);
// }

// void main(int arg,char *arg1[]){

//     // mainWindow();
//     // printf("%d参数个数 \n",arg);
//     // for (int i =0;i< arg;i++){
//     //     printf("第%d个参数的值为%s \n",i,arg1[i]);
//     // }

  
//     if (0 == strcmp(arg1[1],"1")){
//           int a[10];
//           insert_data(a,sizeof(a)/sizeof(int));
//           for( int i=0;i<10;i++){
//             show_data(a[i]);
//           }
//           printf("\n");

//     }else{
//         char a[10];
//         for(int i =0; i< 10;i++){
//             a[i] = 'A'+getInt();
//         }
//         for (int i = 0; i < 10; i++)
//         {
//             printf("%c ",a[i]);
//         }
//         printf("\n");
//     }

// }


int main(void){
    int arr[10] = {0};
    int *p = arr;
    // &arr[3]  arr+3
    // *(p+1) == p[1] ==arr[1]
 // p == arr 
}
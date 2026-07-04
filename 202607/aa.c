 #include <stdio.h>


// int func( int n){
//     if (1 == n)
//     return 1;
//     return n+ func(n-1);
// }


// void func1(){
//      int arr[2][3] = {{1,2,3}, {4,5,6}};
//      int (*p)[2][3] =  &arr;
//      for (int i=0;i<2;i++){
//         for (int j =0;j<3;j++){
//             printf("%d ",(*p)[i][j]);
//             // (*p)[j]) (*p+1)[j]
//         }
//      }
//      printf("\n");
// }

// void func2(){
//     int num[3]={9,8,7};
//     int (*p)[3] = &num;

//     for(int i=0;i<3;i++){
//         printf("(*p)[%d] ==%d ",i,(*p)[i]);
//         printf(" ===");
//         printf("(p[0][%d]) ==%d \n",i,p[0][i]);
//     }

// }

// int main(){

//     // int number = func(10001);
//     // printf("%d \n",number);
//     func1();
//     func2();

//     return 0;
// }

// float product( float number1,float number2){
//     return number1 * number2;
// }
// void main(){
//     float sum;
//     sum = product(23.1,32.2);
//     printf("%lf \n",sum);
// }

// float get_avg(int* array,int size){
//     int sum = 0;
//     for(int i=0;i<size;i++){
//         sum += array[i];
//     }
    
//     return sum / size;
// }
// void main(){
//     int  array[10] = {32,43,645,123,32,545,23,54,23,54};
//     float avg = get_avg(array,sizeof(array)/sizeof(int));
//     printf("%lf \t",avg);
// }


// void printInfo(char name[],int age){
//     printf("姓名: %s, 年龄: %d\n",name,age);
// }
// void main(){
//     printInfo("zengtian",18);
// }


//4.设计一个函数接收一个正整数n，递归输出n的每一位数字（如输入123，输出1 2 3）  (选做)

// void func1(int n){
//     if (0 ==n){
//         return ;
//     }
//     int next_number = n /10;
    
//     func1(next_number);
//     printf("%d ",n %10);
// }

// void main(){
//     func1(123);
//     printf("\n");
// }

// void main(int argc, char * argv[]){
// //     if (argc <3){
// //         printf("缺失必要的参数\n");
// //         return ;
// //     }
// //     printf("%s%s\n",argv[1],argv[2]);
// // }
    
// }

float get_avg(int * array,int size){
    int sum = 0;
    for(int i=0;i<size;i++){
        sum += array[i];
    }
    
    return (float)sum / size;
}
void main(){
    int  array[12] = {32,43,645,123,32,545,23,54,23,54,32,41};
    float avg = get_avg(array,sizeof(array)/sizeof(int));
    printf("%lf \n",avg);
}
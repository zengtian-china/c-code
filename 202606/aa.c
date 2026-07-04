#include <stdio.h>
#include <string.h>
#include <stdint.h> // 必须包含这个头文件

// 将 unsigned long 替换为 uintptr_t

int main(){


    // for(int i =12345; i<=98765;i++){

    //     for (int j = 12345; j<=98765;j++){


    //         int a = i/10000;
    //         int b = (i-a * 10000) /1000;
    //         int c = (i -a *10000 - b *1000) /100;
    //         int d = (i -a *10000 - b *1000 - c *100)/10;
    //         int e = (i -a *10000 - b *1000 - c *100 - d * 10);
    //         if((i * 4 == j) && (a !=b && )){

    //         }
    //     }
    // }


    int a[2][2] = {1,2,3,4};
    int *p1 = (int*)(a+1); 
    int *p2 = (int *)((uintptr_t)a + 1); 
    
    printf("%x %x", *p1,*p2);
}
//         8     4 3 1
// a[4][4]={{1,4,3,2},{8,6,5,7},{3,7,2,5},{4,8,6,1}};
// Int i,j,k,t; 


//  for(i=0;i<4;i++)    
// 	for(j=0;j<3;j++) 
//        for(k=j+1;k<4;k++)	     
//          if(a[j][i]>a[k][i]) 

// 	    { t=a[j][i]; a[j][i]=a[k][i]; a[k][i]=t; } 
//          for(i=0;i<4;i++)  printf("%d,",a[i][i]);   } 

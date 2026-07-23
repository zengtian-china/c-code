/*
 * @Author: zengtian
 * @Date: 2026-07-04 15:43:30
 * @LastEditors: zengtian
 * @LastEditTime: 2026-07-14 14:17:25
 * @Description: File Description
 * @FilePath: \202607\test1.c
 * @@file: 
 */
#include <stdio.h>

void modifyValueViaPointer(int *ptr) {
    printf("函数内 - ptr 的地址 (指针自身): %p\n", (void*)&ptr);
    printf("函数内 - *ptr 的地址 (指向的目标): %p\n", (void*)ptr);
    *ptr = 200; // 通过指针修改原始数据
}

int main() {
    int arg = 20;
    printf("main() 中 - arg 的地址: %p\n", (void*)&arg);
    printf("调用前 - arg 的值: %d\n", arg);

    modifyValueViaPointer(&arg); // 传递 arg 的内存地址

    printf("调用后 - arg 的值: %d\n", arg);
    return 0;
}
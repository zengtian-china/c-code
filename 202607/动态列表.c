
#include <stdlib.h>
#include <assert.h>
//列表类
typedef struct 
{
    int *array; //数组，存放列表元素
    int capacity; //列表容量
    int size; //列表大小
    int extendRatio; //列表每次扩容的倍数

    /* data */
} list;

list *mylist(){
    list *nums = malloc(sizeof(list));
    nums->capacity = 10;
    nums->array = calloc(nums->capacity,sizeof(int));
    nums->size =0;
    nums->extendRatio =2;
    return nums;

}

void delList(list *nums){
    free(nums->array);
    free(nums);
}

int size(list *nums){
    return nums->size;
}
//获取列表容量
int capacity(list *nums){
    return nums->capacity;
}

//访问元素
int get(list *nums,int index){
    //断言
    assert(index >=0 && index < nums->size);
    return nums->array[index];
}

//更新元素
void set(list *nums,int index, int number){
    assert(index >= 0 && index < nums->size);
    nums->array[index] = number;
}

//在尾部添加函数
void add(list *nums,int number){
    if( size(nums) == capacity(nums)){
        extendCapacity(nums);
    }
    nums->array[size(nums)] = number;
    nums->size +=1;
}



//在中间插入元素

void insert(list *nums,int index,int number){
    assert(index >= 0 && index < size(nums));
    if(size(nums)+1 > capacity(nums)){
        extendCapacity(nums);
    }
    for(int i= size(nums);i>index;i--){
        nums->array[i] = nums->array[i-1];
    }
    nums->array[index] = number;
    nums->size += 1;
}


int removeItem(list *nums,int index){
    assert(index >=0 && index <size(nums));
    int num = nums ->array[index];
    for(int i=index;i<size(nums)-1;i++){
        nums->array[i] = nums->array[i+1];
    }
    nums->size--;
    return num;
}


void extendCapacity(list *nums){

    int nuewCapacity = capacity(nums) * nums->extendRatio;
    int *extend = calloc(nuewCapacity,sizeof(int));

    for(int i=0; i<size(nums);i++){
        extend[i]= nums->array[i];
    }
    nums->array = extend;
    nums->capacity = nuewCapacity;
    ree(nums->array);
}
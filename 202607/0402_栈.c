#include <stdio.h>
#include <stdlib.h>

typedef struct lianbiao
{
    int value;
    struct lianbiao *next;
} ListNote;


ListNote * ListNote_init(int number){
    ListNote * list;
    list = calloc(1,sizeof(ListNote));

    list->value = number;
    list->next = NULL;
    return list;
}

int main(void){
    ListNote * list1 = ListNote_init(10);
    ListNote * list2 = ListNote_init(50);
    ListNote * list3 = ListNote_init(60);
    list1->next = list2;
    list2->next = list3;
    printf("%d %d %d\n",list1->value, (list1->next)->value,((list1->next)->next)->value);

}
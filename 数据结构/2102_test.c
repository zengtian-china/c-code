#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"


int main(){
    // cJSON *root = cJSON_CreateObject();

    // cJSON_AddStringToObject(root,"name","zengtian");
    // cJSON_AddNumberToObject(root,"age",42);
    // cJSON *ages = cJSON_CreateArray();
    // // cJSON_AddItemToArray(ages,"array","13");
    // cJSON_AddItemToArray(ages,cJSON_CreateNumber(13));
    // cJSON_AddItemToArray(ages,cJSON_CreateNumber(120));
    // cJSON_AddItemToArray(ages,cJSON_CreateNumber(43));
    // cJSON_AddItemToArray(ages,cJSON_CreateString("hello world"));
    // cJSON *array2 = cJSON_CreateArray();
    // cJSON_AddItemToArray(array2,cJSON_CreateNumber(132));
    // cJSON_AddItemToArray(array2,cJSON_CreateString("金创药"));
    // cJSON_AddItemToArray(ages,array2);
    // cJSON_AddItemToObject(root,"ages",ages);

    // cJSON *information = cJSON_CreateObject();
    // cJSON_AddArrayToObject(information,"tian");
    // char *str = cJSON_Print(root);
    // printf("json\n%s",str);

      const char *json_str = "{\"skills\":[\"剑法\",\"心法\",\"轻功\"],\"duixiang\":{\"name\":\"tian\",\"age\":32}}";
      cJSON *root = cJSON_Parse(json_str);

    //   char *arr[]
    cJSON *skills = cJSON_GetObjectItem(root,"skills");

    int size = cJSON_GetArraySize(skills);
    for(int i =0;i<size;i++){
        cJSON *ss = cJSON_GetArrayItem(skills,i);
        printf("\n数组的内容是%s",ss->valuestring);
        printf("\nget获取%s",cJSON_GetStringValue(ss));
    }

    //获取对象
    cJSON *objecks = cJSON_GetObjectItem(root,"duixiang");
    cJSON *name = cJSON_GetObjectItem(objecks,"name");
    printf("\nmy name is %s\n",name->valuestring);
    cJSON *age = cJSON_GetObjectItem(objecks,"age");
    printf("my age is %d",(int)cJSON_GetNumberValue(age));
}
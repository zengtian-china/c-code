#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE  100
typedef struct 
{
  int index;
  char *str;  
} pair;

/* 基于数组实现的哈希表 */
typedef struct {
    pair *buckets[MAX_SIZE];
} ArrayHashMap;


ArrayHashMap * newArrayHashMap(){
    ArrayHashMap *map = malloc(sizeof(ArrayHashMap));
    for(int i=0; i<MAX_SIZE;i++){
        map->buckets[i] = NULL;
    }
}

//析构函数
void delArrayHashMap(ArrayHashMap *hmap){
    for(int i=0;i<MAX_SIZE;i++){
        if(hmap->buckets[i] !=NULL){
            free(hmap->buckets[i]->str);
            free(hmap->buckets[i]);
        }
    }
    free(hmap);
}


int hashFunc(int key){
    return key%MAX_SIZE;
}


void put(ArrayHashMap *hmap, const int key, const char *val){
    pair *pa = calloc(1,sizeof(pair));
    pa->index = key;
    pa->str = malloc(strlen(val)+1);
    strcpy(pa->str,val);

    int index = hashFunc(key);
    hmap->buckets[index] = pa;
}


void removeTtem(ArrayHashMap *hmap,const int key){
    int index = hashFunc(key);
    free(hmap->buckets[index]->str);
    free(hmap->buckets[index]);
    hmap->buckets[index] = NULL;
}


typedef struct 
{
    /* data */
    pair *set;
    int len;
}MapSet;


void pairSet(ArrayHashMap *hmap,MapSet *set){

    pair *entries;
    int i =0, index = 0;
    int total =0;

    for(i=0;i<MAX_SIZE;i++){
        if(hmap->buckets[i] !=NULL){
            total+=1;
        }
    }
    entries = malloc(sizeof(pair) *total);
    memset(entries,0,sizeof(pair) *total);
    for(i=0;i<MAX_SIZE;i++){
        if(hmap->buckets[i] !=NULL){
            entries[index].index = hmap->buckets[i]->index;
            entries[index].str = malloc(strlen(hmap->buckets[i]->str)+1);
            strcpy(entries[index].str,hmap->buckets[i]->str);
            index++;
            
        }
        set->set = entries;
        set->len = total;
    }
}

void valueSet(ArrayHashMap *hmap,MapSet *set){
    char **vals;
    int i=0, index =0;
    int total =0;
    for(i=0;i<MAX_SIZE;i++){
        if(hmap->buckets[i] !=NULL){
            total++;
        }
    }
    vals = malloc(total * sizeof(char *));
    for(i =0;i<MAX_SIZE;i++){
        if(hmap->buckets[i] !=NULL){
            vals[index] = hmap->buckets[i]->str;
            index++;
        }
    }
    set->set = vals;
    set->len = total;
}
/* 打印哈希表 */
void print(ArrayHashMap *hmap) {
    int i;
    MapSet set;
    pairSet(hmap, &set);
    pair *entries = (pair *)set.set;
    for (i = 0; i < set.len; i++) {
        printf("%d -> %s\n", entries[i].index, entries[i].str);
    }
    free(set.set);
}


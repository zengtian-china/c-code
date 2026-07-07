#include <stdio.h>
#include <string.h>

int main(void){
    char arr[] = "google";
    char *start = arr;
    char *end = arr;
    while (*end !='\0')
    {
        start = arr;
        while (start != end)
        {
            if(*start == *end){
                char *t = end;
                int j=0;
                while (t[j] !='\0')
                {
                    t[j] = t[j+1];
                    j++;
                }
                end--;
            }
            if( start == end) break;
            start++;
        }
        end++;
        printf("%s\n",arr);
        
    }


}
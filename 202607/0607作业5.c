// #include <stdio.h>
// #include <string.h>
// int main(void){
//     char a[100] = "http://www.yueqian.com";
//     strtok(a,"com");
//     strcat(a,"org");
//     printf("%s\n",a);
//     char a2[100] = "http://www.xxx.com"; // yueqian

//     strtok(a2,"xxx");
//     strcat(a2,"yueqian.com");
//     printf("%s\n",a2);
#include <string.h>
#include <stdio.h>

// }
int main(){
    char aa[] = "hello world";
    char bb[] = "人生苦短，我学python";
    char * p = strstr(aa,"wo");
    printf("%s\n",aa);
    printf("%s\n",p);

    strcpy(p,bb);
    printf("%s\n",aa);
// char *p1 = strstr(a,"xxx");
// char *p2 = strstr(p1, ".");
// char buffer[32]={0};
// strcpy(buffer, p2);
// strcpy(p1, "yueqian");
// strcat(a, buffer);
    
}
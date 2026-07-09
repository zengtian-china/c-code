#include<stdio.h>

//#define SELECT

int main()
{

#ifdef SELECT
	int a = 100;
	int b = 300;
	int c = 500;
	printf("SELECT\n");
	printf("a:%d b:%d c:%d\n",a,b,c);
	
#else
	int a = 1000;
	int b = 3000;
	int c = 5000;
	printf("SELECT\n");
	printf("a:%d b:%d c:%d\n",a,b,c);
	
#endif
	
	return 0;
}
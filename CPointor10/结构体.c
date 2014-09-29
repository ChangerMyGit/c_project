#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
//struct B;
//struct A {
//    struct B *b;
//};
//struct B {
//	struct A *a;
//};
struct ali{
	int a;
	char b;
	char c;
} a;

struct bli{
	char b;
	int a;
	char c;
	struct bli *x;
} b;
// 不完整声明
struct B; 
struct A{
   struct B * pa;
};
struct B{
   int a;
   int b;
};
union fl {
	int a;
	float b;
} ;
char * strdup(char const * string);
void print();
char * strup(char const * string);
void main(){
	//union fl x1 ;
	//x1.b = 12.3;
	//x1.a = 10;
	//int x =1;
	//char *s = (char *)malloc(10 * sizeof(char));
	//for(x=0;x<10;x++)
	//  s[x] = x + '0';//指针也可以使用数组方式
	//char * new_string = strup("changer");
	//free(new_string);
	//printf("%s \n",new_string);
	//printf("%s \n",s);
	//free(s);
	//printf("%d %d \n",sizeof(struct ali),sizeof(struct bli));
	//printf("%f %d \n",x1.b,x1.a);
	//print();
	NULL;
	int * ip;
	int i = 26;
	const int limit = 100;
	const int * limitp = &limit;
	limitp = &i;
	// -1 被转换为无符号数
	if( -1 < (unsigned int)1)
		printf("123");
}

char * strdup(char const * string){
    char * new_string;
	new_string = (char *)malloc(strlen(string)+1);
	if(new_string != NULL)
	  strcpy(new_string,string);
	return new_string;
}

void print(){
   int c,length = 0;
   char *str = (char*)malloc(100*sizeof(char));
   while((c = getchar())!=EOF && c!='\n'){
        str[length++] = c;
   }
   str[length] = '\0';
   printf("%s\n",str);
}

char * strup(char const * string){
    char * new_string;
	new_string = (char *)malloc(strlen(string)+1);
	if(new_string!=NULL)
	  strcpy(new_string,string);
	return new_string;
}
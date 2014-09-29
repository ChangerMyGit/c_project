#include <stdio.h>
#include <stdlib.h>
void getint(int *p);//
void strcpy(char *s,char *t);
int strcmp(char *s,char *t);
void strcat(char *s,char *t);
int strend(char *s,char *t);
int strlen(char *s);
void reverse(char *s);
void functionpointor(void (*)(char *),char *);
int strfunction(int (*)(char *),char *);
main(){
	//int i = 10;
	//getint(&i);
	//printf("%d\n",i);
	//int a[10] = {1,2,3,4,5,6,7,8,9,10};
	//int *p = a;
	//printf("%d\n",*(p + 2));
	//printf("%x\n",p);
	//getchar();
	//char s[] = "123456456 ";
	//char t[] = "3456";
	//strcpy(s,t);
	//printf("%s\n",s);
	//printf("%d\n",strcmp(s,t));
	//strcat(s,t);
	//printf("%s\n",s);
	//printf("%d\n",strend(s,t));
	//printf("%d\n",strlen(t));
	//reverse(t);
	//printf("%s\n",t);
	// 如对全部元素赋初值，则第一维的长度可以不给出。
	//int a[][3]={1,2,3,4,5,6,7,8,9};
    //char *r[20];
	//r[1] = "changer";
	//r[2] = "hello";
    //char (*r1)[20];
	//void (*getint)[10];
	//int (*(*com)())[10];
	//int (*comp)();
	//char *strs[] = {"123","456"};
	//char aname[][15] = {"changer","ok"};
	//int (*com)();
	//int (*f[15])();
	char t[] = "3456";
	functionpointor(reverse,t);
	printf("%s\n",t);
	printf("%d\n",strfunction(strlen,t));
}

void getint(int *p){
   *p = *p + 10;
}

void strcpy(char *s,char *t){
    while(*s++ = *t++)
		;
}

int strcmp(char *s,char *t){
    for(;*s == *t;s++,t++)
		if(*s == '\0')
		  return 0;
	return *s - *t;
}

void strcat(char *s,char *t){
   while(*s!='\0')
	   s++;
   strcpy(s,t);
}

int strend(char *s,char *t){
   // 记住开头的指针
   char *bs = s; 
   char *bt = t; 
   // 遍历到指针结束
   for(;*s;s++)
	   ;
   for(;*t;t++)
	   ;
   for(;*s == *t;s--,t--)
	   if(t == bt || s == bs)
		   break;
   if(*s == *t && t == bt && *s!='\0')
	   return 1;
   return 0;
}

int strlen(char *s){
   int i = 0;
   while(*s++)
	   i++;
   return i;
}

void reverse(char *s){
  int c;
  char *t;
  for(t = s + strlen(s) -1;t>s;s++,t--){
     c = *s;
	 *s = *t;
	 *t = c;
  }
}

// 函数指针参数
void functionpointor(void (*resp)(char *),char *s){
	(*resp)(s);
}

// 函数指针参数
int strfunction(int (*str)(char * ),char *s){
	return (*str)(s);
}
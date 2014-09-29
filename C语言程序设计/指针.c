#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
// 字符串比较
int my_strcmp(char *s , char *t);
// 字符串复制尾部
void my_strcat(char *s, char *t);
// 是否出现在尾部
int my_strend(char *s , char *t);
// 获取输入函数
int getLine(char line[]);
// 输出
void writeLines(char *lines[] , int nlines);
void qsort(char *v[],int left , int right);
void mainz(){
    //int ints[10];
    //int *ip = &ints[2];
    //printf("%d\n",ip -  ints);
    //printf("%d\n",my_strcmp("changer","xx"));
	//char s[20] = "hello worldx";
	//char t[20] = "world";
	//my_strcat(s,t);
	//printf("%s\n",s);
	//printf("%d\n",my_strend(s,t));
	// 自定义声明
	typedef int (*PF)(char []); 
	char strings[][12] = {"xxxx","yyy"};
	int len , nlines =0;
	char *lines[100];
	char line[100];
	char *p;
	// 函数指针
	//int (*getP)(char []) = getLine;
	PF getP = getLine;
	while((len = getP(line))>0){
	    p = (char *)malloc(len * sizeof(char));
		strcpy(p,line);
		lines[nlines++] = p;
	}	 
	qsort(lines,0,nlines-1);
	writeLines(lines,nlines);
}

int my_strcmp(char *s , char *t){
   for(;*s == *t ;s++,t++)
	 if(*s == '\0')
	   return 0;
   return *s - *t;
}

void my_strcat(char *s, char *t){
   for(;*s!='\0';s++)
	   ;
   while(*s++ = *t++)
	   ;
}

int my_strend(char *s , char *t){
    int ls = strlen(s);
	int lt = strlen(t);
	if(ls<lt) return 0;
	else {
	   s = s + (ls - lt);
	   while(*s++ == *t++  && *s!= '\0' && *t !='\0')
		   ;
	   if(*s == '\0' && *t == '\0')
		   return 1;
	}
	return 0;
}

int getLine(char line[]){
	int c , i=0;
	while((c = getchar())!=EOF && c!='\n')
		line[i++] = c;
	line[i] = '\0';
	return i;
}

void writeLines(char *lines[] , int nlines){
   int n;
   for(n=0;n<nlines;n++)
	   printf("%s\n",lines[n]);
}

void qsort(char *v[],int left , int right){
   int i , last;
   void swap(char *v[],int i,int j);
   if(left >= right) return;
   swap(v,left,(left + right)/2);
   last = left;
   for(i = left+1;i<=right;i++)
	   if(strcmp(v[i],v[left]) <0)
		   swap(v,++last,i);
   swap(v,left,last);
   qsort(v,left,last-1);
   qsort(v,last+1,right-1);
}

void swap(char *v[],int i,int j){
   char *temp;
   temp = v[i];
   v[i] = v[j];
   v[j] = temp;
}
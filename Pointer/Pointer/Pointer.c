#include <stdio.h>
#include <ctype.h>
void swap(int *,int *);
void getFloat(double *);
int strlen(char *); // 字符串长度
void strcpy(char *,char *);
void strcpy2(char *s,char *t , int n); // 复制前几位
void strtest(char *);
int strcom(char *, char *); // 字符串比较
void strcat(char *,char *); // 字符串复制
int strend(char *,char *);// 是否出现在字符串的尾部
/**
  int *p 代表整形类型的指针 
  *p 从指针取值
  & 去一个对象的地址
**/
int main(int argc,char *argv[]){
	//int x = 10;
	//int y = 20;
	//swap(&x,&y);
	//printf("x = %d , y = %d" ,x,y);
	//double df = 0.0;
	//getFloat(&df);
	//printf("%d\n",strlen("hello"));
	//char s[100] = "changer";
	//char t[100] ;
	//strcpy(&t[0],&s[0]);
	//char *str = "string";
	//strtest(str);
	//printf("%s\n",str+2);
	//printf("%s\n",t);
	//printf("%d\n",strcom("changer","changer1"));
	//char s[] = "hello ";
	//char t[] = "world";
	//strcat(&s[0],&t[0]);
	//printf("%s\n",s);
	//char s[] = "123451";
	//char t[] = "3451";
	//printf("%d\n",strend(&s[0],&t[0]));
    //char s[100] = "changer";
	//char t[100] ;
	//strcpy2(&t[0],&s[0],3);
	//printf("%s\n",t);
	// 字符串数组 使用指针数组表示
	//char *name[] = {"changer","hello","haha"};
	// 字符串数组 使用二维数组表示
	//char name2[3][15] = {"gaga","heihei","hehe"};
	//printf("%s\n",name[0]);
	//printf("%s\n",name2[1]);
	int i;
	for(i=1;i<argc;i++)
	  printf("%s%s",argv[i],(i < argc -1) ? " " : "");
	printf("\n");
	return 0;
}

void swap(int *x,int *y){
	int temp ;
	temp = *x;
	*x = *y;
	*y = temp;
}

void getFloat(double *df){
	int c , sign,flag;
	double pwd;
	flag = 0; // 小数点后标志
	*df = 0.0; // 取指针的值
	pwd = 1.0;
	while((c = getchar())!=EOF){
	    sign  = (c == '-') ? -1 : 1;
		if(isdigit(c)){
		    *df = *df *10.0 + ( c - '0');
		}
		if(c == '.') flag = 1;
		if(flag == 1 && isdigit(c)){
			pwd *= 10.0;
		}
		if(c == '\n'){
			*df = (*df  / pwd);
			printf("%f\n",*df);		
			*df = 0.0;
			pwd = 1.0;
			flag = 0;
		}
	}
}

int strlen(char *s){
   int n;
   for(n=0;*s!= '\0';s++)
	   n++;
   return n;
}

void strcpy(char *s,char *t){
	while((*s++ = *t++)!='\0')
		;
}

void strtest(char *s){
	s = s+1;
}

int strcom(char *s, char *t){
	for(;*s == *t;s++,t++)
		if(*s == '\0')
			return 0;
	return *s - *t;
}

void strcat(char *s , char *t){
  // int n = strlen(s);
  // while(*t!='\0'){
  //   *(s + n) = *t;  
	 //n++;
	 //t++;
  // }
  // *(s + n) = '\0';
	while(*s!= '\0')
		s++;
	while(*t!='\0'){
	   *s++ = *t++;
	}
	*s = '\0';
}

int strend(char *s,char *t){
    int len1 = strlen(s);
	int len2 = strlen(t);

	if(len2 > len1) return -1;
	while((*(s + len1 - len2) == *t) && *t!='\0'){
	     s++;
		 t++;
	}
	if(*t == '\0') return 0;
	return -1;
}

void strcpy2(char *s,char *t , int n){
	while((*s = *t) && n>0){
		s++;
		t++;
	    n--;
	}
	*s = '\0';
}
#include <stdlib.h>
#include <stdio.h>

#define MAXLINE 100
#define MAXOP 100

#define swap(t,x,y) { t temp;temp = x;x = y;y = temp;} //宏替换
int getline(char line[],int lim); // 获取当前行
int strindex(char line[], char pattern[]);// 匹配字符串
int strindexl(char line[], char pattern[]); //返回最右边的位置
int strlen(char line[]);
double atof(char s[]); // 字符串转为浮点数
void test();
void printd(int n);// 递归打印
//int itoa(char s[]); // 递归生产整形
char pattern[] = "loud";
char line[MAXLINE];
int i  = 10; // 外部变量
main(){
	//while(getline(line,MAXLINE)>0){
	//	if(strindex(line,pattern)>0)
	//		printf("%s\n",line);
	//}
	//printf("%d\n",strindexl("1232","2"));
	//printf("%d\n", strindex("1232","2"));
	//printf("%.3f\n",atof("-123.45"));
	//printf("%d\n",(int)atof("-123.45"));
	//test(); // 修改外部变量
	//printf("%d\n",i);
	//int type;
	//double op2;
	//char s[MAXOP];
	//while((type = getop(s))!=EOF){
	//	switch(type){
	//	  case '0':
	//		  push(atof(s));
	//		  break;
	//	  case '+':
	//		  push(pop() + pop());
	//		  break;
	//	  case '*':
	//		  push(pop() * pop());
	//		  break;
	//	  case '-':
	//		  op2 = pop();
	//		  push(pop() - op2);
	//		  break;
	//	  case '/':
	//		  op2 = pop();
	//		  push(pop() / op2);
	//		  break;
	//	  case '\n':
 //             printf("\t%.8f\n",pop());
	//		  break;
	//	  default:
	//		  printf("error: unknown command %s\n",s);
	//		  break;
	//	}
	//	return 0;
	//}

	//register char c = 'a';
	//printf("%x\n",&c); //寄存器变量不能取地址
	// printd(123);
	int x = 10;
	int y = 20;
	// 这是宏定义 不是函数 =。=
	swap(int ,x,y);
	printf("%d %d\n",x,y);
}
void test(){
  extern int i;
  i = 20;
}

int getline(char line[],int lim){
  int c , i = 0; 
  while((c = getchar())!=EOF && --lim >0 && c != '\n'){
      line[i++] = c;
  }
  line[i] = '\0';
  return i;
}
int strlen(char line[]){
   int len = 0;
   while(line[len]!='\0') len ++;
   return len;
}

int strindex(char line[], char pattern[]){
    int i , j , k ;
	for(i=0;line[i]!='\0';i++){
	    j = i;
		k = 0;
		while(line[j] == pattern[k]){
	         j++;
			 k++;
		}
		//	;
		//for(j=i,k=0;line[j] == pattern[k] && pattern[k]!='\0';k++,j++)
		//	;
		if(k >0 && pattern[k] == '\0')
			return i;
	}
	return -1;
}

int strindexl(char line[], char pattern[]){
	int i,j,k;
	int len1 = strlen(line);
    int len2 = strlen(pattern);
	for(i = len1-1;i>0;i--){
		j = i;
		k = len2 -1;
		while(line[j--] == pattern[k--] && k >=0)
			;
		if(k < 0)
			return i - (len2 + 1);
	}
	return -1;
}

 double atof(char s[]){
	int i,sign;
	double base = 0.0;
	double pwd;
	for(i=0;s[i]!='\0' && s[i]!='.';i++){
		if(i==0 && (s[i] == '+' || s[i] == '-')){
		   sign = (s[i] == '+') ? 1 : -1;
		   i++;
		}
        base = base*10.0 + (s[i] - '0');
	}
	if(s[i] == '.')
	   i++;
	for(pwd = 1.0;s[i]!='\0'&& s[i] >= '0' && s[i] <= '9';i++){
	   base = base*10.0 + (s[i] - '0');
	   pwd = pwd * 10.0;
	}
	return sign *(base/pwd);
} 

 void printd(int n){
	// if(n / 10 == 0 ){
	//    putchar((n % 10) + '0');
	//	return;
	// }
	//else
	//  printd(n/10);
	//putchar(n%10+ '0');
	 if(n / 10)
		 printd(n/10);
	 putchar(n%10+ '0');
 }

 
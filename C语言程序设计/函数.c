#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//查找
int strindex(char s[],char t[]);
// 返回最右侧出现的位置
int strrindex(char s[],char t[]);
double atof(char s[]);
// 递归实现
int itoa4(int n , char s[]);
#define swip(t,x,y) {t temp = (x); (x) = (y);(y) = temp;}
void mainy(){
    int x = 20 , y = 10;
	char s[20];
	//printf("%d\n",strrindex("chagerer","ger"));
	//printf("%f\n",atof("-12.3x4"));
	//itoa4(-1234,s);
	//printf("%s\n",s);
	printf("%d %d\n",x,y);
	swip(int ,x,y);
	printf("%d %d\n",x,y);
}

int strindex(char s[],char t[]){
   int i,j,k;
   for(i = 0;s[i]!='\0';i++){
      for(j=i,k=0;t[k]!='\0' && s[j] == t[k];j++,k++)
		  ;
	  if(k>0 && t[k]=='\0')
		  return i;
   }
   return -1;
}

int strrindex(char s[],char t[]){
   int i,j,k,pos = -1;
   for(i = 0;s[i]!='\0';i++){
      for(j=i,k=0;t[k]!='\0' && s[j] == t[k];j++,k++)
		  ;
	  if(k>0 && t[k]=='\0')
		  pos = i;
   }
	return pos;
}

double atof(char s[]){
    double val,pwd,sign;
	int i;
	// 处理空格
	for(i = 0;isspace(s[i]);i++)
		;
	sign = (s[i] == '-')?-1.0:1.0;
	if(s[i] == '-' || s[i] == '+')
		i++;
	for(val = 0.0;s[i]!='\0';i++){
	    if(s[i] == '.') break;
		if(isdigit(s[i]))
		  val = val *10.0 + (s[i] - '0');
	}
	if(s[i] == '.') i++;
	for(pwd = 1.0;s[i]!='\0';i++){
		if(isdigit(s[i])){
			val = val *10.0 + (s[i] - '0');
			pwd *= 10;		
		}
	}
	return  (val/ pwd) * sign;
}

int itoa4(int n , char s[]){
   static int i;
   if(n/10)
	 itoa4(n/10,s);
   // 最里面一层处理负数
   else {
      i = 0;
	  s[i++] = '-';
   }
   s[i++] = abs(n) % 10 + '0';
   s[i] = '\0';
}

#include <stdio.h>
int function(int x);
void delekg(char *str);// 删除连续空格
void main(){
	// 函数指针
	//int (*pf)(int) = function;
	//printf("%d\n",pf(2));
	//printf("%c\n","xyz"[1]);
	char str[] = "he    ok   i   am   changer";
	delekg(str);
	if(-1)
	printf("%s\n",str);
}

int function(int x){
   return 10;
}

void delekg(char *str){
   int i,j;
   for(i=j=0;str[i]!='\0';i++){
   	   if(str[i]!=' ' ||  str[i+1]!= ' ')
		   str[j++] = str[i];
   }
   str[j] = '\0';
}
#include <stdio.h>

int binsearch(int v[],int n,int x); // 折半查找
int atoi(char []);// 字符串转换为整形
void expand(char [] , char []); // 字符串转换
int strlen(char *);
void reverse(char *); //字符串反转
void itoa(int ,char []); // 整形转字符串
main(){
	//int v[] = {2,6,7,10,11,16,18,20};
	//printf("%d\n",binsearch(v,8,201));
	//printf("%d\n",atoi("-1234567x"));
	//char s1[] = "a-b-c-de";
	//char s2[100];
	//expand(s1,s2);
	//printf("%s\n",s2);
	char s[100] ;
	itoa(-1234589,s);
	printf("%s\n",s);
}

int binsearch(int v[],int n,int x){
    int low = 0;
	int high = n - 1;
	int mid;
	while(low <= high){
	   mid = (low + high)/2;
	   if(x > v[mid])
		   low = mid+1;
	   else if(x < v[mid])
		   high = mid-1;
	   else
		   return v[mid];
	}
	return -1;
}

int atoi(char s[]){
	int n,i,sign;
	n = 0;
	if(s[0] == '-' || s[0] == '+')
	  sign = (s[0] == '-') ? -1 : 1;
	for(i=0;s[i]!='\0';i++){
	   if(s[i] >= '0' && s[i] <= '9')
		 n = n*10 + (s[i] - '0');
	}
	return sign * n;
}

void expand(char s1[] , char s2[]){
	int i,j,c;
	for(i=j=0;s1[i]!='\0';i++){
	   c = s1[i];
	   if(c != '-')
		 s2[j++] = c;
	}
	s2[j] = '\0';
}

int strlen(char *s) {
   int len = 0;
   while(*s++!='\0')
	   len++;
   return len;
}

void reverse(char *s){
	int len = 0;
	int i ,j,temp;
    len = strlen(s);
	for(i = 0, j = len -1;i<j;i++,j--){
	   // 字符串交换
	   temp = *(s+i);
	   *(s+i) = *(s+j);
	   *(s+j) = temp;
	}	
}
// 支持负数
void itoa(int n,char s[]){
	int yu,i = 0,sign;
	if(n<0) {
	   n = -n;
	   sign = -1;
	}
	while(n){
	  yu = n%10;
	  s[i++] = yu + '0';
	  n = n/10;
	}
	if(sign == -1)s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}
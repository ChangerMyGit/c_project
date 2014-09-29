#include <stdio.h>
#include <string.h>
int bitcount(unsigned x);//计算位数
int binsearch(int x,int v[],int n); //折半查找
void escape(char s[],char t[]);
void reverse(char s[]); // 更好的空间复杂度
main(){
	//printf("%d",bitcount(6));
	//unsigned char x1 = 0x1f;
	//signed char x2 =0x7f;
	//signed char x3 = 0x0;
	////x2 += x1;
	//printf("%d\n", x1);
	//printf("%d\n", x2);
	//x3 = x1 + x2;
	//printf("%d\n", x3);
	//printf("%d\n", x1 + x2);
	//printf("%d\n", ++x2);
	//int v[] = {1,5,6,8,9,25,28,43,45,56};
	//printf("%d",binsearch(9,v,10));
	//char s[] = "Hello World!\n";
	//char t[100];
	//escape(s,t);
	//char t[] = "changer";
	//reverse(t);
	//printf("%s",t);
	return 0;
}

int bitcount(unsigned x){
    int b;
	for(b=0;x!=0;x>>=1) // 不断右移
	if(x&1) b++;
	return b;
}

int binsearch(int x,int v[],int n){
   int low , high , mid ;
   low =0;
   high = n-1;
   while(low < high){
       mid = low + high / 2 ;
	   if(x > v[mid])
		   low = mid+1;
	   else if(x < v[mid])
		   high = mid-1;
	   else 
		return mid;
   }
   return -1;
}
void escape(char s[],char t[]){
   int i,j;
   i = j = 0;
   while(s[i]!='\0'){
	   switch(s[i]){
	   case '\n':
		   t[j++] = '\\';
		   t[j++] = 'n';
		   break;
	   case '\t':
		   t[j++] = '\\';
		   t[j++] = 't';
		   break;
	   default :
		   t[j++] = s[i];
	   }
	   i++;
   }
   t[j] = '\0';
}
void reverse(char s[]){
  int c,i,j;
  for(i=0,j=strlen(s)-1;i<j;i++,j--){
     c = s[i];
	 s[i] = s[j];
	 s[j] = c;
  }
}
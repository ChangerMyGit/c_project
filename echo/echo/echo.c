#include <stdlib.h>
#include<stdio.h>
#define �����ӡ���� main
int etot(char []); // 8����ת10����
int shtot(char []); // 16����ת10����
void tentoe(int ); // ������תʮ����
void tentoe2(int i) ; //������תʮ���� �ݹ�
�����ӡ����(){
	////system("echo Hello World\n");
	////system("calc");
	////system("notepad");
	////system("mspaint");
	//int const x = 0x60;
	//int a = 10;
	//int b = 20;
	//printf("%d\n",x);
	////printf("%x\n",&x);

	//// getchar();
	//{
	//   int x = 10;
	//   printf("%d\n",x);
	//}
	////a = a + b;
	////b = a-b;
	////a = a-b;
	//a = a * b;
	//b = a / b;
	//a = a / b;

	// ���ƻ��� 
	//char a[] = "01235";
	//char b[] = "0xafe9";
	//printf("%d\n",etot(a));
	 tentoe(10);
	 tentoe2(10);
}

int etot(char s[]){
	int i,n;
	i = n = 0;
	if(s[i] = '0') i++;
	for(;s[i]!='\0';i++)
	  n = n * 8 + (s[i] - '0');
	return n;
}

void tentoe(int n){
   char s[100];
   int yu,i = 0;
   while(n >0){
	   yu = n%2;
	   n = n/2;
	   // putchar(yu + '0');
	   s[i++] = yu + '0';
   }
   s[i] = '\0';
   for(;i >=0;i--){
      putchar(s[i-1]);
   }
   putchar('\012');
}

void tentoe2(int i){
   if(i/2)
     tentoe2(i/2);
   putchar(i%2+'0');
}
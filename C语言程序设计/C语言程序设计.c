#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void escape(char s[], char t[]);// �ַ������� ��������ַ�
void cape(char t[],char s[]); // ����ת���ַ�
int atoi(char s[]);
void itoa2(int n,char s[]);// ����ת���ַ���
void itoa3(int n);// �ݹ�ת��
void reverse(char s[]); // �ַ�����ת
void itob(int n ,char s[] , int b);// 
void testFunction();
int x = 100;
void mainx(){
	//char s[30];
	//char t[30] = "hello\thank\n";
	//char es[30];
	//escape(s,t);
	//printf("%s\n",s);
	//cape(s,es);
	//printf("%s\n",es);
	//printf("%d\n",atoi("-1234x6"));
	// �Ĵ�������
	// �Ĵ���������֧�ֵ�ַ����
	register int n = -1234;
	//char s[30];
	//itob(n,s,8);
	//printf("%s\n",s);
	itoa3(n);
	//testFunction();
}
void testFunction(){
   extern int x;
   printf("%d\n",x);
}

void escape(char s[], char t[]){
	int i , j;
	for(i = j = 0;t[i]!='\0';i++){
		switch(t[i]){
			case '\n':
				s[j++] = '\\';
				s[j++] = 'n';
				break;
			case '\t':
				s[j++] = '\\';
				s[j++] = 't';
				break;
			default:
				s[j++] = t[i];
				break;
		}
	}
	s[j] = '\0';
}

void cape(char t[] , char s[]){
	int i , j;
	for(i = j = 0;t[i]!='\0';i++){
		switch(t[i]){
		case '\\':
			if(t[i+1]  == 'n' ){
			   	s[j++] = '\n';
			    i++;
			}
			else if(t[i+1] == 't'){
			   s[j++] = '\t';
			   i++;
			}		
			break;
		default:
			s[j++] = t[i];
			break;
		}
	}
	s[j] = '\0';
}

int atoi(char s[]){
   int i,n,sign;
   // �Ƴ��ո�
   for(i=0;isspace(s[i]);i++)
	   ;
   sign = (s[i] == '-')?-1:1;
   if(s[i] == '-' || s[i] == '+') i++;
   for(n=0;s[i];i++)
	   if(isdigit(s[i]))
	     n = n * 10 + (s[i] - '0');
   return sign *n;
}

void itoa2(int n,char s[]){
   int i = 0,sign;
   if((sign = n) <0)
	   n = abs(n); // n = -n ���ַ�ʽ�ᵼ�����
   while(n){
       s[i++] = (n%10) + '0';
	   n = n/10;
   }
   if(sign <0) s[i++] = '-';
   s[i] = '\0';
   reverse(s);
}

// ��ת���������һ�����ַ�
void reverse(char s[]){
	int i,j,c;
	for(i=0,j=strlen(s)-1;i<j;i++,j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itob(int n ,char s[] , int b){
   int i = 0,sign , j;
   if((sign = n) <0)
	   n = abs(n); // n = -n ���ַ�ʽ�ᵼ�����
   while(n){
	  j = n % b; // ����ʹ������������
	  s[i++] = (j <=9)?j + '0':j  + 'a' - 10;
      n = n/b;
   }
   if(sign <0) s[i++] = '-';
   s[i] = '\0';
   reverse(s);
}

void itoa3(int n){
  if(n<0){
     n = -n;
	 putchar('-');
  }
  if(n/10)
	  itoa3(n/10);
  putchar(n%10+'0');
}
/**
  ʹ�ú����ķ�ʽ����߼�
**/
#include <stdio.h>
#include <ctype.h>
#include "stack2.h";
#define MAXLINE 100
#define dprint(expr) printf(#expr " = %g\n" ,expr)
int getLine(char line[],int max); // ��������ÿһ��
int strindex(char source[],char search[]); // �����ַ��������Ŀ�ͷλ�ã�����������-1
double atof(char s[]); //�ַ���ת����Ϊ˫���ȵĸ�����
void print(int n);
//void push1(double f);
//double pop1();
main(){
	//char line[MAXLINE];
	//char search[] = "loud";
	//while(getLine(line,MAXLINE)>0){
	//	if(strindex(line,search)!=-1){
	//		printf("%s",line);
	//	}
	//}
	//char s[] = "-123.45";
	//printf("%.3f",atof(s));
	//int i ,testFcuntion();
	//i = 1 + testFcuntion();
	//printf("%d",i);
	// ���׼�����
	//double sum ,atof(char []);
	//sum = 0.0;
	//while(getLine(line,MAXLINE)>0){
	//   printf("\t%g\n",sum+=atof(line));
	//}
    // �沨�������� ֻ֧�����μ���
	//char s[] = " 12+21-* \n";
	//int i = 0;
	//int op2;
	//while(s[i]!='\0'){
	//	if(isdigit(s[i]))
	//		push(s[i] - '0');
	//	else {
	//		switch(s[i]){
	//		   case '+':
	//		     push(pop() + pop());
	//			 break;
	//		   case '*':
	//			 push(pop() * pop());
	//			 break;
	//		   case '-':
	//			 op2 = pop();
	//			 push(pop()-op2);
	//			 break;
	//		   case '/':
	//			 op2 = pop();
	//			 push(pop()/op2);
	//			 break;
	//		   case '\n':
	//			 printf("Result :%d\n",pop());
	//			 break; 
	//		}
	//	}
	//	i++;
	//}
	// �沨�������� ֧�ָ���������
	//extern int sp1;
	//int c ;
	//int i = 0;
	//char s[MAXLINE];
	//double op2;
	//double op1;
	//while((c = getchar())!=EOF){
	//	if(isdigit(c) || c =='.'){
	//	   s[i++] = c;
	//	} else if(c == ' '){
	//	   s[i] = '\0';
	//	   if(i>0){
	//	   	   push1(atof(s));
	//		   i = 0;
	//		   s[0] = '\0';
	//	   }
	//	} else {
	//		switch(c){
	//		   case '+':
	//		     push1(pop1() + pop1());
	//			 break;
	//		   case '*':
	//			 push1(pop1() * pop1());
	//			 break;
	//		   case '-':
	//			 op2 = pop1();
	//			 push1(pop1()-op2);
	//			 break;
	//		   case '/':
	//			 op2 = pop1();
	//			 push1(pop1()/op2);
	//			 break;
	//		   case '%':
	//			 op2 = pop1();
	//			 op1 = pop1();
	//			 push1((op1 - op1/op2)*op2);
	//			 break;
	//		   case '\n':
	//			 printf("Result :%f\n",pop1());
	//			 //printf("%d",sp1);
	//			 break; 			  
	//		}
	//	}
	//}
	// print(1234);
	// printf("%d",1+'0'); 
	// putchar(('0' + 9));
	dprint(123);
	return 0;
}

int getLine(char line[],int max){
    int c ,i ;
	i =0 ;
	while((c = getchar())!=EOF && c!= '\n'){
	   line[i++] = c;
	}
	if(c == '\n') line[i++] = c;
	line[i] = '\0';
}

int strindex(char source[],char search[]){
    int i ,j,k;
	for(i =  0;source[i]!='\0';i++){
	   k = i;
	   j = 0;
	   while((source[k++] == search[j++]) && search[j]!='\0') 
		   ;
	   if(search[j] == '\0')
		 return i;
	}
	return -1;
}
// ����ת�ַ���
void print(int n){
	if(n/10)
	  print(n/10);
	putchar(n%10 + '0'); // ����ת�ַ���
}
//double atof(char s[]){
//    /** 
//	   ���������裬����С����֮ǰ��֮��
//	   123.45 �������12345 Ȼ�� ����100
//	**/
//	double val,power;
//	int i ,sign;
//	for(i=0;isspace(s[i]);i++)
//		;
//	sign = (s[i] == '-')?-1:1;
//	if(s[i] == '+' || s[i] == '-') i++;
//	// ѭ��С����֮ǰ
//	for(val = 0.0;isdigit(s[i]);i++){
//	    val = val * 10.0 + (s[i] - '0');
//	}
//	if(s[i] == '.') i++;
//	// ѭ��С����֮��
//	for(power = 1.0 ;isdigit(s[i]);i++){
//	   val = val * 10.0 + (s[i] - '0');
//	   power *= 10.0;
//	}
//
//	return sign* val / power;
//}
#include <stdio.h>
#define MAXVAL 100

static int sp1 = 0; // ջ�ĵ�ǰλ��
double val2[MAXVAL]; // ջֵ

void push1(double f){
	if(sp1 < MAXVAL)
		val2[sp1++] = f;
	else 
	   printf("error:Stack is Full!");
}

double pop1(){
   if(sp1 >0)
	   return val2[--sp1];
   else 
	   printf("error:Stack is Empty!");
}

#include <stdio.h>
#define MAXVAL 100

static int sp1 = 0; // 栈的当前位置
double val2[MAXVAL]; // 栈值

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

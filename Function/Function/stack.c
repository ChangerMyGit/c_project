#include <stdio.h>
#define MAXVAL 100

int sp = 0; // 栈的当前位置
int val[MAXVAL]; // 栈值

void push(int f){
	if(sp < MAXVAL)
		val[sp++] = f;
	else 
	   printf("error:Stack is Full!");
}

int pop(){
   if(sp >0)
	   return val[--sp];
   else 
	   printf("error:Stack is Empty!");
}

#include <stdio.h>
#define MAXVAL 100

int sp = 0; // ջ�ĵ�ǰλ��
int val[MAXVAL]; // ջֵ

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

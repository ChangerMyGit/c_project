#include <stdio.h>
#include "cal.h"
#define MAXVAL 100
int sp = 0;
double val[MAXVAL];
void push(double f){
	if(sp > MAXVAL)
	  printf("%s\n","������ջ����!");
	else
	  val[sp++] = f;
}

double pop(){
   if(sp > 0)
	 return val[--sp]; // ���鳤��
   else 
	 printf("%s\n","��ջΪ��!");
}
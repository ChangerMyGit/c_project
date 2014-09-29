#include <stdio.h>
#include "cal.h"

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(){
   return (bufp >0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
   if(bufp >= BUFSIZE)
	 printf("%s\n","������ջ����!");
   else 
	 buf[bufp++] = c;
}
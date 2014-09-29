#include <stdio.h>
int hailstone(int n);
int test();
void trim(char str[]);
static int x = 10;
void main(){
	char str[] = "changer  hello              ok";
	trim(str);
	printf("%s\n",str);
}

int test(){
  extern int a;
  printf("%d \n", a);
  return 0;
}

int hailstone(int n){
	int length = 1;
	while(n>1){
		(n%2)? (n = 3*n+1):(n = n/2);
		length++;
	}
	return length;
}

void trim(char str[]){
   int i,j;
   for(i = j = 0;str[i];i++)
	  if(!(str[i]==' ' && str[i+1]== ' '))
		  str[j++] = str[i];
   str[j] = '\0';
}
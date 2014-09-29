#include <stdio.h>
typedef int (*COM)(char *);
// 自定义复杂声明 函数的指针
int testFunctionx(char *);
void mainp(){
	COM com = testFunctionx;
	printf("%d\n",(*com)("X"));
}

int testFunctionx(char *str){
    return -1;
}
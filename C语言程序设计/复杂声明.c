#include <stdio.h>
typedef int (*COM)(char *);
// �Զ��帴������ ������ָ��
int testFunctionx(char *);
void mainp(){
	COM com = testFunctionx;
	printf("%d\n",(*com)("X"));
}

int testFunctionx(char *str){
    return -1;
}
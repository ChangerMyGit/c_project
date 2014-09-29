/**
  函数
**/
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
void binary(int n);
// 可变参数 可变参数列表使用宏来实现的 这些宏定义于stdarg.h 头文件
// 宏文件定义了
float average(int n_values,...);
//厄密多项式
int hermite(int n,int x);
// 字符串转换为整数
int ascii_to_integer(char *string);
// 打印最大整形参数
int max_list(int n_values,...);
int main(void){
	//int a[5][5] = {{1,2,3,4,5},{6,7,8,9,10}};
	//printf("%d\n",*((*a)+1));
	//printf("%d\n",*a[0]);
	//printf("%d\n",a[0][0]);
	//binary(4567);
	//printf("%.2f\n",average(3,2,2,3));
	//printf("%d\n",hermite(3,2));
	//printf("%d\n",ascii_to_integer("12534"));
	//printf("%d\n",max_list(4,1,21,3,12));
	unsigned a = 10, b = 20;
	//printf("%d\n",strcmp("changer","xx"));
	printf("%s\n",strerror(1));
	return 0;
}
 
void binary(int n){
   if(n/10)
     binary(n/10);
   putchar(n%10 + '0');
}

float average(int n_values,...){
	va_list var_arg;
	int count;
	float sum = 0;
	va_start(var_arg,n_values);
	for(count = 0;count <n_values;count++){
		sum += va_arg(var_arg,int);
	}
	va_end(var_arg);
	return sum / n_values;
}

int hermite(int n,int x){
    if(n<=0)
		return 1;
	else if(n == 1)
		return 2*x;
	else
		return (2 * x * hermite(n-1,x)) -( 2 * (n-1)* hermite(n-2,x));
}

int ascii_to_integer(char *string){
   int n;
   for(n=0;*string;string++){
	   if(*string >= '0' && *string <= '9'){
		   n = n*10 + *string - '0';
	   }
	   else 
		 return 0;
   }
   return n;
}

int max_list(int n_values,...){
	va_list var_arg;
	int max,count,temp;
	va_start(var_arg,n_values);
	for(count=0,max = 0;count<n_values;count++){
		temp = va_arg(var_arg,int);
		if(max < temp) max = temp;
	}

	return max;
}
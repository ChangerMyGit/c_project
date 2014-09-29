#include <stdio.h>
int negate(int i);
int increment(int i);
void main(){
  typedef char *spoint; // 自定义指针类型
  enum boolean {YES,NO};
  int y = 10;
  int const x  = 100;
  int const *p = &y; // 指针的变量可以变 但是指向的值不能变
  int * const p2  = &y;// 指针的变量不能变 但是指向的值可以变
  int const * const p3 = &y; // 都不可以变
  long l = 10;
  short sh  = l;
  enum boolean by = YES;
  printf("%d %s \n",sh,by);
  //int x = 10, y = 1;
  //printf("%d  %d  %d\n",increment(x),negate(y),by);
  //spoint a  = "hello";
  //printf("%s \n",a);
  // 代码块作用域
  {
     int x = 30;
	 int y = 20;
	 printf("%d  %d \n",x,y);
  }
}
#include <stdio.h>
int negate(int i);
int increment(int i);
void main(){
  typedef char *spoint; // �Զ���ָ������
  enum boolean {YES,NO};
  int y = 10;
  int const x  = 100;
  int const *p = &y; // ָ��ı������Ա� ����ָ���ֵ���ܱ�
  int * const p2  = &y;// ָ��ı������ܱ� ����ָ���ֵ���Ա�
  int const * const p3 = &y; // �������Ա�
  long l = 10;
  short sh  = l;
  enum boolean by = YES;
  printf("%d %s \n",sh,by);
  //int x = 10, y = 1;
  //printf("%d  %d  %d\n",increment(x),negate(y),by);
  //spoint a  = "hello";
  //printf("%s \n",a);
  // �����������
  {
     int x = 30;
	 int y = 20;
	 printf("%d  %d \n",x,y);
  }
}
#include <stdio.h>
#include <assert.h>
// ���������1�ĸ���
int count_one_bits(unsigned value);
int func(void);
// ������ģʽ���ұ任
unsigned int reverse_bits(unsigned int value);
// ��ȡ���������λ��
int count_high_bit(unsigned value);
void main(){
	int i = 20;
	//printf("%d \n",count_one_bits(10));
	//printf("%d \n",i | 1 << 2);
	//printf("%d \n",i & ~(1 << 3));
	//printf("%f\n",(float)(25/10));
	//i = func() - func() * func();
	//printf("%d\n",i);
	//if( i <= i <= 10)
	//	printf("in");
	//else 
	//	printf("out");
	int c;
	// ת����Сд
	//while((c = getchar())!=EOF){
	//   if(c >= 'A' && c <= 'Z')
	//	   putchar(c + ('a' - 'A'));
	//   else 
	//	   putchar(c);
	//}
	// ��ĸ���� 
	//while((c = getchar())!=EOF){
	//    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	//		putchar(c + 13);
	//	else putchar(c);
	//}
	//printf("%d",count_high_bit(100));
	//int *b = NULL;
	//assert(b != NULL);
	//printf("%d\n",b);
	//unsigned s = reverse_bits(25);
	//printf("%u",s);
	char s[5];
	char *cp;
	for(cp = s;cp <= &s[4];)
		*cp++ = '0';
	printf("%s\n",s);
}

int count_one_bits(unsigned value){
   int ones;
   // �������� ������һλ��1 ��������2
   for(ones = 0;value!=0;value >>= 1){
       //if(value % 2 !=0) // if((value & 1)!=0)
		if(value & 1) 
	      ones++;
   }
   return ones;
}

int func(void){
   static int counter = 1;
   return ++counter;
}

int count_high_bit(unsigned value){
	 int high;
	 for(high = 0;value!=0;value = value >>1,high++)
		 ;
	 return high;
}

unsigned int reverse_bits(unsigned int value){
    unsigned int answer;
    unsigned int i;
    answer = 0;
    /*��һ��unsigned int ����1һֱ���ƣ�ֱ�������ȫ0��ʱ��Ҳ�͵õ��˸û�����unsigned int�ĳ���*/
    for (i = 1; i != 0; i <<= 1){
       answer <<= 1;
       if (value & 1) 
	      answer |= 1; 
       value >>= 1;
   }
   return answer;
}
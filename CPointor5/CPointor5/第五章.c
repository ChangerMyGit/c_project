#include <stdio.h>
#include <assert.h>
// 计算二进制1的个数
int count_one_bits(unsigned value);
int func(void);
// 二进制模式左右变换
unsigned int reverse_bits(unsigned int value);
// 获取二进制最高位数
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
	// 转换大小写
	//while((c = getchar())!=EOF){
	//   if(c >= 'A' && c <= 'Z')
	//	   putchar(c + ('a' - 'A'));
	//   else 
	//	   putchar(c);
	//}
	// 字母加密 
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
   // 不断右移 如果最后一位是1 则不能整除2
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
    /*把一个unsigned int 数字1一直左移，直到它变成全0的时候，也就得到了该机器内unsigned int的长度*/
    for (i = 1; i != 0; i <<= 1){
       answer <<= 1;
       if (value & 1) 
	      answer |= 1; 
       value >>= 1;
   }
   return answer;
}
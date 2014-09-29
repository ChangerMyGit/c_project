#include<stdio.h>
#include<limits.h>
#define LOWER 0  // 常量定义
#define HIGH 10
#define MAXLINE 1000
int getLine(char line[],int max);
void copy(char to[],char from[]);
void revser(char s[]);
void testEnum();
int atoi(char s[]); // 字符串转换为整形
int lower(int c);
int htoi(char s[]); // 十六进制字符串转为十进制的数字
void squeeze(char s[],int c);// 从字符串中删除字符c
void strcat(char s[],char c[]);// 字符串合并
void squeeze2(char s[],char c[]); // 将字符串s1中 任何包含s2中的字符都删掉 
int strcon(char s[],int c);// 字符串包含
int any(char s1[],char s2[]); //返回s1中包含s2的第一个位置 
main(){
    //float fathr , celsius;
	//int lower ,upper ,step;
	//lower = 0;
	//upper = 300;
	//step = 20;
	//fathr = lower;
	//printf("Tem Title\n ");
	//while(fathr <=upper ){
	//	 celsius = 5.0*(fathr - 32.0)/9.0;
	//	 printf("%3.0f\t%6.1f\n",fathr,celsius);
	//	 fathr = fathr+ step;
	//}

	//int c ;// 用整形表示字符是为了能够存储文件结束符EOF
	//c = getchar();
	//while((c!=EOF) == 1){ // 0为false , 1为true
	//	putchar(c);
	//	c = getchar();
	//}
   
	// 统计行数
	//int c ;
	//int nl = 0 ;
	//while((c = getchar())!= EOF)
	//	if(c == '\n') {
	//	     ++nl;
	//	}
	//printf("%d",nl);

	// 编写一个程序 以每行一个单词的方式打印起输入
	//int c ;
	//while((c = getchar())!=EOF){
	//	if(c == ' '){
	//	    putchar('\n'); 
	//	} else {
	//	    putchar(c);
	//	}
	//}

	// 编写一个程序 打印输入中字符出现频率的直方图
    //int a[26];
	//int c;
	//int i;
	//int j;
	//
	//for(i = 0; i <26; i++){
	//	a[i] = 0;
	//}
	//while((c =getchar()) != EOF){
	//	for(i = 'a'; i <= 'z'; i++){
	//		if(c == i){
	//			a[i - 97]++;
	//		}
	//	}
	//}
	//for(i = 0; i < 26; i++){
	//	if(a[i] != 0){
	//		printf("%c  ", i + 97);
	//		printf("%d\n",a[i]);
	//		//for(j = 0; j < a[i]; j++){
	//		//	putchar(a[i]);
	//		//}
	//		//putchar('\n');
	//	}
	//}
	//int i = 2;
	//printf("%3d%3d\n",i,power(10,i));

	// 输入最长的字符串行
	//int len, max;
	//char line[MAXLINE];    // 当前输入行 
	//char longest[MAXLINE]; // 保存的最长的行
	//max = 0;
	//while((len = getLine(line,MAXLINE)) >0){
	//	if(len > max){
	//		max = len;
	//		copy(longest,line);
	//	}
	//}
	//if(max > 0)
	//  printf("%s",longest);

	// 字符串反转
	//char s[MAXLINE];
	//int c ;
	//int i = 0;
	//while((c = getchar())!=EOF){
	//   s[i++] = c;
	//}
	//s[++i] = '\0';
	//// printf("%s",s);
	//revser(s);
	// printf("%d %d\n",CHAR_MIN,CHAR_MAX);
	// printf("%d %d\n",CHAR_MIN,UCHAR_MAX);
	// testEnum();
	// char c[] = "1234" ;
	// printf("%d\n",atoi(c));
	// printf("%c\n",lower('X'));
	//char x[] = "0X11" ;
 //   printf("%d\n",htoi(x));
	//printf("%c\n",97);
	//printf("%d\n",'A');
 //   char s[] = "changer";
	//int c = 'r';
	//squeeze(s,c);
	//printf("%s",s);
    char s1[] = "123456";
    char s2[] = "45";
	// strcat(s,c);
	// squeeze2(s,c);
	// printf("%d",any(s1,s2));
	// printf("%d",0177);
	return 0;
}
// 自定义函数
int power(int base , int n){
    int i ,p ;
	p = 1;
	for(i = 1;i<=n;i++){
		p = p * base;
	}
	return p;
}

int getLine(char s[],int lim){
    int c ,i;
	for(i = 0;i<MAXLINE-1 && (c= getchar())!= EOF && c!= '\n';i++){
	    s[i] = c;
	}
	if(c == '\n'){
	    s[i] = c;
		++i;
	}
	s[i] = '\0'; // 字符串末尾
	return i;
}

// 复制
void copy(char to[] , char from[]){
	int i = 0 ;
	while((to[i] = from[i])!= '\0'){
	    ++i;
	}
}
// 字符串反转
void revser(char s[]){
	int i = 0;
	int j = 0 ;
	int k = 0;

	char to[MAXLINE]; // 输出字符串
	while(s[i]!='\0'){
	    i++;
	}
	// 计算字符串长度 首先移除掉回车 然后移除掉结束符 ，所以从两个后遍历
	for(j = i-2 , k = 0;j >= 0 , k < i;j--, k++){
	    to[k] = s[j];
	}
	//k++;
	to[k] = '\0';
	printf("%s",to);
}

void testEnum(){
    // 枚举
	enum boolean {YES,NO};
	enum boolean flag = YES;
    printf("%d\n", flag);
}

int atoi(char s[]){
	int i,n;
	n = 0;
	for(i=0;s[i]>= '0' && s[i] <='9';i++){
	   n = 10 * n + (s[i] - '0');
	}
	return n;
}

int lower(int c){
	if(c>= 'A' && c <= 'Z'){
	    return c + 'a' - 'A';
	} else 
		return c;
}

int htoi(char s[]){
   int i = 0;
   int n = 0;
   int digit = 0;
   // 首先处理前两位
   if(s[i]=='0'){
     ++i;
     if(s[i] == 'X' || s[i] == 'x')
       ++i;
    } else {
       printf("it is not true\n");
    }
   // 处理后面的数字 
   for(i;s[i]!='\0';i++){
      if(s[i]<'9'&&s[i]>'0')
        digit = s[i]-'0';
	  else if(s[i]<='z'&&s[i]>='a')
		digit=s[i]-'a'+10;
	  else if(s[i]>='A'&&s[i]<='Z')
		digit=s[i]-'A'+10;
	  else 
		break;
	   n=n*16+digit;
   }
   return n;
}

void squeeze(char s[],int c){
    int i ,j ;
	for(i = j =0 ;s[i]!='\0';i++){
		if(s[i]!=c){
		   s[j++] = s[i]; // 如果找到要删除的字符 则不赋值，跳到下一个字符。
		}
	}
	s[j] = '\0';
}

void strcat(char s[],char c[]){
    int i,j;
	i = j =0;
	while(s[i]!='\0') i++; // 找到队尾
	while((s[i++] = c[j++]) != '\0')
		;
}

int strcon(char s[],int c){
	int i = 0;
	for(i=0;s[i]!='\0';i++){
		if(s[i] == c){
		   return 1;
		}
	}
	return 0;
}

void squeeze2(char s[],char c[]){
   int i,j;
   for(i = j = 0;s[i]!='\0';i++){
       if(strcon(c,s[i]) != 1)
		   s[j++] = s[i];
   }
   s[j] = '\0';
}

int any(char s1[],char s2[]){
   int i ,j,k;
   i = j =0;
   for(i=0;s1[i]!='\0';i++){
	   k = i;
	   j = 0;
	   if(s1[k] = s2[j]){
		   while(s1[k] == s2[j]){
			   k++;
			   j++;
		   }
		   if(s2[j] == '\0')
			 return i;
	   } 
   }
   return -1;
}
#include <stdio.h>
#define IN 0
#define OUT 1
#define MAXLINE 100
int getline(char *,int);
void stringcopy(char * ,char *);
void reverse(char *); //字符串反转
int strlen(char *);
int main(){
	//int fathr;
	//for(fathr = 300 ;fathr >=0;fathr -= 30)
	//	printf("%3d %6.1f\n",fathr,(5.0/9.0) * (fathr - 32));

	// 合并空格
	//int c;
	//while((c = getchar())!=EOF){
	//	if(c == ' '){
	//	   putchar(c);
	//	   while((c = getchar()) == ' ')
	//		   ;
	//	   putchar(c);
	//	} else 
	//		putchar(c);
	//}
  
	// printf("\\t");
	// 单词计数
	//int c ,nl, nc,nw,stage;
	//nl = nw = nc = 0;
	//stage = OUT;
	//while((c = getchar())!=EOF){
	//    nc ++ ; // 字符数
	//	if(c == '\n') nl ++; // 行号 
	//	if(c == '\n' || c == ' ' || c == '\t')
	//		stage = OUT; //单词外
	//	else if(stage == OUT){ // 单词内 之前的特殊字符已经处理
	//	    nw ++;
	//		stage = IN;
	//	}
	//}

	//printf("%3d%3d%3d\n",nc,nl,nw);

	// 每行一个单词
	//int c;
	//while((c = getchar())!=EOF){
	//   if(c == ' ' || c == '\t')
	//	   putchar('\n');
	//   else putchar(c);
	//}
	// 计算数字字符数量，回车 空格 数量 和其他字符数量
	//int c ,i ,nwhite , nother;
	//int dinit[10];
	//nwhite = nother = 0;
	//for(i=0;i<10;i++)
	//  dinit[i] = 0;
	//while((c = getchar())!=EOF){
	//   if(c>='0' && c<='9')
 //        dinit[c-'0']++; // 数字的字符型转换为整形 c - '0'
	//   else if(c == ' '|| c == '\n' || c == '\t')
 //        nwhite++;
	//   else 
	//	 nother++;
	//}

	//for(i=0;i<10;i++)
	// printf("%2d",dinit[i]);
	//printf("%3d%3d",nwhite,nother);
	// 打印输入的各个字符出现频度的直方图
	//char zifu[26]; // 记录字符
	//int qty[26];   // 记录字符数量
	//int c ,i ;
	//char z = 'a';
	//for(i = 0;i<26;i++){
	//    zifu[i] = z++;
	//	qty[i] = 0;
	//}
	//while((c = getchar())!=EOF){
	//	if(c >= 'a' && c <= 'z')
	//	   qty[c - 'a'] ++;  
	//}
	//for(i = 0;i<26;i++){
	//    printf("%3c%3d\n",zifu[i],qty[i]);
	//}

	// 记录输入的最大行
	//char line[MAXLINE];  // 当前行 
	//char maxline[MAXLINE]; // 最大行
	//int len ,max;
	//max = len = 0;
	//while ((len = getline(line,MAXLINE))>0){
	//	if(len > max){
	//	   max = len;
	//	   stringcopy(line,maxline);
	//	}
	//	printf("最大行 : %s",maxline);
	//}
	// 字符串反转
	//char s[] = "changer";
	//reverse(s);
	//printf("%s",s);
	return 0;
}

int getline(char * line ,int lim){
   int c,len;
   len = 0;
   while((c = getchar())!=EOF && lim>0){
	   lim--;
	   len ++;
	   if(c!= '\n' && c!= ' ' && c!='\t') { // 删除空格和制表符
		  *line++ = c;
	   } else if(c == '\n'){
	      *line++ = c;
		  *line = '\0';
		  return len;
	   }
   }
   return len;
}

void stringcopy(char *s ,char *t){
	while(*t++ = *s++)
		;
}
int strlen(char *s) {
   int len = 0;
   while(*s++!='\0')
	   len++;
   return len;
}

void reverse(char *s){
	int len = 0;
	int i ,j,temp;
    len = strlen(s);
	for(i = 0, j = len -1;i<j;i++,j--){
	   // 字符串交换
	   temp = *(s+i);
	   *(s+i) = *(s+j);
	   *(s+j) = temp;
	}	
}
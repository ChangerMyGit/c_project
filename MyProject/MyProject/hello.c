#include<stdio.h>
#include<limits.h>
#define LOWER 0  // ��������
#define HIGH 10
#define MAXLINE 1000
int getLine(char line[],int max);
void copy(char to[],char from[]);
void revser(char s[]);
void testEnum();
int atoi(char s[]); // �ַ���ת��Ϊ����
int lower(int c);
int htoi(char s[]); // ʮ�������ַ���תΪʮ���Ƶ�����
void squeeze(char s[],int c);// ���ַ�����ɾ���ַ�c
void strcat(char s[],char c[]);// �ַ����ϲ�
void squeeze2(char s[],char c[]); // ���ַ���s1�� �κΰ���s2�е��ַ���ɾ�� 
int strcon(char s[],int c);// �ַ�������
int any(char s1[],char s2[]); //����s1�а���s2�ĵ�һ��λ�� 
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

	//int c ;// �����α�ʾ�ַ���Ϊ���ܹ��洢�ļ�������EOF
	//c = getchar();
	//while((c!=EOF) == 1){ // 0Ϊfalse , 1Ϊtrue
	//	putchar(c);
	//	c = getchar();
	//}
   
	// ͳ������
	//int c ;
	//int nl = 0 ;
	//while((c = getchar())!= EOF)
	//	if(c == '\n') {
	//	     ++nl;
	//	}
	//printf("%d",nl);

	// ��дһ������ ��ÿ��һ�����ʵķ�ʽ��ӡ������
	//int c ;
	//while((c = getchar())!=EOF){
	//	if(c == ' '){
	//	    putchar('\n'); 
	//	} else {
	//	    putchar(c);
	//	}
	//}

	// ��дһ������ ��ӡ�������ַ�����Ƶ�ʵ�ֱ��ͼ
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

	// ��������ַ�����
	//int len, max;
	//char line[MAXLINE];    // ��ǰ������ 
	//char longest[MAXLINE]; // ����������
	//max = 0;
	//while((len = getLine(line,MAXLINE)) >0){
	//	if(len > max){
	//		max = len;
	//		copy(longest,line);
	//	}
	//}
	//if(max > 0)
	//  printf("%s",longest);

	// �ַ�����ת
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
// �Զ��庯��
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
	s[i] = '\0'; // �ַ���ĩβ
	return i;
}

// ����
void copy(char to[] , char from[]){
	int i = 0 ;
	while((to[i] = from[i])!= '\0'){
	    ++i;
	}
}
// �ַ�����ת
void revser(char s[]){
	int i = 0;
	int j = 0 ;
	int k = 0;

	char to[MAXLINE]; // ����ַ���
	while(s[i]!='\0'){
	    i++;
	}
	// �����ַ������� �����Ƴ����س� Ȼ���Ƴ��������� �����Դ����������
	for(j = i-2 , k = 0;j >= 0 , k < i;j--, k++){
	    to[k] = s[j];
	}
	//k++;
	to[k] = '\0';
	printf("%s",to);
}

void testEnum(){
    // ö��
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
   // ���ȴ���ǰ��λ
   if(s[i]=='0'){
     ++i;
     if(s[i] == 'X' || s[i] == 'x')
       ++i;
    } else {
       printf("it is not true\n");
    }
   // ������������ 
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
		   s[j++] = s[i]; // ����ҵ�Ҫɾ�����ַ� �򲻸�ֵ��������һ���ַ���
		}
	}
	s[j] = '\0';
}

void strcat(char s[],char c[]){
    int i,j;
	i = j =0;
	while(s[i]!='\0') i++; // �ҵ���β
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
#include <stdio.h>
#define MAX 100
#define TRUE 0
#define FALSE 1
char* find_char(char ** strings , char c);
// ����ƥ���ַ���
char * find_string(char  * source , char  * chars);
// ɾ�����ϵ��ַ���
int del_substr(char *str,char *substr);
// ��ȡ�ַ�������
int strlen(char *s);
// �ַ�����ת
void reverse_string(char *string);
void main(){
	//int *p = NULL;
	//int *p2 = (int*)100; // ָ�볣��
	//if(p){
	//	int a = *p;
	//} 

	// ָ���ָ��
	//int **p ,a =10;
	//int *x = &a;
	//p = &x;
	//printf("%d",**p);
	//char* strings[3] = {"123","456","hello"};
	//char *string = find_char(strings,'5');
	//if(string !=NULL)
	//  printf("%s\n",string);
	//char source[] = {"changer"};
	//char chars[] = {"ng"};
	//char * s = find_string(source,chars);
	//printf("%s\n",s);
	// �ַ���ɾ�� 
	//char source[] = {"changer"};
    //char chars[] = {"r"};
	//del_substr(source,chars);
	//printf("%s\n",source);
	char source[] = {"123456"};
	reverse_string(source);
	printf("%s\n",source);
}

// ָ���ָ��
char* find_char(char ** strings , char c){
	int i;
	char *string , *cp;
	for(i=0, string = *strings;i<3; string = *++strings,i++){
		cp = string;
		while(*cp!='\0'){
			if(*cp++ == c){
				return string;
			}
		}
	}
	return NULL;
}

char * find_string(char  * source , char  * chars){
	char  *sourcecp , *charscp;
	for(;*source!='\0';source++){
		sourcecp = source;
		charscp = chars;
		while(*charscp!='\0' && *sourcecp!='\0' && (*sourcecp == *charscp))
			sourcecp++ , charscp++;
		if(*charscp=='\0')
			return source;
	}
	return NULL;
}

int del_substr(char *str,char *substr){
	char * endstr; // ��β�ַ���
	int len;
	char * string = find_string(str,substr);
	if(string == NULL)
		return 0;
	len = string - str;
	endstr = str + len + strlen(substr);
	// �н�β�ַ���
	if(*endstr != '\0'){
		str = str +len;
		while( *str++ = *endstr++)
			;
		*str = '\0';
	} else {
	    // �����޽�β
		*string = '\0';
	}
	return 0;
}

int strlen(char *s){
   int len = 0;
   while(*s++!='\0')
	   len++;
   return len;
}

void reverse_string(char *string){
    int i,j;
	char temp;
	int length = strlen(string);
	for(i=0,j = length-1;i<j;i++,j--){
	   temp = *(string+i);
	   *(string+i) = *(string+j);
	   *(string+j) = temp;
	}
}
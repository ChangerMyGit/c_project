#include <stdio.h>
#include <string.h>
int j; // Ĭ���ⲿ������ʼ��Ϊ��
int atoi(char []);// �ַ���ת��Ϊ����
int lower(int);// �ַ�תСд
int htoi(char []);//ʮ������ת��
void squeeze(char [] ,char);//ɾ�����ڵ��ַ�
void squeeze2(char [] ,char[]);//ɾ�����ڵ��ַ�
int charat(char [],char); //�ַ�����
void strcopy(char [],char []);//�ַ�������
int any(char [],char []);//�ַ�������
main(){
	
	// ��д�������͵�ȡֵ��Χ
	//printf("unsigned char length %d\n",(1<<8)-1);
	//printf("signed char length %d\n",(1<<7)-1);
	//printf("unsigned int length %d\n",(1<<16)-1);
	//printf("signed int length %d\n",(1<<15)-1);

    //printf("unsigned float length %lu\n",(unsigned long)~0);
	//printf("signed float length %lu\n",((signed long)~0)>>1);
	//enum boolen{YES,NO};
	//printf("%c",'\012'); // 012 8���� 0xa 16����
	//printf("%d  %d\n",YES,j);
    //printf("%d",10 - 1 % 1);
	//printf("%d\n",atoi("1234f1"));
	//printf("%c\n",lower('D'));
	//printf("%d\n",htoi("7C89A"));
	
	//char str[] = "aaabbbccc";
	//char c = 'c';
	//squeeze(str,c);
	//printf("%s\n",str);

    //char s[] = "123";
	//char t[] = "456";
	//strcopy(s,t);
	//printf("%s\n",s);

	//char s[] = "1234567x89";
	//char t[] = "567x";
	//squeeze2(s,t);
	//printf("%s\n",s);
	//printf("%d\n",any(s,t));
	//printf("%c\n",lower('S'));
	printf("%c",lower('A'));
}

int atoi(char s[]){
	int n,i;
	n = 0;
	for(i=0;s[i]!='\0';i++){
	   if(s[i] >= '0' && s[i] <= '9')
		 n = n*10 + (s[i] - '0');
	}
	return n;
}

// Ĭ�ϲ���ǰ׺
int htoi(char s[]){
   int n,i;
   n = 0;
   for(i = 0;s[i]!='\0';i++){
      if(s[i] >= '0' && s[i] <= '9')
		 n = n*16 + (s[i] - '0');
	  else if(s[i] >= 'a' && s[i] <= 'f'){
	     n = n*16 + (s[i] - 'a') + 10;
	  }
	  else if(s[i] >= 'A' && s[i] <= 'F'){
	     n = n*16 + (s[i] - 'A') + 10;
	  }
   }
   return n;
}

// ֻ��ASC|| ����Ч
int lower(int c){
  // if(c >='A' && c <= 'Z')
	 //return c + 'a' - 'A'; // Сд���д��ASC�ַ����еļ����ͬ
  // else
	 //return c;
	return (c >='A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

void squeeze(char str[] ,char c){
	int i,j;
	for(i=j=0;str[i]!='\0';i++)
		if(str[i]!=c)
			str[j++] = str[i];
	str[j] = '\0';
}

void strcopy(char s[],char t[]){
   int i = 0,j=0;
   while(s[i]!='\0')
	   i++;
   while(s[i++] = t[j++])
	   ;
}

int charat(char s[],char t){
	int i = 0;
	while(s[i]!='\0'){
	   if(s[i]== t) 
		  return -1;
	   i++;
	}
	return 1;
}

void squeeze2(char s[] ,char t[]){
	int i , j;
	for(i = j = 0 ;s[i]!='\0';i++){
		if(charat(t,s[i])>0){ // ��������д�� ��ʹ�ö�������� ��ʡ�ռ�
		   s[j++] = s[i];
		}
	}
	s[j] = '\0';
}

int any(char s[],char t[]){
   int i,j,k;
   for(i=0;s[i]!='\0';i++){
       j = i; // s�ĵ�ǰλ��
	   k = 0; // t�ĵ�ǰλ��
	   while(s[j++] == t[k++] && t[k]!='\0')
		   ;// ���α����Ƿ�ƥ��
	   if(t[k] == '\0')
		 return i;
   }
   return -1;
}
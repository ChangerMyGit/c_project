#include<stdio.h>
void deblank(char string[]);
void substr(char dist[] , char src[], int start , int len); // �ַ���ǰ��
void main(){
	//enum Liquid {QUART = 1,PINT = 16};
	//enum Liquid jar = QUART;
	//printf("%s \n",jar);
	char string[] = "a     asd    asdas       asdasd";
	deblank(string);
	//char dist[20];
	//char src[] = "changer";
	//substr(dist,src,2,3);
	//printf("%s",dist);
}
// ����ո� �ĳ� �����ո�
void deblank(char string[]){
   int current ,next;
   int i,j;
   for(i = 0 , j = 0 ;string[i]!='\0';i++){
       //current = string[i];
       //next = string[i+1];
	   // �ҵ������ո� ������ǰ��һλ
	   if(string[i] ==' ' && string[i+1] == ' '){
           j = i;
		   for(j = i;string[j]!='\0';j++){
		        string[j] = string[j+1];
		   }
		   i--; // ����ֱ�����������пո�
	   }
   }
   printf("%s",string);
}

void substr(char dist[] , char src[], int start , int len){
	int i , j;
	for(i = start-1,j =0;src[i] && j < len;i++,j++){
	    dist[j] = src[i];
	}
	if(j>0)
	 dist[++j] = '\0';
	else dist[j] = '\0';
}
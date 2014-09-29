#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAXWORD 100
#define HASHSIZE 101
static struct nlist *hashtable[HASHSIZE]; // HashTable����

int getword(char * ,int); // ��ȡ����ĵ���
struct key *binsearch(char * ,struct key * ,int); // ���ֲ���
unsigned hash(char *); // hash�㷨
struct nlist *lookup(char *); // ���ҷ��� ���Ȳ���hashֵ ������� ������������name��ͬ��Ԫ��
struct nlist *install(char *);// �������� 
void undef(char *);// ɾ��
/**
   �ṹ��
**/
struct point {
   int x;
   int y;
};

struct changer {
   int age;
   char *name;
   int sex;
};

struct key {
   char *word;
   int count;
};

struct nlist {
   struct nlist * next; // ��һ���ڵ�
   char *name;
};
void main(){
	//struct point p1 = {100,200}; // ���ṹ��ǵ�����
	//struct {int y;char s;} ns; // ��ʹ�ýṹ��ǵ�����
	//struct changer cc = {34,"lyb",0};
	//// printf("%d ; %d ; %f\n",p1.x , p1.y, p1.x + 10.00);
	//struct point *p ;
	//struct point *p2 ;
	//p2 = &p1;
	//p = &p1;
	//printf("%d ; %d\n",p->x , p->y);
	//printf("%d ; %d ; %f\n",p1.x , p1.y, p1.x + 10.00);
	//printf("%d\n" ,sizeof cc);
	//printf("%d\n" ,++p->x);
	//printf("%d\n" ,p - p2); // ָ��ļӷ�����Ƿ� ����������Ϸ�
	// ------------------------------��
	//char word[MAXWORD];
	//struct key *p;
	//// ��ʼ���ṹ������
	//struct key keytab[] = {"auto",0,"break",0,"case",0,"char",0,"int",0}; 
	//// ��ȡ������ַ���
	//while(getword(word,MAXWORD)!=-1)
	//	;
	//if((p = binsearch(word,keytab,5)) != NULL){
	//	p->count++;
	//}
	//// ָ�����
	//for(p = keytab;p<keytab+5 ;p++){
	//	printf("%s %d\n",p->word,p->count);
	//}
	// ------------------------------>
	
	// HashMap C����ʵ�� 
	//struct nlist nl = {NULL,"changer"};
	//struct nlist *np;
	//hashtable[8] = &nl;
	//printf("%s\n",lookup("changer") == NULL ? "������" : lookup("changer")->name);
	char word[MAXWORD];
	while(getword(word,MAXWORD)!=-1);
	install(word);
	undef(word);
	printf("%s\n",lookup(word) == NULL ? "������" : lookup(word)->name);
}

int getword(char *word ,int n){
   int c;
   // ʹ��wile ������if ָ����Ϊ���� ������
   while((c = getchar())!=EOF ){
	  if(c == '\n'){
		 *word = '\0';
	     return -1;
	  } else {
	     *word++ = c;
	  }
   }
}
// ���ֲ���
struct key *binsearch(char *word ,struct key *tab ,int n){
	int cond;
	struct key *low = &tab[0]; // ȡ�׵�ַ
	struct key *high = &tab[n-1]; // β��ַ
	struct key *mid ;
	while(low <= high){
	    mid = low + (high - low) /2 ; //ָ��ӷ������ǷǷ��ģ����Ǽ�������Ϸ� ���ȼ����ָ��֮��Ĳ�����������ǰ�ƶ�
		if((cond = strcmp(word,mid->word)) <0 ){
		    high = mid - 1;
		} else if(cond > 0){
		    low = mid + 1 ;
		} else 
			return mid;
	}
	return NULL;
}

unsigned hash(char *s){
	unsigned hashval;
	for(hashval=0;*s!='\0';s++){
	   hashval = *s + 31 * hashval;
	}
	return hashval % HASHSIZE;
}

struct nlist *lookup(char *s){
	struct nlist *p = hashtable[hash(s)];
	if(p == NULL) return NULL;
	else {
		while(p->next!=NULL){
			if(strcmp(s,p->name) == 0){
				return p;
			} else {
				p = p->next;
			}
		}
	}
}

struct nlist *install(char *s){
   struct nlist *p;
   if((p = lookup(s))==NULL){
       p = (struct nlist *) malloc(sizeof(*p)); // �����ṹ��
	   p->name = s;
	   hashtable[hash(s)] = p;
   }
   return p;
}

void undef(char *s){
	 struct nlist *p;
	 if((p = lookup(s))!=NULL){
		free(p);
	    hashtable[hash(s)] = NULL;
	 }
}
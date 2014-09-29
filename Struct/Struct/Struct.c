#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAXWORD 100
#define HASHSIZE 101
static struct nlist *hashtable[HASHSIZE]; // HashTable数组

int getword(char * ,int); // 获取输入的单词
struct key *binsearch(char * ,struct key * ,int); // 二分查找
unsigned hash(char *); // hash算法
struct nlist *lookup(char *); // 查找方法 首先查找hash值 如果存在 遍历链表，查找name相同的元素
struct nlist *install(char *);// 新增方法 
void undef(char *);// 删除
/**
   结构体
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
   struct nlist * next; // 下一个节点
   char *name;
};
void main(){
	//struct point p1 = {100,200}; // 带结构标记的声明
	//struct {int y;char s;} ns; // 不使用结构标记的声明
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
	//printf("%d\n" ,p - p2); // 指针的加法运算非法 ，减法运算合法
	// ------------------------------〉
	//char word[MAXWORD];
	//struct key *p;
	//// 初始化结构体数组
	//struct key keytab[] = {"auto",0,"break",0,"case",0,"char",0,"int",0}; 
	//// 获取输入的字符串
	//while(getword(word,MAXWORD)!=-1)
	//	;
	//if((p = binsearch(word,keytab,5)) != NULL){
	//	p->count++;
	//}
	//// 指针遍历
	//for(p = keytab;p<keytab+5 ;p++){
	//	printf("%s %d\n",p->word,p->count);
	//}
	// ------------------------------>
	
	// HashMap C语言实现 
	//struct nlist nl = {NULL,"changer"};
	//struct nlist *np;
	//hashtable[8] = &nl;
	//printf("%s\n",lookup("changer") == NULL ? "无数据" : lookup("changer")->name);
	char word[MAXWORD];
	while(getword(word,MAXWORD)!=-1);
	install(word);
	undef(word);
	printf("%s\n",lookup(word) == NULL ? "无数据" : lookup(word)->name);
}

int getword(char *word ,int n){
   int c;
   // 使用wile 而不是if 指针作为参数 会重置
   while((c = getchar())!=EOF ){
	  if(c == '\n'){
		 *word = '\0';
	     return -1;
	  } else {
	     *word++ = c;
	  }
   }
}
// 二分查找
struct key *binsearch(char *word ,struct key *tab ,int n){
	int cond;
	struct key *low = &tab[0]; // 取首地址
	struct key *high = &tab[n-1]; // 尾地址
	struct key *mid ;
	while(low <= high){
	    mid = low + (high - low) /2 ; //指针加法运算是非法的，但是减法运算合法 首先计算出指针之间的差，在用这个差往前移动
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
       p = (struct nlist *) malloc(sizeof(*p)); // 声明结构体
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
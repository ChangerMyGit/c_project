#include<stdio.h>
#include <stdlib.h>
#include <string.h>
// 结构也是值传递
struct point {
   int x;
   int y;
};

struct nlist {
   char *name;
   struct nlist *next;
};

#define HASHSIZE 100
static struct nlist *hashTable[HASHSIZE];
unsigned hash(char *s); // 计算hash值
struct nlist *lookup(char *s);  // 查找方法
struct nlist *install(char *s); // 添加方法
void undef(char *s);// 删除
int any(char *s , char *t);
int anyend(char *s , char *t);
main(){
	//struct point ps[10] = {{1,2},{2,3},{3,4},{4,5},{5,6}};// 结构体数组
	//struct point p = {1,2};
	//struct point *p2 = (struct point *)malloc(sizeof (struct point));
	//int size = sizeof(ps)/sizeof(struct point);
	//printf("%d %d\n",p.x,p.y);
	//printf("%d %d\n",ps[1].x,ps[1].y);
	//printf("%x\n",p2);
	// 指针遍历
	//struct point *np ;
	//for(np = ps;np<ps+size;np++){
	//	printf("%d\n",np->x);
	//}
	// 模拟哈希表
	//install("changer");
	//install("hello");
	//install("world");

	//printf("%s\n",lookup("changer")->name);
	//undef("changer");
	//printf("%s\n",lookup("changer")->name);
	//struct Y { int a; char b;  char d;int c;};
	//printf("%d\n", sizeof(struct Y));
	//char *p = (char *)malloc(10*sizeof(char));
	//int i;
	//for(i=0;i<10;i++){
	//   *p++ = i + '0';
	//}
	//*p = '\0';
	//printf("%s\n",p - 10);
	//int c;
	//while((c = getchar())!=EOF){
	//   putchar(c);
	//}
	//int day,year;
	//char monthname[20];
	//scanf("%d %s %d",&day,monthname,&year);
	//printf("%d %s %d",day,monthname,year);
	//int c;
	//FILE *fp = fopen("hello.c","r");
	//FILE *sout = fopen("test.c","w");
	//while((c = getc(fp))!=EOF){
	//	putc(c,sout);
	//   //putchar(c);
	//}
	//fclose(fp);
	//fclose(sout);
	//printf("%d\n",sizeof(unsigned));
    //printf("%d\n",anyend("changerrger","ger1"));
	#if 0
	  	int i = 5,q;
	    q = (++i) + (++i) +(++i);
	    printf("%d %d",i,q);
	#endif
} 

unsigned hash(char *s){
  unsigned hashval;
  for(hashval = 0;*s!='\0';s++)
    hashval =  *s + 31 * hashval;
  return hashval % HASHSIZE;
}

struct nlist *lookup(char *s){
   struct nlist *np = hashTable[hash(s)];
   while(np!= NULL){
	   if(strcmp(s,np->name) == 0)
		  return np;
	   else 
		   np = np->next;
   }

   return NULL;
}

struct nlist *install(char *s){
	struct nlist *nowp ;
   // 声明结构体指针
	struct nlist *np = (struct nlist *)malloc(sizeof (struct nlist));
	np->name = s;
	nowp = hashTable[hash(s)];
	if(nowp == NULL)
		hashTable[hash(s)] = np;
	else {
		while(nowp->next!=NULL)
			nowp = nowp->next;
		nowp->next = np;
	}
	return np;
}

void undef(char *s){
  struct nlist *np = lookup(s);
  if(np!= NULL){
	  free((void *)np->name);
	  free((void *)np->next);
	  free((void *)np);
  }
}

int any(char *s , char *t){
  int i;
  char *cs;
  char *ct;
  for(i=0;*s;s++,i++){
     cs = s;
	 ct = t;
	 for(;*cs == *ct;cs++,ct++)
		 ;
	 if(*ct == '\0')
		 return i;
  }
  return -1;
}

int anyend(char *s , char *t){
   int i , j;
   char *cs ,*ct ;
   int lens = strlen(s);
   int lent = strlen(t);
   s = s + lens - 1;
   t = t + lent - 1;
   for(i = lens ; i>0;s--,i--){
      cs = s;
	  ct = t;
	  for(j = lent;*cs == *ct;cs--,ct--,j--)
		  ;
	  if(j ==0)
		  return i - lent +1;
   }
   return -1;
}
#include <stdio.h>
#define YEAR (365*24*60*60)UL
#define max(A,B) (A > B ? (A):(B))
void main(){
	//int x = 100,y =20;
	//int array[10] = {1,2,3,4,5,6,7,8,9,0};
	//int *ap = array +2;
	//int (*p)[10] = &array;
	//char *strings[] = {"123","456","789",NULL};
	//char string[] = "changer";
	//int * const a = &x;
	//printf("%d %d \n",ap[-1],2[ap]);
	//printf("%d \n",*(*p)+3);
	//char *s = *strings;
	//printf("%s \n",s);
	// 指针数组 要使用指针的指针
	//char **s ;
	//for(s = strings;*s!=NULL;s++){
	//    printf("%s \n",*s);
	//}
	// 使用下标
	//char *s;
	//int i;
	//for(i=0;i<3;i++){
	//   s = strings[i];
	//   printf("%s \n",s);
	//}
	unsigned int a=6; 
	unsigned int b = 20; 
	
	unsigned int x = a - b;
	printf("%d\n",max(1,3)); 
}
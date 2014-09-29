#include <stdarg.h>
#include <stdio.h>
#include <Windows.h>

void minprintf(char *, ...);
void filecopy(FILE *,FILE *);//�ļ�����
void main(void){
	// minprintf("%s\n","changer");
	// minprintf("%d\n",200);
	// minprintf("%c\n",'A');
	// ���׼����� ʹ�����뺯��
	// double sum ,v;
	// sum = 0;
	// while(scanf("%lf",&v) == 1)
	//	 printf("%.2f",sum+=v);
	//FILE *fp; // �ļ�ָ��
	//char s[100];
	//int c;
	//if((fp = fopen("file.c","r"))!=NULL){
	//   while((c = getc(fp))!=EOF)
	//	   putchar(c);
	//   fclose(fp);
	//} else {
	//	fprintf(stderr,"%s");
	//}
	//if((fp = fopen("file.c","r"))!=NULL){
	//	while(fgets(s,100,fp)!=NULL){
	//	  printf("%s\n",s);
	//	}
	//	fclose(fp);
	//}

	//if(argc == 1){
	//	filecopy(stdin,stdout);
	//} else {
	//	while(--argc > 0){
	//		if((fp = fopen(*++argv,"r"))!=NULL){
	//		   printf("can,t open %s",*argv);
	//		   return 1;
	//		} else {
	//		   filecopy(fp,stdout);
	//		   fclose(fp);
	//		}
	//	}
	//}
	// system("start notepad"); // �첽�򿪼��±�
	printf("hello\n");
	// getchar();
}

void minprintf(char *fmt, ...){
   va_list ap; // ����ָ��ÿ����������
   char *p , *sval;
   int ival;
   double dval;
   char cval;
   va_start(ap,fmt); // ��apָ���һ����������
   for(p = fmt;*p;p++){
	   if(*p != '%'){
	      putchar(*p);
		  continue;
	   }
	   switch(*++p){
	     case  'd':
           ival = va_arg(ap,int);
		   printf("%d",ival);
		   break;
	     case  'f':
           dval = va_arg(ap,double);
		   printf("%f",ival);
		   break;
	     case  'c':
           cval = va_arg(ap,char);
		   printf("%c",cval);
		   break;
	     case  's':
			 for(sval = va_arg(ap,char *);*sval;sval++){
			      putchar(*sval);
			 }
		   break;
		 default :
			 putchar(*p);
			 break;
	   }
   }
}

void filecopy(FILE * ifp ,FILE * ofp){
	int c;
	while((c = getc(ifp))!=EOF){
	   putc(c,ofp);
	}
}
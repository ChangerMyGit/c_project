#include <stdio.h>
#define MAXLINE 100	
int getLine(char line[]);
void copyMaxLine(char line[],char maxLineNum[]);
void main(){
   //int c , checkSum = 0;
   //while((c = getchar())!=EOF){
   //    checkSum += c;
	  // putchar(c);
   //}

   //printf("%d",checkSum);
	char line[MAXLINE];
	char maxLine[MAXLINE];
	int c,lineNum = 0 , maxLineNum = 0;
	while((lineNum = getLine(line)) > 0){
		if(lineNum > maxLineNum){
		   maxLineNum = lineNum;
		   copyMaxLine(line,maxLine);
		}
		printf("%s", maxLine);
	}
}

int getLine(char line[]){
	int c , i = 0;
	while((c = getchar())!=EOF && c!='\n' && i < MAXLINE){
	    line[i++] = c;
	}
    line[i] = '\0';
	return i;
}

void copyMaxLine(char line[],char maxLineNum[]){
	 int i;
	 for(i = 0;line[i]!='\0';i++){
	     maxLineNum[i] = line[i];
	 }
	 maxLineNum[i++] = '\n';
	 maxLineNum[i] = '\0';
}
#include <stdio.h>
#include <string.h>
char const * my_strstr(char const * str,char const * search); // 返回最右侧符合记录的值
void my_strcpy(char dist[]  , char orc[]); // 防止字符溢出
void my_strcat(char * dist  , char * orc, int len); // 防止字符溢出
char * my_str_end(char *dist,char*orc);//指向末尾指针
char const * my_strrchr(char const *str ,int ch);
int count_chars(char const *str,char const *chars);// 返回包含字符的数量
int palindrome(char *string);//判断回文数
void main(){
    //char string[40] = "Hello there ,honey , there honey";
	//char const *ans;
	////ans = strchr(string,'h');
	//ans = my_strstr(string,"there");
	//printf("%s\n",ans);
	//char input[16]="abc,d";
    //char *p;
	//p = strtok(input,",");
	//if(p)
	//  printf("%s\n",p);
	//p = strtok(NULL,",");
    //if(p)
	//  printf("%s\n",p);
	//int temp[10] = {1,2,3,4,5};
	//int values[10] = {8,8,8,8,8,9,0,10,11,12};
	//// 默认长度使用字节 
	//memcpy(values,temp,sizeof(int) * 5);
	//printf("%d\n",values);
	//char dist[5] = "chan";
	//char orc[50] = "hahahaha";
	//my_strcpy(dist,orc);
	//printf("%s\n",dist);
	//char dist[10] = "chan";
	//char orc[50] = "hahahahaasdasdasdasdas";
	//my_strcat(dist,orc,9);
	//printf("%s\n",dist);
	//char dist[50] = "chan";
	//char orc[50] = "hahahaha";
	//printf("%s\n",my_str_end(dist,orc));
	//char *dist = "changergerger";
	//printf("%s\n",my_strrchr(dist,'g'));
	//char *str = "changer hello ok hello1";
	//char *chars = "hello1";
	//printf("%d\n",count_chars(str,chars));
	printf("%d\n",palindrome("1234321"));
}

char const * my_strstr(char const * str,char const * search){
     char const * current;
	 char const * last;
	 current = strstr(str,search);
	 while(current!=NULL){
	    last = current;
		// 前移一位 查看后面的是否还有匹配的字符串（前移的话 之前的字符串就不符合）
	    current = strstr(last+1,search); 
	 }
	 return last;
}

void my_strcpy(char dist[]  , char orc[]){
	int i;
	for(i=0;orc[i]!='\0' && dist[i]!='\0';i++){
	    dist[i] = orc[i];
	}
}

void my_strcat(char * dist  , char * orc, int len){
	while(*dist){
	   dist++;
	   len--;
	}
	while(*orc && len >0){
	   *dist++ = *orc++;
	   len--;
	}
	*dist = '\0';
}

char * my_str_end(char *dist,char*orc){
	   while(*dist++ = *orc++)
		   ;
	   return dist -1;
}

char const * my_strrchr(char const *str ,int ch){
	char const * last;
	char const * current =  strchr(str,ch);
	while(current!=NULL){
	   last = current;
	   current = strchr(last+1,ch);
	}
	return last;
}

int count_chars(char const *str,char const *chars){
    int count = 0;
   	char const * last;
	char const * current = strstr(str,chars);
	while(current!=NULL){
	    count++;
		last = current;
		current = strstr(last+1,chars);
	}
	return count;
}

int palindrome(char *string){
	int len = strlen(string);
	char * last = string + len-1;
	while(*last == *string && len >0){
	    last--;
	    string++;
		len--;
	}
	if(len ==0)
		return 1;
	return 0;
}
#include <ctype.h>
int testFcuntion(){
   return 1;
}

double atof(char s[]){
    /** 
	   ���������裬����С����֮ǰ��֮��
	   123.45 �������12345 Ȼ�� ����100
	**/
	double val,power;
	int i ,sign;
	for(i=0;isspace(s[i]);i++)
		;
	sign = (s[i] == '-')?-1:1;
	if(s[i] == '+' || s[i] == '-') i++;
	// ѭ��С����֮ǰ
	for(val = 0.0;isdigit(s[i]);i++){
	    val = val * 10.0 + (s[i] - '0');
	}
	if(s[i] == '.') i++;
	// ѭ��С����֮��
	for(power = 1.0 ;isdigit(s[i]);i++){
	   val = val * 10.0 + (s[i] - '0');
	   power *= 10.0;
	}

	return sign* val / power;
}
#include <ctype.h>
int testFcuntion(){
   return 1;
}

double atof(char s[]){
    /** 
	   分两个步骤，处理小数点之前和之后
	   123.45 首先算出12345 然后 除以100
	**/
	double val,power;
	int i ,sign;
	for(i=0;isspace(s[i]);i++)
		;
	sign = (s[i] == '-')?-1:1;
	if(s[i] == '+' || s[i] == '-') i++;
	// 循环小数点之前
	for(val = 0.0;isdigit(s[i]);i++){
	    val = val * 10.0 + (s[i] - '0');
	}
	if(s[i] == '.') i++;
	// 循环小数点之后
	for(power = 1.0 ;isdigit(s[i]);i++){
	   val = val * 10.0 + (s[i] - '0');
	   power *= 10.0;
	}

	return sign* val / power;
}
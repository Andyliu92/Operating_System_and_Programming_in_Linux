#include <stdio.h>

#define STR_LEN 1000

void main(){
	int i;
	char s[STR_LEN];
	scanf("%s", s);
#ifdef CONVERT
	for(i = 0; i < STR_LEN; i++){
		if(s[i] >= 65 && s[i] <= 90){
			s[i] += 32;
		}
		else if(s[i] >=97 && s[i] <= 122){
			s[i] -= 32;
		}
	}
	
	printf("%s\n", s);
#else
	printf("201180078\n");
#endif
}

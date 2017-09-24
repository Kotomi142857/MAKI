#include <stdio.h>
#include <string.h>

int main(){
	char a[100] = "1/2/3/4/5/6/7/8/9/0";
	char b[] = "/";
	char *start = strtok(a, b);
	while(start != NULL){
		printf("%s\n", start);
		start = strtok(NULL, b);
	}
	return 0;
} 

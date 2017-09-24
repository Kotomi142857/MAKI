#include <stdio.h>

int main(){
	char a[10] = "2017-9-16", k[10];
	int b, c, d;
	sscanf(a, "%d-%d-%d", &b, &c, &d);
	sprintf(k, "%d/%d/%d", b, c, d);
	printf("%s\n", k);
	return 0;
}

#include <stdio.h>

void change(int *a, int b){
	if(a[b] <= a[(b - 1) / 2]){
		return;
	}
	int temp = a[b];
	a[b] = a[(b - 1) / 2];
	a[(b - 1) / 2] = temp; 
	change(a, (b - 1) / 2);
	return;
}
int main(){
	int N, num;
	scanf("%d", &N);
	int arr[N];
	for(int i = 0; i < N; i++){
		scanf("%d", &num);
		arr[i] = num;
		change(arr, i);
	}
	for(int i = 0; i < N; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}


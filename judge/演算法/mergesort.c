#include <stdio.h>

void mergesort(int *a, int start, int middle, int end){
	int x = start;
	int y = middle + 1;
	int b[end - start + 1];
	for(int i = 0; i < end - start + 1; i++){
		if(a[x] < a[y]){
			if(x == middle + 1){
				b[i] = a[y];
				y++;
			}
			else{
				b[i] = a[x];
				x++;
			}
		} 
		else{
			if(y == end + 1){
				b[i] = a[x];
				x++;
			}
			else{
				b[i] = a[y];
				y++;
			}
		}
	}
	for(int i = start; i <= end; i++){
		a[i] = b[i - start]; 
	}
}
void merge(int *a, int start, int end){
	if(start == end){
		return;
	}
	int middle = (start + end) / 2;
	merge(a, start, middle);
	merge(a, middle + 1, end);
	mergesort(a, start, middle, end);
}
int main(){
	int array[11] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
	merge(array, 0, 10);
	for(int i = 0; i < 10; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
} 

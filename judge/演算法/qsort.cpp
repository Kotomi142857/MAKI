#include <stdio.h>

void quicksort(int *a, int start, int end){
	//printf("%d %d\n", start, end);
	if(start >= end){
		return;
	}
	int left = start, change;
	int x = left;
	int right = end + 1;
	int y = right;
    while(right > left){
    	int flag1 = 0, flag2 = 0;
    	//printf("%d %d\n", left, right);
    //	for(int i = x; i <= y; i++){
    //		printf("%d ", a[i]);
	//	} 
		//printf("\n"); 
    	for(int i = left + 1; i <= right - 1; i++){
    		if(a[i] > a[start]){
    			left = i;
    			flag1 = 1;
				break;
			}
		}
		if(!flag1){
			a[start] ^= a[right - 1] ^= a[start] ^= a[right - 1];
			change = end;
			break;
		}
		for(int i = right - 1; i >= left + 1; i--){
			if(a[i] < a[start]){
				right = i;
				flag2 = 1;
				break;
			}
		}
		if(!flag2){
			change = left - 1;
			a[start] ^= a[change] ^= a[start] ^= a[change];
			break;
		}
		//printf("%d %d\n", a[left], a[right]); 
		a[left] ^= a[right] ^= a[left] ^= a[right];
	}
	//for(int i = x; i <= y; i++){
	//	printf("%d ", a[i]);
//	}
	//printf("\n");
	//for(int i = start; i < change; i++){
	//	printf("%d ", a[i]);
//	}
	//printf("\npivot = %d\n", a[change]);
	//for(int i = change + 1; i <= end; i++){
	//	printf("%d ", a[i]);
	//}
//	printf("\n\n");
	quicksort(a, start, change - 1);
	quicksort(a, change + 1, end);
}
int main(){
	int array[11] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
	quicksort(array, 0, 10);
	for(int i = 0; i < 11; i++){
		printf("%d ", array[i]);
	}
	return 0;
}

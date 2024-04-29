#include <stdio.h>
#include <stdlib.h>

int *num;

int max(int a, int b){
	if (a >= b){
		return a;
	}
	else {
		return b;
	}
}

int LIS_recursive(int i){
	if (i == 0){
		return 1;
	}
	else {
		int big = 1;
		for (j = 0; j < i; j++){
			if (num[j] < num[i]){
				big = max(big, LIS_recursive(j) + 1);
			}
		}
	}
	return big;
}

int biggest_sub_sequence(int n){
	int big = 1;
	for (int i = 0; i < n; i++){
		big = max(big, LIS_recursive(i));
	}
	return big;
}
int main(){
	return EXIT_SUCCESS;
}

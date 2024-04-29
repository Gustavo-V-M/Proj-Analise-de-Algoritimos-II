#include <stdio.h>
#include <stdlib.h>
#define EXIT_SUCCESS 0


void selectiona_atividade(int s[], int t[], int n, int *A){
	// Sort t (qsort)
	int a_index = 0;
	A[a_index] = 1;
	int j = 0;
	for (int i = 1; i < n; n++){
		if (s[i] >= t[j]){
			a_index++;
			A[a_index] = j;
			j = i;
		}
	}
}
int main(){
	// nao tive tempo para implementar direito 
	return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#define EXIT_SUCCESS 0

int parada(int P[], int n, int delta, int *U){
	int u_index = 0;
	U[u_index] = P[0];
	int last_pos = P[0];
	for (int i = 1; i < n; i++){
		if (P[i] - last_pos > delta){
			last_pos = P[i-1];
			u_index++;
			U[u_index] = last_pos;
		}
	}
	u_index++;
	U[u_index] = P[n-1];
	return u_index+1;
}

int main(int argc, int argv[]){
	int n = 4;
	int delta = 2;
	int p[] = {1,2,3,5,6,7};
	int *u = (int*)malloc(n * sizeof(int));
	int u_size = parada(p, n, delta, u);
	for (int i = 0; i < u_size; i++){
		printf("%i\n", u[i]);
	}

	free(u);
	
	

}


#include <stdio.h>
#include <stdlib.h>

int *salto_sapo(p, n, delta){
	int *u = (int*)malloc(n * sizeof(int));
	int u_index = 0;
	int ultima_pos = p[0];
	for (int i = 1; i < n; i++){
		if (p[i] - ultima_pos > delta){
			ultima_pos = p[i-1];
			u[u_index] = p[i-1];
			u_index++;
		}
	}
	u[u_index] = p[n];
	return u;
}

int main(int argc, int argv[]){
	return EXIT_SUCCESS
}

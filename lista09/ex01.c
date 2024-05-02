#include <stdio.h>
#define EXIT_SUCCESS 0

int fat(int n) {
	if (n == 0 || n == 1){
		return n;
	}
	else {
		return n * fat(n-1);
	}
}

int soma_fatoriais(int n){
	int soma = 0;
	for (int i = n-1; i > 0; i--){
		int f = fat(i);
		if ( (n - f) >= 0 ){
			soma++;
			n -= f;
			
		}
	}
	return soma;
}
int main(){
	int n = 10;

	int test = soma_fatoriais(n);
	printf("%i\n", test);
	return EXIT_SUCCESS;
}

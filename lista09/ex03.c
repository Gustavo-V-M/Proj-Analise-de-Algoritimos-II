#include <stdio.h>
#define EXIT_SUCCESS 0
#define MINUS_INF  -999999

int corredor(int csize, int corredor[csize]){
	int big = MINUS_INF;
	int sum = 0;
	for (int i = 0; i < csize; i++){
		sum += corredor[i];
		if (sum >= big){
			big = sum;
		}
		if (sum < 0){
			sum = 0;
		}

		}
	return big;
		
	}
int main(){
	int csize = 7;
	int corr[] = {-2, 5, -1, 8, -11, 7, 3};
	int test = corredor(csize, corr);
	printf("%i\n", test);
	return EXIT_SUCCESS;
}

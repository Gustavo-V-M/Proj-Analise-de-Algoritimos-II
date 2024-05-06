#include <stdio.h>
#define NEG_INF -9999


int restaurante(int start[], int end[], int size){
	int count = 1;
	int cur_end = end[0];
	for (int i = 0; i < size; i++)
	{
		if (start[i] > cur_end){
			cur_end = end[i];
			count++;
		}
	}
	return count;
}
int main(){
	int start[] = {1,2,3,4,5};
	int end[] = {2,3,4,5,6};
	int n = 5;
	int test = restaurante(start, end, n);
	printf("%i\n", test);

}

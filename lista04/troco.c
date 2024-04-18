#include <stdio.h>
#include <stdlib.h>
#define EXIT_SUCCESS 0
void change(int n, int x, int V[x], int *S) {
  int sum = 0;
  int i = 0;
  int j = x - 1;
  while (j >= 0 && sum < n) {
    // V[x] is assumed to be sorted
    int m = V[j];
    if (sum + m <= n) {
      sum += m;
      S[i] = m;
      i++;
    } else {
      j -= 1;
    }
  }
}

void change_backtracking(int n, int x, int V[x], int *S, int sum, int i) {
  if (sum == n) {
    for (int j = 0; j < i; j++) {
      printf("%i", S[j]);
    }
    printf("\n");
  } else {
    sum += V[x - 1];
    if (sum <= n) {
      S[i] = V[x - 1];
      i++;
      change_backtracking(n, x, V, S, sum, i);
    } else {
      sum -= V[x - 1];
      change_backtracking(n, x - 1, V, S, sum, i);
    }
  }
}

int main(int argc, char *argv[]) {

  int n = 12;
  int V[3] = {1, 2, 5};

  printf("Guloso: ") int *S = (int *)malloc(3 * sizeof(int));
  change(12, 3, V, S);
  for (int i = 0; i <)
    printf("\n");
  free(S);
  return EXIT_SUCCESS;
}

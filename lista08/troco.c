#include <stdio.h>
#include <stdlib.h>
#define INF 999999999

int *moedas;
int *memo;
int min(int a, int b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}
int conta_moedas_recursive(int t, int n, int small) {
  if (t == 0) {
    return 0;
  } else if (t < 0) {
    return INF;
  } else {
    for (int i = 0; i < n; i++) {
      small = min(small, conta_moedas_recursive(t - moedas[i], n, small) + 1);
    }
    return small;
  }
}

int conta_moedas_topdown(int t, int n, int small) {
  if (t == 0) {
    return 0;
  } else if (t < 0) {
    return INF;
  } else if (memo[t] != -1) {
    return memo[t];
  } else {
    for (int i = 0; i < n; i++) {
      small = min(small, conta_moedas_topdown(t - moedas[i], n, small) + 1);
    }
    memo[t] = small;
    return small;
  }
}

int conta_moedas_bottomup(int t, int n) {
  int troco[t];
  for (int i = 0; i < t; i++) {
    troco[i] = INF;
  }
  troco[0] = 0;
  for (int i = 0; i < t; i++) {
    for (int j = 0; j < n; j++) {
      if (i >= moedas[j]) {
        troco[i] = min(troco[i], troco[i - moedas[j]] + 1);
      }
    }
  }
  return troco[t - 1];
}

int main(int argc, char *argv[]) {
  int t = 8;
  int n = 3;

  moedas = (int *)malloc(n * sizeof(int));
  memo = (int *)malloc(t * sizeof(int));

  moedas[0] = 1;
  moedas[1] = 4;
  moedas[2] = 6;

  for (int i = 0; i < t; i++) {
    memo[i] = -1;
  }

  int test_recursivo = conta_moedas_recursive(t, n, INF);
  int test_topdown = conta_moedas_topdown(t - 1, n, INF);
  int test_bottomup = conta_moedas_bottomup(t, n);

  printf("Teste recursivo %i\n", test_recursivo);
  printf("Teste top down %i\n", test_topdown);
  printf("Teste bottom up %i\n", test_bottomup);
  return EXIT_SUCCESS;
}

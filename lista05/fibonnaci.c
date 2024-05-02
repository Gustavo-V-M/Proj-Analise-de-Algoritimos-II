#include <stdio.h>
#include <stdlib.h>
#define EXIT_SUCCESS 0

int *memo;

int fib_bottomup(int n) {
  int f1 = 0;
  int f2 = 1;
  int f3;
  for (int i = 2; i < n + 1; i++) {
    f3 = f2 + f1;
    f1 = f2;
    f2 = f3;
  }
  return f3;
}

int fib_topd(int n) {
  if (memo[n] != -1) {
    return memo[n];
  } else if (n == 0 || n == 1) {
    memo[n] = n;
  } else {
    memo[n] = fib_topd(n - 1) + fib_topd(n - 2);
  }
  return memo[n];
}

int fib_r(int n) {
  if (n == 0 || n == 1) {
    return n;
  } else {
    return fib_r(n - 1) + fib_r(n - 2);
  }
}
int main(int argc, char *argv[]) {
  int n = 9;

  memo = (int *)malloc((n + 1) * sizeof(int));
  for (int i = 0; i < 10; i++) {
    memo[i] = -1;
  }

  printf("Fibonnaci Recursivo: ");
  printf("%i\n", fib_r(n));

  printf("Fibonnaci Top Down: ");
  printf("%i\n", fib_topd(n));

  printf("Fibonnaci Bottom Up: ");
  printf("%i\n", fib_bottomup(n));
  return EXIT_SUCCESS;
}

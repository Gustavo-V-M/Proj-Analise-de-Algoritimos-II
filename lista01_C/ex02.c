#include <stdio.h>
#define EXIT_SUCCESS 0

int binomial_recursivo(int n, int m) {
  if (m == 0 || m == n)
    return 1;
  else {
    return (binomial_recursivo(n - 1, m) + binomial_recursivo(n - 1, m - 1));
  }
}

int main(int argc, char *argv[]) {
  int test = binomial_recursivo(3, 2);
  printf("%i\n", test);
  return EXIT_SUCCESS;
}

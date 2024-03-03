#include <stdio.h>
#define EXIT_SUCCESS 0

int encontra_maior(int *a, int inicio, int final) {
  int meio = (inicio + final) / 2;

  if (meio == 0) {
    return a[meio];
  } else if (a[meio] > a[meio - 1] && a[meio] > a[meio + 1]) {
    return a[meio];
  } else if (a[meio] > a[meio - 1] && a[meio] < a[meio + 1]) {
    return encontra_maior(a, meio, final);
  } else {
    return encontra_maior(a, inicio, meio);
  }
}
int main(int argc, char *argv[]) {
  int a[] = {2, 5, 8, 7, 3};
  int test = encontra_maior(a, 0, 4);
  printf("%i\n", test);
  return EXIT_SUCCESS;
}

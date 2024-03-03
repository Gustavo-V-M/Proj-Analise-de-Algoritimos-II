#include <stdio.h>
#define EXIT_SUCCESS 0

int mdc_recursivo(int x, int y) {
  if (x == y)
    return x;
  else if (x % 2 == 0 && y % 2 == 0)
    return (2 * mdc_recursivo(x / 2, y / 2));
  else if (x % 2 == 0 && y % 2 == 1)
    return mdc_recursivo(x / 2, y);
  else if (x % 2 == 1 && y % 2 == 0)
    return mdc_recursivo(x, y / 2);
  else if (x % 2 == 1 && y % 2 == 1 && x > y) {
    return mdc_recursivo((x - y) / 2, y);
  } else {
    return mdc_recursivo(x, (y - x) / 2);
  }
}
int main(int argc, char *argv[]) {
  int test_1 = mdc_recursivo(270, 192);
  int test_2 = mdc_recursivo(35, 10);
  int test_3 = mdc_recursivo(10, 15);
  int test_4 = mdc_recursivo(31, 2);

  printf("%i\n", test_1);
  printf("%i\n", test_2);
  printf("%i\n", test_3);
  printf("%i\n", test_4);
  return EXIT_SUCCESS;
}

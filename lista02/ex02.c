#include <stdio.h>

#define EXIT_SUCCESS 0

int checkLexicogram(int *r, int *s, int r_size, int s_size) {
  int i = 0;
  while (i < r_size && i < s_size) {
    if (r[i] < s[i])
      return -1;
    else if (r[i] == s[i]) {
      i++;
    } else {
      return 1;
    }
  }

  if (i < r_size) {
    return 1;
  } else if (i > r_size) {
    return -1;
  } else {
    return 0;
  }
}

int main(int argc, char *argv[]) {
  int r[] = {1, 2, 3, 4, 5};
  int s[] = {1, 2, 3, 4, 5};

  int test = checkLexicogram(r, s, 6, 5);

  printf("%i\n", test);

  return EXIT_SUCCESS;
}

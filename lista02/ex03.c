#include <stdio.h>

#define EXIT_SUCCESS 0
#define TRUE 1
#define FALSE 0

int check_subsequence(int *s, int *a, int s_size, int a_size) {
  if (s_size > a_size) {
    return FALSE;
  }

  int i = 0;
  int found = 0;
  while (a_size - i >= s_size) {
    for (int j = 0; j < s_size; j++) {
      if (s[i + j] != a[j]) {
        found = FALSE;
      } else if (j == s_size - 1) {
        found = TRUE;
        return found;
      }
    }
    i++;
  }
  return found;
}
int main(int argc, char *argv[]) {
  int s[] = {1, 2};
  int a[] = {1, 3, 4, 3, 6, 1, 2};

  int test = check_subsequence(s, a, 2, 7);
  printf("%i\n", test);
  return EXIT_SUCCESS;
}

#include <stdio.h>

#define EXIT_SUCCESS 0
#define TRUE 1
#define FALSE 0

int suffix_check(int *s, int *a, int s_size, int a_size) {
  if (s_size > a_size) {
    return FALSE;
  } else {
    for (int i = 0; i < s_size; i++) {
      if (s[i] != a[i]) {
        return FALSE;
      }
    }
    return TRUE;
  }
}

int postfix_check(int *s, int *a, int s_size, int a_size) {
  if (s_size > a_size) {
    return FALSE;
  } else {
    for (int i = 0; i < s_size; i++) {
      if (s[i] != a[a_size - s_size + i]) {
        return FALSE;
      }
    }
    return TRUE;
  }
}

int is_segment(int *s, int *a, int s_size, int a_size) {
  if (suffix_check(s, a, s_size, a_size) ||
      postfix_check(s, a, s_size, a_size)) {
    return TRUE;
  }
  return FALSE;
}

int main(int argc, char *argv[]) {
  int s[] = {1, 2};
  int a[] = {3, 2, 3, 4, 1, 5};

  int test = is_segment(s, a, 2, 6);
  printf("%i\n", test);
  return EXIT_SUCCESS;
}

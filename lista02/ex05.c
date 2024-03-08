#include <stdio.h>
#define EXIT_SUCCESS 0

// Complexidade do algorítmo é O(n)
int check_equal_subsequence(int *s, int s_size) {
  int current_num = s[0];
  int count = 0;

  for (int i = 1; i < s_size; i++) { // O(n)
    if (s[i] != current_num) {       // O(n)
      count++;                       // O(n)
      current_num = s[i];            // O(n)
    }
  }
  count++; // O(1)
  return count;
}

int main(int argc, char *argv[]) {
  int s[] = {5, 2, 2, 3, 4, 4, 4, 4, 4, 1, 1};

  int test = check_equal_subsequence(s, 11);
  printf("%i\n", test);

  return EXIT_SUCCESS;
}

#include <stdio.h>

#define EXIT_SUCCESS 0

// A complexidade do algorítmo é O(n)
int count_max_sequence(int *s, int s_size) {
  int count_max = 1;         // O(1)
  int count_cur = count_max; // O(1)

  for (int i = 0; i < s_size - 1; i++) { // O(n)
    if (s[i] <= s[i + 1]) {              // O(n)
      count_cur++;                       // O(n)
      if (count_cur >= count_max) {      // O(n)
        count_max = count_cur;           // O(n)
      }
    }
  }
  return count_max; // O(1)
}
int main(int argc, char *argv[]) {

  int s[] = {5, 10, 3, 2, 4, 7, 9, 8};

  int test = count_max_sequence(s, 8);

  printf("%i\n", test);

  return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>

int *num;
int *memo;

int max(int a, int b) {
  if (a >= b) {
    return a;
  } else {
    return b;
  }
}

int LIS_topdown(int i) {
  if (memo[i] != -1) {
    return memo[i];
  } else if (i == 0) {
    memo[i] = 1;
    return memo[i];
  } else {
    int big = 1;
    for (int j = 0; j < i; j++) {
      if (num[j] < num[i]) {
        big = max(big, LIS_topdown(j) + 1);
      }
    }
    memo[i] = big;
    return memo[i];
  }
}

int LIS_bottomup(int n) {
  for (int i = 0; i < n; i++) {
    memo[i] = 1;
  }
  int big = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (num[j] < num[i]) {
        memo[i] = max(memo[i], memo[j] + 1);
      }
      big = max(big, memo[i]);
    }
  }
  return big;
}
int LIS_recursive(int i) {
  if (i == 0) {
    return 1;
  } else {
    int big = 1;
    for (int j = 0; j < i; j++) {
      if (num[j] < num[i]) {
        big = max(big, LIS_recursive(j) + 1);
      }
    }
    return big;
  }
}

int biggest_sub_sequence(int n) {
  int big = 1;
  for (int i = 0; i < n; i++) {
    big = max(big, LIS_recursive(i));
  }
  return big;
}
int main() {
  int n = 4;
  int

      return EXIT_SUCCESS;
}

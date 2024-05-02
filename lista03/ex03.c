#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int fact(int n) {
  if (n == 0 || n == 1) {
    return 1;
  } else {
    return n * fact(n - 1);
  }
}

void permutations(int *arr, int size, int index, int **solution,
                  int *solution_index) {
  if (index == size - 1) {
    for (int i = 0; i < size; i++) {
      solution[*solution_index][i] = arr[i];
    }
    (*solution_index)++;
  } else {
    for (int i = index; i < size; i++) {
      swap(&arr[index], &arr[i]);
      permutations(arr, size, index + 1, solution, solution_index);
      swap(&arr[index], &arr[i]);
    }
  }
}
int calculateElagantSum(int **arr, int perm_count, int perm_size) {
  int max = 0;
  int cur = 0;
  int sum = 0;
  for (int i = 0; i < perm_count; i++) {
    sum = 0;
    for (int j = 0; j < perm_size; j++) {
      if (j == 0) {
        cur = arr[i][j];
      } else {
        sum = sum + abs(cur - arr[i][j]);
        cur = arr[i][j];
      }
    }
    if (sum >= max) {
      max = sum;
    }
  }
  return max;
}
int main(int argc, char *args[]) {

  int values[4] = {4, 2, 1, 5};
  int values_size = 4;

  int num_of_permutations = fact(values_size);

  int **permutation = (int **)malloc(num_of_permutations * sizeof(int *));
  if (permutation == NULL) {
    return EXIT_FAILURE;
  }

  for (int i = 0; i < num_of_permutations; i++) {
    permutation[i] = (int *)malloc(values_size * sizeof(int));
  }
  int solution_index = 0;

  permutations(values, values_size, 0, permutation, &solution_index);

  int max = calculateElagantSum(permutation, num_of_permutations, values_size);

  printf("%i\n", max);
  for (int i = 0; i < num_of_permutations; i++) {
    free(permutation[i]);
  }

  return EXIT_SUCCESS;
}
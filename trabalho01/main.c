#include <stdio.h>

#define EXIT_SUCCESS 0;
#define EXIT_FAILURE 1;

void backtracking(int *solution, int solution_size, int index,
                  int *values_vector, int vector_size) {
  if (index == solution_size) {
    for (int i = 0; i < solution_size; i++) {
      printf("%i", solution[i]);
    }
    printf("\n");
  } else {
    for (int j = 0; j < vector_size; j++) {
      solution[index] = values_vector[j];
      backtracking(solution, solution_size, index + 1, values_vector,
                   vector_size);
    }
  }
}

int main(int argc, char *argv[]) { return EXIT_SUCCESS; }

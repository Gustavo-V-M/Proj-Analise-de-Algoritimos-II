#include <stdio.h>
#include <stdlib.h> 


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

int main(int argc, char* argv[]){

    int size = atoi(argv[1]);

    int solution[size];
    int solution_size = size;

    int values_vector[2] = {0,1};
    int vector_size = 2;

    backtracking(solution, solution_size, 0, values_vector, vector_size);

    return EXIT_SUCCESS;

}
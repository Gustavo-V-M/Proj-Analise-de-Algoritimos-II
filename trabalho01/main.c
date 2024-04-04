#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

struct delta {
  int x;
  int y;
};

void find_start(char **matrix, int *i, int *j, const int MAX_COLS,
                const int MAX_ROWS) {
  for (int x = 0; x < MAX_ROWS; x++) {
    for (int y = 0; y < MAX_COLS - 1; y++) {
      if (matrix[x][y] == 'E') {
        *i = x;
        *j = y;
        return;
      }
    }
  }
}

int validate_path(int i, int j, char **matrix, const int MAX_COLS,
                  const int MAX_ROWS) {
  if (i < 0 || j < 0 || j >= MAX_COLS || i >= MAX_ROWS) {
    return FALSE;
  } else {
    if (matrix[i][j] == '.' || matrix[i][j] == 'S') {
      return TRUE;
    } else {
      return FALSE;
    }
  }
}

void find_exit(int i, int j, char **matrix, struct delta delta_list[4],
               int *done, const int MAX_COLS, const int MAX_ROWS,
               FILE *fwrite) {
  if (matrix[i][j] == 'S' && *done == 0) {
    for (int x = 0; x < MAX_ROWS; x++) {
      for (int y = 0; y < MAX_COLS; y++) {
        fprintf(fwrite, "%c", matrix[x][y]);
      }
      fprintf(fwrite, "\n");
    }
    *done = 1;
    return;
  } else {
    if (matrix[i][j] != 'E')
      matrix[i][j] = 'O';
    for (int x = 0; x < 4; x++) {
      if (validate_path(i + delta_list[x].x, j + delta_list[x].y, matrix,
                        MAX_COLS, MAX_ROWS) == TRUE) {

        find_exit(i + delta_list[x].x, j + delta_list[x].y, matrix, delta_list,
                  done, MAX_COLS, MAX_ROWS, fwrite);
      }
    }
    if (matrix[i][j] != 'E')
      matrix[i][j] = '.';
  }
}

int main() {

  FILE *file;
  char file_path[] = "./labyrinth.txt";
  FILE *fwrite;
  char fwrite_path[] = "./solution.txt";

  fwrite = fopen(fwrite_path, "w");
  file = fopen(file_path, "r");

  int lines;
  int columns;

  fscanf(file, "%d %d", &lines, &columns);

  char **matriz;
  int k = 0;

  matriz = (char **)malloc(lines * sizeof(char *));
  for (int i = 0; i < lines; i++) {
    matriz[i] = (char *)malloc(columns * sizeof(char));
  }

  for (int k = 0; k < lines; k++) {
    char *s = (char *)malloc(columns * sizeof(char));
    fscanf(file, "%s", s);
    for (int i = 0; i < columns; i++) {
      matriz[k][i] = s[i];
    }
  }

  struct delta m1 = {0, 1};
  struct delta m2 = {0, -1};
  struct delta m3 = {1, 0};
  struct delta m4 = {-1, 0};

  int i;
  int j;
  int done = 0;

  find_start(matriz, &i, &j, columns, lines);

  struct delta delta_list[] = {m1, m2, m3, m4};

  find_exit(i, j, matriz, delta_list, &done, columns, lines, fwrite);

  return EXIT_SUCCESS;
}

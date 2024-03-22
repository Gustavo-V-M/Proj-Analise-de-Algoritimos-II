#include <stdio.h>
#include <stdlib.h>

#define EXIT_SUCCESS 0

// Eu não sei se isso funciona, todos os testes que fiz deram negativos.
struct movement {
  int x;
  int y;
};

int validMovement(int u, int v, int **board, int board_size) {
  if (0 <= u && u < board_size && 0 <= v && v < board_size &&
      board[u][v] == 0) {
    return 1;
  } else {
    return 0;
  }
}

int checkPath(int **board, int board_size, int u, int v,
              struct movement *mv_array, int mv_size, int visited) {
  if (visited == board_size * board_size - 1) {
    return 1;
  } else {
    board[u][v] = 1;
    for (int i = 0; i < mv_size; i++) {
      int new_u = u + mv_array[i].x;
      int new_v = v + mv_array[i].y;

      if (validMovement(new_u, new_v, board, board_size) == 0)
        continue;
      visited++;
      if (checkPath(board, board_size, new_u, new_v, mv_array, mv_size,
                    visited) == 0)
        visited--;
    }
    board[u][v] = 0;
    return 0;
  }
}

int main(int argc, char *args[]) {

  struct movement x1y3;
  x1y3.x = 1;
  x1y3.y = 3;

  struct movement x3y1;
  x3y1.x = 3;
  x3y1.y = 1;

  struct movement xback1y3;
  xback1y3.x = -1;
  xback1y3.y = 3;

  struct movement x1yback3;
  x1yback3.x = 1;
  x1yback3.y = -3;

  struct movement xback3y1;
  xback3y1.x = -3;
  xback3y1.y = 1;

  struct movement x3yback1;
  x3yback1.x = 3;
  x3yback1.y = -1;

  struct movement movement_array[6] = {x1y3,     x3y1,     xback1y3,
                                       x1yback3, xback1y3, x3yback1};

  int *board[5];

  for (int i = 0; i < 5; i++) {
    board[i] = malloc(5 * sizeof(int));
    for (int j = 0; j < 5; j++) {
      board[i][j] = 0;
    }
  }

  int test = checkPath(board, 5, 0, 0, movement_array, 6, 0);

  printf("%i\n", test);

  for (int i = 0; i < 5; i++) {
    free(board[i]);
  }
}
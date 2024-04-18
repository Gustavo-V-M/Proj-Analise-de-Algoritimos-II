#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int w;
  int v;
} num;
int cmp(const void *v, const void *w) {
  int x = ((num *)v)->v / ((num *)v)->w;
  int y = ((num *)w)->v / ((num *)w)->w;
  return (x - y);
}
void mochila_fracionaria(num *vw, int n, int c, int *x) {
  qsort(vw, n, sizeof(num), cmp);
  int i = 0;
  while (i < n && c > 0) {
    if (vw[i].w <= c) {
      x[i] = 1;
      c -= vw[i].w;
      i++;
    }
  }
}
int main(int argc, char *argv[]) {

  num a[3];

  return EXIT_SUCCESS;
}

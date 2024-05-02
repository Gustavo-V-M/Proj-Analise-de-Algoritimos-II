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
void mochila_fracionaria(num *vw, int n, int c, double *x) {
  qsort(vw, n, sizeof(num), cmp);
  int i = 0;
  while (i < n && c > 0) {
    if (vw[i].w <= c) {
      x[i] = 1;
      c -= vw[i].w;
      i++;
    } else {
      x[i] = (double)c / (double)vw[i].w;
      c = 0;
    }
  }
}
int main(int argc, char *argv[]) {

  num a1 = {10, 60};
  num a2 = {20, 100};
  num a3 = {30, 120};

  num a[3] = {a1, a2, a3};
  double *x = (double *)malloc(3 * sizeof(double));

  mochila_fracionaria(a, 3, 50, x);

  for (int i = 0; i < 3; i++) {
    printf("%f\n", x[i]);
  }

  return EXIT_SUCCESS;
}

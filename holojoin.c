#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "finite_field.h"


int main(int argc, char *argv[]) {
  FILE **in;
  uint8_t *a, *ai, *d;
  int i,j;
  long int sz = 0L;
  char s[20];
  
  if (argc < 2) {
    fprintf(stderr, "Usage holojoin n filename1 ... filenameN\n");
    exit(1);
  }

  int n = atoi(argv[1]);
  a = malloc(n * n);
  d = malloc(n);
  in = malloc(n * sizeof(FILE *));
  if (argc < n + 1) {
    fprintf(stderr, "Usage holojoin n filename1 ... filenameN\n");
    exit(1);
  }
  for (i = 0; i < n; i++) {
    if (!(in[i] = fopen(argv[2 + i], "r"))) {
      fprintf(stderr, "Cannot open file: %s\n", argv[2 + i]);
    }
    fscanf(in[i], "%s", s);
    if (strcmp(s, "Holosplit")) {
      fprintf(stderr, "%s is not a Holosplit file!\n", argv[2 + i]);
      exit(1);
    }
    fscanf(in[i], "%ld", &sz);
    for (j = 0; j < n; j++)
      fscanf(in[i], "%hhd\n", a + i * n + j);
  }

  ai = matrix_inverse(a, n);

  while (sz > 0L) {
    for (i = 0; i < n; i++)
      d[i] = getc(in[i]);

    for (i = 0; i < n; i++) {
      uint8_t s = 0;
      for (j = 0; j < n; j++)
	s ^= mult[ai[i * n + j]][d[j]];
      if (sz-- > 0)
	putchar(s);
    }
  }
  exit(0);
}

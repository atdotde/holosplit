#include <stdio.h>
#include <stdlib.h>
#include "finite_field.h"


int main(int argc, char *argv[]) {
  FILE *in;
  uint8_t *v, *d;
  int i,j;
  
  if (argc < 2) {
    fprintf(stderr, "Usage: holosplit n filename\n");
    exit(1);
  }

  srandomdev();
  int n = atoi(argv[1]);
  v = malloc(n);
  d = malloc(n);
  
  
  if(!(in = fopen(argv[2],"r"))) {
    fprintf(stderr, "Cannot open file: %s\n", argv[2]);
      exit(1);
  }
  fseek(in, 0L, SEEK_END);
  long int sz = ftell(in);  
  rewind(in);
  printf("Holosplit\n%ld\n", sz);
  for (i = 0; i < n; i++){
    v[i] = (uint8_t)(random() & 255);
    printf("%hhu\n", v[i]);
  }

  while (sz > 0) {
    int r = fread(d, 1, n, in);
    sz -= n;
    if (r < n)
      for (i = r; i < n; i++)
	d[i] = 0;
    
    uint8_t s = 0;
    for (i = 0; i < n; i++)
      s ^= mult[d[i]][v[i]];
    putchar(s);
  }
  exit(0);
}

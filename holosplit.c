#include <stdio.h>
#include <stdlib.h>
#include "finite_field.h"


int main() {
  short a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  //  short a[] = {1, 0, 0, 0, 1, 0, 0, 0, 3};
  
  dump_matrix(a, 3);

  printf("\n");
  short *e = matrix_inverse(a, 3);
  dump_matrix(e, 3);

  printf("\n");
  dump_matrix(matrix_product(a, e, 3), 3);

  printf("3x244=%hd\n", mult[3][244]);
}

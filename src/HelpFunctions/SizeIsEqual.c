#include "../s21_matrix.h"

int SizeIsEqual(matrix_t *A, matrix_t *B) {
  return (A->rows == B->rows && A->columns == B->columns);
}
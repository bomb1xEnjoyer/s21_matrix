#include "../s21_matrix.h"

int SizeIsValidForMult(matrix_t *A, matrix_t *B) {
  return (A->columns == B->rows);
}
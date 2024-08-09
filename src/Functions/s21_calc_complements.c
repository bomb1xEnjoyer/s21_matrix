#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (PointerIsNull(A) || WrongSize(A->rows, A->columns) ||
      PointerIsNull(result)) {
    return INVALID_MATRIX;
  }
  if (A->rows != A->columns || CheckMatrixForInf(A)) {
    return CALCULATION_ERROR;
  }
  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = GetMinor(A, i, j);
    }
  }
  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      if ((i + j) % 2 == 1) {
        result->matrix[i][j] *= -1;
      }
    }
  }
  return OK;
}
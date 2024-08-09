#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (PointerIsNull(A) || PointerIsNull(B) || PointerIsNull(result) ||
      WrongSize(A->rows, A->columns) || WrongSize(B->rows, B->columns)) {
    return INVALID_MATRIX;
  }
  if (CheckMatrixForInf(A) || CheckMatrixForInf(B) ||
      !SizeIsValidForMult(A, B)) {
    return CALCULATION_ERROR;
  }
  s21_create_matrix(A->rows, B->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      for (int k = 0; k < A->columns; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }
  return OK;
}
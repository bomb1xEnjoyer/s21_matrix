#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (PointerIsNull(A) || PointerIsNull(B) || PointerIsNull(result) ||
      WrongSize(A->rows, A->columns) || WrongSize(B->rows, B->columns)) {
    return INVALID_MATRIX;
  }
  if (!SizeIsEqual(A, B) || CheckMatrixForInf(A) || CheckMatrixForInf(B)) {
    return CALCULATION_ERROR;
  }
  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }
  return OK;
}
#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (PointerIsNull(A) || result == NULL || WrongSize(A->rows, A->columns)) {
    return INVALID_MATRIX;
  }
  if (A->rows != A->columns || CheckMatrixForInf(A)) {
    return CALCULATION_ERROR;
  }
  if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else if (A->rows == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    *result = 1;
    matrix_t A_copy;
    s21_create_matrix(A->rows, A->columns, &A_copy);
    for (int i = 0; i < A_copy.rows; i++) {
      for (int j = 0; j < A_copy.columns; j++) {
        A_copy.matrix[i][j] = A->matrix[i][j];
      }
    }
    TransformationToTriangleMatrix(&A_copy);
    for (int i = 0; i < A_copy.rows; i++) {
      *result *= A_copy.matrix[i][i];
    }
    s21_remove_matrix(&A_copy);
  }
  return OK;
}
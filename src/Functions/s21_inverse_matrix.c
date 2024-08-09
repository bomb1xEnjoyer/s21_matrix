#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  double det;
  int det_check = s21_determinant(A, &det), answer = OK;
  if (PointerIsNull(A) || WrongSize(A->rows, A->columns) ||
      PointerIsNull(result)) {
    return INVALID_MATRIX;
  }
  if (A->rows != A->columns || (det >= 0 - 1e-7 && det <= 0 + 1e-7) ||
      det_check != 0) {
    return CALCULATION_ERROR;
  }
  s21_create_matrix(A->rows, A->columns, result);
  matrix_t algebraic_complement_matrix;
  matrix_t transposed_algebraic_complement_matrix;
  int check = s21_calc_complements(A, &algebraic_complement_matrix);
  if (check == 0) {
    check = s21_transpose(&algebraic_complement_matrix,
                          &transposed_algebraic_complement_matrix);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] =
            transposed_algebraic_complement_matrix.matrix[i][j] * (1. / det);
      }
    }
  } else {
    answer = CALCULATION_ERROR;
  }
  s21_remove_matrix(&algebraic_complement_matrix);
  s21_remove_matrix(&transposed_algebraic_complement_matrix);
  return answer;
}
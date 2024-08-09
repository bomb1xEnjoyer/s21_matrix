#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (PointerIsNull(A) || PointerIsNull(B) || WrongSize(A->rows, A->columns) ||
      WrongSize(B->rows, B->columns) || !SizeIsEqual(A, B)) {
    return FAILURE;
  }
  int answer = SUCCESS;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) {
        answer = FAILURE;
      }
    }
  }
  return answer;
}
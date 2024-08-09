#include "../s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  if (!(PointerIsNull(A) || WrongSize(A->rows, A->columns))) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->rows = 0;
    A->columns = 0;
  }
  A->matrix = NULL;
}
#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (PointerIsNull(result)) {
    return INVALID_MATRIX;
  }
  if (WrongSize(rows, columns)) {
    result->rows = 0;
    result->columns = 0;
    return INVALID_MATRIX;
  }
  result->matrix = (double **)calloc(rows, sizeof(double *));
  // if (result->matrix == NULL) {
  //   return INVALID_MATRIX;
  // }
  for (int i = 0; i < rows; i++) {
    result->matrix[i] = (double *)calloc(columns, sizeof(double));
    // if (result->matrix[i] == NULL) {
    //   return INVALID_MATRIX;
    // }
  }
  result->rows = rows;
  result->columns = columns;
  return OK;
}
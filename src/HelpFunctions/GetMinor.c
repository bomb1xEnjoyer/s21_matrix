#include "../s21_matrix.h"

double GetMinor(matrix_t *matrix, int row, int column) {
  double minor;
  matrix_t small;
  int small_i = 0, small_j = 0;
  s21_create_matrix(matrix->rows - 1, matrix->columns - 1, &small);
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      if (i != row && j != column) {
        small.matrix[small_i][small_j] = matrix->matrix[i][j];
        small_j++;
        if (small_j == small.rows) {
          small_j = 0;
          small_i++;
        }
      }
    }
  }
  small_i = s21_determinant(&small, &minor);
  s21_remove_matrix(&small);
  return minor;
}
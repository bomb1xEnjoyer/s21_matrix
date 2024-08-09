#include "../s21_matrix.h"

void TransformationToTriangleMatrix(matrix_t *matrix) {
  for (int i = 0; i < matrix->rows - 1; i++) {
    for (int k = i + 1; k < matrix->rows; k++) {
      double coefficient = matrix->matrix[k][i] / matrix->matrix[i][i];
      for (int j = 0; j < matrix->rows; j++) {
        matrix->matrix[k][j] -= coefficient * matrix->matrix[i][j];
      }
    }
  }
}
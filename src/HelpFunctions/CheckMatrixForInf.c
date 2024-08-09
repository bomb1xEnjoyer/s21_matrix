#include "../s21_matrix.h"

int CheckMatrixForInf(matrix_t *matrix) {
  int answer = 0;
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      if (IsInf(matrix->matrix[i][j])) {
        answer = 1;
      }
    }
  }
  return answer;
}
#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
// Все операции (кроме сравнения матриц) должны возвращать результирующий код:
// 0 - OK
// 1 - Ошибка, некорректная матрица
// 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
// нельзя провести вычисления и т.д.)
#define SUCCESS 1
#define FAILURE 0

enum return_codes { OK, INVALID_MATRIX, CALCULATION_ERROR };

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// Help funcs and values
#define Pos_Inf 1.0 / 0.0
#define Neg_Inf -1.0 / 0.0
int PointerIsNull(matrix_t *pointer);
int WrongSize(int rows, int columns);
int SizeIsEqual(matrix_t *A, matrix_t *B);
int SizeIsValidForMult(matrix_t *A, matrix_t *B);
int IsInf(double number);
int CheckMatrixForInf(matrix_t *matrix);
void TransformationToTriangleMatrix(matrix_t *matrix);
double GetMinor(matrix_t *matrix, int row, int column);

#endif
#define  _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <ctime>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

#include "matrix.h"
#include "calculation.h"
#include "SLAE_solve.h"
#include "inverse_matrix.h"

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	assert(50 == test_SLAE::test(50, 1e-5));

	assert(50 == test_inverse_matrix::test(50, 1e-5));

	/*srand(time(nullptr));
	matrix A(4, 4), b(4, 1);
	for (int i = 0; i < 4; ++i) {
	for (int j = 0; j < 4; ++j) {
	A[i][j] = rand() % 20 - 8;
	}
	}
	for (int i = 0; i < 4; ++i) {
	b[i][0] = rand() % 20 - 5;
	}
	for (int i = 0; i < A.rows; ++i) {
	for (int j = 0; j < A.columns; ++j) {
	cout << A[i][j] << " ";
	}
	cout << endl;
	}
	cout << endl;
	for (int i = 0; i < 4; ++i) {
	cout << b[i][0] << " ";
	}
	cout << endl;
	matrix x = calculation::SLAE_solve::LU_method(A, b);
	for (int i = 0; i < 4; ++i) {
	cout << x[i][0] << " ";
	}
	cout << endl;*/
	/*matrix LU = A.LU_decomposition();
	for (int i = 0; i < LU.rows; ++i) {
	for (int j = 0; j < LU.columns; ++j) {
	printf("% 4.5Lf ", LU[i][j]);
	}
	cout << endl;
	}
	calculation::SLAE_solve::LU_method(A, A);*/
	/*matrix L(4, 4);
	L[0][0] = 1;
	L[0][1] = 0;
	L[0][2] = 0;
	L[0][3] = 0;
	L[1][0] = 2;
	L[1][1] = 1;
	L[1][2] = 0;
	L[1][3] = 0;
	L[2][0] = 1;
	L[2][1] = 3;
	L[2][2] = 1;
	L[2][3] = 0;
	L[3][0] = 2;
	L[3][1] = 4;
	L[3][2] = 5;
	L[3][3] = 1;
	matrix b(4, 1);
	b[0][0] = 3;
	b[1][0] = 5;
	b[2][0] = 6;
	b[3][0] = 6;
	matrix x = calculation::SLAE_solve::straight_substitution(L, b);*/
	/*matrix U(4, 4);
	for (int i = 0; i < 4; ++i) {
	for (int j = i; j < 4; ++j) {
	U[i][j] = rand() % 10;
	cout << U[i][j] << " ";
	}
	cout << endl;
	}
	matrix b(4, 1);
	b[0][0] = 12;
	b[1][0] = 7;
	b[2][0] = 3;
	b[3][0] = -2;
	matrix x = calculation::SLAE_solve::back_substitution(U, b);
	for (int i = 0; i < 4; ++i) {
	cout << x[i][0] << endl;
	}*/
	return 0;
}
#include "calculation.h"

matrix calculation::SLAE::back_substitution(const matrix& U, const matrix& b) {
	matrix x(U.columns, 1);
	for (int i = x.rows - 1; i >= 0; --i) {
		x[i][0] = b[i][0];
		for (int j = i + 1; j < U.columns; ++j) {
			x[i][0] -= U[i][j] * x[j][0];
		}
		x[i][0] /= U[i][i];
	}
	return x;
}

matrix calculation::SLAE::straight_substitution(const matrix& L, const matrix& b) {
	matrix x(L.columns, 1);
	for (int i = 0; i < x.rows; ++i) {
		x[i][0] = b[i][0];
		for (int j = 0; j < i; ++j) {
			x[i][0] -= L[i][j] * x[j][0];
		}
		x[i][0] /= L[i][i];
	}
	return x;
}

matrix calculation::SLAE::LU_method(const matrix& A, const matrix& b) {
	matrix LU = A.LU_decomposition();
	matrix L(LU.rows, LU.columns), U(LU.rows, LU.columns);
	for (int i = 0; i < LU.rows; ++i) {
		for (int j = 0; j < i; ++j) {
			L[i][j] = LU[i][j];
		}
		L[i][i] = 1;
	}
	for (int i = 0; i < LU.columns; ++i) {
		for (int j = i; j < LU.columns; ++j) {
			U[i][j] = LU[i][j];
		}
	}
	//LU.~~matrix();
	matrix y = straight_substitution(L, b);
	matrix x = back_substitution(U, y);
	return x;
}

//matrix calculation::inverse_matrix::LU_method(const matrix& A) {
//
//}
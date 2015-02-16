#include "calculation.h"

matrix calculation::SLAE_solve::back_substitution(const matrix& U, const matrix& b) {
	matrix A(1, 1);

	return A;
}

matrix calculation::SLAE_solve::straight_substitution(const matrix& L, const matrix& b) {
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

matrix calculation::SLAE_solve::LU_method(const matrix& A, const matrix& b) {
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
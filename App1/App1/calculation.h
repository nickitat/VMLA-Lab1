#ifndef __CALCULATION_H__
#define __CALCULATION_H__

#include "matrix.h"

class calculation {
public:

	class SLAE_solve {
	public:

		static matrix back_substitution(const matrix& U, const matrix& b);
		static matrix straight_substitution(const matrix& L, const matrix& b);
		static matrix LU_method(const matrix& A, const matrix& b);
	};

};

matrix calculation::SLAE_solve::back_substitution(const matrix& U, const matrix& b) {
	matrix A(1, 1);

	return A;
}

matrix calculation::SLAE_solve::straight_substitution(const matrix& L, const matrix& b) {
	matrix A(1, 1);

	return A;
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

#endif/*__CALCULATION_H__*/
#ifndef __CALCULATION_H__
#define __CALCULATION_H__

#include "matrix.h"

class calculation {
public:

	class SLAE {
	public:

		static matrix back_substitution(const matrix& U, const matrix& b);
		static matrix straight_substitution(const matrix& L, const matrix& b);
		static matrix LU_method(const matrix& A, const matrix& b);
	};

	class inverse_matrix {
	public:

		static matrix LU_method(const matrix& A);
	};

};

#endif/*__CALCULATION_H__*/
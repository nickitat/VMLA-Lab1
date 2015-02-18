#ifndef _TEST_INVERSE_MATRIX__
#define _TEST_INVERSE_MATRIX__

#include <ctime>
#include "matrix.h"
#include "calculation.h"

class test_inverse_matrix {
public:

	static int test(int num_of_tests, long double precission);

private:

	static bool random_test(long double precission);
};

int test_inverse_matrix::test(int num_of_tests, long double precission) {
	int passed_tests = 0;
	for (int i = 0; i < num_of_tests; ++i) {
		if (random_test(precission)) {
			passed_tests++;
		}
	}
	return passed_tests;
}

bool test_inverse_matrix::random_test(long double precission) {
	srand(time(nullptr));
	int n = rand() % 10 + 1;
	matrix A(n, n);
	for (int i = 0; i < A.rows; ++i) {
		for (int j = 0; j < A.columns; ++j) {
			A[i][j] = rand() % 20 - 8;
		}
	}
	matrix A_inv = calculation::inverse_matrix::LU_method(A);
	matrix E0 = A * A_inv, E1 = A_inv * A;
	for (int i = 0; i < E0.rows; ++i) {
		for (int j = 0; j < E0.columns; ++j) {
			if (i != j) {
				if (fabsl(E0[i][j]) > precission || fabsl(E1[i][j]) > precission) {
					return false;
				}
			}
			else {
				if (fabsl(E0[i][j] - 1) > precission || fabsl(E1[i][j] - 1) > precission) {
					return false;
				}
			}
		}
	}
	return true;
}

#endif/*_TEST_INVERSE_MATRIX__*/
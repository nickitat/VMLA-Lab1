#ifndef _TEST_INVERSE_MATRIX__
#define _TEST_INVERSE_MATRIX__

#include <ctime>
#include "matrix.h"
#include "calculation.h"

class test_inverse_matrix {
public:

	static int test(int num_of_tests);

private:

	static bool random_test();
};

int test_inverse_matrix::test(int num_of_tests) {
	int passed_tests = 0;
	for (int i = 0; i < num_of_tests; ++i) {
		if (random_test()) {
			passed_tests++;
		}
	}
	return passed_tests;
}

bool test_inverse_matrix::random_test() {
	srand(time(nullptr));
	int n = rand() % 10 + 1;
	matrix A(n, n), E(n, n);
	for (int i = 0; i < A.rows(); ++i) {
		for (int j = 0; j < A.columns(); ++j) {
			A[i][j] = rand() % 20 - 8;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				E[i][i] = 1;
			}
			else {
				E[i][j] = 0;
			}
		}
	}
	matrix A_inv = calculation::inverse_matrix::LU_method(A);
	matrix E0 = A * A_inv;
	matrix E1 = A_inv * A;
	return E0 == E && E1 == E;
}

#endif/*_TEST_INVERSE_MATRIX__*/
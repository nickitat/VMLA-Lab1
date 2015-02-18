#ifndef __TEST_SLAE_H__
#define __TEST_SLAE_H__

#include <ctime>
#include "matrix.h"
#include "calculation.h"

class test_SLAE {
public:

	static int test(int num_of_tests);

private:

	static bool random_test();
};

int test_SLAE::test(int num_of_tests) {
	int passed_tests = 0;
	for (int i = 0; i < num_of_tests; ++i) {
		if (random_test()) {
			passed_tests++;
		}
	}
	return passed_tests;
}

bool test_SLAE::random_test() {
	srand(time(nullptr)); 
	int n = rand() % 10 + 1;
	matrix A(n, n), b(n, 1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			A[i][j] = rand() % 20 - 8;
		}
		b[i][0] = rand() % 20 - 8;
	}
	matrix x = calculation::SLAE::LU_method(A, b);
	matrix b0 = A * x;
	return b0 == b;
}

#endif/*__TEST_SLAE_SOLVE_H__*/
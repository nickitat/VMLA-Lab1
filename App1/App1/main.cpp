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

	const int num_of_tests = 100;
	int test_inv = test_inverse_matrix::test(num_of_tests);
	cout << test_inv << endl;

	time_t start = clock();
	int n = 100;
	matrix A(n, n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			A[i][j] = max(i + 1, j + 1);
		}
	}
	matrix A_inv = calculation::inverse_matrix::LU_method(A);
	cout << A_inv << endl;
	time_t end = clock();
	printf("Calculation %.5Lf", double(end - start) / CLOCKS_PER_SEC);

	// 200 - 3s ; 500 - 45s

	return 0;
}
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

	/*int test_slae = test_SLAE::test(num_of_tests);
	cout << test_slae << endl;

	srand(time(nullptr));
	int n = 10;
	matrix A(n, n), Q(n, n), R(n, n);
	for (int i = 0; i < n; ++i) {
	for (int j = 0; j < n; ++j) {
	A[i][j] = rand() % 20 - 8;
	}
	}
	A.QR_decomposition(Q, R);
	cout << A << endl;
	cout << Q << endl;
	cout << R << endl;
	cout << Q * R << endl;
	cout << (A == Q*R ? "equal" : "oops...") << endl;*/

	const int num_of_tests = 115;
	int test_inv = test_inverse_matrix::test(num_of_tests);
	cout << test_inv << endl;

	//time_t start = clock();
	//int n = 500;
	//matrix A(n, n);
	//for (int i = 0; i < n; ++i) {
	//	for (int j = 0; j < n; ++j) {
	//		A[i][j] = max(i + 1, j + 1);
	//	}
	//}
	////cout << A << endl;
	//matrix A_inv = calculation::inverse_matrix::QR_method(A);
	////cout << A_inv << endl;
	//time_t end = clock();
	//printf("Calculation %.5Lf", double(end - start) / CLOCKS_PER_SEC);

	// LU: 200 - 3s  ; 500 - 45s
	// QR: 200 - 14s ; 500 - 230s

	return 0;
}
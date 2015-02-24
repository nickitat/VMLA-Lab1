#define  _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <ctime>
#include <iostream>
#include <utility>
#include <vector>

#include "matrix.h"
#include "calculation.h"
#include "SLAE_solve.h"
#include "inverse_matrix.h"

using namespace std;
using namespace Garbage;

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	//time_t start = clock();

	int n = 50;
	matrix A(n, n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			A[i][j] = max(i + 1, j + 1);
		}
	}
	matrix A_inv_LU = calculation::inverse_matrix::LU_method(A);
	matrix A_inv_QR = calculation::inverse_matrix::QR_method(A);
	cout << A_inv_LU << endl;
	cout << A_inv_QR << endl;
	
	//time_t end = clock();
	//printf("Calculation %.5Lf", double(end - start) / CLOCKS_PER_SEC);

	// LU: 200 - 3s  ; 500 - 45s
	// QR: 200 - 14s ; 500 - 230s

	return 0;
}
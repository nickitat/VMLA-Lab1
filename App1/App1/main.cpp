#define  _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

#include "matrix.h"

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	matrix A(4, 4);
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			A[i][j] = rand() % 20 - 8;
		}
	}
	for (int i = 0; i < A.rows; ++i) {
		for (int j = 0; j < A.columns; ++j) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	matrix LU = A.LU_decomposition();
	for (int i = 0; i < LU.rows; ++i) {
		for (int j = 0; j < LU.columns; ++j) {
			printf("% 4.5Lf ", LU[i][j]);
		}
		cout << endl;
	}
	return 0;
}
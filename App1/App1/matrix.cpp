#include "matrix.h"
#include <cassert>
#include <ostream>
#include <iostream>

matrix::matrix(int m_rows, int m_columns)
	: m_rows(m_rows), m_columns(m_columns)
{
	data.assign(m_rows, vector<_Type>(m_columns));
}

matrix::matrix(const matrix& other)
	: m_rows(other.m_rows), m_columns(other.m_columns)
{
	data.resize(m_rows);
	for (size_t i = 0; i < m_rows; ++i) {
		data[i].assign(other.data[i].begin(), other.data[i].end());
	}
}

matrix::~matrix() {
	for (size_t i = 0; i < data.size(); ++i) {
		data[i].clear();
	}
	data.clear();
}

vector<matrix::_Type> matrix::get_row(size_t i) const {
	//if (i >= m_rows) {
	//
	//}
	return data[i];
}

vector<matrix::_Type> matrix::get_column(size_t j) const {
	//if (j >= m_columns) {
	//
	//}
	vector<_Type> ret(m_rows);
	for (int i = 0; i < m_rows; ++i) {
		ret[i] = data[i][j];
	}
	return ret;
}

void matrix::operator=(const matrix& other) {
	m_rows = other.m_rows;
	m_columns = other.m_columns;
	data.resize(m_rows);
	for (size_t i = 0; i < m_rows; ++i) {
		data[i].assign(other.data[i].begin(), other.data[i].end());
	}
}

vector<matrix::_Type>& matrix::operator[](size_t i) {
	return data[i];
}

const vector<matrix::_Type>& matrix::operator[](size_t i) const {
	return data[i];
}

matrix matrix::operator+(const matrix& other) {
	//if (m_rows != other.m_rows || m_columns != other.m_columns) {
	//
	//}
	matrix Res(m_rows, m_columns);
	for (size_t i = 0; i < m_rows; ++i) {
		for (size_t j = 0; j < m_columns; ++j) {
			Res[i][j] = data[i][j] + other.data[i][j];
		}
	}
	return Res;
}

matrix matrix::operator*(const double alpha) {
	matrix Res(m_rows, m_columns);
	for (size_t i = 0; i < m_rows; ++i) {
		for (size_t j = 0; j < m_columns; ++j) {
			Res[i][j] *= alpha;
		}
	}
	return Res;
}

matrix matrix::operator*(const matrix& other) {
	//if (m_columns != other.m_rows) {
	//
	//}
	matrix Res(m_rows, other.m_columns);
	for (size_t i = 0; i < Res.m_rows; ++i) {
		for (size_t j = 0; j < Res.m_columns; ++j) {
			Res[i][j] = 0;
			for (size_t k = 0; k < m_columns; ++k) {
				Res[i][j] += data[i][k] * other.data[k][j];
			}
		}
	}
	return Res;
}

bool matrix::operator==(const matrix& other) {
	if (m_rows != other.m_rows || m_columns != other.m_columns) {
		return false;
	}
	const long double precission = 1e-5;
	for (int i = 0; i < m_rows; ++i) {
		for (int j = 0; j < m_columns; ++j) {
			if (fabsl(data[i][j] - other.data[i][j]) > precission) {
				return false;
			}
		}
	}
	return true;
}

std::ostream& operator<<(std::ostream& os, const matrix& A) {
	for (int i = 0; i < A.m_rows; ++i) {
		for (int j = 0; j < A.m_columns; ++j) {
			os << (fabsl(A[i][j]) > 1e-5 ? A[i][j] : 0) << " ";
		}
		os << std::endl;
	}
	return os;
}


matrix matrix::LU_decomposition() const {
	//if (m_rows != m_columns) {
	//
	//}
	size_t n = m_rows;
	matrix L(n, n), U(n, n);
	for (int i = 0; i < n; ++i) {
		U[0][i] = data[0][i];
	}
	for (int i = 0; i < n; ++i) {
		L[i][0] = data[i][0] / U[0][0];
		L[i][i] = 1;
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < n; ++j) {
			if (j < i) {
				L[i][j] = data[i][j];
				for (int k = 0; k < j; ++k) {
					L[i][j] -= L[i][k] * U[k][j];
				}
				L[i][j] /= U[j][j];
			}
		}
		for (int j = 1; j < n; ++j) {
			if (j >= i) {
				U[i][j] = data[i][j];
				for (int k = 0; k < i; ++k) {
					U[i][j] -= L[i][k] * U[k][j];
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			L[i][j] = U[i][j];
		}
	}
	return L;
}
#ifndef __MATRIX_H__
#define __MATRIX_H__

class matrix {
public:

	typedef double _Type;

	matrix(int columns, int rows);
	matrix(const matrix& other);
	~matrix();

	vector<_Type>& operator[](size_t i);

	void operator=(const matrix& other);
	matrix operator+(const matrix& other);
	matrix operator*(const matrix& other);
	matrix operator*(const double alpha);

	matrix LU_decomposition() const;

	//private:

	size_t columns, rows;
	vector<vector<_Type>> data;
};

matrix::matrix(int columns, int rows)
	: rows(rows), columns(columns)
{
	data.assign(rows, vector<_Type>(columns));
}

matrix::matrix(const matrix& other)
	: rows(other.rows), columns(other.columns)
{
	data.resize(rows);
	for (size_t i = 0; i < rows; ++i) {
		data[i].assign(other.data[i].begin(), other.data[i].end());
	}
}

matrix::~matrix() {
	for (size_t i = 0; i < data.size(); ++i) {
		data[i].clear();
	}
	data.clear();
}

void matrix::operator=(const matrix& other) {
	rows = other.rows;
	columns = other.columns;
	data.resize(rows);
	for (size_t i = 0; i < rows; ++i) {
		data[i].assign(other.data[i].begin(), other.data[i].end());
	}
}

vector<matrix::_Type>& matrix::operator[](size_t i) {
	return data[i];
}

matrix matrix::operator+(const matrix& other) {
	//if (rows != other.rows || columns != other.columns) {
	//
	//}
	matrix Res(rows, columns);
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			Res[i][j] = data[i][j] + other.data[i][j];
		}
	}
	return Res;
}

matrix matrix::operator*(const double alpha) {
	matrix Res(rows, columns);
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			Res[i][j] *= alpha;
		}
	}
	return Res;
}

matrix matrix::operator*(const matrix& other) {
	//if (columns != other.rows) {
	//
	//}
	matrix Res(rows, other.columns);
	for (size_t i = 0; i < Res.rows; ++i) {
		for (size_t j = 0; j < Res.columns; ++j) {
			Res[i][j] = 0;
			for (size_t k = 0; k < columns; ++k) {
				Res[i][j] += data[i][k] * other.data[k][j];
			}
		}
	}
	return Res;
}

matrix matrix::LU_decomposition() const {
	//if (rows != columns) {
	//
	//}
	size_t n = rows;
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
	/*for (int a = 0; a < n; ++a) {
	for (int b = 0; b < n; ++b) {
	cout << L[a][b] << " ";
	}
	cout << endl;
	}
	cout << endl;
	for (int a = 0; a < n; ++a) {
	for (int b = 0; b < n; ++b) {
	cout << U[a][b] << " ";
	}
	cout << endl;
	}
	cout << endl;*/
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			L[i][j] = U[i][j];
		}
	}
	return L;
}

#endif/*__MATRIX_H__*/
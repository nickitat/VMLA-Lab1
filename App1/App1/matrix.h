#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <ostream>
#include <vector>
using std::vector;

class matrix {
public:

	typedef long double _Type;

	matrix(int rows, int columns);
	matrix(const matrix& other);
	~matrix();

	size_t rows() const { return m_rows; }
	size_t columns() const { return m_columns; }

	vector<_Type> get_row(size_t i) const;
	vector<_Type> get_column(size_t j) const;

	vector<_Type>& operator[](size_t i);
	const vector<_Type>& operator[](size_t i) const;

	void operator=(const matrix& other);
	matrix operator+(const matrix& other);
	matrix operator*(const matrix& other);
	matrix operator*(const double alpha);

	bool operator==(const matrix& other);

	friend std::ostream& operator<<(std::ostream& os, const matrix& A);

	matrix LU_decomposition() const;

private:

	size_t m_columns, m_rows;
	vector<vector<_Type>> data;
};

#endif/*__MATRIX_H__*/
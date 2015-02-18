#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <vector>
using std::vector;

class matrix {
public:

	typedef long double _Type;

	matrix(int rows, int columns);
	matrix(const matrix& other);
	~matrix();

	vector<_Type>& operator[](size_t i);
	const vector<_Type>& operator[](size_t i) const;

	void operator=(const matrix& other);
	matrix operator+(const matrix& other);
	matrix operator*(const matrix& other);
	matrix operator*(const double alpha);

	matrix LU_decomposition() const;

	//private:

	size_t columns, rows;
	vector<vector<_Type>> data;
};

#endif/*__MATRIX_H__*/
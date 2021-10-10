#include "matrix.h"
double matrix::epsilon = 0.01;
matrix::matrix(const unsigned size1, const unsigned size2, const double value) 
{
	this->size1 = size1;
	this->size2 = size2;
	this->data = new double* [size1];
	for (unsigned i = 0; i < size1; i++)
	{
		data[i] = new double[size2];
	}
	for (unsigned i = 0; i < size1; i++)
	{
		for (unsigned j = 0; j < size2; j++)
		{
			data[i][j] = value;
		}
	}
};
double& matrix::operator()(const unsigned x, const unsigned y)
{
	if ((x >= size1) || (x < 0)) throw"Invalid Index";
	if ((y >= size2) || (y < 0)) throw"Invelid Index";
	return data[x][y];
}
matrix::matrix(const matrix& cp)
{
	this->size1 = cp.size1;
	this->size2 = cp.size2;
	this->data = new double* [size1];
	for (unsigned i = 0; i < size1; i++)
	{
		this->data[i] = new double[size2];
	}
	for (unsigned i = 0; i < size1; i++)
	{
		for (unsigned j = 0; j < size2; j++)
		{
			this->data[i][j] = cp.data[i][j];
		}
	}
}
matrix matrix::operator+(matrix& m2)
{
	if ((this->size1 != m2.size1) || (this->size2 != m2.size2)) throw"Different sizes";
	matrix res(size1,size2,0);
	for (unsigned i = 0; i < size1; i++)
	{
		for (unsigned j = 0; j < size2; j++)
		{
			res(i, j) = (*this)(i, j) + m2(i, j);
		}
	}
	return res;
}
matrix matrix::operator-(matrix& m2)
{
	if ((this->size1 != m2.size1) || (this->size2 != m2.size2)) throw"Different sizes";
	matrix res(size1, size2, 0);
	for (unsigned i = 0; i < size1; i++)
	{
		for (unsigned j = 0; j < size2; j++)
		{
			res(i, j) = (*this)(i, j) - m2(i, j);
		}
	}
	return res;
}
matrix matrix::operator*(matrix& m2)
{
	if (this->size2 != m2.size1) throw"Multiplication is impossible";
	matrix res(this->size1, m2.size2);
	for(unsigned i=0;i<size1;i++)
	{
		for (unsigned j = 0; j < res.size2; j++)
		{
			res(i,j) = 0;
			for (unsigned k = 0; k < this->size2; k++)
				res(i,j) += (*this)(i,k) * m2(k,j);
		}
	}
	return res;
}
matrix matrix::operator/(const double v)
{
	if (v == 0) { throw"Division by zero"; }
	matrix res(size1, size2);
	for (unsigned i = 0; i < size1; i++)
	{
		for (unsigned j = 0; j < size2; j++)
		{
			res(i, j) = (*this)(i, j) / v;
		}
	}
	return res;
}
double matrix::Trace()
{
	if (size1 != size2) { throw "It is not a square matrix"; }
	double res=0;
	for (unsigned i = 0; i < this->size1; i++)
	{
		for (unsigned j = 0; j < this->size2; j++)
		{
			if (i == j) { res += (*this)(i, j); }
		}
	}
	return res;
}
std::ostream& operator<<(std::ostream& out, matrix& m1)
{
	for (unsigned i = 0; i < m1.size1; i++)
	{
		for (unsigned j = 0; j < m1.size2; j++)
		{
			out << m1(i,j);
			out << '\t';
		}
		out << '\n';
	}
	return out;
}
matrix operator*(matrix& m1, const double value)
{
	matrix res(m1.size1, m1.size2);
	for (unsigned i = 0; i < res.size1; i++)
	{
		for (unsigned j = 0; j < res.size2; j++)
		{
			res(i, j) = m1(i, j) * value;
		}
	}
	return res;
}
matrix operator*(const double value, matrix& m1)
{
	return operator*(m1, value);
}
bool operator==(matrix& m1, matrix& m2)
{
	if ((m1.size1 != m2.size1) || (m1.size2 != m2.size2)) {return false;}
	for (unsigned i = 0; i < m1.size1; i++)
	{
		for (unsigned j = 0; j < m1.size2; j++)
		{
			if (fabs(m1(i,j) - m2(i,j)) > m1.epsilon) { return false; }
		}
	}
	return true;
}
bool operator!=(matrix& m1, matrix& m2)
{
	return !(operator==(m1,m2));
}
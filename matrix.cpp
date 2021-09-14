#include "matrix.h"
matrix::matrix(const unsigned size1, const unsigned size2, const double value) 
{
	this->size1 = size1;
	this->size2 = size2;
	this->data = new double* [size1];
	for (int i = 0; i < size1; i++)
	{
		data[i] = new double[size2];
	}
	for (unsigned i = 0; i < size1; i++)
	{
		for (unsigned j = 0; j < size2; j++)
		{
			data[i][j] = 0;
		}
	}
};
double& matrix::operator()(const unsigned x, const unsigned y)
{
	if ((x >= size1) || (x < 0)) throw"Invalid Index";
	if ((y >= size2) || (y < 0)) throw"Invelid Index";
	return data[x][y];

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
}
matrix matrix::operator*(matrix& m2)
{
	if (this->size2 != m2.size1) throw"Multiplication is impossible";
	matrix res(this->size1, m2.size2);
	for(unsigned i=0;i<size1;i++)
	{
		for (unsigned j = 0; j < m2.size2; j++)
		{
			res(i,j) = 0;
			for (int k = 0; k < this->size2; k++)
				res(i,j) += res(i,k) * res(k,j);
		}
	}
}
matrix matrix::operator*(const double v)
{
	matrix res(size1, size2);
	for (unsigned i = 0; i < size1; i++)
	{
		for (unsigned j = 0; j < size2; j++)
		{
			res(i, j) = (*this)(i, j)*v;
		}
	}
	return res;
}
matrix matrix::operator/(const double v)
{
	matrix res(size1, size2);
	for (unsigned i = 0; i < size1; i++)
	{
		for (unsigned j = 0; j < size2; j++)
		{
			res(i, j) = (i, j) / v;
		}
	}
	return res;
}
double matrix::Trace() const
{
	double res;
	for (unsigned i = 0; i < this->size1; i++)
	{
		for (unsigned j = 0; j < this->size2; j++)
		{
			if (i == j) res += (i,j);
		}
	}
	return res;
}
#pragma once
#include "iostream"
class matrix
{
private:
	double** data;
	unsigned size1;
	unsigned size2;
	static double epsilon;
public:
	matrix(const unsigned size1=2, const unsigned size2=2, const double value=0);
	matrix(const matrix& cp);
	const unsigned GetSize1() const { return size1; }
	const unsigned GetSize2() const { return size2; }
	double& operator()(const unsigned x, const unsigned y);
	matrix operator+(matrix& m2);
	matrix operator-(matrix& m2);
	matrix operator*(matrix& m2);
	matrix operator/(const double v);
	double Trace();
	friend std::ostream& operator<<(std::ostream& out, matrix& m1);
	friend matrix operator*(matrix& m1, const double value);
	friend matrix operator*(const double value, matrix& m1);
	friend bool operator==(matrix& m1, matrix& m2);
	friend bool operator!=(matrix& m1, matrix& m2);
};


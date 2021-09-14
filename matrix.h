#pragma once
class matrix
{
private:
	double** data;
	unsigned size1;
	unsigned size2;
public:
	matrix(const unsigned size1=2, const unsigned size2=2, const double value=0);
	double& operator()(const unsigned x, const unsigned y);
	matrix operator+(matrix& m2);
	matrix operator-(matrix& m2);
	matrix operator*(matrix& m2);
	matrix operator*(const double v);
	matrix operator/(const double v);
	double Trace() const;
};


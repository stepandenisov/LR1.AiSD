#include "stdio.h"
#include "iostream"
#include "matrix.h"
int main()
{
	matrix a(3, 3, 4), b(3, 3, 2);
	std::cout << a << b;
}
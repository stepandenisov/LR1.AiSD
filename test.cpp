#include "pch.h"
#include "../LR1.AiSD/matrix.h"
TEST(OperatorTest, OperatorValue) {
	matrix a;
	try
	{
		a(3, 3) = 9;
	}
	catch (const char* err)
	{
		FAIL() << err;
	}
	ASSERT_EQ(a(1, 1), 0);
	a(1, 1) = 3;
	ASSERT_EQ(a(1, 1), 3);
}
TEST(ConstructorTest, Default) {
	matrix a;
	ASSERT_EQ(a.GetSize1(), 2);
	ASSERT_EQ(a.GetSize2(), 2);
	for (unsigned i = 0; i < a.GetSize1(); i++)
	{
		for (unsigned j = 0; j < a.GetSize2(); j++)
		{
			ASSERT_EQ(a(i, j), 0);
		}
	}
}
TEST(ConstructorTest, Parameterized) {
	matrix a(3, 3, 2);
	ASSERT_EQ(a.GetSize1(), 3);
	ASSERT_EQ(a.GetSize2(), 3);
	for (unsigned i = 0; i < a.GetSize1(); i++)
	{
		for (unsigned j = 0; j < a.GetSize2(); j++)
		{
			ASSERT_EQ(a(i, j), 2);
		}
	}
}
TEST(ConstructorTest, Copy) {
	matrix a(3, 3, 3), b = a;
	ASSERT_EQ(b.GetSize1(), 3);
	ASSERT_EQ(b.GetSize2(), 3);
	for (unsigned i = 0; i < a.GetSize1(); i++)
	{
		for (unsigned j = 0; j < a.GetSize2(); j++)
		{
			ASSERT_EQ(b(i, j), 3);
		}
	}
}
TEST(OperatorTest, OperatorAddition) {
	matrix a(3, 3, 1), b(3, 3, 7), c;
	try
	{
		c = a + b;
	}
	catch (const char* err)
	{
		FAIL() << err;
	}
	ASSERT_EQ(c.GetSize1(), 3);
	ASSERT_EQ(c.GetSize2(), 3);
	for (unsigned i = 0; i < c.GetSize1(); i++)
	{
		for (unsigned j = 0; j < c.GetSize2(); j++)
		{
			ASSERT_EQ(c(i, j), 8);
		}
	}
}
TEST(OperatorTest, OperatorDifference) {
	matrix a(3, 3, 1), b(3, 3, 7), c;
	try
	{
		c = a - b;
	}
	catch (const char* err)
	{
		FAIL() << err;
	}
	ASSERT_EQ(c.GetSize1(), 3);
	ASSERT_EQ(c.GetSize2(), 3);
	for (unsigned i = 0; i < c.GetSize1(); i++)
	{
		for (unsigned j = 0; j < c.GetSize2(); j++)
		{
			ASSERT_EQ(c(i, j), 6);
		}
	}
}
TEST(OperatorTest, OperatorMatrixMultiplication) {
	matrix a(2, 3, 2), b(3, 4, 7), c;
	try
	{
		c = a * b;
	}
	catch (const char* err)
	{
		FAIL() << err;
	}
	ASSERT_EQ(c.GetSize1(), 2);
	ASSERT_EQ(c.GetSize2(), 4);
	for (unsigned i = 0; i < c.GetSize1(); i++)
	{
		for (unsigned j = 0; j < c.GetSize2(); j++)
		{
			ASSERT_EQ(c(i, j), 42);
		}
	}
}
TEST(OperatorTest, OperatorDivision) {
	matrix a(2, 3, 2), c;
	double v = 4;
	try
	{
		c = a / v;
	}
	catch (const char* err)
	{
		FAIL() << err;
	}
	matrix c = a / v;
	ASSERT_EQ(c.GetSize1(), 2, L"1");
	ASSERT_EQ(c.GetSize2(), 3);
	for (unsigned i = 0; i < c.GetSize1(); i++)
	{
		for (unsigned j = 0; j < c.GetSize2(); j++)
		{
			ASSERT_EQ(c(i, j), 0.5);
		}
	}
}
TEST(MethodTest, TraceTest) {
	matrix a(3, 3, 5);
	double res = a.Trace();
	ASSERT_EQ(res, 15);
}
TEST(OperatorTest, OperatorMultiplicationMatrixNumber) {
	matrix a(3, 3, 4), c = a * 2, d = 3 * a;
	ASSERT_EQ(c.GetSize1(), 3);
	ASSERT_EQ(c.GetSize2(), 3);
	for (unsigned i = 0; i < c.GetSize1(); i++)
	{
		for (unsigned j = 0; j < c.GetSize2(); j++)
		{
			ASSERT_EQ(c(i, j), 8);
		}
	}
	ASSERT_EQ(d.GetSize1(), 3);
	ASSERT_EQ(d.GetSize2(), 3);
	for (unsigned i = 0; i < c.GetSize1(); i++)
	{
		for (unsigned j = 0; j < c.GetSize2(); j++)
		{
			ASSERT_EQ(d(i, j), 12);
		}
	}
}
TEST(OperatorTest, OperatorCompare) {
	matrix a(2, 3, 2), b(2, 3, 2), c(2, 3, 4);
	bool res1 = (a == b), res2 = false, res3 = (a != c), res4 = true;
	for (unsigned i = 0; i < a.GetSize1(); i++)
	{
		for (unsigned j = 0; j < a.GetSize2(); j++)
		{
			if (a(i, j) == b(i, j)) { res2 = true; }
			else { res2 = false; }
			if (a(i, j) != c(i, j)) { res4 = true; }
			else { res4 = false; }
		}
	}
	ASSERT_EQ(res1, res2);
	ASSERT_EQ(res3, res4);
}

#include "Polynomial.hpp"
#include "doctest.h"
#include <sstream>
TEST_CASE("operator==")
{
	Polynomial<int> p1(4);
	Polynomial<int> p2(4);
	CHECK_EQ(p1,p2);
}
TEST_CASE("operator>")
{
	Polynomial<int> p1(5);
	Polynomial<int> p2(4);
	CHECK_NE(p1, p2);
}
TEST_CASE("operator+")
{
	int* arr = new int[5];
	arr[0] = -2;
	arr[1] = 0;
	arr[2] = 3;
	arr[3] = 5;
	arr[4] = 8;
	Polynomial<int> p1(arr, 5);
	int* arr1 = new int[5];
	arr1[0] = -2;
	arr1[1] = -3;
	arr1[2] =  4;
	arr1[3] = -1;
	arr1[4] =  3;
	Polynomial<int> p2(arr1, 5);
	int* arr2 = new int[5];
	arr2[0] = -4;
	arr2[1] = -3;
	arr2[2] = 7;
	arr2[3] = 4;
	arr2[4] = 11;
	Polynomial<int> p3(arr2,5);
	CHECK_EQ(p1 + p2, p3);
}
TEST_CASE("operator*")
{
	int* arr = new int[5];
	arr[0] = -2;
	arr[1] = 0;
	arr[2] = 3;
	arr[3] = 5;
	arr[4] = 8;
	Polynomial<int> p1(arr, 5);
	int* arr1 = new int[5];
	arr1[0] = -2;
	arr1[1] = -3;
	arr1[2] = 4;
	arr1[3] = -1;
	arr1[4] = 3;
	Polynomial<int> p2(arr1, 5);
	int* arr2 = new int[4];
	arr2[0] = 3;
	arr2[1] = -1;
	arr2[2] = 6;
	arr2[3] = 5;
	Polynomial<int> p3(arr2, 4);
	CHECK_EQ(p1 - p2, p3);
}
TEST_CASE("operator/")
{
	int* arr = new int[4];
	arr[0] = 2;
	arr[1] = 3;
	arr[2] = -4;
	arr[3] = 1;
	Polynomial<int> p1(arr, 4);
	int* arr1 = new int[3];
	arr1[0] = 1;
	arr1[1] = 2;
	arr1[2] = 2;
	Polynomial<int> p2(arr1, 3);
	int* arr2 = new int[2];
	arr2[0] = -6;
	arr2[1] = 3;
	Polynomial<int> p3(arr2, 2);
	CHECK_EQ(p1 / p2, p3);
}
TEST_CASE("operator%")
{
	int* arr = new int[4];
	arr[0] = 2;
	arr[1] = 3;
	arr[2] = -4;
	arr[3] = 1;
	Polynomial<int> p1(arr, 4);
	int* arr1 = new int[3];
	arr1[0] = 1;
	arr1[1] = 2;
	arr1[2] = 2;
	Polynomial<int> p2(arr1, 3);
	int* arr2 = new int[2];
	arr2[0] = 2;
	arr2[1] = -1;
	Polynomial<int> p3(arr2, 2);
	CHECK_EQ(p1 % p2, p3);
}
TEST_CASE("operator()")
{
	int* arr = new int[4];
	arr[0] = 2;
	arr[1] = 3;
	arr[2] = -4;
	arr[3] = 1;
	Polynomial<int> f(arr, 4);
	CHECK_EQ(f(3), 70);
}
TEST_CASE("definite integral")
{
	Polynomial<double> f(2,1);
	CHECK_EQ(f(-1,2), 3);
}
TEST_CASE("derivative")
{
	int* arr = new int[3];
	arr[0] = 3;
	arr[1] = 5;
	arr[2] = 4;
	Polynomial<int> f(arr, 3);
	int* arr1 = new int[2];
	arr1[0] = 6;
	arr1[1] = 5;
	Polynomial<int> result(arr1, 2);
	CHECK_EQ(--f, result);
	CHECK_EQ(f--, result);
}
TEST_CASE("integration")
{
	double* arr = new double[3];
	arr[0] = 3;
	arr[1] = 2;
	arr[2] = -7;
	Polynomial<double> f(arr, 3);
	double* arr1 = new double[4];
	arr1[0] = 1;
	arr1[1] = 1;
	arr1[2] = -7;
	arr1[3] = 0;
	Polynomial<double> result(arr1, 4);
	CHECK_EQ(++f, result);
	CHECK_EQ(f++, result);
}
TEST_CASE("indexing")
{
	double* arr = new double[3];
	arr[0] = 3;
	arr[1] = 2;
	arr[2] = -7;
	Polynomial<double> f(arr[1], 3);
	CHECK_EQ(arr[1], 2);
	CHECK_EQ(arr[0], 3);
}
TEST_CASE("indexing")
{
	double* arr = new double[3];
	arr[0] = 3;
	arr[1] = 2;
	arr[2] = -7;
	Polynomial<double> f(arr[1], 3);
	CHECK_EQ(arr[1], 2);
	CHECK_EQ(arr[0], 3);
}
TEST_CASE("not Zero")
{
	double* arr = new double[3];
	arr[0] = 3;
	arr[1] = 2;
	arr[2] = -7;
	Polynomial<double> f(arr[1], 3);
	CHECK_EQ(!f, 1);
	CHECK_EQ(!f, 1);
}
TEST_CASE("cast Polynomial to int")
{
	int* arr = new int[3];
	arr[0] = 3;
	arr[1] = 2;
	arr[2] = -7;
	Polynomial<int> f(arr, 3);
	int temp = f;
	CHECK_EQ(temp, 2);
}
TEST_CASE("cast Polynomial to bool")
{
	int* arr = new int[3];
	arr[0] = 3;
	arr[1] = 2;
	arr[2] = -7;
	Polynomial<int> f(arr, 3);
	bool temp = f;
	CHECK_EQ(temp, 0);
	CHECK_EQ(!f, 1);
}
TEST_CASE("operator <<")
{
	int* arr = new int[3];
	arr[0] = 3;
	arr[1] = 2;
	arr[2] = -7;
	Polynomial<int> f(arr, 3);
	ostringstream os;
	os << f;
	string temp = "f(x) = 3x^2+2x-7\n";
	CHECK_EQ(os.str(), temp);
}
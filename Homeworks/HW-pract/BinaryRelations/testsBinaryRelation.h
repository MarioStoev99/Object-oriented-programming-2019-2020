#pragma once
#include "doctest.h"
#include "BinaryRelation.h"

TEST_CASE("t and u are in relation")
{
	Pair<int, String> pair[5];
	pair[0] = { 1,"one" };
	pair[1] = { 2,"two" };
	pair[2] = { 3,"three"};
	pair[3] = { 4,"four" };
	pair[4] = { 5,"five" };
	BinaryRelation<int, String> r("nameOf",pair,5);
	CHECK_EQ(r(1, "four"), 0);
	CHECK_EQ(r(6, "four"), 0);
	CHECK_EQ(r(3, "four"), 0);
}
TEST_CASE("Union")
{
	Pair<int, String> pair1[2];
	pair1[0] = { 1,"one" };
	pair1[1] = { 2,"two" };
	BinaryRelation<int, String> r1("nameOf", pair1, 2);
	Pair<int, String> pair2[3];
	pair2[0] = { 1,"one" };
	pair2[1] = { 2,"two" };
	pair2[2] = { 3,"three" };
	BinaryRelation<int, String> r2("nameOf", pair2, 3);
	BinaryRelation<int, String> r3("nameOf", pair2, 3);
	CHECK_EQ(r1 + r2, r3);
}
TEST_CASE("Insection")
{
	Pair<int, String> pair1[2];
	pair1[0] = { 1,"one" };
	pair1[1] = { 2,"two" };
	BinaryRelation<int, String> r1("nameOf", pair1, 2);
	Pair<int, String> pair2[3];
	pair2[0] = { 1,"one" };
	pair2[1] = { 2,"two" };
	pair2[2] = { 3,"three" };
	BinaryRelation<int, String> r2("nameOf", pair2, 3);
	BinaryRelation<int, String> r3("nameOf", pair1, 2);
	CHECK_EQ(r1 ^ r2, r3);
}
TEST_CASE("Multi")
{
	Pair<int, String> pair1[2];
	pair1[0] = { 1,"one" };
	pair1[1] = { 2,"two" };
	BinaryRelation<int, String> r1("nameOf", pair1, 2);
	Pair<String, int> pair2[3];
	pair2[0] = { "one",1 };
	pair2[1] = { "two",2 };
	pair2[2] = { "three",3 };
	BinaryRelation<String, int> r2("nameOf", pair2, 3);
	Pair<int, int> pair3[2];
	pair3[0] = { 1,1 };
	pair3[1] = { 2,2 };
	BinaryRelation<int, int> r3("nameOf", pair3, 2);
	CHECK_EQ(r1 * r2, r3);
}
TEST_CASE("image")
{
	Pair<int, int> pair1[5];
	pair1[0] = { 1,2 };
	pair1[1] = { 2,3};
	pair1[2] = { 3,4};
	pair1[3] = { 4, 5};
	pair1[4] = { 4, 6};
	BinaryRelation<int, int> r1("nameOf", pair1, 5);
	int* temp = r1[4];
	int arr[2] = { 6,5 };
	for (int i = 0; i < r1.getSize(); i++)
	{
		CHECK_EQ(temp[i], arr[i]);
	}
	delete[] temp;
}
TEST_CASE("function")
{
	Pair<int, String> pair1[5];
	pair1[0] = { 1,"one" };
	pair1[1] = { 2,"two" };
	pair1[2] = { 3,"three"};
	pair1[3] = { 4,"four" };
	pair1[4] = { 5,"five" };
	BinaryRelation<int, String> r1("nameOf", pair1, 5);
	CHECK_EQ(r1.function(), 1);
	Pair<int, int> pair2[5];
	pair2[0] = { 2,3 };
	pair2[1] = { 2,4 };
	pair2[2] = { 3,5 };
	pair2[3] = { 4,6 };
	pair2[4] = { 5,7 };
	BinaryRelation<int,int> r2("nameOf", pair2, 5);
	CHECK_EQ(r2.function(), 0);
}
TEST_CASE("injection")
{
	Pair<int, String> pair1[5];
	pair1[0] = { 1,"one" };
	pair1[1] = { 2,"one" };
	pair1[2] = { 3,"three" };
	pair1[3] = { 4,"four" };
	pair1[4] = { 5,"five" };
	BinaryRelation<int, String> r1("nameOf", pair1, 5);
	CHECK_EQ(r1.injection(), 0);
	Pair<int, int> pair2[5];
	pair2[0] = { 2,3 };
	pair2[1] = { 2,4 };
	pair2[2] = { 3,5 };
	pair2[3] = { 4,6 };
	pair2[4] = { 5,7 };
	BinaryRelation<int, int> r2("oxoboxo", pair2, 5);
	CHECK_EQ(r2.injection(), 0);
	Pair<int, int> pair3[2];
	pair3[0] = { 0,1 };
	pair3[1] = { 1,2 };
	BinaryRelation<int, int> r3("oxoboxo", pair3, 2);
	CHECK_EQ(r3.injection(), 1);
}

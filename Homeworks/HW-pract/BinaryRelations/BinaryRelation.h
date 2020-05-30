#include <iostream>
#include <typeinfo>
#include "Pair.h"
#include "String.h"
using namespace std;
#pragma once
template <typename T, typename U>
class BinaryRelation
{
private:
	Pair<T, U>* arr;
	String nameofRelation;
	size_t size;

	void copy(const BinaryRelation&);
	void del();

	// Union
	void transferElements(const BinaryRelation&);
	void removeRepeats();

public:
	//big 4
	BinaryRelation(String = "");
	BinaryRelation(String, Pair<T,U>*,size_t);
	BinaryRelation(const BinaryRelation&);
	BinaryRelation& operator=(const BinaryRelation&);
	~BinaryRelation();

	String getName() const { return nameofRelation; }
	// cin,cout
	template <typename X, typename Y>
	friend istream& operator>>(istream&, BinaryRelation<X, Y>&);
	template <typename X, typename Y>
	friend ostream& operator<<(ostream&, const BinaryRelation<X, Y>&);
	template<typename X, typename Y,typename Z>
	friend BinaryRelation<X, Z> operator*(const BinaryRelation<X, Y>&, const BinaryRelation<Y, Z>&);
	//aritmetic operations
	BinaryRelation& operator+=(const BinaryRelation&);
	template<typename Y>
	BinaryRelation<T,Y>& operator*=(const BinaryRelation<Y,Y>&);
	BinaryRelation& operator^=(const BinaryRelation&);
	// is Relation?
	bool operator()(T, U) const;
	// swap elements of pair
	void operator!();
	// compare relations
	bool operator==(const BinaryRelation&) const;

	T* dom() const;
	U* ran() const;
	U* operator[](T);
	T* operator()(U);
	//pridicates
	bool function() const;
	bool injection() const;
	// ...
	int getSize() const { return size; }
};
template <typename T, typename U>
void BinaryRelation<T, U>::copy(const BinaryRelation& other)
{
	nameofRelation = other.nameofRelation;
	size = other.size;
	arr = new Pair<T, U>[other.size];
	for (int i = 0; i < other.size; i++)
		arr[i] = other.arr[i];
}
template <typename T, typename U>
void BinaryRelation<T, U>::del()
{
	delete[] arr;
	arr = nullptr;
}
template <typename T, typename U>
BinaryRelation<T, U>::BinaryRelation(String _nameofRelation)
{
	arr = nullptr;
	nameofRelation = _nameofRelation;
	size = 0;
}
template<typename T,typename U>
BinaryRelation<T, U>::BinaryRelation(String _nameofRelation,Pair<T,U>* _pairs,size_t _size)
{
	arr = new Pair<T,U>[_size];
	for (int i = 0; i < _size; i++)
		arr[i] = _pairs[i];
	size = _size;
	nameofRelation = _nameofRelation;
}
template <typename T, typename U>
BinaryRelation<T, U>::BinaryRelation(const BinaryRelation& other)
{
	copy(other);
}
template <typename T, typename U>
BinaryRelation<T, U>& BinaryRelation<T, U>::operator=(const BinaryRelation& other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}
	return *this;
}
template <typename T, typename U>
BinaryRelation<T, U>::~BinaryRelation()
{
	del();
}
template <typename T, typename U>
ostream& operator<<(ostream& out,const BinaryRelation<T,U>& b)
{
	for (int i = 0; i < b.size; i++)
		out << b.nameofRelation << "(" << b.arr[i].first << "," << b.arr[i].second << ")" << endl;
	return out;
}
template <typename T, typename U>
istream& operator>>(istream& in, BinaryRelation<T, U>& b)
{
	cout << "Enter the number of relations : ";
	in >> b.size;
	if(typeid(T).name() == typeid(String).name())
		in.ignore();
	Pair<T, U>* newPairs = new Pair<T, U>[b.size];
	for (int i = 0; i < b.size; i++)
	{
		in >> newPairs[i].first;
		if (typeid(U).name() == typeid(String).name() && typeid(T).name() != typeid(String).name())
			in.ignore();
		in >> newPairs[i].second;
		if (typeid(U).name() != typeid(String).name() && typeid(T).name() == typeid(String).name())
			in.ignore();
	}
	delete[] b.arr;
	b.arr = newPairs;
	b.removeRepeats();
	return in;
}
template <typename T, typename U>
bool BinaryRelation<T, U>::operator()(T x,U y) const
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i].first == x && arr[i].second == y)
			return true;
	}
	return false;
}
template <typename T, typename U>
void BinaryRelation<T, U>::operator!()
{
	Pair<U, T>* newPairs = new Pair<T, U>[size];
	for (int i = 0; i < size; i++)
	{
		newPairs[i].first = arr[i].second;
		newPairs[i].second = arr[i].first;
	}
	delete[] arr;
	arr = newPairs;
}
template <typename T, typename U>
void BinaryRelation<T, U>::transferElements(const BinaryRelation& other)
{
	Pair<T, U>* newArr = new Pair<T, U>[size + other.size];
	int i;
	for (i = 0; i < size; i++)
		newArr[i] = arr[i];
	for (int j = 0; j < other.size; j++)
		newArr[i++] = other.arr[j];
	delete[] arr;
	size += other.size;
	arr = newArr;
}
template <typename T, typename U>
void BinaryRelation<T, U>::removeRepeats() 
{
	for (int i = 0; i < size; i++)
	{
		int j = i + 1;
		while(j < size)
		{
			if (arr[i] == arr[j])
			{
				swap(arr[j], arr[size - 1]);
				size--;
			}
			else
				j++;
		}
	}
}
template <typename T, typename U>
BinaryRelation<T,U>& BinaryRelation<T,U>::operator+=(const BinaryRelation& second)
{
	this->transferElements(second);
	this->removeRepeats();
	return *this;
}
template <typename T, typename U>
BinaryRelation<T, U> operator+(const BinaryRelation<T,U>& first,const BinaryRelation<T,U>& second)
{
	BinaryRelation<T, U> temp = first;
	temp += second;
	return temp;
}
template <typename T, typename U>
BinaryRelation<T, U>& BinaryRelation<T, U>::operator^=(const BinaryRelation& second)
{
	int i = 0;
	while (i < size)
	{
		bool insectionPair = false;
		for (int j = 0; j < second.size; j++)
		{
			bool condition = (arr[i].first == second.arr[j].first && arr[i].second == second.arr[j].second);
			if (condition)
			{
				insectionPair = true;
				break;
			}
		}
		if (!insectionPair)
		{
			swap(arr[i], arr[size - 1]);
			size--;
		}
		else i++;
	}
	return *this;
}
template <typename T, typename U>
BinaryRelation<T, U> operator^(const BinaryRelation<T,U>& first,const BinaryRelation<T,U>& second)
{
	BinaryRelation<T, U> temp = first;
	temp ^= second;
	return temp;
}
template <typename T, typename U>
U* BinaryRelation<T, U>::operator[](T t)
{
	U* newArr = new U[size];
	int i = 0;
	while(i < size)
	{
		if (arr[i].first == t)
		{
			newArr[i] = arr[i].second;
			i++;
		}
		else
		{
			swap(arr[i], arr[size - 1]);
			size--;
		}
	}
	return newArr;
}
template <typename T, typename U>
T* BinaryRelation<T, U>::operator()(U u)
{
	T* newArr = new T[size];
	int i = 0;
	while (i < size)
	{
		if (arr[i].second == u)
		{
			newArr[i] = arr[i].first;
			i++;
		}
		else
		{
			swap(arr[i], arr[size - 1]);
			size--;
		}
	}
	return newArr;
}
template <typename T, typename U>
T* BinaryRelation<T, U>::dom() const
{
	T* newArr = new T[size];
	for(int i = 0;i < size;i++)
		newArr[i] = arr[i].first;
	return newArr;
}
template <typename T, typename U>
U* BinaryRelation<T, U>::ran() const
{
	U* newArr = new U[size];
	for (int i = 0; i < size; i++)
		newArr[i] = arr[i].second;
	return newArr;
}
template <typename T,typename U>
bool BinaryRelation<T, U>::function() const
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i].first == arr[j].first)
				return false;
		}
	}
	return true;
}
template <typename T, typename U>
bool BinaryRelation<T, U>::injection() const
{
	if (this->function())
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (arr[i].second == arr[j].second)
					return false;
			}
		}
	}
	else return false;
	return true;
}
template<typename T,typename U,typename V>
BinaryRelation<T,V> operator*(const BinaryRelation<T,U>& lhs,const BinaryRelation<U,V>& rhs)
{
	Pair<T, V>* newPair = new Pair<T, V>[lhs.size * rhs.size];
	int index = 0;
	BinaryRelation<T, V> temp;
	for (int i = 0; i < lhs.size; i++)
	{
		for (int j = 0; j < rhs.size; j++)
		{
			if (lhs.arr[i].second == rhs.arr[j].first)
			{
				newPair[index].first = lhs.arr[i].first;
				newPair[index].second = rhs.arr[j].second;
				index++;
			}
		}
	}
	temp.size = index;
	temp.arr = newPair;
	return temp;
}
template<typename T,typename U>
template<typename Y>
BinaryRelation<T, Y>& BinaryRelation<T, U>::operator*=(const BinaryRelation<Y, Y>& rhs)
{
	*this = *this * rhs;
	return *this;
}
template <typename T,typename U>
bool BinaryRelation<T, U>::operator==(const BinaryRelation& rhs) const
{
	if (size != rhs.size)
		return false;
	for (int i = 0; i < size; i++)
	{
		int cnt = 0;
		for (int j = 0; j < rhs.size; j++)
		{
			if (arr[i] == rhs.arr[i])
			{
				cnt++;
				break;
			}
		}
		if (cnt == 0)
			return false;
	}
	return true;
}
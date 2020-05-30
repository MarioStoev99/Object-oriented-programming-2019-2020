#include <iostream>
#include <cmath>
using namespace std;
#pragma once

template <typename T>
class Polynomial
{
public:
	class Iterator
	{
	public:
		T* it;
	public:
		Iterator(T* elements) : it(elements) {}
		// operators for increment and decrement
		Iterator operator++(int)
		{
			Iterator temp(*this);
			++this->it;
			return temp;
		}
		Iterator& operator++()
		{
			++this->it;
			return *this;
		}
		Iterator operator--(int)
		{
			Iterator temp(*this);
			--this->it;
			return temp;
		}
		Iterator& operator--()
		{
			--this->it;
			return *this;
		}
		T* operator->() { return this->it; }
		T& operator*() { return (*this->it); }
		bool operator==(const Iterator& other) { return this->it == other.it;}
		bool operator!=(const Iterator& other) { return this->it != other.it; }
		bool operator>(const Iterator& other) { return this->it > other.it; }
		bool operator<(const Iterator& other) { return this->it < other.it; }
		bool operator>=(const Iterator& other) { return this->it >= other.it; }
		bool operator<=(const Iterator& other) { return this->it <= other.it; }
	};
private :
	T* arr = nullptr;
	size_t size;

	void copy(const Polynomial&);
	void del();
	void resize();

	void removeSeniorZeroes();
public : 
	// big 4
	Polynomial(size_t = 0,T = 0);
	Polynomial(T* arr, size_t);
	Polynomial(const Polynomial&);
	Polynomial& operator=(const Polynomial&);
	~Polynomial();
	Iterator begin() const { return Iterator(arr); }
	Iterator end() const   { return Iterator(arr + size); }
	// lenght
	size_t lenght() const { return size; }
	// compare functions
	bool operator==(const Polynomial&) const;
	bool operator!=(const Polynomial&) const;
	bool operator>=(const Polynomial&) const;
	bool operator<=(const Polynomial&) const;
	bool operator>(const Polynomial&) const;
	bool operator<(const Polynomial&) const;
	//aritmetics operations
	Polynomial& operator+=(const Polynomial&);
	Polynomial& operator-=(const Polynomial&);
	Polynomial& operator*=(const Polynomial&);
	Polynomial& operator/=(const Polynomial&);
	Polynomial& operator%=(const Polynomial&);
	Polynomial& operator*=(T);
	Polynomial& operator/=(T);
	//index operation
	T& operator[](size_t);
	//find value of f(x)
	T operator()(T) const;
	// operations for increment and decrement
	Polynomial& operator--();
	Polynomial operator--(int);
	Polynomial& operator++();
	Polynomial operator++(int);
	// cin,cout
	template <typename P>
	friend istream& operator>>(istream&,Polynomial<P>&);
	template <typename P>
	friend ostream& operator<<(ostream&, const Polynomial<P>&);
	//polynomial to int
	operator int() const;
	//definite integrals
	T operator()(T a, T b);
	// polynomial to bool
	operator bool() const;
	bool operator!() const;

};

template <typename T>
void Polynomial<T>::copy(const Polynomial& other)
{
	arr = new T[other.size];
	for (int i = 0; i < other.size; i++)
	{
		arr[i] = other.arr[i];
	}
	size = other.size;
}
template <typename T>
void Polynomial<T>::del()
{
	delete[] arr;
}
template <typename T>
void Polynomial<T>::resize()
{
	T* newArr = new T[size + 1];
	for (int i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}
	del();
	arr = newArr;
	size += 1;
}
template <typename T>
Polynomial<T>::Polynomial(size_t _size,T seniorMember)
{
	size = _size + 1;
	arr = new T[size];
	arr[0] = seniorMember;
	for (int i = 1; i < size; i++)
	{
		arr[i] = 0;
	}
}
template <typename T>
Polynomial<T>::Polynomial(T* _arr, size_t _size)
{
	size = _size;
	arr = _arr;
}
template <typename T>
Polynomial<T>::Polynomial(const Polynomial& other)
{
	copy(other);
}
template <typename T>
Polynomial<T>& Polynomial<T>::operator=(const Polynomial& other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}
	return *this;
}	
template <typename T>
Polynomial<T>::~Polynomial()
{
	del();
}
// This function is not convenient for comparing polynomials,because the polynomials 
// are compare in degrees,not their values
/*
template <typename T>
bool Polynomial<T>::operator==(const Polynomial& second) const
{
	return size == second.size;
}
*/
template <typename T>
bool Polynomial<T>::operator==(const Polynomial& second) const
{
	if (size != second.size)
		return false;
	for (int i = 0; i < size; i++)
	{
		if (this->arr[i] != second.arr[i])
			return false;
	}
	return true;
}
template <typename T>
bool Polynomial<T>::operator!=(const Polynomial& second) const
{
	return size != second.size;
}
template <typename T>
bool Polynomial<T>::operator>=(const Polynomial& second) const
{
	return size >= second.size;
}
template <typename T>
bool Polynomial<T>::operator<=(const Polynomial& second) const
{
	return size <= second.size;
}
template <typename T>
bool Polynomial<T>::operator<(const Polynomial& second) const
{
	return size < second.size;
}
template <typename T>
bool Polynomial<T>::operator>(const Polynomial& second) const
{
	return size > second.size;
}
template <typename T>
Polynomial<T>& Polynomial<T>::operator+=(const Polynomial& second)
{
	T* newArr = nullptr;
	if (size >= second.size)
	{
		int j = 0;
		for (int i = size - second.size; i < size; i++)
		{
			arr[i] += second.arr[j++];
		}
	}
	else 
	{
		newArr = new T[second.size];
		int i = 0;
		int j = 0;
		while (i < second.size - size)
		{
			newArr[i] = second.arr[i];
			i++;
		}
		for (i; i < second.size; i++)
		{
			newArr[i] = arr[j++] + second.arr[i];
		}
		delete[] arr;
		arr = newArr;
		size = second.size;
	}
	return *this;
}
template <typename T>
Polynomial<T>& Polynomial<T>::operator-=(const Polynomial& second)
{
	for (int i = 0; i < second.size; i++)
		second.arr[i] *= -1;
	*this += second;
	this->removeSeniorZeroes();
	return *this;
}
template <typename T>
Polynomial<T> operator+(const Polynomial<T>& first, const Polynomial<T>& second)
{
	Polynomial<T> temp = first;
	temp += second;
	return temp;
}
template <typename T>
Polynomial<T> operator-(const Polynomial<T>& first, const Polynomial<T>& second)
{
	Polynomial<T> temp = first;
	temp -= second;
	return temp;
}
template <typename T>
Polynomial<T>& Polynomial<T>::operator*=(const Polynomial<T>& second)
{
	size_t newSize = size + second.size - 1;
	T* newArr = new T[newSize];
	for (int i = 0; i < newSize; i++)
		newArr[i] = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < second.size; j++)
		{
			T sum = arr[i] * second.arr[j];
			newArr[i + j] += sum;
		}
	}
	delete[] arr;
	arr = newArr;
	size = newSize;
	return *this;
}
template<typename T>
Polynomial<T> operator*(const Polynomial<T>& first, const Polynomial<T>& second)
{
	Polynomial<T> temp = first;
	temp *= second;
	return temp;
}
template <typename T>
Polynomial<T>& Polynomial<T>::operator/=(const Polynomial& second)
{
	if (size < second.size)
		throw exception("delish po-niska stepen na po-visoka");
	while (size >= second.size)
	{
		Polynomial<T> cloningSecond = second;
		T seniorMember = arr[0] / second.arr[0];
		unsigned diff = size - second.size;
		Polynomial<T> remainder(diff, seniorMember);
		cloningSecond *= remainder;
		*this -= cloningSecond;
		this->removeSeniorZeroes();
	}
	this->removeSeniorZeroes();
	return *this;
}
template <typename T>
Polynomial<T> operator/(const Polynomial<T>& first,const Polynomial<T>& second)
{
	Polynomial<T> temp = first;
	temp /= second;
	return temp;
}
template <typename T>
void Polynomial<T>::removeSeniorZeroes() 
{
	T* newArr = nullptr;
	bool flag = false;
	while (arr[0] == 0)
	{
		flag = true;
		for (int i = 0; i < size - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		size--;
	}
	if (flag == true)
	{
		newArr = new T[size];
		for (int i = 0; i < size; i++)
		{
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
	}
}
template <typename T>
Polynomial<T>& Polynomial<T>::operator%=(const Polynomial& second)
{
	Polynomial<T> result;
	if (size < second.size)
		throw "delish po-niska stepen na po-visoka";
	while (size >= second.size)
	{
		Polynomial<T> cloningSecond = second;
		T seniorMember = arr[0] / second.arr[0];
		unsigned diff = size - second.size;
		Polynomial<T> remainder(diff, seniorMember);
		result += remainder;
		cloningSecond *= remainder;
		*this -= cloningSecond;
		this->removeSeniorZeroes();
	}
	*this = result;
	return *this;
}
template <typename T>
Polynomial<T> operator%(const Polynomial<T>& first, const Polynomial<T>& second)
{
	Polynomial<T> remainder = first;
	remainder %= second;
	return remainder;
}
template <typename T>
T& Polynomial<T>::operator[](size_t x)
{
	if(x >= 0 && x < size)
		return arr[x];
	else
		throw exception("this index not exist");
}
template <typename T>
T Polynomial<T>::operator()(T x) const
{
	T sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i] * pow(x, size - 1 - i);
	}
	return sum;
}
template <typename T>
Polynomial<T>& Polynomial<T>::operator--()
{
	for (int i = 0; i < size; i++)
	{
		arr[i] *= (size - 1 - i);
	}
	size--;
	return *this;
}
template <typename T>
Polynomial<T> Polynomial<T>::operator--(int) 
{
	Polynomial<T> temp = *this;
	--*this;
	return temp;
}
template <typename T>
Polynomial<T>& Polynomial<T>::operator++()
{
	for (int i = 0; i < size; i++)
	{
		T sum = (double)1 / (size - i);
		arr[i] *= sum;
	}
	resize();
	arr[size - 1] = 0;
	return *this;
}
template <typename T>
Polynomial<T> Polynomial<T>::operator++(int)
{
	Polynomial<T> temp = *this;
	++*this;
	return temp;
}
template <typename T = int>
ostream& operator<<(ostream& out, const Polynomial<T>& p)
{
	out << "f(x) = ";
	for (int i = 0; i < p.size; i++)
	{
		if (i != 0 && p.arr[i] >= 0)
			out << "+";
		out << p.arr[i];
		if (p.size - 1 - i > 1)
			out << "x^" << p.size - 1 - i;
		else if (p.size - 1 - i == 1)
			out << "x";
	}
	return out << endl;
}
template <typename T>
istream& operator>>(istream& in,Polynomial<T>& p)
{
	for (int i = 0; i < p.size; i++)
	{
		cout << "coefficient a" << i << " : ";
		in >> p.arr[i];
	}
	p.removeSeniorZeroes();
	return in;
}
template <typename T>
Polynomial<T>::operator int() const
{
	return size - 1;
}
template <typename T>
Polynomial<T>::operator bool() const
{
	return size == 0;
}
template <typename T>
bool Polynomial<T>::operator!() const
{
	return size != 0;
}
template <typename T>
Polynomial<T> operator*(const Polynomial<T>& first,T x)
{
	Polynomial<T> temp = Polynomial<T>(0,x);
	temp *= first;
	return temp;
}
template <typename T>
Polynomial<T>& Polynomial<T>::operator*=(T x)
{
	Polynomial<T> temp = Polynomial<T>(0, x);
	*this *= temp;
	return *this;
}
template <typename T>
Polynomial<T>& Polynomial<T>::operator/=(T x)
{
	Polynomial<T> temp;
	*this = temp;
	return *this;
}
template <typename T>
Polynomial<T> operator/(const Polynomial<T>& first, T x)
{
	Polynomial<T> temp;
	return temp;
}
template <typename T>
T Polynomial<T>::operator()(T a, T b) 
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != 0)
		{
			T sum = (double)1 / (size - i);
			arr[i] *= sum;
			T sub = pow(b, size - i) - pow(a, size - i);
			arr[i] *= sub;
		}
	}
	T sum = 0;
	for (int i = 0; i < size; i++)
		sum += arr[i];
	return sum;
}
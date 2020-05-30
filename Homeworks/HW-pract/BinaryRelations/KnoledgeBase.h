#include "BinaryRelation.h"
#include "String.h"
#pragma once
template<typename T, typename U>
class KnoledgeBase
{
private:
	size_t size;
	size_t cap;
	BinaryRelation<T, U>* knoledgeBase = nullptr;
	void copy(const KnoledgeBase&);
	void del();
	void resize();
public:
	KnoledgeBase(size_t = 0);
	KnoledgeBase(const KnoledgeBase&);
	KnoledgeBase& operator=(const KnoledgeBase&);
	~KnoledgeBase();
	void addRelation(const BinaryRelation<T, U>&);
	void print() const;
	BinaryRelation<T,U> kb(const String) const;
};
template<typename T, typename U>
void KnoledgeBase<T, U>::copy(const KnoledgeBase& other)
{
	knoledgeBase = new BinaryRelation<T, U>[other.cap];
	for (int i = 0; i < size; i++)
	{
		knoledgeBase[i] = other.knoledgeBase[i];
	}
	cap = other.cap;
	size = other.size;
}
template<typename T, typename U>
void KnoledgeBase<T, U>::del()
{
	delete[] knoledgeBase;
}
template<typename T, typename U>
void KnoledgeBase<T, U>::resize()
{
	BinaryRelation<T, U>* newknoledgeBase = new BinaryRelation<T, U>[cap];
	for (int i = 0; i < size; i++)
		newknoledgeBase[i] = knoledgeBase[i];
	delete[] knoledgeBase;
	knoledgeBase = newknoledgeBase;
	cap *= 2;
}
template<typename T, typename U>
KnoledgeBase<T, U>::KnoledgeBase(size_t _cap)
	: cap(_cap),size(0)
{
	knoledgeBase = new BinaryRelation<T, U>[cap];
}
template<typename T, typename U>
KnoledgeBase<T, U>::KnoledgeBase(const KnoledgeBase& other)
{
	copy(other);
}
template<typename T, typename U>
KnoledgeBase<T, U>& KnoledgeBase<T, U>::operator=(const KnoledgeBase& other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}
	return *this;
}
template<typename T, typename U>
KnoledgeBase<T, U>::~KnoledgeBase()
{
	del();
}
template<typename T, typename U>
void KnoledgeBase<T, U>::addRelation(const BinaryRelation<T, U>& relation)
{
	if (size >= cap)
		resize();
	knoledgeBase[size++] = relation;
}
template<typename T, typename U>
void KnoledgeBase<T, U>::print() const
{
	for (int i = 0; i < size; i++)
	{
		cout << knoledgeBase[i];
	}
}
template<typename T, typename U>
BinaryRelation<T,U> KnoledgeBase<T, U>::kb(const String relationName) const
{
	for (int i = 0; i < size; i++)
	{
		if (knoledgeBase[i].getName() == relationName)
		{
			return knoledgeBase[i];
		}
	}
	BinaryRelation<T, U> p;
	return p;
}

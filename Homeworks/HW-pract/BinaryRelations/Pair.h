#pragma once
template <typename T, typename U>
struct Pair
{
	T first;
	U second;
	bool operator==(const Pair&) const;
};
template <typename T, typename U>
bool Pair<T, U>::operator==(const Pair& rhs) const
{
	return first == rhs.first && second == rhs.second;
}
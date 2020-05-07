#pragma once
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private :
	string author;
	string title;
	string genre;
	string description;
	int issuanceYear;
	int keyWords;
	double rating;
	int uniqueNumberofLibrary;

public :
	Book(const string = "", const string = "", const string = "",
		string = "", int = 0, int = 0, double = 0, int = 0);
	friend ostream& operator<<(ostream&,const Book&);
	string getAuthor() const { return author; }
	string getTitle() const { return title; }
	string getGenre() const { return genre; }
	string getDescription() const { return description; }
	int getissuanceYear() const { return issuanceYear; }
	int getKeyWords() const { return keyWords; }
	double getRating() const { return rating; }
	int getUniqueNumberofLibrary() const { return uniqueNumberofLibrary; }
	void setAuthor(const string _author) { author = _author; }
	void setTitle(const string _title) { title = _title; }
	void setGenre(const string _genre) { genre = _genre; }
	void setDescription(const string _description) { description = _description; }
	void setIssuanceYear(int _issuanceYear) { issuanceYear = _issuanceYear; }
	void setKeyWords(int _keyWords) { keyWords = _keyWords; }
	void setUniqueNumberofLibrary(int _uniqueNumberofLibrary) { uniqueNumberofLibrary = _uniqueNumberofLibrary; }
	void setRating(double _rating) { rating = _rating; }
};
ostream& operator<<(ostream&,const Book&);

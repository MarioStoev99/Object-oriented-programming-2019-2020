#include "Book.h"

Book::Book(const string _author, const string _title, const string _genre,
	const string _description, int _issuanceYear, int _keyWords,
	double _rating, int _uniqueNumberofLibrary)
{
	author = _author;
	title = _title;
	genre = _genre;
	description = _description;
	issuanceYear = _issuanceYear;
	keyWords = _keyWords;
	rating = _rating;
	uniqueNumberofLibrary = _uniqueNumberofLibrary;
}
ostream& operator<<(ostream& o, const Book& book)
{
	return o << book.author << " " << book.title << " "
		<< book.genre << " " << book.uniqueNumberofLibrary << endl;
}

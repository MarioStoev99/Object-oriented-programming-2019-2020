#pragma once

#include "Book.h"
#include <string>
#include <fstream>

class BooksHandling;
typedef bool (BooksHandling::*f)(size_t, size_t) const;

const size_t MAX_SIZE = 1024;
class BooksHandling
{
private :
	Book* books = nullptr;
	size_t booksCap;
	size_t booksSize;
	char currentFileName[MAX_SIZE];

	void delBooks();
	void resize();
	void copy(const BooksHandling&);
public:
	void setBooksSizeToZero() { booksSize = 0; }
	const char* getcurrentFileName() const { return currentFileName; }

	void changeFileName(const char* filepath);
	void chargeSizeFromFileAndResize(ifstream& file);
	void chargeBooksFromFile(ifstream& file);
	void readBook(ifstream& file, size_t index);
	void chargeBookData(const string, const string, const string,
		const string, int, int, double, int, size_t);
	void save() const;
	void saveAs();
	void booksInfo(string uniqueNumber);
	void print() const;
	void initBook(Book& b) const;
	void features(size_t index) const;
	void addFeaturesToBook(size_t index, string temp, Book& b) const;
	bool isValidbookId(string& buffer) const;
	void removeBookFromArray(string nameofBook);

	//add books to array
	bool ExistSushId(const Book&) const;
	void addBookToArray(const Book& book);
	//books find
	void print(const string,const string) const;
	//Sorts
	void cutTypeSort(string&, const string) const;
	void bubbleSort(f);
	void callFunctionsSort(const string, const string);
	bool ascAndTitle(size_t, size_t) const;
	bool ascAndAuthor(size_t, size_t) const;
	bool ascAndRating(size_t, size_t) const;
	bool ascAndYear(size_t, size_t) const;
	bool descAndTitle(size_t, size_t) const;
	bool descAndAuthor(size_t, size_t) const;
	bool descAndRating(size_t, size_t) const;
	bool descAndYear(size_t, size_t) const;

	//big 4
	BooksHandling();
	BooksHandling(const BooksHandling&);
	BooksHandling& operator=(const BooksHandling&);
	~BooksHandling();
};

#include "BooksHandling.h"
#include "myNamespace.h"

void BooksHandling::delBooks()
{
	delete[] books;
}
void BooksHandling::copy(const BooksHandling& other)
{
	books = new Book[other.booksCap];
	for (int i = 0; i < other.booksSize; i++)
		books[i] = other.books[i];
	booksSize = other.booksSize;
	booksCap = other.booksCap;
	strcpy(currentFileName, other.currentFileName);
}
void BooksHandling::resize()
{
	Book* newBooks = new Book[booksCap * 2];
	for (int i = 0; i < booksSize; i++)
		newBooks[i] = books[i];
	delBooks();
	books = newBooks;
	booksCap *= 2;
}
BooksHandling::BooksHandling()	: booksCap(2), booksSize(0)
{
	ifstream file("currentFileName.txt");
	if (file.good())
		file.getline(currentFileName, MAX_SIZE);
	books = new Book[booksCap];
}
BooksHandling::BooksHandling(const BooksHandling& other)
{
	copy(other);
}
BooksHandling& BooksHandling::operator=(const BooksHandling& other)
{
	if (this != &other)
	{
		delBooks();
		copy(other);
	}
	return *this;
}
BooksHandling::~BooksHandling()
{
	delBooks();
}
void BooksHandling::changeFileName(const char* filepath)
{
	unsigned len = strlen(filepath);
	strncpy(currentFileName, filepath, len);
	currentFileName[len] = '\0';
}
void BooksHandling::chargeSizeFromFileAndResize(ifstream& file)
{
	unsigned temp = 0;
	file >> temp;
	file.ignore();
	while(temp >= booksCap)
		resize();
	booksSize = temp;
	chargeBooksFromFile(file);
}
void BooksHandling::chargeBooksFromFile(ifstream& file)
{
	for (int i = 0; i < booksSize; i++)
	{
		readBook(file, i);
	}
}
void BooksHandling::readBook(ifstream& file, size_t index)
{
	string _author, _title, _description, _genre;
	int _issuanceYear, _keyWords, _uniqueNumberofLibrary;
	double _rating;
	getline(file, _author, ',');
	getline(file, _title, ',');
	getline(file, _genre, ',');
	getline(file, _description, ',');
	file >> _issuanceYear >> _keyWords
		>> _rating >> _uniqueNumberofLibrary;
	chargeBookData(_author, _title, _description, _genre, _issuanceYear,
		_keyWords, _rating, _uniqueNumberofLibrary, index);
}
void BooksHandling::chargeBookData(const string _author, const string _title,
	const string _genre, const string _description, int _issuanceYear,
	int _keyWords, double _rating, int _uniqueNumberofLibrary, size_t i)
{
	books[i].setAuthor(_author);
	books[i].setTitle(_title);
	books[i].setGenre(_genre);
	books[i].setDescription(_description);
	books[i].setKeyWords(_keyWords);
	books[i].setIssuanceYear(_issuanceYear);
	books[i].setRating(_rating);
	books[i].setUniqueNumberofLibrary(_uniqueNumberofLibrary);
}
void BooksHandling::save() const
{
	system("cls");
	ofstream file(currentFileName);
	file << booksSize << endl;
	for (int i = 0; i < booksSize; i++)
	{
		file << books[i].getAuthor() << "," << books[i].getTitle() << ","
			<< books[i].getGenre() << "," << books[i].getDescription() << ","
			<< books[i].getissuanceYear() << " " << books[i].getKeyWords() << " "
			<< books[i].getRating() << " " << books[i].getUniqueNumberofLibrary();
	}
	cout << "Save successfully.Please choose an operation below : " << endl;
	file.close();
}
void BooksHandling::saveAs()
{
	char temp[MAX_SIZE];
	system("cls");
	cout << "Enter new file name : ";
	cin.getline(temp, MAX_SIZE);
	strcat(temp, ".txt");
	ofstream file("currentFileName.txt");
	if (file.good())
		file << temp;
	remove(currentFileName);
	changeFileName(temp);
}
void BooksHandling::booksInfo(string uniqueNumber)
{
	short uniqNumber = stoi(uniqueNumber);
	for (int i = 0; i < booksSize; i++)
	{
		if (books[i].getUniqueNumberofLibrary() == uniqNumber)
		{
			cout << books[i].getAuthor() << " " << books[i].getTitle() << " "
				<< books[i].getGenre() << " " << books[i].getDescription() << " "
				<< books[i].getissuanceYear() << " " << books[i].getKeyWords() << " "
				<< books[i].getRating() << " " << books[i].getUniqueNumberofLibrary() << endl;
			return;
		}
	}
}
void BooksHandling::print() const
{
	for (int i = 0; i < booksSize; i++)
		cout << books[i];
	cout << endl;
}
void BooksHandling::addBookToArray(const Book& book)
{
	if (booksSize >= booksCap)
		resize();
	books[booksSize++] = book;
	system("cls");
	cout << "Successfully added a book to Library.If you want this changed to be reflected forever,please click save or save as :)" << endl;
}
void BooksHandling::initBook(Book& b) const
{
	system("cls");
	cout << "Please write all features for this book one by one!!" << endl;
	for (int i = 0; i < 8; i++)
	{
		string temp;
		features(i);
		getline(cin, temp);
		addFeaturesToBook(i, temp, b);
	}
}
void BooksHandling::features(size_t index) const
{
	switch (index)
	{
	case 0: cout << "author : "; break;
	case 1: cout << "title : "; break;
	case 2: cout << "genre : "; break;
	case 3: cout << "description : "; break;
	case 4: cout << "issuance year : "; break;
	case 5: cout << "key words : "; break;
	case 6: cout << "rating : "; break;
	case 7: cout << "unique number for library : ";
	}
}
void BooksHandling::addFeaturesToBook(size_t index, string temp, Book& b) const
{
	switch (index)
	{
	case 0: b.setAuthor(temp); break;
	case 1: b.setTitle(temp); break;
	case 2: b.setGenre(temp); break;
	case 3: b.setDescription(temp); break;
	case 4: b.setIssuanceYear(stoi(temp)); break;
	case 5: b.setKeyWords(stoi(temp)); break;
	case 6: b.setRating(stod(temp)); break;
	case 7: b.setUniqueNumberofLibrary(stoi(temp));
	}
}
bool BooksHandling::isValidbookId(string& buffer) const
{
	if (buffer.size() != 4)
		return false;
	for (int i = 0; i < 4; i++)
	{
		if (myNameSpace::isDigit(buffer[i]))
			return false;
	}
	return true;
}
void BooksHandling::removeBookFromArray(string nameofBook)
{
	bool isLogin = false;
	myNameSpace::checkAdminPasswordAndUsername(isLogin);
	if (isLogin == true)
	{
		for (int i = 0; i < booksSize; i++)
		{
			if (nameofBook.compare(books[i].getTitle()) == 0)
			{
				swap(books[i], books[booksSize - 1]);
				booksSize--;
				system("cls");
				cout << "Successfully remove book.Choose another operation below : " << endl;
				return;
			}
		}
	}
	system("cls");
	cout << "This book does not exist in Library.Choose an operation : " << endl;
}
bool BooksHandling::possibleSorts(string& buffer) const
{
	if (buffer.compare(0, 5, "title") == 0)
	{
		buffer.erase(0, 5);
		return true;
	}
	if (buffer.compare(0, 6, "author") == 0)
	{
		buffer.erase(0, 6);
		return true;
	}
	if (buffer.compare(0, 4, "year") == 0)
	{
		buffer.erase(0, 4);
		return true;
	}
	if (buffer.compare(0, 6, "rating") == 0)
	{
		buffer.erase(0, 6);
		return true;
	}
	return false;
}
bool BooksHandling::isDescorAsc(string& buffer) const
{
	if (buffer.size() > 5)
		return false;
	if (buffer.size() == 0)
		return true;
	buffer.erase(0, 1);
	if (buffer.compare(0, 4, "desc") == 0)
		return true;
	if (buffer.compare(0, 3, "asc") == 0)
		return true;
	return false;
}
void BooksHandling::bubbleSort(f function)
{
	bool changed = false;
	size_t sorted = 0;
	do
	{
		changed = false;
		for (size_t i = booksSize - 1; i > sorted; i--)
		{
			if ((this->*function)(i, i - 1))
			{
				swap(books[i], books[i - 1]);
				changed = true;
			}
		}
		++sorted;
	} while (changed);
}

void BooksHandling::cutTypeSort(string& temp, const string buffer) const
{
	if (buffer.compare(0, 4, "desc") == 0)
		temp.erase(temp.size() - 5);
	if (buffer.compare(0, 3, "asc"))
		temp.erase(temp.size() - 4);
}
void BooksHandling::callFunctionsSort(const string descOrAsc, const string typeSort)
{
	if (descOrAsc.compare("") == 0 || descOrAsc.compare("asc") &&
		typeSort.compare("author"))
		bubbleSort(&BooksHandling::ascAndAuthor);
	if (descOrAsc.compare("") == 0 || descOrAsc.compare("asc") &&
		typeSort.compare("title"))
		bubbleSort(&BooksHandling::ascAndTitle);
	if (descOrAsc.compare("") == 0 || descOrAsc.compare("asc") &&
		typeSort.compare("rating"))
		bubbleSort(&BooksHandling::ascAndRating);
	if (descOrAsc.compare("") == 0 || descOrAsc.compare("asc") &&
		typeSort.compare("year"))
		bubbleSort(&BooksHandling::ascAndYear);
	if (descOrAsc.compare("desc") && typeSort.compare("title"))
		bubbleSort(&BooksHandling::descAndTitle);
	if (descOrAsc.compare("desc") && typeSort.compare("author"))
		bubbleSort(&BooksHandling::descAndAuthor);
	if (descOrAsc.compare("desc") && typeSort.compare("rating"))
		bubbleSort(&BooksHandling::descAndRating);
	if (descOrAsc.compare("desc") && typeSort.compare("year"))
		bubbleSort(&BooksHandling::descAndYear);
}
bool BooksHandling::ascAndTitle(size_t i, size_t j) const
{
	return books[i].getTitle() < books[j].getTitle();
}
bool BooksHandling::ascAndAuthor(size_t i, size_t j) const
{
	return books[i].getAuthor() < books[j].getAuthor();
}
bool BooksHandling::ascAndRating(size_t i, size_t j) const
{
	return books[i].getRating() < books[j].getRating();
}
bool BooksHandling::ascAndYear(size_t i, size_t j) const
{
	return books[i].getissuanceYear() < books[j].getissuanceYear();
}
bool BooksHandling::descAndTitle(size_t i, size_t j) const
{
	return books[i].getTitle() > books[j].getTitle();
}
bool BooksHandling::descAndAuthor(size_t i, size_t j) const
{
	return books[i].getAuthor() > books[j].getAuthor();
}
bool BooksHandling::descAndRating(size_t i, size_t j) const
{
	return books[i].getRating() > books[j].getRating();
}
bool BooksHandling::descAndYear(size_t i, size_t j) const
{
	return books[i].getissuanceYear() > books[j].getissuanceYear();
}
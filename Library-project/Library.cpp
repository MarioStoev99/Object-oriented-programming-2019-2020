#include "Library.h"
Library::Library() : administrator("admin", "i<3c++", 1)
{}
void Library::openAPP()
{	
	bool startAPP = false;
	bool openButton = true;
	bool closeButton = false;
	bool isLogin = false;
	while (true)
	{
		if (!startAPP)
		{
			cout << "Welcome,choose an operation : " << endl;
			startStatement();
			startAPP = true;
		}
		string buffer;
		getline(cin, buffer);
		if (buffer == "exit" && openButton)
			break;
		else if (buffer == "help" && openButton)
		{
			while (buffer != "back")
			{
				miniCopyHelp();
				getline(cin, buffer);
			}
			miniCopy();
			startStatement();
		}
		else if (buffer == "open" && openButton)
		{
			openButton = false;
			closeButton = true;
			open();
			afterOpenFileOperations();
		}
		else if (buffer == "close" && closeButton)
		{
			closeButton = false;
			openButton = true;
			controlBooks.setBooksSizeToZero();
			miniCopy();
			startStatement();
		}
		else if (buffer == "save" && closeButton)
		{
			controlBooks.save();
			afterOpenFileOperations();
		}
		else if (buffer == "save as" && closeButton)
		{
			controlBooks.saveAs();
			controlBooks.save();
			afterOpenFileOperations();
		}
		else if (buffer == "login" && closeButton)
		{
			login(isLogin);
			afterOpenFileOperations();
		}
		else if (buffer == "logout" && isLogin)
		{
			isLogin = false;
			miniCopy();
			changeDataUser("", "");
			afterOpenFileOperations();
		}
		else if (buffer == "books all" && isLogin)
		{
			miniCopy();
			afterOpenFileOperations();
			controlBooks.print();
		}
		else if (AuxiliaryMethodsForAllClasses::isValidOperation(buffer,"books info ") && isLogin)
		{
			if (!controlBooks.isValidbookId(buffer)) {
				system("cls");
				cout << "Invalid books id.." << endl;
				afterOpenFileOperations();
				continue;
			}
			miniCopy();
			afterOpenFileOperations();
			controlBooks.booksInfo(buffer);
		}
		else if (AuxiliaryMethodsForAllClasses::isValidOperation(buffer,"books find ") && isLogin)
		{
			system("cls");
			afterOpenFileOperations();
			string temp = AuxiliaryMethodsForAllClasses::booksFindOptions(buffer);
			if (temp == "error")
			{
				system("cls");
				cout << "invalid option.Please try again" << endl;
				afterOpenFileOperations();
			}
			controlBooks.print(temp, buffer);
		}
		else if (AuxiliaryMethodsForAllClasses::isValidOperation(buffer,"books sort ") && isLogin)
		{
			system("cls");
			afterOpenFileOperations();
			string temp = buffer;
			if (!AuxiliaryMethodsForAllClasses::possibleSorts(buffer) || !AuxiliaryMethodsForAllClasses::isDescorAsc(buffer))
			{
				system("cls");
				cout << "Invalid command,please follow instructions" << endl;
				afterOpenFileOperations();
			}
			controlBooks.cutTypeSort(temp, buffer);
			controlBooks.callFunctionsSort(buffer,temp);
			controlBooks.print();
		}
		else if (AuxiliaryMethodsForAllClasses::isValidOptionAdd(buffer, "users add ") && isLogin)
		{
			controlUsers.addUsers(buffer);
			afterOpenFileOperations();
		}
		else if (AuxiliaryMethodsForAllClasses::isValidOptionRemove(buffer, "users remove ") && isLogin)
		{
			system("cls");
			controlUsers.removeUser(buffer);
			afterOpenFileOperations();
		}
		else if (buffer == "books add" && isLogin)
		{
			Book b;
			controlBooks.initBook(b);
			if (controlBooks.ExistSushId(b))
			{
				system("cls");
				cout << "This unique number has already existed!!" << endl;
			}
			else
				controlBooks.addBookToArray(b);
			afterOpenFileOperations();
		}
		else if (AuxiliaryMethodsForAllClasses::isValidOptionRemove(buffer, "books remove ") && isLogin)
		{
			controlBooks.removeBookFromArray(buffer);
			afterOpenFileOperations();
		}
		else
		{
			system("cls");
			cout << "Bad command,please try again!!" << endl;
			if (closeButton)
				afterOpenFileOperations();
			else
				startStatement();
		}
	}
}
void Library::startStatement() const
{
	cout << 1 << ")open" << endl;
	cout << 2 << ")help" << endl;
	cout << 3 << ")exit" << endl;
}
void Library::afterOpenFileOperations() const
{
	cout << 1 << ")close" << endl;
	cout << 2 << ")save" << endl;
	cout << 3 << ")save as" << endl;
	cout << 4 << ")login" << endl;
	if (user.getName() != "" && user.getPassword() != "")
	{
		cout << 5 << ")logout" << endl;
		cout << 6 << ")books all" << endl;
		cout << 7 << ")books info <isbn_value>" << endl;
		cout << 8 << ")books find <option> <option_string>" << endl;
		cout << 9 << ")books sort <option> [asc|desc]" << endl;
		cout << 10 << ")users add <user> <password>" << endl;
		cout << 11 << ")users remove <user>" << endl;
		cout << 12 << ")books add" << endl;
		cout << 13 << ")books remove <name of book>" << endl;
	}
}
void Library::miniCopy()
{
	system("cls");
	cout << "Welcome,choose an operation : " << endl;
}
void Library::help() const
{
	cout << "... ... ..." << endl;
	cout << "... ... ..." << endl;
	cout << "... ... ..." << endl;
}
void Library::miniCopyHelp() const
{
	system("cls");
	help();
	cout << "Please write 'back',if you want return to menu : ";
}
void Library::open()
{
	string filepath;
	system("cls");
	cout << "The last file name you set is  : " << controlBooks.getcurrentFileName() << endl;
	cout << "Enter it without .txt and you will charge all books in Library: " << endl;
	cout << "File name : ";
	AuxiliaryMethodsForAllClasses::initFileName(filepath);
	ifstream file(filepath);
	while (!file.is_open())
	{
		system("cls");
		cout << "The file not exist!!The last file name you set is  : books.txt" << endl;
		cout << "Enter it without .txt and you will charge all books in Library:  ";
		AuxiliaryMethodsForAllClasses::initFileName(filepath);
		file.open(filepath);
	}
	system("cls");
	cout << "Opened file succesfuly !!Choose an operation below.." << endl;
	controlBooks.chargeSizeFromFileAndResize(file);
}
void Library::login(bool& isLogin)
{
	system("cls");
	string username;
	string password;
	AuxiliaryMethodsForAllClasses::initAccount(username, password);
	ifstream file("users.txt");
	unsigned len = 0;
	file >> len;
	file.ignore();
	for(int i = 0;i < len;i++)
	{
		if (AuxiliaryMethodsForAllClasses::isExistAccountinFile(file, username,password))
		{
			if (isAlreadyLogin(username))
			{
				system("cls");
				cout << "You are already logged in!" << endl;
				return;
			}
			isLogin = true;
			system("cls");
			cout << "Welcome," << username << "!Choose an operation below.." << endl;
			changeDataUser(username, password);
			return;
		}
	}
	system("cls");
	cout << "Invalid nickname or password !" << endl;
}
bool Library::isAlreadyLogin(const string username) const
{
	if (username == user.getName())
		return true;
	return false;
}
void Library::changeDataUser(const string username,const string password)
{
	user.setName(username);
	user.setPassword(password);
}


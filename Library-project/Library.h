#pragma once

#include "Book.h"
#include "User.h"
#include "BooksHandling.h"
#include "UsersHandling.h"
#include <fstream>
#include <cassert>
#include "AuxiliaryMethods.h"

class Library
{
private : 
	User user;
	User administrator;	
	BooksHandling controlBooks;
	UsersHandling controlUsers;

	void startStatement() const;
	void afterOpenFileOperations() const;
	void miniCopy();
	void help() const;
	void open();
	void login(bool&);
	void miniCopyHelp() const;
	bool  isAlreadyLogin(const string) const;
	void changeDataUser(const string,const string);
public : 
	Library();
	Library(const Library&) = delete;
	Library& operator=(const Library&) = delete;
	void openAPP();
};


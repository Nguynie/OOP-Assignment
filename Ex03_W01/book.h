#pragma once





struct book {
	char ISBN[15];
	char nameOfBook[40];
	char nameOfAuthor[40];
	char publisher[30];
	int publishingYear;
	char typeOfBook[20];
	long priceOfBook;
	int theNumberOfBooks;
};

void readFileOfListBook(const char* filename, book listBook[], int& numberOfBooks);

void printListOfBooks(book listBook[], int numberOfBooks);

bool checkValidCharacter(char name[]);

void toUpper(char name[]);



void addBook(book listBook[], int& numberOfBooks);

void adjustInformationOfBook(book listBook[], int numberOfBooks);

void deleteInformationOfBook(book listBook[], int& numberOfBooks);

void findBookByISBN(book listBook[], int numberOfBooks);

void findBookByName(book listBook[], int numberOfBooks);

void exportNewFileOfBook(const char* filename, book listBook[], int numberOfBooks);
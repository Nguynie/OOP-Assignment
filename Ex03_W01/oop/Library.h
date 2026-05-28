#pragma once
#include "Book.h"
#include "Reader.h"
#include "Date.h"
#include "Menu.h"

class Library {
private:
    Reader listReader[100];
    Book listBook[100];
    int numberOfReaders;
    int numberOfBooks;

public:
    Library();
    void run();

private:
    void readFileOfListReaders(const char* filename);
    void readFileOfListBook(const char* filename);
    void exportNewFileOfReaders(const char* filename);
    void exportNewFileOfBook(const char* filename);

    Date inputDate();
    Date fillBorrowDate();
    void calculateReturnDay(int day1, int month1, int year1, int& day2, int& month2, int& year2);
    int calculateSpace(int day1, int month1, int year1, int day2, int month2, int year2);

    void printAllReaders();
    void addReader();
    void adjustReader();
    void deleteReader();
    void findReaderByCitizenId();
    void findBookByNameOfReader();
    void readerManagement();

    void printAllBooks();
    void addBook();
    void adjustBook();
    void deleteBook();
    void findBookByISBN();
    void findBookByName();
    void bookManagement();

    void borrowBookForReader(Date today, int readerIndex);
    void returnBook(Date today);

    void statistics();
    void statNumberOfBooks();
    void statNumberOfBooksByType();
    void statNumberOfReaders();
    void statGender();
    void statBooksBorrowed();
    void statReaderMissDl(Date today);
};

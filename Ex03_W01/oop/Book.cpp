#include "Book.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Book::Book() {
    ISBN[0] = '\0';
    nameOfBook[0] = '\0';
    nameOfAuthor[0] = '\0';
    publisher[0] = '\0';
    publishingYear = 0;
    typeOfBook[0] = '\0';
    priceOfBook = 0;
    theNumberOfBooks = 0;
}

const char* Book::getISBN() const { return ISBN; }
const char* Book::getNameOfBook() const { return nameOfBook; }
const char* Book::getNameOfAuthor() const { return nameOfAuthor; }
const char* Book::getPublisher() const { return publisher; }
int Book::getPublishingYear() const { return publishingYear; }
const char* Book::getTypeOfBook() const { return typeOfBook; }
long Book::getPriceOfBook() const { return priceOfBook; }
int Book::getTheNumberOfBooks() const { return theNumberOfBooks; }

void Book::setISBN(const char* isbn) { strcpy(ISBN, isbn); }
void Book::setNameOfBook(const char* name) { strcpy(nameOfBook, name); }
void Book::setNameOfAuthor(const char* author) { strcpy(nameOfAuthor, author); }
void Book::setPublisher(const char* pub) { strcpy(publisher, pub); }
void Book::setPublishingYear(int year) { publishingYear = year; }
void Book::setTypeOfBook(const char* type) { strcpy(typeOfBook, type); }
void Book::setPriceOfBook(long price) { priceOfBook = price; }
void Book::setTheNumberOfBooks(int qty) { theNumberOfBooks = qty; }

bool Book::checkValidISBN() const {
    int number = atoi(ISBN);
    if (number < 0) return false;
    for (int i = 1; i < (int)strlen(ISBN); i++) {
        if (ISBN[i] < '0' || ISBN[i] > '9') return false;
    }
    return true;
}

void Book::displayHeader() const {
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|| %-12s  || %-20s  || %-20s  || %-20s  || %-5s  || %-15s  || %-10s  || %-10s ||\n", "ISBN", "NAME", "AUTHOR", "PUBLISHER", "YEAR", "TYPE", "PRICE", "QUANTITY");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void Book::displayRow() const {
    printf("|| %-12s  || %-20s  || %-20s  || %-20s  || %-5d  || %-15s  || %-10ld  || %-10d ||\n",
        ISBN, nameOfBook, nameOfAuthor, publisher, publishingYear, typeOfBook, priceOfBook, theNumberOfBooks);
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void Book::decreaseQuantity() {
    theNumberOfBooks--;
}

void Book::increaseQuantity() {
    theNumberOfBooks++;
}

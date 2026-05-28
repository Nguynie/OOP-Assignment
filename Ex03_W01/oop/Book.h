#pragma once

class Book {
private:
    char ISBN[15];
    char nameOfBook[40];
    char nameOfAuthor[40];
    char publisher[30];
    int publishingYear;
    char typeOfBook[20];
    long priceOfBook;
    int theNumberOfBooks;

public:
    Book();

    const char* getISBN() const;
    const char* getNameOfBook() const;
    const char* getNameOfAuthor() const;
    const char* getPublisher() const;
    int getPublishingYear() const;
    const char* getTypeOfBook() const;
    long getPriceOfBook() const;
    int getTheNumberOfBooks() const;

    void setISBN(const char* isbn);
    void setNameOfBook(const char* name);
    void setNameOfAuthor(const char* author);
    void setPublisher(const char* pub);
    void setPublishingYear(int year);
    void setTypeOfBook(const char* type);
    void setPriceOfBook(long price);
    void setTheNumberOfBooks(int qty);

    bool checkValidISBN() const;
    void displayHeader() const;
    void displayRow() const;
    void decreaseQuantity();
    void increaseQuantity();
};

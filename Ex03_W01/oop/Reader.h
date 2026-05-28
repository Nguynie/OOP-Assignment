#pragma once
#include "Date.h"
#include "Book.h"

class Reader {
private:
    char code[10];
    char name[40];
    char idNumber[13];
    Date dob;
    char email[40];
    char address[40];
    char gender[10];
    Date creatingCardDay;
    Date expiringCardDay;
    Book borrowBook[6];
    int quantityOfBorrowing;
    Date borrowDay[6];
    Date returnDay[6];

public:
    Reader();

    const char* getCode() const;
    const char* getName() const;
    const char* getIdNumber() const;
    Date getDob() const;
    const char* getEmail() const;
    const char* getAddress() const;
    const char* getGender() const;
    Date getCreatingCardDay() const;
    Date getExpiringCardDay() const;
    int getQuantityOfBorrowing() const;
    Book getBorrowBook(int index) const;
    Date getBorrowDay(int index) const;
    Date getReturnDay(int index) const;

    void setCode(const char* c);
    void setName(const char* n);
    void setIdNumber(const char* id);
    void setDob(Date d);
    void setEmail(const char* e);
    void setAddress(const char* a);
    void setGender(const char* g);
    void setCreatingCardDay(Date d);
    void setExpiringCardDay(Date d);
    void setQuantityOfBorrowing(int qty);
    void setBorrowBook(int index, const Book& b);
    void setBorrowDay(int index, Date d);
    void setReturnDay(int index, Date d);

    bool checkValidCode() const;
    bool checkValidID() const;
    void displayHeader() const;
    void displayRow() const;
    void printForm() const;
    void removeBorrowedBook(int index);
};

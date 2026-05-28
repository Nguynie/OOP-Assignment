#include "Reader.h"
#include "StringUtils.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Reader::Reader() {
    code[0] = '\0';
    name[0] = '\0';
    idNumber[0] = '\0';
    dob = {0, 0, 0};
    email[0] = '\0';
    address[0] = '\0';
    gender[0] = '\0';
    creatingCardDay = {0, 0, 0};
    expiringCardDay = {0, 0, 0};
    quantityOfBorrowing = 0;
    for (int i = 0; i < 6; i++) {
        borrowDay[i] = {0, 0, 0};
        returnDay[i] = {0, 0, 0};
    }
}

const char* Reader::getCode() const { return code; }
const char* Reader::getName() const { return name; }
const char* Reader::getIdNumber() const { return idNumber; }
Date Reader::getDob() const { return dob; }
const char* Reader::getEmail() const { return email; }
const char* Reader::getAddress() const { return address; }
const char* Reader::getGender() const { return gender; }
Date Reader::getCreatingCardDay() const { return creatingCardDay; }
Date Reader::getExpiringCardDay() const { return expiringCardDay; }
int Reader::getQuantityOfBorrowing() const { return quantityOfBorrowing; }
Book Reader::getBorrowBook(int index) const { return borrowBook[index]; }
Date Reader::getBorrowDay(int index) const { return borrowDay[index]; }
Date Reader::getReturnDay(int index) const { return returnDay[index]; }

void Reader::setCode(const char* c) { strcpy(code, c); }
void Reader::setName(const char* n) { strcpy(name, n); }
void Reader::setIdNumber(const char* id) { strcpy(idNumber, id); }
void Reader::setDob(Date d) { dob = d; }
void Reader::setEmail(const char* e) { strcpy(email, e); }
void Reader::setAddress(const char* a) { strcpy(address, a); }
void Reader::setGender(const char* g) { strcpy(gender, g); }
void Reader::setCreatingCardDay(Date d) { creatingCardDay = d; }
void Reader::setExpiringCardDay(Date d) { expiringCardDay = d; }
void Reader::setQuantityOfBorrowing(int qty) { quantityOfBorrowing = qty; }
void Reader::setBorrowBook(int index, const Book& b) { borrowBook[index] = b; }
void Reader::setBorrowDay(int index, Date d) { borrowDay[index] = d; }
void Reader::setReturnDay(int index, Date d) { returnDay[index] = d; }

bool Reader::checkValidCode() const {
    int number = atoi(code);
    if (code[0] == '0' || number < 0) return false;
    for (int i = 1; i < (int)strlen(code); i++) {
        if (code[i] < '0' || code[i] > '9') return false;
    }
    return true;
}

bool Reader::checkValidID() const {
    for (int i = 0; i < (int)strlen(idNumber); i++) {
        if (idNumber[i] < '0' || idNumber[i] > '9') return false;
    }
    return true;
}

void Reader::displayHeader() const {
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|| %-10s  ||  %-22s  ||  %-15s  ||   %-8s  ||  %-3s   ||  %-30s  ||  %-40s  ||  %-3s ||   %-3s  ||\n", "CODE", "FULL NAME", "ID NUMBER", "DATEOFBIRTH", "GENDER", "EMAIL", "ADDRESS", "CREATING", "EXPIRING");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void Reader::displayRow() const {
    printf("|| %-10s  ||  %-22s  ||  %-15s  ||   %-2d-%-2d-%-5d  ||  %-7s  ||  %-30s  ||  %-40s  ||  %d-%d-%d ||   %d-%d-%d  ||\n",
        code, name, idNumber, dob.day, dob.month, dob.year, gender, email, address,
        creatingCardDay.day, creatingCardDay.month, creatingCardDay.year,
        expiringCardDay.day, expiringCardDay.month, expiringCardDay.year);
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void Reader::printForm() const {
    printf("STUDENT CODE: %s\n", code);
    printf("NAME: %s\n", name);
    printf("CITIZEN ID NUMBER: %s\n", idNumber);
    printf("BOOKS BORROWED\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|| %-12s  || %-20s  || %-20s  || %-20s  || %-15s  || %-15s ||  %-7s ||   %-7s  ||\n", "ISBN", "NAME", "AUTHOR", "PUBLISHER", "PUBLISHINGYEAR", "TYPE", "BORROW", "RETURN");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < quantityOfBorrowing; i++) {
        printf("|| %-12s  || %-20s  || %-20s  || %-20s  || %-15d  || %-15s || %d/%d/%d ||  %d/%d/%d  ||\n",
            borrowBook[i].getISBN(), borrowBook[i].getNameOfBook(), borrowBook[i].getNameOfAuthor(),
            borrowBook[i].getPublisher(), borrowBook[i].getPublishingYear(), borrowBook[i].getTypeOfBook(),
            borrowDay[i].day, borrowDay[i].month, borrowDay[i].year,
            returnDay[i].day, returnDay[i].month, returnDay[i].year);
        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    }
    system("pause");
}

void Reader::removeBorrowedBook(int index) {
    for (int i = index; i < quantityOfBorrowing - 1; i++) {
        borrowBook[i] = borrowBook[i + 1];
        borrowDay[i] = borrowDay[i + 1];
        returnDay[i] = returnDay[i + 1];
    }
    quantityOfBorrowing--;
}

#pragma once
#include"book.h"

struct Date {
	int day;
	int month;
	int year;

};


struct reader {
	char code[10];
	char name[40];
	char idNumber[13];
	Date dob;
	char email[40];
	char address[40];
	char gender[10];
	Date creatingCardDay;
	Date expiringCardDay;
	book borrowBook[6];
	int quantityOfBorrowing;
	Date borrowDay[6];
	Date returnDay[6];
};


void readFileOfListReaders(const char *filename, reader listReader[], int& numberOfReaders);

void printListOfReaders(reader listReader[], int numberOfReaders);


void addReader(reader listReader[], int& numberOfReaders);

void adjustInformation( reader listReader[], int numberOfReaders);
void exportNewFile(const char* filename, reader listReader[], int numberOfReaders);

void deleteInformation(reader listReader[], int& numberOfReaders);

void findReaderByCitizenIdNumber(reader listReader[], int numberOfReaders);

void findBookByNameOfReader(reader listReader[], int numberOfReaders);
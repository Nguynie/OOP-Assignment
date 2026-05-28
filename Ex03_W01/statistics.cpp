
#include "reader.h"

#include "book.h"

#include <string.h>

#include <stdio.h>

#include <stdlib.h>


// This function prints the number of books in library now

void statisticsNumberOfBooks(book listBook[], int numberOfBooks) {

	int totalBook = 0;
	for (int i = 0;i < numberOfBooks;i++) {
		totalBook += listBook[i].theNumberOfBooks;
	}
	printf("STATISTICS OF NUMBER OF BOOKS IN LIBRARY\n");
	printf("NUMBER OF BOOKS IN LIBRARY NOW: %d \n"  , totalBook);
}

// This function prints the number of books of each category in library

void statisticsNumberOfBooksByType(book listBook[], int numberOfBooks) {
	int count[100]; // count the appearances 
	for (int i = 0;i < numberOfBooks;i++) {
		count[i] = 0;
		for (int j = 0;j < numberOfBooks;j++) {
			if (strcmp(listBook[i].typeOfBook, listBook[j].typeOfBook) == 0) {
				if (j < i) {
					break;
				}
				else {
					count[i] += listBook[j].theNumberOfBooks;
				}
			}
		}
	}

	int total = 0;
	printf(" STATISTICS FOR NUMBER OF BOOKS (CATEGORIES)\n");
	for (int i = 0;i < numberOfBooks;i++) {
		if (count[i] != 0) {


			printf("%s: %d\n", listBook[i].typeOfBook, count[i]);
		}
	}


	system("pause");
}

// This function prints the number of readers in library now

void statisticsNumberOfReaders( int numberOfReaders) {
	
	printf("STATISTICS OF NUMBER OF READERS IN LIBRARY\n");
	printf("NUMBER OF READERS IN LIBRARY NOW: %d\n ", numberOfReaders);
	system("pause");
}

// This function prints the number of readers of each gender

void statisticsGender(reader listReader[], int numberOfReaders) {
	int countMale = 0;
	int countFemale = 0;
	for (int i = 0;i < numberOfReaders;i++) {
		if (strcmp(listReader[i].gender, "MALE") == 0) {
			countMale++;
		}
		else {
			countFemale++;
		}
	}
	printf("NUMBERS OF MALES IN LIBRARY: %d\n", countMale);
	printf("NUMBERS OF FEMALES IN LIBRARY: %d\n", countFemale);
	system("pause");
}

// This function prints the number of books which are being borrowed

void statisticsBooksBorrowed(reader listReader[], int numberOfReaders) {
	int count = 0;
	for (int i = 0;i < numberOfReaders;i++) {
		for (int j = 0;j < listReader[i].quantityOfBorrowing;j++) {
			count++;
		}
	}
	printf("The NUMBER OF BOOKS WHICH ARE BEING BORROWED: %d\n", count);
	system("pause");
}

// This function prints the number of readers who are late for deadline
void statisticsReaderMissDl(reader listReader[], int numberOfReaders, Date today) {
	int count = 0;
	for (int i = 0;i < numberOfReaders;i++) {
		for (int j = 0;j < listReader[i].quantityOfBorrowing;j++) {
			if (today.year < listReader[i].returnDay[j].year) {
				continue;
			}
			if (today.year == listReader[i].returnDay[j].year)
				if (today.month < listReader[i].returnDay[j].month)
					continue;
			if (today.year == listReader[i].returnDay[j].year)
				if (today.month == listReader[i].returnDay[j].month)
					if (today.day < listReader[i].returnDay[j].day)
						continue;
			count++;
		}


	}
	printf("THE NUMBER OF READERS WHO ARE MISSING DEADLINE: %d\n", count);
	system("pause");
}
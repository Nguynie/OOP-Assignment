
#include "reader.h"

#include "book.h"

#include <string.h>

#include <stdio.h>

#include <stdlib.h>


// This function helps to calculate the day when you must return the book
// Inputs are the date you borrow the book and the return day that you want to calculate
// Outputs are the date you must return book
void calculateReturnDay(int day1, int month1, int year1, int& day2, int& month2, int& year2) {
	day2 = day1 + 7;
	int top;
	switch (month1) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		top = 31;
		break;
	case 2:
		if ((year1 % 4 == 0 && year1 % 100 != 0) || year1 % 400 == 0) {
			top = 29;
		}
		else {
			top = 28;
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		top = 30;
		break;
	}
	if (day2 > top) {
		month2 = month1 + 1;
		day2 = day2 - top;
	}
	else {
		month2 = month1;
	}
	if (month2 > 12) {
		month2 = month2 - 12;
		year2 = year1 + 1;
	}
	else {
		year2 = year1;
	}

}
// This function print the form of borrowing books
// Input is a reader
void printForm(reader reader) {

	printf("STUDENT CODE: %s\n", reader.code);
	printf("NAME: %s\n", reader.name);
	printf("CITIZEN ID NUMBER: %s\n", reader.idNumber);
	printf("BOOKS BORROWED\n");
	printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("|| %-12s  || %-20s  || %-20s  || %-20s  || %-15s  || %-15s ||  %-7s ||   %-7s  ||\n", "ISBN", "NAME", "AUTHOR", "PUBLISHER", "PUBLISHINGYEAR", "TYPE", "BORROW", "RETURN");
	printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	for (int i = 0;i < reader.quantityOfBorrowing;i++) {
		printf("|| %-12s  || %-20s  || %-20s  || %-20s  || %-15d  || %-15s || %d/%d/%d ||  %d/%d/%d  ||\n", reader.borrowBook[i].ISBN,reader.borrowBook[i].nameOfBook,reader.borrowBook[i].nameOfAuthor,
			reader.borrowBook[i].publisher, reader.borrowBook[i].publishingYear,reader.borrowBook[i].typeOfBook,reader.borrowDay[i].day, reader.borrowDay[i].month, reader.borrowDay[i].year
			,reader.returnDay[i].day, reader.returnDay[i].month, reader.returnDay[i].year);
		printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	}

	system("pause");
}


void borrowingBook(book listBook[], int numberOfBooks, reader listReader[], int numberOfReaders,Date today, int choose,int & quantityOfBorrowing) {
	
	
	quantityOfBorrowing = 0;
	printListOfBooks(listBook, numberOfBooks);
	while (true) {
		printf("WHICH BOOK DO YOU WANT TO BORROW? (1...%d): ", numberOfBooks);
		int choice = 0;
		scanf("%d", &choice);
		while (choice<1 || choice>numberOfBooks) {
			printf("PLEASE FILL AGAIN: ");
			scanf("%d", &choice);

		}
		strcpy(listReader[choose - 1].borrowBook[quantityOfBorrowing].ISBN, listBook[choice - 1].ISBN);
		strcpy(listReader[choose - 1].borrowBook[	quantityOfBorrowing].nameOfBook, listBook[choice - 1].nameOfBook);
		strcpy(listReader[choose - 1].borrowBook[quantityOfBorrowing].nameOfAuthor, listBook[choice - 1].nameOfAuthor);
		strcpy(listReader[choose - 1].borrowBook[quantityOfBorrowing].publisher, listBook[choice - 1].publisher);
		listReader[choose - 1].borrowBook[quantityOfBorrowing].publishingYear=listBook[choice - 1].publishingYear;
		strcpy(listReader[choose - 1].borrowBook[quantityOfBorrowing].typeOfBook, listBook[choice - 1].typeOfBook);
		listReader[choose - 1].borrowDay[quantityOfBorrowing].day = today.day;
		listReader[choose - 1].borrowDay[quantityOfBorrowing].month = today.month;
		listReader[choose - 1].borrowDay[quantityOfBorrowing].year = today.year;
		calculateReturnDay(listReader[choose - 1].borrowDay[quantityOfBorrowing].day, listReader[choose - 1].borrowDay[listReader[choose - 1].quantityOfBorrowing].month,
			listReader[choose - 1].borrowDay[quantityOfBorrowing].year, listReader[choose - 1].returnDay[listReader[choose - 1].quantityOfBorrowing].day,
			listReader[choose - 1].returnDay[quantityOfBorrowing].month, listReader[choose - 1].returnDay[listReader[choose - 1].quantityOfBorrowing].year);
		listReader[choose - 1].borrowBook[quantityOfBorrowing].priceOfBook = listBook[choice - 1].priceOfBook;
		quantityOfBorrowing++;
		listBook[choice - 1].theNumberOfBooks -= 1;
		exportNewFileOfBook("listBook.txt", listBook, numberOfBooks);
		if (quantityOfBorrowing > 5) {
			printf("YOU CAN BORROW OVER 5 BOOKS");
			printf("PLEASE PRESS BUTTON 1 TO EXIT\n");
			char button;
			scanf("\n");
			scanf("%c", &button);
			if (button == '1') {
				break;
			}
		}
		printf("PLEASE PRESS BUTTON 0 TO EXIT IF YOU WANT TO STOP BORROWING OR PRESS ANY BUTTON FROM 1 TO 9 TO CONTINUE: \n");
		char button;
		scanf("\n");
		scanf("%c", &button);
		if (button == '0') {
			break;
		}
		else {
			continue;
		}
	}
	system("cls");
	printForm(listReader[choose - 1]);
}

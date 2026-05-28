
#include "reader.h"

#include "book.h"

#include <string.h>

#include <stdio.h>

#include <stdlib.h>


// This function helps to calculate the subtraction between the date when you return the book and the date when you have to return it

int calculateSpace(int day1, int month1, int year1, int day2, int month2, int year2) {

	int space1 = 0;
	int space2 = 0;

	for (int i = 1;i < month1;i++) {
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
			space1 += 31;
		}
		else if (i == 2) {
			if ((year1 % 4 == 0 && year1 % 100 != 0) || year1 % 400 == 0) {
				space1 += 29;
			}
			else {
				space1 += 28;
			}
		}
		else {
			space1 += 30;
		}
	}
	space1 += day1;

	for (int j = year1;j < year2;j++) {
		if ((j % 4 == 0 && j % 100 != 0) || j % 400 == 0) {
			space2 += 366;
		}
		else {
			space2 += 365;
		}

	}
	for (int j1 = 1;j1 < month2;j1++) {
		if (j1 == 1 || j1 == 3 || j1 == 5 || j1 == 7 || j1 == 8 || j1 == 10 || j1 == 12) {
			space2 += 31;
		}
		else if (j1 == 2) {
			if ((year2 % 4 == 0 && year2 % 100 != 0) || year2 % 400 == 0) {
				space2 += 29;
			}
			else {
				space2 += 28;
			}
		}
		else {
			space2 += 30;
		}
	}
	space2 += day2;

	int space = space2 - space1;
	return space;

}

 
// This function helps to choose the book that you want to return and print the form of fee that you have to pay

void returnBook(reader listReader[], int numberOfReaders,Date today, book listBook[], int numberOfBooks) {
	
	for (int i = 0;i < numberOfReaders;i++) {
		printf("%s\n", listReader[i].name);

	}
	printf("PLEASE CHOOSE YOUR NAME (1 TO %d): ",numberOfReaders);
	int choice = 0;
	scanf("%d", &choice);
	while (true) {
		printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("|| %-12s  || %-20s  || %-20s  || %-20s  || %-15s  || %-15s ||  %-7s ||   %-7s  ||\n", "ISBN", "NAME", "AUTHOR", "PUBLISHER", "PUBLISHINGYEAR", "TYPE", "BORROW", "RETURN");
		printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		for (int i = 0;i < listReader[choice - 1].quantityOfBorrowing;i++) {
			printf("|| %-12s  || %-20s  || %-20s  || %-20s  || %-15d  || %-15s || %d/%d/%d ||  %d/%d/%d  ||\n", listReader[choice - 1].borrowBook[i].ISBN, listReader[choice - 1].borrowBook[i].nameOfBook, listReader[choice - 1].borrowBook[i].nameOfAuthor,
				listReader[choice - 1].borrowBook[i].publisher, listReader[choice - 1].borrowBook[i].publishingYear, listReader[choice - 1].borrowBook[i].typeOfBook, listReader[choice - 1].borrowDay[i].day, listReader[choice - 1].borrowDay[i].month, listReader[choice - 1].borrowDay[i].year
				, listReader[choice - 1].returnDay[i].day, listReader[choice - 1].returnDay[i].month, listReader[choice - 1].returnDay[i].year);
			printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		}
		printf("PLEASE CHOOSE THE BOOK YOU RETURN (1 TO %d): ", listReader[choice - 1].quantityOfBorrowing);
		int choose = 0;
		scanf("%d", &choose);
		printf("PLEASE CHOOSE \n");
		printf("1. LOSE BOOK\n");
		printf("2. RETURN BOOK\n");
		int select = 0;
		scanf("%d", &select);
		while (select != 1 && select != 2) {
			printf("PLEASE CHOOSE AGAIN: ");
			scanf("%d", &select);
		}
		if (select == 2) {
			Date returnDay;
			returnDay.day = today.day;
			returnDay.month = today.month;
			returnDay.year = today.year;
			for (int i = 0;i < numberOfBooks;i++) {
				if (strcmp(listBook[i].ISBN, listReader[choice - 1].borrowBook[choose - 1].ISBN) == 0) {
					listBook[i].theNumberOfBooks++;
					exportNewFileOfBook("listBook.txt", listBook, numberOfBooks);
					break;
				}
			}
			for (int i = choose-1;i < listReader[choice - 1].quantityOfBorrowing-1;i++) {
				listReader[choice - 1].borrowBook[i] = listReader[choice - 1].borrowBook[i + 1];
				listReader[choice - 1].borrowDay[i] = listReader[choice - 1].borrowDay[i + 1];
				listReader[choice - 1].returnDay[i] = listReader[choice - 1].returnDay[i + 1];
			}
			int space = calculateSpace( listReader[choice - 1].returnDay[choose - 1].day, listReader[choice - 1].returnDay[choose - 1].month, listReader[choice - 1].returnDay[choose - 1].year, returnDay.day, returnDay.month, returnDay.year);
			if (space <= 0) {
				printf("YOU DON'T HAVE TO PAY FEE!\n");
			}
			else {
				printf("YOU HAVE BEEN LATE %d. YOU HAVE TO PAY %d VND",space,(space)*5000 );
			}
		}
		else if (select == 1) {
			int fee = listReader[choice - 1].borrowBook[choose - 1].priceOfBook * 2;
			for (int i = choose - 1;i < listReader[choice - 1].quantityOfBorrowing - 1;i++) {
				listReader[choice - 1].borrowBook[i] = listReader[choice - 1].borrowBook[i + 1];
				listReader[choice - 1].borrowDay[i] = listReader[choice - 1].borrowDay[i + 1];
				listReader[choice - 1].returnDay[i] = listReader[choice - 1].returnDay[i + 1];
			}
			printf("THE PRICE OF THIS BOOK IS %d SO YOU HAVE TO PAY %d VND", listReader[choice - 1].borrowBook[choose - 1].priceOfBook, fee );
		}
		listReader[choice - 1].quantityOfBorrowing--;
		printf("\nPRESS 1 TO CONTINUE OR 2 TO EXIT: ");
		int execute = 0;
		scanf("%d", &execute);
		if (execute == 2) {
			break;
		}
	}



}
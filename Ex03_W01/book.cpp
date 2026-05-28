#include <iostream>

#include <string.h>

#include <stdio.h>

#include <stdlib.h>

#include "book.h"




//This function helps to get the data from file "listBook.txt"
//array listBook contain information of books
//numberOfBooks is the number of books now in library

void readFileOfListBook(const char* filename, book listBook[], int& numberOfBooks) {
	numberOfBooks = 0;
	FILE* fi;
	fi = fopen(filename, "rt");
	if (fi != NULL) {
		while (!feof(fi)) {
			char str[200];
			fgets(str, 200, fi);
			char* token = strtok(str, ",");
			int countInfor = 0;
			while (token != NULL) {
				if (countInfor == 0) { 
					strcpy(listBook[numberOfBooks].ISBN, token);
				}
				else if (countInfor == 1) { 
					strcpy(listBook[numberOfBooks].nameOfBook, token);
				}
				else if (countInfor == 2) { 
					strcpy(listBook[numberOfBooks].nameOfAuthor, token);
				}
				else if (countInfor == 3) { 
					strcpy(listBook[numberOfBooks].publisher, token);
				}
				else if (countInfor == 4) {
					char year[10];
					strcpy(year, token);
					listBook[numberOfBooks].publishingYear = atoi(year);
				}
				else if (countInfor == 5) {
					strcpy(listBook[numberOfBooks].typeOfBook, token);
				}
				else if (countInfor == 6) { 
					char price[10];
					strcpy(price, token);
					listBook[numberOfBooks].priceOfBook = atol(price);
				}
			
				else if (countInfor == 7) { 
					char quantity[10];
					strcpy(quantity, token);
					listBook[numberOfBooks].theNumberOfBooks = atoi(quantity);
				}
				
				countInfor++;
				token = strtok(NULL, ",");





			}
			numberOfBooks++;
		}
		fclose(fi);
	}


}

//This functions helps update the data in file listBook.txt

void exportNewFileOfBook(const char* filename, book listBook[], int numberOfBooks) {
	FILE* fi;
	fi = fopen(filename, "wt");
	if (fi != NULL) {
		for (int i = 0;i < numberOfBooks;i++) {
		
			if (i != numberOfBooks - 1) {
				fprintf(fi, "%s,%s,%s,%s,%d,%s,%ld,%d\n", listBook[i].ISBN, listBook[i].nameOfBook, listBook[i].nameOfAuthor, listBook[i].publisher, listBook[i].publishingYear, listBook[i].typeOfBook,  listBook[i].priceOfBook, listBook[i].theNumberOfBooks);
			}
			else {
				fprintf(fi, "%s,%s,%s,%s,%d,%s,%ld,%d", listBook[i].ISBN, listBook[i].nameOfBook, listBook[i].nameOfAuthor, listBook[i].publisher, listBook[i].publishingYear, listBook[i].typeOfBook, listBook[i].priceOfBook, listBook[i].theNumberOfBooks);
			}

		}
		fclose(fi);
	}

}
//This function print list of books in library, which belongs to function "a" of book management

void printListOfBooks(book listBook[], int numberOfBooks) {
	printf("%110s", "LIST OF BOOKS IN LIBRARY\n");
	printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("|| %-12s  || %-20s  || %-20s  || %-20s  || %-5s  || %-15s  || %-10s  || %-10s ||\n", "ISBN", "NAME", "AUTHOR", "PUBLISHER", "YEAR", "TYPE", "PRICE", "QUANTITY");
	printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	for (int i = 0;i < numberOfBooks;i++) {
		printf("|| %-12s  || %-20s  || %-20s  || %-20s  || %-5d  || %-15s  || %-10ld  || %-10d ||\n", listBook[i].ISBN, listBook[i].nameOfBook, listBook[i].nameOfAuthor, listBook[i].publisher,
			listBook[i].publishingYear, listBook[i].typeOfBook, listBook[i].priceOfBook, listBook[i].theNumberOfBooks);
		printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	}
	system("pause");
}


// This function helps check the characters of ISBN of books
// If ISBN contains letters, function return false

bool checkValidISBN(char ISBN[]) {
	int number = atoi(ISBN);
	if ( number < 0) {
		return false;
	}
	else {
		for (int i = 1;i < strlen(ISBN);i++) {
			if (ISBN[i] < '48' && ISBN[i]>'57') {
				return false;
			}

		}
	}
	return true;
}
// This function helps user to add books to list of library

void addBook(book listBook[], int& numberOfBooks) {


	
	while (true) {

		printf("ISBN OF BOOK (10 NUMBERS): ");
		scanf("\n");
		fgets(listBook[numberOfBooks].ISBN, 15, stdin);
		listBook[numberOfBooks].ISBN[strlen(listBook[numberOfBooks].ISBN) - 1] = '\0';
		while (!checkValidISBN(listBook[numberOfBooks].ISBN) || strlen(listBook[numberOfBooks].ISBN) != 10) {
			printf("PLEASE FILL AGAIN: ");
			scanf("\n");
			fgets(listBook[numberOfBooks].ISBN, 15, stdin);
			listBook[numberOfBooks].ISBN[strlen(listBook[numberOfBooks].ISBN) - 1] = '\0';
		}


		printf("NAME OF BOOK: ");
		scanf("\n");
		fgets(listBook[numberOfBooks].nameOfBook, 40, stdin);
		listBook[numberOfBooks].nameOfBook[strlen(listBook[numberOfBooks].nameOfBook) - 1] = '\0';
		while (!checkValidCharacter(listBook[numberOfBooks].nameOfBook) || strlen(listBook[numberOfBooks].nameOfBook) > 50) {
			printf("PLEASE FILL AGAIN: ");
			scanf("\n");
			fgets(listBook[numberOfBooks].nameOfBook, 40, stdin);
			listBook[numberOfBooks].nameOfBook[strlen(listBook[numberOfBooks].nameOfBook) - 1] = '\0';
		}
		toUpper(listBook[numberOfBooks].nameOfBook);

		printf("NAME OF AUTHOR: ");
		scanf("\n");
		fgets(listBook[numberOfBooks].nameOfAuthor, 40, stdin);
		listBook[numberOfBooks].nameOfAuthor[strlen(listBook[numberOfBooks].nameOfAuthor) - 1] = '\0';
		while (!checkValidCharacter(listBook[numberOfBooks].nameOfAuthor) || strlen(listBook[numberOfBooks].nameOfAuthor) > 50) {
			printf("PLEASE FILL AGAIN: ");
			scanf("\n");
			fgets(listBook[numberOfBooks].nameOfAuthor, 40, stdin);
			listBook[numberOfBooks].nameOfAuthor[strlen(listBook[numberOfBooks].nameOfAuthor) - 1] = '\0';
		}
		toUpper(listBook[numberOfBooks].nameOfAuthor);

		printf("PUBLISHER: ");
		scanf("\n");
		fgets(listBook[numberOfBooks].publisher, 30, stdin);
		listBook[numberOfBooks].publisher[strlen(listBook[numberOfBooks].publisher) - 1] = '\0';
		while (!checkValidCharacter(listBook[numberOfBooks].publisher) || strlen(listBook[numberOfBooks].publisher) > 50) {
			printf("PLEASE FILL AGAIN: ");
			scanf("\n");
			fgets(listBook[numberOfBooks].publisher, 30, stdin);
			listBook[numberOfBooks].publisher[strlen(listBook[numberOfBooks].publisher) - 1] = '\0';
		}
		toUpper(listBook[numberOfBooks].publisher);

		printf("FILL PUBLISHING YEAR: ");
		scanf("%d", &listBook[numberOfBooks].publishingYear);
		while (listBook[numberOfBooks].publishingYear < 1900) {
			printf("FILL AGAIN: ");
			scanf("%d", &listBook[numberOfBooks].publishingYear);
		}

		printf("TYPE OF BOOK: ");

		scanf("\n");
		fgets(listBook[numberOfBooks].typeOfBook, 20, stdin);
		listBook[numberOfBooks].typeOfBook[strlen(listBook[numberOfBooks].typeOfBook) - 1] = '\0';
		while (!checkValidCharacter(listBook[numberOfBooks].typeOfBook) || strlen(listBook[numberOfBooks].typeOfBook) > 40) {
			printf("PLEASE FILL AGAIN: ");
			scanf("\n");
			fgets(listBook[numberOfBooks].typeOfBook, 20, stdin);
			listBook[numberOfBooks].typeOfBook[strlen(listBook[numberOfBooks].typeOfBook) - 1] = '\0';
		}
		toUpper(listBook[numberOfBooks].typeOfBook);

		printf("PRICE OF BOOK: ");
		scanf("%ld", &listBook[numberOfBooks].priceOfBook);
		while (listBook[numberOfBooks].priceOfBook < 0 || listBook[numberOfBooks].priceOfBook>10000000) {

			printf("FILL AGAIN: ");
			scanf("%ld", &listBook[numberOfBooks].priceOfBook);
		}

		printf("THE QUANTITY: ");
		scanf("%d", &listBook[numberOfBooks].theNumberOfBooks);
		while (listBook[numberOfBooks].theNumberOfBooks < 0 || listBook[numberOfBooks].theNumberOfBooks>1000000) {

			printf("FILL AGAIN: ");
			scanf("%d", &listBook[numberOfBooks].theNumberOfBooks);
		}



		numberOfBooks++;
		exportNewFileOfBook("listBook.txt", listBook, numberOfBooks);
		int choose = 0;
		printf("1. CONTINUE FILLING INFORMATION\n");
		printf("2. STOP\n");
		printf("YOUR CHOICE: ");
		
		scanf("%d", &choose);
		if (choose == 2) {
			break;

		}
		else {
			continue;
		}

	
	}

}

// This function helps user to choose a book to adjust its information

void adjustInformationOfBook(book listBook[], int numberOfBooks) {

	bool flag = true;
	while (flag) {
		printListOfBooks(listBook, numberOfBooks);
		printf("PLEASE CHOOSE A BOOK TO ADJUST INFORMATION (1,2,..,%d): ", numberOfBooks);
		int chooseBook = 0;
		scanf("%d", &chooseBook);
		while (chooseBook <= 0 || chooseBook > numberOfBooks) {
			printf("PLEASE FILL AGAIN: ");
			scanf("%d", &chooseBook);
		}
		bool flag1 = true;
		while (flag1) {
			int choice = 0;
			int chooseInfor = 0;

			printf("WHICH INFORMATION DO YOU NEED TO ADJUST?\n");
			printf("1. ISBN OF BOOK\n");
			printf("2. NAME OF BOOK\n");
			printf("3. NAME OF AUTHOR\n");
			printf("4. PUBLISHER\n");
			printf("5. PUBLISHING YEAR\n");
			printf("6. TYPE OF BOOK\n");
			printf("7. PRICE OF BOOK\n");
			printf("8. QUANTITY OF BOOK\n");
			scanf("%d", &chooseInfor);
			while (chooseInfor < 1 || chooseInfor>8) {
				printf("PLEASE FILL AGAIN: ");
				scanf("%d", &chooseInfor);
			}
			switch (chooseInfor) {
			case 1:
				printf("ISBN (10 NUMBERS): ");
				scanf("\n");
				fgets(listBook[chooseBook - 1].ISBN, 15, stdin);
				listBook[chooseBook - 1].ISBN[strlen(listBook[chooseBook - 1].ISBN) - 1] = '\0';
				while (!checkValidISBN(listBook[chooseBook - 1].ISBN) || strlen(listBook[chooseBook - 1].ISBN) != 10) {
					printf("PLEASE FILL AGAIN: ");
					scanf("\n");
					fgets(listBook[chooseBook - 1].ISBN, 10, stdin);
					listBook[chooseBook - 1].ISBN[strlen(listBook[chooseBook - 1].ISBN) - 1] = '\0';
				}
				break;
			case 2:
				printf("NAME OF BOOK: ");
				scanf("\n");
				fgets(listBook[chooseBook - 1].nameOfBook, 40, stdin);
				listBook[chooseBook - 1].nameOfBook[strlen(listBook[chooseBook - 1].nameOfBook) - 1] = '\0';
				while (!checkValidCharacter(listBook[chooseBook - 1].nameOfBook) || strlen(listBook[chooseBook - 1].nameOfBook) > 50) {
					printf("PLEASE FILL AGAIN: ");
					scanf("\n");
					fgets(listBook[chooseBook - 1].nameOfBook, 40, stdin);
					listBook[chooseBook - 1].nameOfBook[strlen(listBook[chooseBook - 1].nameOfBook) - 1] = '\0';
				}
				toUpper(listBook[chooseBook - 1].nameOfBook);
				break;
			case 3:
				printf("NAME OF AUTHOR: ");
				scanf("\n");
				fgets(listBook[chooseBook - 1].nameOfAuthor, 40, stdin);
				listBook[chooseBook - 1].nameOfAuthor[strlen(listBook[chooseBook - 1].nameOfAuthor) - 1] = '\0';
				while (!checkValidCharacter(listBook[chooseBook - 1].nameOfAuthor) || strlen(listBook[chooseBook - 1].nameOfAuthor) > 50) {
					printf("PLEASE FILL AGAIN: ");
					scanf("\n");
					fgets(listBook[chooseBook - 1].nameOfAuthor, 40, stdin);
					listBook[chooseBook - 1].nameOfAuthor[strlen(listBook[chooseBook - 1].nameOfAuthor) - 1] = '\0';
				}
				toUpper(listBook[numberOfBooks].nameOfAuthor);
				break;
			case 4:
				printf("PUBLISHER: ");
				scanf("\n");
				fgets(listBook[chooseBook - 1].publisher, 30, stdin);
				listBook[chooseBook - 1].publisher[strlen(listBook[chooseBook - 1].publisher) - 1] = '\0';
				while (!checkValidCharacter(listBook[chooseBook - 1].publisher) || strlen(listBook[chooseBook - 1].publisher) > 50) {
					printf("PLEASE FILL AGAIN: ");
					scanf("\n");
					fgets(listBook[chooseBook - 1].publisher, 30, stdin);
					listBook[chooseBook - 1].publisher[strlen(listBook[chooseBook - 1].publisher) - 1] = '\0';
				}
				toUpper(listBook[chooseBook - 1].publisher);
				break;
			case 5:

				printf("FILL PUBLISHING YEAR: ");
				scanf("%d", &listBook[chooseBook - 1].publishingYear);
				while (listBook[chooseBook - 1].publishingYear < 1900) {
					printf("FILL AGAIN: ");
					scanf("%d", &listBook[chooseBook - 1].publishingYear);
				}
				break;
			case 6:
				printf("TYPE OF BOOK: ");

				scanf("\n");
				fgets(listBook[chooseBook - 1].typeOfBook, 20, stdin);
				listBook[chooseBook - 1].typeOfBook[strlen(listBook[chooseBook - 1].typeOfBook) - 1] = '\0';
				while (!checkValidCharacter(listBook[chooseBook - 1].typeOfBook) || strlen(listBook[chooseBook - 1].typeOfBook) > 40) {
					printf("PLEASE FILL AGAIN: ");
					scanf("\n");
					fgets(listBook[chooseBook - 1].typeOfBook, 20, stdin);
					listBook[chooseBook - 1].typeOfBook[strlen(listBook[chooseBook - 1].typeOfBook) - 1] = '\0';
				}
				toUpper(listBook[chooseBook - 1].typeOfBook);break;
			case 7:
				printf("PRICE OF BOOK: ");
				scanf("%ld", &listBook[chooseBook - 1].priceOfBook);
				while (listBook[chooseBook - 1].priceOfBook < 0 || listBook[chooseBook - 1].priceOfBook>1000000) {

					printf("FILL AGAIN: ");
					scanf("%ld", &listBook[chooseBook - 1].priceOfBook);
				}
				break;
			case 8:
				printf("THE QUANTITY: ");
				scanf("%d", &listBook[chooseBook - 1].theNumberOfBooks);
				while (listBook[chooseBook - 1].theNumberOfBooks < 0 || listBook[chooseBook - 1].theNumberOfBooks>1000000) {

					printf("FILL AGAIN: ");
					scanf("%d", &listBook[numberOfBooks].theNumberOfBooks);
				}
				break;

			}

			exportNewFileOfBook("listBook.txt", listBook, numberOfBooks);




			int choose = 0;
			printf("1. CONTINUE ADJUSTING INFORMATION OF THIS BOOK\n");
			printf("2. STOP\n");
			printf("YOUR CHOICE: ");
			scanf("%d", &choose);
			if (choose == 1) {
				flag1 = true;
			}
			else {
				flag1 = false;
			}
		}
		int choose = 0;
		printf("1. CONTINUE ADJUSTING INFORMATION \n");
		printf("2. STOP\n");
		printf("YOUR CHOICE: ");
		scanf("%d", &choose);
		if (choose == 1) {
			flag = true;
		}
		else {
			flag = false;
		}

	

	}


}

// This function helps user to delete a book in book list of library

void deleteInformationOfBook(book listBook[], int& numberOfBooks) {
	printListOfBooks(listBook, numberOfBooks);
	bool flag = true;
	while (flag) {
		printf("BOOK THAT YOU WANT TO DELETE (1 to %d): ", numberOfBooks);
		int choose = 0;
		scanf("%d", &choose);
		for (int i = choose - 1;i < numberOfBooks - 1;i++) {


			listBook[i] = listBook[i + 1];

		}
		numberOfBooks--;
		system("cls");
		printListOfBooks(listBook, numberOfBooks);
		exportNewFileOfBook("listBook.txt", listBook, numberOfBooks);
		int choice = 0;
		printf("DO YOU WANT TO CONTINUE DELETING?\n");
		printf("1. YES\n");
		printf("2. NO\n");
		scanf("%d", &choice);
		if (choice == 1) {
			flag = true;
		}
		else {
			flag = false;
		}
	}

}
// This function helps user to find a book by filling its name
void findBookByName(book listBook[], int numberOfBooks) {
	printf("LIST ISBN OF BOOKS IN LIBRARY\n");
	for (int i = 0;i < numberOfBooks;i++) {
		printf("%s\n", listBook[i].nameOfBook);
	}
	char name[40]{};
	printf("NAME OF BOOK THAT YOU NEED TO FIND: ");
	scanf("\n");
	fgets(name, 40, stdin);
	name[strlen(name) - 1] = '\0';
	
	while (!checkValidCharacter(name) || strlen(name) >50) {
		printf("PLEASE FILL AGAIN: ");
		scanf("\n");
		fgets(name, 40, stdin);
		name[strlen(name) - 1] = '\0';
	}
	toUpper(name);
	int index = -1;
	for (int i = 0;i < numberOfBooks;i++) {
		if (strcmp(name, listBook[i].nameOfBook) == 0) {
			index = i;
		}

	}
	if (index == -1) {
		printf("CAN'T FIND THE BOOK!");
	}
	else {
		printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("|| %-12s  || %-20s  || %-20s  || %-20s  || %-5s  || %-15s  || %-10s  || %-10s ||\n", "ISBN", "NAME", "AUTHOR", "PUBLISHER", "YEAR", "TYPE", "PRICE", "QUANTITY");
		printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		
		printf("|| %-12s  || %-20s  || %-20s  || %-20s  || %-5d  || %-15s  || %-10ld  || %-10d ||\n", listBook[index].ISBN, listBook[index].nameOfBook, listBook[index].nameOfAuthor, listBook[index].publisher,
				listBook[index].publishingYear, listBook[index].typeOfBook, listBook[index].priceOfBook, listBook[index].theNumberOfBooks);
		printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		
		system("pause");
	}
}

// This function helps to find a book by filling its ISBN
void findBookByISBN (book listBook[], int numberOfBooks) {
	printf("LIST NAME OF BOOKS IN LIBRARY\n");
	for (int i = 0;i < numberOfBooks;i++) {
		printf("%s\n", listBook[i].ISBN);
	}
	char isbn[15]{};
	printf("ISBN THAT YOU NEED TO FIND: ");
	scanf("\n");
	fgets(isbn, 15, stdin);
	isbn[strlen(isbn) - 1] = '\0';
	while (!checkValidISBN(isbn) || strlen(isbn) != 10) {
		printf("PLEASE FILL AGAIN: ");
		scanf("\n");
		fgets(isbn, 15, stdin);
		isbn[strlen(isbn) - 1] = '\0';
	}
	int index = -1;
	for (int i = 0;i < numberOfBooks;i++) {
		if (strcmp(isbn, listBook[i].ISBN) == 0) {
			index = i;
		}

	}
	if (index == -1) {
		printf("CAN'T FIND ISBN!");
	}
	else {
		printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("|| %-12s  || %-20s  || %-20s  || %-20s  || %-5s  || %-15s  || %-10s  || %-10s ||\n", "ISBN", "NAME", "AUTHOR", "PUBLISHER", "YEAR", "TYPE", "PRICE", "QUANTITY");
		printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");

		printf("|| %-12s  || %-20s  || %-20s  || %-20s  || %-5d  || %-15s  || %-10ld  || %-10d ||\n", listBook[index].ISBN, listBook[index].nameOfBook, listBook[index].nameOfAuthor, listBook[index].publisher,
			listBook[index].publishingYear, listBook[index].typeOfBook, listBook[index].priceOfBook, listBook[index].theNumberOfBooks);
		printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");

		system("pause");
	}
}
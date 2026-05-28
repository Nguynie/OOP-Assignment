

#include <string.h>

#include <stdio.h>

#include <stdlib.h>

#include "menu.h"

#include "reader.h"

#include "book.h"

#include "borrow.h"

#include "return.h"

#include "statistics.h"



int main() {
	reader listReader[100];
	book listBook[100];
	int numberOfReaders = 0;
	int numberOfBooks=0 ;
	bool flag = true;
	do {
		printf("WAITING SCREEN!!!\n");
		printf("1. USE APP\n");
		printf("2. CLOSE APP");
		printf("\n YOUR CHOICE: ");
		int choice = 0;
		scanf("%d", &choice);
		while (choice != 1 && choice != 2) {
			printf("PLEASE CHOOSE AGAIN: ");
			scanf("%d", &choice);
		}
		system("cls");
		Date toDay;
		printf("PLEASE FILL THE DATE BEFORE USING APP!\n");
		fillDate(toDay.day, toDay.month, toDay.year);
		system("cls");
		
		if (choice == 1) {
			do {
				readFileOfListReaders("listReader.txt", listReader, numberOfReaders);
				readFileOfListBook("listBook.txt", listBook, numberOfBooks);
				
				printMenu();
				char choice{};
				scanf("\n");
				scanf("%c", &choice);

				while (choice < '1' || choice>'6') {
					printf("                                   \n ERROR. PLEASE FILL AGAIN: ");
					scanf("\n");
					scanf("%c", &choice);
				}
				system("cls");
				if (choice == '1') {

					do {
						readFileOfListReaders("listReader.txt", listReader, numberOfReaders);
						printMenuOfFunction1();
						char choice{};
						printf("                                   \n Which function do you want to choose (a,b,c...): ");
						scanf("\n");
						scanf("%c", &choice);
						while (choice < 'a' || choice>'g') {
							printf("                                   \n ERROR. PLEASE FILL AGAIN: ");
							scanf("\n");
							scanf("%c", &choice);
						}
						system("cls");
						if (choice == 'a') {

							printListOfReaders(listReader, numberOfReaders);
							system("cls");
						}
						else if (choice == 'b') {
							addReader(listReader, numberOfReaders);
							system("cls");;

						}
						else if (choice == 'c') {
							adjustInformation(listReader, numberOfReaders);
							system("cls");

						}
						else if (choice == 'd') {
							deleteInformation(listReader, numberOfReaders);
							system("cls");
						}
						else if (choice == 'e') {
							findReaderByCitizenIdNumber(listReader, numberOfReaders);
							system("cls");
						}
						else if (choice == 'f') {
							findBookByNameOfReader(listReader, numberOfReaders);
							system("cls");
						}
						else if (choice == 'g') {
							break;
						}
					} while (true);
				}
				else if (choice == '2') {

					do {
						readFileOfListBook("listBook.txt", listBook, numberOfBooks);
						char choice{};
						printMenuOfFunction2();
						printf("                                 \n Which function do you want to choose (a,b,c...): ");
						scanf("\n");
						scanf("%c", &choice);
						system("cls");
						while (choice < 'a' || choice>'g') {
							printf("                                   \n ERROR. PLEASE FILL AGAIN: ");
							scanf("\n");
							scanf("%c", &choice);
						}
						if (choice == 'a') {
							printListOfBooks(listBook, numberOfBooks);
							system("cls");
						}
						else if (choice == 'b') {
							addBook(listBook, numberOfBooks);
							system("cls");
						}
						else if (choice == 'c') {
							adjustInformationOfBook(listBook, numberOfBooks);
							system("cls");
						}
						else if (choice == 'd') {
							deleteInformationOfBook(listBook, numberOfBooks);
							system("cls");
						}
						else if (choice == 'e') {
							findBookByISBN(listBook, numberOfBooks);
							system("cls");
						}
						else if (choice == 'f') {
							findBookByName(listBook, numberOfBooks);
							system("cls");
						}
						else if (choice == 'g') {
							break;
						}
					} while (true);

				}
				else if (choice == '3') {
					printf("LIST CODE OF READERS IN LIBRARY\n");
					for (int i = 0;i < numberOfReaders;i++) {
						printf("%s\n", listReader[i].code);
					}
					printf("PLEASE CHOOSE YOUR STUDENT CODE BEFORE BORROWING BOOK ( 1 TO %d): ", numberOfReaders);
					int choose = 0;
					scanf("%d", &choose);
					int count = 0;
					
					
					borrowingBook(listBook, numberOfBooks, listReader, numberOfReaders, toDay,choose, listReader[choose - 1].quantityOfBorrowing);
					system("cls");

				}
				else if (choice == '4') {
					returnBook(listReader, numberOfReaders, toDay, listBook, numberOfBooks);
					system("cls");

				}
				else if (choice == '5') {
					do {
						
						char choice{};
						printMenuOfFunction5();
						printf("                                 \n Which function do you want to choose (a,b,c...): ");
						scanf("\n");
						scanf("%c", &choice);
						system("cls");
						while (choice < 'a' || choice>'g') {
							printf("                                   \n ERROR. PLEASE FILL AGAIN: ");
							scanf("\n");
							scanf("%c", &choice);
						}
						if (choice == 'a') {
							statisticsNumberOfBooks(listBook, numberOfBooks);
							system("pause");
							system("cls");
						}
						else if (choice == 'b') {
							statisticsNumberOfBooksByType(listBook, numberOfBooks);
							system("cls");
						}
						else if (choice == 'c') {
							statisticsNumberOfReaders(numberOfReaders);
							system("cls");
						}
						else if (choice == 'd') {
							statisticsGender(listReader, numberOfReaders);
							system("cls");
						}
						else if (choice == 'e') {
							statisticsBooksBorrowed(listReader, numberOfReaders);
							system("cls");
						}
						else if (choice == 'f') {
							statisticsReaderMissDl(listReader, numberOfReaders, toDay);
							system("cls");
						}
						else if (choice == 'g') {
							break;
						}
					} while (true);

				}
				else if (choice == '6') {
					break;
				}




			} while (true);
		}
		else if (choice == 2) {
			flag = false;
		}
	}while (flag);

	return 0;
}
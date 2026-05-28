#include <iostream>

#include <string.h>

#include <stdio.h>

#include <stdlib.h>

#include "reader.h"




//This function helps to get the data from file "listReader.txt"
//array listReader contain information of readers
//numberOfReaders is the number of readers now in library


void readFileOfListReaders(const char*filename, reader listReader[], int& numberOfReaders) {
	numberOfReaders = 0;
	FILE* fi;
	fi = fopen(filename, "rt");
	if (fi != NULL) {
		while (!feof(fi)) {
			char str[200];
			fgets(str, 200, fi);
			char* token = strtok(str, ",-");
			int countInfor = 0;
			while (token != NULL) {
				if (countInfor == 0) { // Code of reader
					strcpy(listReader[numberOfReaders].code, token);
				}
				else if (countInfor == 1) { // Full name of reader
					strcpy(listReader[numberOfReaders].name, token);
				}
				else if (countInfor == 2) { // Identity number
					strcpy(listReader[numberOfReaders].idNumber, token);
				}
				else if (countInfor == 3) { // date of birth
					char date[10];
					strcpy(date, token);
					
					listReader[numberOfReaders].dob.day = atoi(date);
					

				}
				else if (countInfor == 4) {
					char month[10];
					strcpy(month, token );
					listReader[numberOfReaders].dob.month = atoi(month);
				}
				else if (countInfor == 5) {
					char year[10];
					strcpy(year, token) ;
					listReader[numberOfReaders].dob.year = atoi(year);
				}
				else if (countInfor == 6) { // gender
					if (strcmp(token,"1")==0) {
						strcpy(listReader[numberOfReaders].gender, "MALE");
					}
					else {
						strcpy(listReader[numberOfReaders].gender, "FEMALE");
					}
				}
				else if (countInfor == 7) { // email
					strcpy(listReader[numberOfReaders].email, token);
				}
				else if (countInfor == 8) { // dia chi
					strcpy(listReader[numberOfReaders].address, token);
				}
				else if (countInfor == 9) { // ngay lap the
					char date[10];
					strcpy(date, token);
					
					listReader[numberOfReaders].creatingCardDay.day = atoi(date);
					
					listReader[numberOfReaders].expiringCardDay.day = atoi(date);
					
				}
				else if(countInfor==10) {
					char month[10];
					strcpy(month, token );
					listReader[numberOfReaders].creatingCardDay.month = atoi(month);
					listReader[numberOfReaders].expiringCardDay.month = atoi(month);
					
				}
				else if (countInfor == 11) {
					char year[10];
					strcpy(year, token);
					listReader[numberOfReaders].creatingCardDay.year = atoi(year);
					listReader[numberOfReaders].expiringCardDay.year = atoi(year) + 4;
				}
				countInfor++;
				token = strtok(NULL, ",-");
				



			
			}
			numberOfReaders++;
		}
		fclose(fi);
	}
	

}


//This functions helps update the data in file listReader.txt

void exportNewFile(const char* filename, reader listReader[], int numberOfReaders) {
	FILE* fi;
	fi = fopen(filename, "wt");
	if (fi != NULL) {
		for (int i = 0;i < numberOfReaders;i++) {
			int choice;
			if (strcmp(listReader[i].gender, "MALE") == 0) {
				choice = 1;
			}
			else {
				choice = 0;
			}
			if (i != numberOfReaders - 1) {
				fprintf(fi, "%s,%s,%s,%d-%d-%d,%d,%s,%s,%d-%d-%d\n", listReader[i].code, listReader[i].name, listReader[i].idNumber, listReader[i].dob.day, listReader[i].dob.month, listReader[i].dob.year, choice, listReader[i].email, listReader[i].address, listReader[i].creatingCardDay.day, listReader[i].creatingCardDay.month, listReader[i].creatingCardDay.year);
			}
			else {
				fprintf(fi, "%s,%s,%s,%d-%d-%d,%d,%s,%s,%d-%d-%d", listReader[i].code, listReader[i].name, listReader[i].idNumber, listReader[i].dob.day, listReader[i].dob.month, listReader[i].dob.year, choice, listReader[i].email, listReader[i].address, listReader[i].creatingCardDay.day, listReader[i].creatingCardDay.month, listReader[i].creatingCardDay.year);
			}

		}
		fclose(fi);
	}

}

//This function print list of readers in library, which belongs to function "a" of reader management

void printListOfReaders(reader listReader[], int numberOfReaders) {
	printf("%110s", "LIST OF READERS IN LIBRARY\n");
	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("|| %-10s  ||  %-22s  ||  %-15s  ||   %-8s  ||  %-3s   ||  %-30s  ||  %-40s  ||  %-3s ||   %-3s  ||\n", "CODE","FULL NAME","ID NUMBER","DATEOFBIRTH","GENDER","EMAIL","ADDRESS","CREATING","EXPIRING");
	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	for (int i = 0;i < numberOfReaders;i++) {
		printf("|| %-10s  ||  %-22s  ||  %-15s  ||   %-2d-%-2d-%-5d  ||  %-7s  ||  %-30s  ||  %-40s  ||  %d-%d-%d ||   %d-%d-%d  ||\n",listReader[i].code, listReader[i].name, listReader[i].idNumber,listReader[i].dob.day,
					listReader[i].dob.month,listReader[i].dob.year,listReader[i].gender,listReader[i].email,listReader[i].address,
				    listReader[i].creatingCardDay.day,listReader[i].creatingCardDay.month, listReader[i].creatingCardDay.year,
					listReader[i].expiringCardDay.day, listReader[i].expiringCardDay.month, listReader[i].expiringCardDay.year);
		printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	}
	system("pause");
}


// This function helps check the characters of code of readers
// If code contains letters, function return false

bool checkValidCode(char code[]) {
	int number = atoi(code);
	if (code[0] == '0' || number < 0) {
		return false;
	}
	else {
		for (int i = 1;i < strlen(code);i++) {
			if (code[i] < '48' && code[i]>'57') {
				return false;
			}
			
		}
	}
	return true;
}

// This function helps check the characters of citizen id number of readers
// If code contains letters, function return false

bool checkValidID(char id[]) {

		for (int i = 0;i < strlen(id);i++) {
			if (id[i] < '48' && id[i]>'57') {
				return false;
			}
		
	}
	return true;
}


// This function helps check the characters of names
// If names contain numbers, function return false
bool checkValidCharacter(char name[]) {
	
	for (int i = 0;i < strlen(name);i++) {
		if (name[i]<'A' || name[i]>'Z') {
			if( (name[i]<'a' || name[i] > 'z'))
				if(name[i]!=' ')
					return false;
		}

	}
	return true;
}

// This function helps to transfer from lower letters to upper letters

void toUpper(char name[]) {
	for (int i = 0;i < strlen(name);i++) {
		if (name[i] >= 'a' && name[i] <= 'z') {
			name[i] = toupper(name[i]);
		}
	}
}

// This function helps user to fill in the dates

void fillDate(int& day, int& month, int& year) {
	printf("YEAR: ");
	scanf("%d", &year);
	while (year < 2000) {
		printf("FILL AGAIN: ");

		scanf("%d", &year);


	}
	printf("MONTH: ");
	scanf("%d", &month);
	while (month <= 0 || month > 12) {
		printf("FILL AGAIN: ");

		scanf("%d", &month);


	}
	switch (month) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		printf("DAY: ");

		scanf("%d", &day);





		while (day <= 0 || day > 31) {
			printf("FILL AGAIN: ");

			scanf("%d", &day);

		}
		break;
	case 2:
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
			printf("DAY: ");

			scanf("%d", &day);


			while (day <= 0 || day > 29) {
				printf("FILL AGAIN: ");

				scanf("%d", &day);

			}
		}
		else {
			printf("DAY: ");

			scanf("%d", &day);


			while (day <= 0 || day > 28) {
				printf("FILL AGAIN: ");

				scanf("%d", &day);

			}
			
		}
		break;
	case 4: case 6: case 9: case 11:
		printf("DAY: ");

		scanf("%d", &day);



		while (day <= 0 || day > 30) {
			printf("FILL AGAIN: ");

			scanf("%d", &day);

		}
		break;
	}
}

// This function helps user to add readers to list of library

void addReader(reader listReader[],  int &numberOfReaders) {
	
	
	bool flag = true;
	int choice = 0;
	while (flag) {
		
		printf("CODE OF READER (YOUR ID STUDENT NUMBER): ");
		scanf("\n");
		fgets(listReader[numberOfReaders].code, 10, stdin);
		listReader[numberOfReaders ].code[strlen(listReader[numberOfReaders ].code) - 1] = '\0';
		while (!checkValidCode(listReader[numberOfReaders ].code) || strlen(listReader[numberOfReaders ].code) != 8) {
			printf("PLEASE FILL AGAIN: ");
			scanf("\n");
			fgets(listReader[numberOfReaders].code, 10, stdin);
			listReader[numberOfReaders ].code[strlen(listReader[numberOfReaders ].code) - 1] = '\0';
		}


		printf("NAME OF READER: ");
		scanf("\n");
		fgets(listReader[numberOfReaders ].name, 40, stdin);
		listReader[numberOfReaders ].name[strlen(listReader[numberOfReaders ].name) - 1] = '\0';
		while (!checkValidCharacter(listReader[numberOfReaders ].name)|| strlen(listReader[numberOfReaders ].code)>50) {
			printf("PLEASE FILL AGAIN: ");
			scanf("\n");
			fgets(listReader[numberOfReaders ].name, 40, stdin);
			listReader[numberOfReaders ].name[strlen(listReader[numberOfReaders ].name) - 1] = '\0';
		}
		toUpper(listReader[numberOfReaders ].name);

		printf("ID NUMBER OF READER (YOUR CITIZEN ID NUMBER): ");
		scanf("\n");
		fgets(listReader[numberOfReaders ].idNumber, 14, stdin);
		listReader[numberOfReaders ].idNumber[strlen(listReader[numberOfReaders ].idNumber) - 1] = '\0';
		while (!checkValidID(listReader[numberOfReaders ].idNumber) || strlen(listReader[numberOfReaders ].idNumber) != 12) {
			printf("PLEASE FILL AGAIN: ");
			scanf("\n");
			fgets(listReader[numberOfReaders ].idNumber, 14, stdin);
			listReader[numberOfReaders ].idNumber[strlen(listReader[numberOfReaders ].idNumber) - 1] = '\0';
		}
		printf("FILL YOUR BIRTHDAY\n");
		fillDate(listReader[numberOfReaders ].dob.day, listReader[numberOfReaders ].dob.month, listReader[numberOfReaders ].dob.year);

		printf("PLEASE FILL 1 ( MALE) OR FILL 0( FEMALE): ");
		scanf("%d", &choice);
		while (choice != 0 && choice != 1) {
			printf("PLEASE FILL AGAIN: ");
			scanf("%d", &choice);
		}
		if (choice == 1) {
			strcpy(listReader[numberOfReaders ].gender, "MALE");
		}
		else {
			strcpy(listReader[numberOfReaders ].gender, "FEMALE");
		}
		printf("EMAIL OF READER: ");
	
		scanf("\n");
		fgets(listReader[numberOfReaders ].email, 40, stdin);
		listReader[numberOfReaders ].email[strlen(listReader[numberOfReaders ].email) - 1] = '\0';
		while ( strlen(listReader[numberOfReaders ].email)>50) {
			printf("PLEASE FILL AGAIN: ");
			scanf("\n");
			fgets(listReader[numberOfReaders ].email, 40, stdin);
			listReader[numberOfReaders ].email[strlen(listReader[numberOfReaders ].email) - 1] = '\0';
		}

		printf("ADDRESS OF READER ( ADDRESS NUMBER, WARD, DISTRICT): ");
		scanf("\n");
		fgets(listReader[numberOfReaders ].address, 40, stdin);
		listReader[numberOfReaders ].address[strlen(listReader[numberOfReaders ].address) - 1] = '\0';
		while (strlen(listReader[numberOfReaders ].address) > 50) {
			printf("PLEASE FILL AGAIN: ");
			scanf("\n");
			fgets(listReader[numberOfReaders ].address, 40, stdin);
			listReader[numberOfReaders ].address[strlen(listReader[numberOfReaders ].address) - 1] = '\0';
		}
		printf("FILL YOUR CARD CREATING DAY\n");
		fillDate(listReader[numberOfReaders ].creatingCardDay.day, listReader[numberOfReaders ].creatingCardDay.month, listReader[numberOfReaders ].creatingCardDay.year);
		listReader[numberOfReaders ].expiringCardDay.day = listReader[numberOfReaders ].creatingCardDay.day;
		listReader[numberOfReaders ].expiringCardDay.month = listReader[numberOfReaders ].creatingCardDay.month;
		listReader[numberOfReaders ].expiringCardDay.year = listReader[numberOfReaders ].creatingCardDay.year+4;
		numberOfReaders++;
		exportNewFile("listReader.txt", listReader, numberOfReaders);
		int choose = 0;
		printf("1. CONTINUE FILLING INFORMATION\n");
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


// This function helps user to choose a reader to adjust him/ her information

void adjustInformation( reader listReader[], int numberOfReaders) {
	
	bool flag = true;
	while (flag) {
		printListOfReaders(listReader, numberOfReaders);
		printf("PLEASE CHOOSE A READER TO ADJUST INFORMATION (1,2,..,%d): ",numberOfReaders);
		int chooseReader = 0;
		scanf("%d", &chooseReader);
		while (chooseReader<=0 || chooseReader>numberOfReaders) {
			printf("PLEASE FILL AGAIN: ");
			scanf("%d", &chooseReader);
		}
		bool flag1 = true;
		while (flag1) {
			int choice = 0;
			int chooseInfor = 0;

			printf("WHICH INFORMATION DO YOU NEED TO ADJUST?\n");
			printf("1. CODE OF READER\n");
			printf("2. NAME OF READER\n");
			printf("3. CITIZEN ID NUMBER\n");
			printf("4. DATE OF BIRTH\n");
			printf("5. GENDER\n");
			printf("6. EMAIL\n");
			printf("7. ADDRESS\n");
			printf("8. CARD CREATING DATE\n");
			scanf("%d", &chooseInfor);
			while (chooseInfor < 1 || chooseInfor>8) {
				printf("PLEASE FILL AGAIN: ");
				scanf("%d", &chooseInfor);
			}
			switch (chooseInfor) {
			case 1:
				printf("CODE OF READER (YOUR ID STUDENT NUMBER): ");
				scanf("\n");
				fgets(listReader[chooseReader-1].code, 10, stdin);
				listReader[chooseReader - 1].code[strlen(listReader[chooseReader - 1].code) - 1] = '\0';
				while (!checkValidCode(listReader[chooseReader - 1].code) || strlen(listReader[chooseReader - 1].code) != 8) {
					printf("PLEASE FILL AGAIN: ");
					scanf("\n");
					fgets(listReader[chooseReader - 1].code, 10, stdin);
					listReader[chooseReader - 1].code[strlen(listReader[chooseReader - 1].code) - 1] = '\0';
				}
				break;
			case 2:
				printf("NAME OF READER: ");
				scanf("\n");
				fgets(listReader[chooseReader - 1].name, 40, stdin);
				listReader[chooseReader - 1].name[strlen(listReader[chooseReader - 1].name) - 1] = '\0';
				while (!checkValidCharacter(listReader[chooseReader - 1].name) || strlen(listReader[chooseReader - 1].name) > 50) {
					printf("PLEASE FILL AGAIN: ");
					scanf("\n");
					fgets(listReader[chooseReader - 1].name, 40, stdin);
					listReader[chooseReader - 1].name[strlen(listReader[chooseReader - 1].name) - 1] = '\0';
				}
				toUpper(listReader[chooseReader - 1].name);
				break;
			case 3:
				printf("ID NUMBER OF READER (YOUR CITIZEN ID NUMBER): ");
				scanf("\n");
				fgets(listReader[chooseReader - 1].idNumber, 14, stdin);
				listReader[chooseReader - 1].idNumber[strlen(listReader[chooseReader - 1].idNumber) - 1] = '\0';
				while (!checkValidID(listReader[chooseReader - 1].idNumber) || strlen(listReader[chooseReader - 1].idNumber) != 12) {
					printf("PLEASE FILL AGAIN: ");
					scanf("\n");
					fgets(listReader[chooseReader - 1].idNumber, 14, stdin);
					listReader[chooseReader - 1].idNumber[strlen(listReader[chooseReader - 1].idNumber) - 1] = '\0';
				}
				break;
			case 4:
				fillDate(listReader[chooseReader - 1].dob.day, listReader[chooseReader - 1].dob.month, listReader[chooseReader - 1].dob.year);
				break;
			case 5:
				
				printf("PLEASE FILL 1 ( MALE) OR FILL 0( FEMALE): ");
				scanf("%d", &choice);
				while (choice != 0 && choice != 1) {
					printf("PLEASE FILL AGAIN: ");
					scanf("%d", &choice);
				}
				if (choice == 1) {
					strcpy(listReader[chooseReader - 1].gender, "MALE");
				}
				else {
					strcpy(listReader[chooseReader - 1].gender, "FEMALE");
				}
				break;
			case 6:
				printf("EMAIL OF READER: ");

				scanf("\n");
				fgets(listReader[chooseReader - 1].email, 40, stdin);
				listReader[chooseReader - 1].email[strlen(listReader[chooseReader - 1].email) - 1] = '\0';
				while (strlen(listReader[chooseReader - 1].email) > 50) {
					printf("PLEASE FILL AGAIN: ");
					scanf("\n");
					fgets(listReader[chooseReader - 1].email, 40, stdin);
					listReader[chooseReader - 1].email[strlen(listReader[chooseReader - 1].email) - 1] = '\0';
				}
				break;
			case 7:
				printf("ADDRESS OF READER ( ADDRESS NUMBER, WARD, DISTRICT): ");
				scanf("\n");
				fgets(listReader[chooseReader - 1].address, 40, stdin);
				listReader[chooseReader - 1].address[strlen(listReader[chooseReader - 1].address) - 1] = '\0';
				while (strlen(listReader[chooseReader - 1].address) > 50) {
					printf("PLEASE FILL AGAIN: ");
					scanf("\n");
					fgets(listReader[chooseReader - 1].address, 40, stdin);
					listReader[chooseReader - 1].address[strlen(listReader[chooseReader - 1].address) - 1] = '\0';
				}
				break;
			case 8:
				fillDate(listReader[chooseReader - 1].creatingCardDay.day, listReader[chooseReader - 1].creatingCardDay.month, listReader[chooseReader - 1].creatingCardDay.year);
				listReader[chooseReader - 1].creatingCardDay.day = listReader[chooseReader - 1].expiringCardDay.day;
				listReader[chooseReader - 1].creatingCardDay.month = listReader[chooseReader - 1].expiringCardDay.month;
				listReader[chooseReader - 1].creatingCardDay.year = listReader[chooseReader - 1].expiringCardDay.year;
				break;
			
			}
			
			exportNewFile("listReader.txt", listReader, numberOfReaders);
			



			int choose = 0;
			printf("1. CONTINUE ADJUSTING INFORMATION OF THIS READER\n");
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

// This function helps user to delete a reader in reader list of library

void deleteInformation(reader listReader[], int &numberOfReaders) {
	printListOfReaders(listReader, numberOfReaders);
	bool flag = true;
	while (flag) {
		printf("READER WHOSE INFORMATION YOU WANT TO DELETE (1 to %d): ", numberOfReaders);
		int choose = 0;
		scanf("%d", &choose);
		for (int i = choose - 1;i < numberOfReaders - 1;i++) {


			listReader[i] = listReader[i + 1];

		}
		numberOfReaders--;
		system("cls");
		printListOfReaders(listReader, numberOfReaders);
		exportNewFile("listReader.txt", listReader, numberOfReaders);
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
// This function helps user to find a reader by filling him/ her citizen id number

void findReaderByCitizenIdNumber(reader listReader[], int numberOfReaders) {
	printf("CITIZEN ID NUMBER OF READERS IN LIBRARY\n");
	for (int i = 0;i < numberOfReaders;i++) {
		printf("%s\n", listReader[i].idNumber);
	}
	char id[14]{};
	printf("ID NUMBER OF READER (YOUR CITIZEN ID NUMBER) THAT YOU NEED TO FIND: ");
	scanf("\n");
	fgets(id, 14, stdin);
	id[strlen(id) - 1] = '\0';
	while (!checkValidID(id) || strlen(id) != 12) {
		printf("PLEASE FILL AGAIN: ");
		scanf("\n");
		fgets(id, 14, stdin);
		id[strlen(id) - 1] = '\0';
	}
	int index = -1;
	for (int i = 0;i < numberOfReaders;i++) {
		if (strcmp(id, listReader[i].idNumber) == 0) {
			index = i;
		}
		
	}
	if (index == -1) {
		printf("CAN'T FIND CITIZEN ID NUMBER!");
	}
	else {
		
		printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("|| %-10s  ||  %-22s  ||  %-15s  ||   %-8s  ||  %-3s   ||  %-30s  ||  %-40s  ||  %-3s ||   %-3s  ||\n", "CODE", "FULL NAME", "ID NUMBER", "DATEOFBIRTH", "GENDER", "EMAIL", "ADDRESS", "CREATING", "EXPIRING");
		printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		
			printf("|| %-10s  ||  %-22s  ||  %-15s  ||   %-2d-%-2d-%-5d  ||  %-7s  ||  %-30s  ||  %-40s  ||  %d-%d-%d ||   %d-%d-%d  ||\n", listReader[index].code, listReader[index].name, listReader[index].idNumber, listReader[index].dob.day,
				listReader[index].dob.month, listReader[index].dob.year, listReader[index].gender, listReader[index].email, listReader[index].address,
				listReader[index].creatingCardDay.day, listReader[index].creatingCardDay.month, listReader[index].creatingCardDay.year,
				listReader[index].expiringCardDay.day, listReader[index].expiringCardDay.month, listReader[index].expiringCardDay.year);
			printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		
		system("pause");
	}

}

// This function helps user to find books by filling the name of reader who borrowed these books
void findBookByNameOfReader(reader listReader[], int numberOfReaders) {
	printf("LIST NAME OF READERS\n");
	for (int i = 0;i < numberOfReaders;i++) {
		printf("%s\n", listReader[i].name);
	}
	printf("PLEASE CHOOSE 1 TO %d: ", numberOfReaders);
	int choose = 0;
	scanf("%d", &choose);
	system("cls");
	printf("----------------------------------------------------------------------------------------------------------------------------\n");
	printf("|| %-12s  || %-20s  || %-20s  || %-20s  || %-5s  || %-15s  || \n", "ISBN", "NAME", "AUTHOR", "PUBLISHER", "YEAR", "TYPE");
	printf("----------------------------------------------------------------------------------------------------------------------------\n");
	for (int i = 0;i < listReader[choose - 1].quantityOfBorrowing;i++) {



		printf("|| %-12s  || %-20s  || %-20s  || %-20s  || %-5d  || %-15s  || \n", listReader[choose-1].borrowBook[i].ISBN, listReader[choose - 1].borrowBook[i].nameOfBook, listReader[choose-1].borrowBook[i].nameOfAuthor, listReader[choose-1].borrowBook[i].publisher,
			listReader[choose-1].borrowBook[i].publishingYear, listReader[choose-1].borrowBook[i].typeOfBook);
		printf("----------------------------------------------------------------------------------------------------------------------------\n");

		
	}
	system("pause");
}
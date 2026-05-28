#include "Library.h"
#include "StringUtils.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

Library::Library() {
    numberOfReaders = 0;
    numberOfBooks = 0;
}

void Library::run() {
    bool flag = true;
    do {
        system("cls");
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
        toDay = inputDate();
        system("cls");

        if (choice == 1) {
            do {
                readFileOfListReaders("listReader.txt");
                readFileOfListBook("listBook.txt");

                Menu::printMainMenu();
                char menuChoice{};
                scanf("\n");
                scanf("%c", &menuChoice);
                while (menuChoice < '1' || menuChoice > '6') {
                    printf("                                   \n ERROR. PLEASE FILL AGAIN: ");
                    scanf("\n");
                    scanf("%c", &menuChoice);
                }
                system("cls");
                if (menuChoice == '1') {
                    readerManagement();
                } else if (menuChoice == '2') {
                    bookManagement();
                } else if (menuChoice == '3') {
                    printf("LIST CODE OF READERS IN LIBRARY\n");
                    for (int i = 0; i < numberOfReaders; i++) {
                        printf("%s\n", listReader[i].getCode());
                    }
                    printf("PLEASE CHOOSE YOUR STUDENT CODE BEFORE BORROWING BOOK ( 1 TO %d): ", numberOfReaders);
                    int choose = 0;
                    scanf("%d", &choose);
                    borrowBookForReader(toDay, choose - 1);
                    system("cls");
                } else if (menuChoice == '4') {
                    returnBook(toDay);
                    system("cls");
                } else if (menuChoice == '5') {
                    do {
                        char statChoice{};
                        Menu::printStatisticsMenu();
                        printf("                                 \n Which function do you want to choose (a,b,c...): ");
                        scanf("\n");
                        scanf("%c", &statChoice);
                        system("cls");
                        while (statChoice < 'a' || statChoice > 'g') {
                            printf("                                   \n ERROR. PLEASE FILL AGAIN: ");
                            scanf("\n");
                            scanf("%c", &statChoice);
                        }
                        if (statChoice == 'a') {
                            statNumberOfBooks();
                            system("pause");
                            system("cls");
                        } else if (statChoice == 'b') {
                            statNumberOfBooksByType();
                            system("cls");
                        } else if (statChoice == 'c') {
                            statNumberOfReaders();
                            system("cls");
                        } else if (statChoice == 'd') {
                            statGender();
                            system("cls");
                        } else if (statChoice == 'e') {
                            statBooksBorrowed();
                            system("cls");
                        } else if (statChoice == 'f') {
                            statReaderMissDl(toDay);
                            system("cls");
                        } else if (statChoice == 'g') {
                            break;
                        }
                    } while (true);
                } else if (menuChoice == '6') {
                    break;
                }
            } while (true);
        } else if (choice == 2) {
            flag = false;
        }
    } while (flag);
}

Date Library::inputDate() {
    Date d;
    printf("YEAR: ");
    scanf("%d", &d.year);
    while (d.year < 2000) {
        printf("FILL AGAIN: ");
        scanf("%d", &d.year);
    }
    printf("MONTH: ");
    scanf("%d", &d.month);
    while (d.month <= 0 || d.month > 12) {
        printf("FILL AGAIN: ");
        scanf("%d", &d.month);
    }
    switch (d.month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        printf("DAY: ");
        scanf("%d", &d.day);
        while (d.day <= 0 || d.day > 31) {
            printf("FILL AGAIN: ");
            scanf("%d", &d.day);
        }
        break;
    case 2:
        if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0) {
            printf("DAY: ");
            scanf("%d", &d.day);
            while (d.day <= 0 || d.day > 29) {
                printf("FILL AGAIN: ");
                scanf("%d", &d.day);
            }
        } else {
            printf("DAY: ");
            scanf("%d", &d.day);
            while (d.day <= 0 || d.day > 28) {
                printf("FILL AGAIN: ");
                scanf("%d", &d.day);
            }
        }
        break;
    case 4: case 6: case 9: case 11:
        printf("DAY: ");
        scanf("%d", &d.day);
        while (d.day <= 0 || d.day > 30) {
            printf("FILL AGAIN: ");
            scanf("%d", &d.day);
        }
        break;
    }
    return d;
}

void Library::readFileOfListReaders(const char* filename) {
    numberOfReaders = 0;
    FILE* fi = fopen(filename, "rt");
    if (fi != NULL) {
        while (!feof(fi)) {
            char str[200];
            fgets(str, 200, fi);
            char* token = strtok(str, ",-");
            int countInfor = 0;
            while (token != NULL) {
                if (countInfor == 0) {
                    listReader[numberOfReaders].setCode(token);
                } else if (countInfor == 1) {
                    listReader[numberOfReaders].setName(token);
                } else if (countInfor == 2) {
                    listReader[numberOfReaders].setIdNumber(token);
                } else if (countInfor == 3) {
                    Date dob = listReader[numberOfReaders].getDob();
                    dob.day = atoi(token);
                    listReader[numberOfReaders].setDob(dob);
                } else if (countInfor == 4) {
                    Date dob = listReader[numberOfReaders].getDob();
                    dob.month = atoi(token);
                    listReader[numberOfReaders].setDob(dob);
                } else if (countInfor == 5) {
                    Date dob = listReader[numberOfReaders].getDob();
                    dob.year = atoi(token);
                    listReader[numberOfReaders].setDob(dob);
                } else if (countInfor == 6) {
                    if (strcmp(token, "1") == 0) {
                        listReader[numberOfReaders].setGender("MALE");
                    } else {
                        listReader[numberOfReaders].setGender("FEMALE");
                    }
                } else if (countInfor == 7) {
                    listReader[numberOfReaders].setEmail(token);
                } else if (countInfor == 8) {
                    listReader[numberOfReaders].setAddress(token);
                } else if (countInfor == 9) {
                    Date cd;
                    cd.day = atoi(token);
                    listReader[numberOfReaders].setCreatingCardDay(cd);
                    listReader[numberOfReaders].setExpiringCardDay(cd);
                } else if (countInfor == 10) {
                    Date cd = listReader[numberOfReaders].getCreatingCardDay();
                    cd.month = atoi(token);
                    listReader[numberOfReaders].setCreatingCardDay(cd);
                    Date ed = listReader[numberOfReaders].getExpiringCardDay();
                    ed.month = atoi(token);
                    listReader[numberOfReaders].setExpiringCardDay(ed);
                } else if (countInfor == 11) {
                    Date cd = listReader[numberOfReaders].getCreatingCardDay();
                    cd.year = atoi(token);
                    listReader[numberOfReaders].setCreatingCardDay(cd);
                    Date ed = listReader[numberOfReaders].getExpiringCardDay();
                    ed.year = atoi(token) + 4;
                    listReader[numberOfReaders].setExpiringCardDay(ed);
                }
                countInfor++;
                token = strtok(NULL, ",-");
            }
            numberOfReaders++;
        }
        fclose(fi);
    }
}

void Library::exportNewFileOfReaders(const char* filename) {
    FILE* fi = fopen(filename, "wt");
    if (fi != NULL) {
        for (int i = 0; i < numberOfReaders; i++) {
            int choice;
            if (strcmp(listReader[i].getGender(), "MALE") == 0) {
                choice = 1;
            } else {
                choice = 0;
            }
            Date dob = listReader[i].getDob();
            Date cd = listReader[i].getCreatingCardDay();
            if (i != numberOfReaders - 1) {
                fprintf(fi, "%s,%s,%s,%d-%d-%d,%d,%s,%s,%d-%d-%d\n",
                    listReader[i].getCode(), listReader[i].getName(), listReader[i].getIdNumber(),
                    dob.day, dob.month, dob.year, choice,
                    listReader[i].getEmail(), listReader[i].getAddress(),
                    cd.day, cd.month, cd.year);
            } else {
                fprintf(fi, "%s,%s,%s,%d-%d-%d,%d,%s,%s,%d-%d-%d",
                    listReader[i].getCode(), listReader[i].getName(), listReader[i].getIdNumber(),
                    dob.day, dob.month, dob.year, choice,
                    listReader[i].getEmail(), listReader[i].getAddress(),
                    cd.day, cd.month, cd.year);
            }
        }
        fclose(fi);
    }
}

void Library::readFileOfListBook(const char* filename) {
    numberOfBooks = 0;
    FILE* fi = fopen(filename, "rt");
    if (fi != NULL) {
        while (!feof(fi)) {
            char str[200];
            fgets(str, 200, fi);
            char* token = strtok(str, ",");
            int countInfor = 0;
            while (token != NULL) {
                if (countInfor == 0) {
                    listBook[numberOfBooks].setISBN(token);
                } else if (countInfor == 1) {
                    listBook[numberOfBooks].setNameOfBook(token);
                } else if (countInfor == 2) {
                    listBook[numberOfBooks].setNameOfAuthor(token);
                } else if (countInfor == 3) {
                    listBook[numberOfBooks].setPublisher(token);
                } else if (countInfor == 4) {
                    listBook[numberOfBooks].setPublishingYear(atoi(token));
                } else if (countInfor == 5) {
                    listBook[numberOfBooks].setTypeOfBook(token);
                } else if (countInfor == 6) {
                    listBook[numberOfBooks].setPriceOfBook(atol(token));
                } else if (countInfor == 7) {
                    listBook[numberOfBooks].setTheNumberOfBooks(atoi(token));
                }
                countInfor++;
                token = strtok(NULL, ",");
            }
            numberOfBooks++;
        }
        fclose(fi);
    }
}

void Library::exportNewFileOfBook(const char* filename) {
    FILE* fi = fopen(filename, "wt");
    if (fi != NULL) {
        for (int i = 0; i < numberOfBooks; i++) {
            if (i != numberOfBooks - 1) {
                fprintf(fi, "%s,%s,%s,%s,%d,%s,%ld,%d\n",
                    listBook[i].getISBN(), listBook[i].getNameOfBook(), listBook[i].getNameOfAuthor(),
                    listBook[i].getPublisher(), listBook[i].getPublishingYear(),
                    listBook[i].getTypeOfBook(), listBook[i].getPriceOfBook(), listBook[i].getTheNumberOfBooks());
            } else {
                fprintf(fi, "%s,%s,%s,%s,%d,%s,%ld,%d",
                    listBook[i].getISBN(), listBook[i].getNameOfBook(), listBook[i].getNameOfAuthor(),
                    listBook[i].getPublisher(), listBook[i].getPublishingYear(),
                    listBook[i].getTypeOfBook(), listBook[i].getPriceOfBook(), listBook[i].getTheNumberOfBooks());
            }
        }
        fclose(fi);
    }
}

void Library::readerManagement() {
    do {
        readFileOfListReaders("listReader.txt");
        Menu::printReaderManagementMenu();
        char choice{};
        printf("                                   \n Which function do you want to choose (a,b,c...): ");
        scanf("\n");
        scanf("%c", &choice);
        while (choice < 'a' || choice > 'g') {
            printf("                                   \n ERROR. PLEASE FILL AGAIN: ");
            scanf("\n");
            scanf("%c", &choice);
        }
        system("cls");
        if (choice == 'a') {
            printAllReaders();
            system("cls");
        } else if (choice == 'b') {
            addReader();
            system("cls");
        } else if (choice == 'c') {
            adjustReader();
            system("cls");
        } else if (choice == 'd') {
            deleteReader();
            system("cls");
        } else if (choice == 'e') {
            findReaderByCitizenId();
            system("cls");
        } else if (choice == 'f') {
            findBookByNameOfReader();
            system("cls");
        } else if (choice == 'g') {
            break;
        }
    } while (true);
}

void Library::printAllReaders() {
    printf("%110s", "LIST OF READERS IN LIBRARY\n");
    if (numberOfReaders > 0) {
        listReader[0].displayHeader();
        for (int i = 0; i < numberOfReaders; i++) {
            listReader[i].displayRow();
        }
    }
    system("pause");
}

void Library::addReader() {
    bool flag = true;
    while (flag) {
        char buffer[50];

        printf("CODE OF READER (YOUR ID STUDENT NUMBER): ");
        scanf("\n");
        fgets(buffer, 10, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        while (strlen(buffer) != 8) {
            printf("PLEASE FILL AGAIN: ");
            scanf("\n");
            fgets(buffer, 10, stdin);
            buffer[strlen(buffer) - 1] = '\0';
        }
        listReader[numberOfReaders].setCode(buffer);

        printf("NAME OF READER: ");
        scanf("\n");
        fgets(buffer, 40, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        while (!StringUtils::checkValidCharacter(buffer)) {
            printf("PLEASE FILL AGAIN: ");
            scanf("\n");
            fgets(buffer, 40, stdin);
            buffer[strlen(buffer) - 1] = '\0';
        }
        StringUtils::toUpper(buffer);
        listReader[numberOfReaders].setName(buffer);

        printf("ID NUMBER OF READER (YOUR CITIZEN ID NUMBER): ");
        scanf("\n");
        fgets(buffer, 14, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        while (strlen(buffer) != 12) {
            printf("PLEASE FILL AGAIN: ");
            scanf("\n");
            fgets(buffer, 14, stdin);
            buffer[strlen(buffer) - 1] = '\0';
        }
        listReader[numberOfReaders].setIdNumber(buffer);

        printf("FILL YOUR BIRTHDAY\n");
        Date birthDate = inputDate();
        listReader[numberOfReaders].setDob(birthDate);

        int choice = 0;
        printf("PLEASE FILL 1 ( MALE) OR FILL 0( FEMALE): ");
        scanf("%d", &choice);
        while (choice != 0 && choice != 1) {
            printf("PLEASE FILL AGAIN: ");
            scanf("%d", &choice);
        }
        if (choice == 1) {
            listReader[numberOfReaders].setGender("MALE");
        } else {
            listReader[numberOfReaders].setGender("FEMALE");
        }

        printf("EMAIL OF READER: ");
        scanf("\n");
        fgets(buffer, 40, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        while (strlen(buffer) > 50) {
            printf("PLEASE FILL AGAIN: ");
            scanf("\n");
            fgets(buffer, 40, stdin);
            buffer[strlen(buffer) - 1] = '\0';
        }
        listReader[numberOfReaders].setEmail(buffer);

        printf("ADDRESS OF READER ( ADDRESS NUMBER, WARD, DISTRICT): ");
        scanf("\n");
        fgets(buffer, 40, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        while (strlen(buffer) > 50) {
            printf("PLEASE FILL AGAIN: ");
            scanf("\n");
            fgets(buffer, 40, stdin);
            buffer[strlen(buffer) - 1] = '\0';
        }
        listReader[numberOfReaders].setAddress(buffer);

        printf("FILL YOUR CARD CREATING DAY\n");
        Date cardDate = inputDate();
        listReader[numberOfReaders].setCreatingCardDay(cardDate);
        Date expDate = cardDate;
        expDate.year = cardDate.year + 4;
        listReader[numberOfReaders].setExpiringCardDay(expDate);

        numberOfReaders++;
        exportNewFileOfReaders("listReader.txt");
        int choose = 0;
        printf("1. CONTINUE FILLING INFORMATION\n");
        printf("2. STOP\n");
        printf("YOUR CHOICE: ");
        scanf("%d", &choose);
        if (choose == 2) {
            flag = false;
        }
    }
}

void Library::adjustReader() {
    bool flag = true;
    while (flag) {
        printAllReaders();
        printf("PLEASE CHOOSE A READER TO ADJUST INFORMATION (1,2,..,%d): ", numberOfReaders);
        int chooseReader = 0;
        scanf("%d", &chooseReader);
        while (chooseReader <= 0 || chooseReader > numberOfReaders) {
            printf("PLEASE FILL AGAIN: ");
            scanf("%d", &chooseReader);
        }
        bool flag1 = true;
        while (flag1) {
            int choice = 0;
            int chooseInfor = 0;
            char buffer[50];

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
            while (chooseInfor < 1 || chooseInfor > 8) {
                printf("PLEASE FILL AGAIN: ");
                scanf("%d", &chooseInfor);
            }
            Reader& r = listReader[chooseReader - 1];
            switch (chooseInfor) {
            case 1:
                printf("CODE OF READER (YOUR ID STUDENT NUMBER): ");
                scanf("\n");
                fgets(buffer, 10, stdin);
                buffer[strlen(buffer) - 1] = '\0';
                while (strlen(buffer) != 8) {
                    printf("PLEASE FILL AGAIN: ");
                    scanf("\n");
                    fgets(buffer, 10, stdin);
                    buffer[strlen(buffer) - 1] = '\0';
                }
                r.setCode(buffer);
                break;
            case 2:
                printf("NAME OF READER: ");
                scanf("\n");
                fgets(buffer, 40, stdin);
                buffer[strlen(buffer) - 1] = '\0';
                while (!StringUtils::checkValidCharacter(buffer)) {
                    printf("PLEASE FILL AGAIN: ");
                    scanf("\n");
                    fgets(buffer, 40, stdin);
                    buffer[strlen(buffer) - 1] = '\0';
                }
                StringUtils::toUpper(buffer);
                r.setName(buffer);
                break;
            case 3:
                printf("ID NUMBER OF READER (YOUR CITIZEN ID NUMBER): ");
                scanf("\n");
                fgets(buffer, 14, stdin);
                buffer[strlen(buffer) - 1] = '\0';
                while (strlen(buffer) != 12) {
                    printf("PLEASE FILL AGAIN: ");
                    scanf("\n");
                    fgets(buffer, 14, stdin);
                    buffer[strlen(buffer) - 1] = '\0';
                }
                r.setIdNumber(buffer);
                break;
            case 4:
                r.setDob(inputDate());
                break;
            case 5:
                printf("PLEASE FILL 1 ( MALE) OR FILL 0( FEMALE): ");
                scanf("%d", &choice);
                while (choice != 0 && choice != 1) {
                    printf("PLEASE FILL AGAIN: ");
                    scanf("%d", &choice);
                }
                if (choice == 1) {
                    r.setGender("MALE");
                } else {
                    r.setGender("FEMALE");
                }
                break;
            case 6:
                printf("EMAIL OF READER: ");
                scanf("\n");
                fgets(buffer, 40, stdin);
                buffer[strlen(buffer) - 1] = '\0';
                while (strlen(buffer) > 50) {
                    printf("PLEASE FILL AGAIN: ");
                    scanf("\n");
                    fgets(buffer, 40, stdin);
                    buffer[strlen(buffer) - 1] = '\0';
                }
                r.setEmail(buffer);
                break;
            case 7:
                printf("ADDRESS OF READER ( ADDRESS NUMBER, WARD, DISTRICT): ");
                scanf("\n");
                fgets(buffer, 40, stdin);
                buffer[strlen(buffer) - 1] = '\0';
                while (strlen(buffer) > 50) {
                    printf("PLEASE FILL AGAIN: ");
                    scanf("\n");
                    fgets(buffer, 40, stdin);
                    buffer[strlen(buffer) - 1] = '\0';
                }
                r.setAddress(buffer);
                break;
            case 8:
            {
                Date cd = inputDate();
                r.setCreatingCardDay(cd);
                r.setExpiringCardDay(cd);
                break;
            }
            }
            exportNewFileOfReaders("listReader.txt");
            int choose = 0;
            printf("1. CONTINUE ADJUSTING INFORMATION OF THIS READER\n");
            printf("2. STOP\n");
            printf("YOUR CHOICE: ");
            scanf("%d", &choose);
            if (choose == 1) {
                flag1 = true;
            } else {
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
        } else {
            flag = false;
        }
    }
}

void Library::deleteReader() {
    printAllReaders();
    bool flag = true;
    while (flag) {
        printf("READER WHOSE INFORMATION YOU WANT TO DELETE (1 to %d): ", numberOfReaders);
        int choose = 0;
        scanf("%d", &choose);
        for (int i = choose - 1; i < numberOfReaders - 1; i++) {
            listReader[i] = listReader[i + 1];
        }
        numberOfReaders--;
        system("cls");
        printAllReaders();
        exportNewFileOfReaders("listReader.txt");
        int choice = 0;
        printf("DO YOU WANT TO CONTINUE DELETING?\n");
        printf("1. YES\n");
        printf("2. NO\n");
        scanf("%d", &choice);
        if (choice == 1) {
            flag = true;
        } else {
            flag = false;
        }
    }
}

void Library::findReaderByCitizenId() {
    printf("CITIZEN ID NUMBER OF READERS IN LIBRARY\n");
    for (int i = 0; i < numberOfReaders; i++) {
        printf("%s\n", listReader[i].getIdNumber());
    }
    char id[14]{};
    printf("ID NUMBER OF READER (YOUR CITIZEN ID NUMBER) THAT YOU NEED TO FIND: ");
    scanf("\n");
    fgets(id, 14, stdin);
    id[strlen(id) - 1] = '\0';
    while (strlen(id) != 12) {
        printf("PLEASE FILL AGAIN: ");
        scanf("\n");
        fgets(id, 14, stdin);
        id[strlen(id) - 1] = '\0';
    }
    int index = -1;
    for (int i = 0; i < numberOfReaders; i++) {
        if (strcmp(id, listReader[i].getIdNumber()) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("CAN'T FIND CITIZEN ID NUMBER!");
    } else {
        listReader[0].displayHeader();
        listReader[index].displayRow();
        system("pause");
    }
}

void Library::findBookByNameOfReader() {
    printf("LIST NAME OF READERS\n");
    for (int i = 0; i < numberOfReaders; i++) {
        printf("%s\n", listReader[i].getName());
    }
    printf("PLEASE CHOOSE 1 TO %d: ", numberOfReaders);
    int choose = 0;
    scanf("%d", &choose);
    system("cls");
    printf("----------------------------------------------------------------------------------------------------------------------------\n");
    printf("|| %-12s  || %-20s  || %-20s  || %-20s  || %-5s  || %-15s  || \n", "ISBN", "NAME", "AUTHOR", "PUBLISHER", "YEAR", "TYPE");
    printf("----------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < listReader[choose - 1].getQuantityOfBorrowing(); i++) {
        Book b = listReader[choose - 1].getBorrowBook(i);
        printf("|| %-12s  || %-20s  || %-20s  || %-20s  || %-5d  || %-15s  || \n",
            b.getISBN(), b.getNameOfBook(), b.getNameOfAuthor(), b.getPublisher(),
            b.getPublishingYear(), b.getTypeOfBook());
        printf("----------------------------------------------------------------------------------------------------------------------------\n");
    }
    system("pause");
}

void Library::bookManagement() {
    do {
        readFileOfListBook("listBook.txt");
        Menu::printBookManagementMenu();
        char choice{};
        printf("                                 \n Which function do you want to choose (a,b,c...): ");
        scanf("\n");
        scanf("%c", &choice);
        system("cls");
        while (choice < 'a' || choice > 'g') {
            printf("                                   \n ERROR. PLEASE FILL AGAIN: ");
            scanf("\n");
            scanf("%c", &choice);
        }
        if (choice == 'a') {
            printAllBooks();
            system("cls");
        } else if (choice == 'b') {
            addBook();
            system("cls");
        } else if (choice == 'c') {
            adjustBook();
            system("cls");
        } else if (choice == 'd') {
            deleteBook();
            system("cls");
        } else if (choice == 'e') {
            findBookByISBN();
            system("cls");
        } else if (choice == 'f') {
            findBookByName();
            system("cls");
        } else if (choice == 'g') {
            break;
        }
    } while (true);
}

void Library::printAllBooks() {
    printf("%110s", "LIST OF BOOKS IN LIBRARY\n");
    if (numberOfBooks > 0) {
        listBook[0].displayHeader();
        for (int i = 0; i < numberOfBooks; i++) {
            listBook[i].displayRow();
        }
    }
    system("pause");
}

void Library::addBook() {
    while (true) {
        char buffer[50];

        printf("ISBN OF BOOK (10 NUMBERS): ");
        scanf("\n");
        fgets(buffer, 15, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        while (strlen(buffer) != 10) {
            printf("PLEASE FILL AGAIN: ");
            scanf("\n");
            fgets(buffer, 15, stdin);
            buffer[strlen(buffer) - 1] = '\0';
        }
        listBook[numberOfBooks].setISBN(buffer);
        while (!listBook[numberOfBooks].checkValidISBN()) {
            printf("PLEASE FILL AGAIN: ");
            scanf("\n");
            fgets(buffer, 15, stdin);
            buffer[strlen(buffer) - 1] = '\0';
            listBook[numberOfBooks].setISBN(buffer);
        }

        printf("NAME OF BOOK: ");
        scanf("\n");
        fgets(buffer, 40, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        while (!StringUtils::checkValidCharacter(buffer)) {
            printf("PLEASE FILL AGAIN: ");
            scanf("\n");
            fgets(buffer, 40, stdin);
            buffer[strlen(buffer) - 1] = '\0';
        }
        StringUtils::toUpper(buffer);
        listBook[numberOfBooks].setNameOfBook(buffer);

        printf("NAME OF AUTHOR: ");
        scanf("\n");
        fgets(buffer, 40, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        while (!StringUtils::checkValidCharacter(buffer)) {
            printf("PLEASE FILL AGAIN: ");
            scanf("\n");
            fgets(buffer, 40, stdin);
            buffer[strlen(buffer) - 1] = '\0';
        }
        StringUtils::toUpper(buffer);
        listBook[numberOfBooks].setNameOfAuthor(buffer);

        printf("PUBLISHER: ");
        scanf("\n");
        fgets(buffer, 30, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        while (!StringUtils::checkValidCharacter(buffer)) {
            printf("PLEASE FILL AGAIN: ");
            scanf("\n");
            fgets(buffer, 30, stdin);
            buffer[strlen(buffer) - 1] = '\0';
        }
        StringUtils::toUpper(buffer);
        listBook[numberOfBooks].setPublisher(buffer);

        printf("FILL PUBLISHING YEAR: ");
        int year;
        scanf("%d", &year);
        while (year < 1900) {
            printf("FILL AGAIN: ");
            scanf("%d", &year);
        }
        listBook[numberOfBooks].setPublishingYear(year);

        printf("TYPE OF BOOK: ");
        scanf("\n");
        fgets(buffer, 20, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        while (!StringUtils::checkValidCharacter(buffer)) {
            printf("PLEASE FILL AGAIN: ");
            scanf("\n");
            fgets(buffer, 20, stdin);
            buffer[strlen(buffer) - 1] = '\0';
        }
        StringUtils::toUpper(buffer);
        listBook[numberOfBooks].setTypeOfBook(buffer);

        printf("PRICE OF BOOK: ");
        long price;
        scanf("%ld", &price);
        while (price < 0 || price > 10000000) {
            printf("FILL AGAIN: ");
            scanf("%ld", &price);
        }
        listBook[numberOfBooks].setPriceOfBook(price);

        printf("THE QUANTITY: ");
        int qty;
        scanf("%d", &qty);
        while (qty < 0 || qty > 1000000) {
            printf("FILL AGAIN: ");
            scanf("%d", &qty);
        }
        listBook[numberOfBooks].setTheNumberOfBooks(qty);

        numberOfBooks++;
        exportNewFileOfBook("listBook.txt");
        int choose = 0;
        printf("1. CONTINUE FILLING INFORMATION\n");
        printf("2. STOP\n");
        printf("YOUR CHOICE: ");
        scanf("%d", &choose);
        if (choose == 2) {
            break;
        }
    }
}

void Library::adjustBook() {
    bool flag = true;
    while (flag) {
        printAllBooks();
        printf("PLEASE CHOOSE A BOOK TO ADJUST INFORMATION (1,2,..,%d): ", numberOfBooks);
        int chooseBook = 0;
        scanf("%d", &chooseBook);
        while (chooseBook <= 0 || chooseBook > numberOfBooks) {
            printf("PLEASE FILL AGAIN: ");
            scanf("%d", &chooseBook);
        }
        bool flag1 = true;
        while (flag1) {
            int chooseInfor = 0;
            char buffer[50];

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
            while (chooseInfor < 1 || chooseInfor > 8) {
                printf("PLEASE FILL AGAIN: ");
                scanf("%d", &chooseInfor);
            }
            Book& b = listBook[chooseBook - 1];
            switch (chooseInfor) {
            case 1:
                printf("ISBN (10 NUMBERS): ");
                scanf("\n");
                fgets(buffer, 15, stdin);
                buffer[strlen(buffer) - 1] = '\0';
                b.setISBN(buffer);
                while (!b.checkValidISBN() || strlen(buffer) != 10) {
                    printf("PLEASE FILL AGAIN: ");
                    scanf("\n");
                    fgets(buffer, 15, stdin);
                    buffer[strlen(buffer) - 1] = '\0';
                    b.setISBN(buffer);
                }
                break;
            case 2:
                printf("NAME OF BOOK: ");
                scanf("\n");
                fgets(buffer, 40, stdin);
                buffer[strlen(buffer) - 1] = '\0';
                while (!StringUtils::checkValidCharacter(buffer)) {
                    printf("PLEASE FILL AGAIN: ");
                    scanf("\n");
                    fgets(buffer, 40, stdin);
                    buffer[strlen(buffer) - 1] = '\0';
                }
                StringUtils::toUpper(buffer);
                b.setNameOfBook(buffer);
                break;
            case 3:
                printf("NAME OF AUTHOR: ");
                scanf("\n");
                fgets(buffer, 40, stdin);
                buffer[strlen(buffer) - 1] = '\0';
                while (!StringUtils::checkValidCharacter(buffer)) {
                    printf("PLEASE FILL AGAIN: ");
                    scanf("\n");
                    fgets(buffer, 40, stdin);
                    buffer[strlen(buffer) - 1] = '\0';
                }
                StringUtils::toUpper(buffer);
                b.setNameOfAuthor(buffer);
                break;
            case 4:
                printf("PUBLISHER: ");
                scanf("\n");
                fgets(buffer, 30, stdin);
                buffer[strlen(buffer) - 1] = '\0';
                while (!StringUtils::checkValidCharacter(buffer)) {
                    printf("PLEASE FILL AGAIN: ");
                    scanf("\n");
                    fgets(buffer, 30, stdin);
                    buffer[strlen(buffer) - 1] = '\0';
                }
                StringUtils::toUpper(buffer);
                b.setPublisher(buffer);
                break;
            case 5:
                printf("FILL PUBLISHING YEAR: ");
                int year;
                scanf("%d", &year);
                while (year < 1900) {
                    printf("FILL AGAIN: ");
                    scanf("%d", &year);
                }
                b.setPublishingYear(year);
                break;
            case 6:
                printf("TYPE OF BOOK: ");
                scanf("\n");
                fgets(buffer, 20, stdin);
                buffer[strlen(buffer) - 1] = '\0';
                while (!StringUtils::checkValidCharacter(buffer)) {
                    printf("PLEASE FILL AGAIN: ");
                    scanf("\n");
                    fgets(buffer, 20, stdin);
                    buffer[strlen(buffer) - 1] = '\0';
                }
                StringUtils::toUpper(buffer);
                b.setTypeOfBook(buffer);
                break;
            case 7:
                printf("PRICE OF BOOK: ");
                long price;
                scanf("%ld", &price);
                while (price < 0 || price > 1000000) {
                    printf("FILL AGAIN: ");
                    scanf("%ld", &price);
                }
                b.setPriceOfBook(price);
                break;
            case 8:
                printf("THE QUANTITY: ");
                int qty;
                scanf("%d", &qty);
                while (qty < 0 || qty > 1000000) {
                    printf("FILL AGAIN: ");
                    scanf("%d", &qty);
                }
                b.setTheNumberOfBooks(qty);
                break;
            }
            exportNewFileOfBook("listBook.txt");
            int choose = 0;
            printf("1. CONTINUE ADJUSTING INFORMATION OF THIS BOOK\n");
            printf("2. STOP\n");
            printf("YOUR CHOICE: ");
            scanf("%d", &choose);
            if (choose == 1) {
                flag1 = true;
            } else {
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
        } else {
            flag = false;
        }
    }
}

void Library::deleteBook() {
    printAllBooks();
    bool flag = true;
    while (flag) {
        printf("BOOK THAT YOU WANT TO DELETE (1 to %d): ", numberOfBooks);
        int choose = 0;
        scanf("%d", &choose);
        for (int i = choose - 1; i < numberOfBooks - 1; i++) {
            listBook[i] = listBook[i + 1];
        }
        numberOfBooks--;
        system("cls");
        printAllBooks();
        exportNewFileOfBook("listBook.txt");
        int choice = 0;
        printf("DO YOU WANT TO CONTINUE DELETING?\n");
        printf("1. YES\n");
        printf("2. NO\n");
        scanf("%d", &choice);
        if (choice == 1) {
            flag = true;
        } else {
            flag = false;
        }
    }
}

void Library::findBookByISBN() {
    printf("LIST NAME OF BOOKS IN LIBRARY\n");
    for (int i = 0; i < numberOfBooks; i++) {
        printf("%s\n", listBook[i].getISBN());
    }
    char isbn[15]{};
    printf("ISBN THAT YOU NEED TO FIND: ");
    scanf("\n");
    fgets(isbn, 15, stdin);
    isbn[strlen(isbn) - 1] = '\0';
    while (strlen(isbn) != 10) {
        printf("PLEASE FILL AGAIN: ");
        scanf("\n");
        fgets(isbn, 15, stdin);
        isbn[strlen(isbn) - 1] = '\0';
    }
    int index = -1;
    for (int i = 0; i < numberOfBooks; i++) {
        if (strcmp(isbn, listBook[i].getISBN()) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("CAN'T FIND ISBN!");
    } else {
        listBook[0].displayHeader();
        listBook[index].displayRow();
        system("pause");
    }
}

void Library::findBookByName() {
    printf("LIST ISBN OF BOOKS IN LIBRARY\n");
    for (int i = 0; i < numberOfBooks; i++) {
        printf("%s\n", listBook[i].getNameOfBook());
    }
    char name[40]{};
    printf("NAME OF BOOK THAT YOU NEED TO FIND: ");
    scanf("\n");
    fgets(name, 40, stdin);
    name[strlen(name) - 1] = '\0';
    while (!StringUtils::checkValidCharacter(name)) {
        printf("PLEASE FILL AGAIN: ");
        scanf("\n");
        fgets(name, 40, stdin);
        name[strlen(name) - 1] = '\0';
    }
    StringUtils::toUpper(name);
    int index = -1;
    for (int i = 0; i < numberOfBooks; i++) {
        if (strcmp(name, listBook[i].getNameOfBook()) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("CAN'T FIND THE BOOK!");
    } else {
        listBook[0].displayHeader();
        listBook[index].displayRow();
        system("pause");
    }
}

void Library::calculateReturnDay(int day1, int month1, int year1, int& day2, int& month2, int& year2) {
    day2 = day1 + 7;
    int top;
    switch (month1) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        top = 31;
        break;
    case 2:
        if ((year1 % 4 == 0 && year1 % 100 != 0) || year1 % 400 == 0) {
            top = 29;
        } else {
            top = 28;
        }
        break;
    case 4: case 6: case 9: case 11:
        top = 30;
        break;
    }
    if (day2 > top) {
        month2 = month1 + 1;
        day2 = day2 - top;
    } else {
        month2 = month1;
    }
    if (month2 > 12) {
        month2 = month2 - 12;
        year2 = year1 + 1;
    } else {
        year2 = year1;
    }
}

void Library::borrowBookForReader(Date today, int readerIndex) {
    listReader[readerIndex].setQuantityOfBorrowing(0);
    int qtyIdx = 0;
    printAllBooks();
    while (true) {
        printf("WHICH BOOK DO YOU WANT TO BORROW? (1...%d): ", numberOfBooks);
        int choice = 0;
        scanf("%d", &choice);
        while (choice < 1 || choice > numberOfBooks) {
            printf("PLEASE FILL AGAIN: ");
            scanf("%d", &choice);
        }
        Book bk;
        bk.setISBN(listBook[choice - 1].getISBN());
        bk.setNameOfBook(listBook[choice - 1].getNameOfBook());
        bk.setNameOfAuthor(listBook[choice - 1].getNameOfAuthor());
        bk.setPublisher(listBook[choice - 1].getPublisher());
        bk.setPublishingYear(listBook[choice - 1].getPublishingYear());
        bk.setTypeOfBook(listBook[choice - 1].getTypeOfBook());
        bk.setPriceOfBook(listBook[choice - 1].getPriceOfBook());
        listReader[readerIndex].setBorrowBook(qtyIdx, bk);
        listReader[readerIndex].setBorrowDay(qtyIdx, today);
        Date retDay;
        calculateReturnDay(today.day, today.month, today.year, retDay.day, retDay.month, retDay.year);
        listReader[readerIndex].setReturnDay(qtyIdx, retDay);
        listBook[choice - 1].decreaseQuantity();
        exportNewFileOfBook("listBook.txt");
        qtyIdx++;
        listReader[readerIndex].setQuantityOfBorrowing(qtyIdx);
        if (qtyIdx > 5) {
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
    }
    system("cls");
    if (numberOfReaders > 0) {
        listReader[readerIndex].printForm();
    }
}

int Library::calculateSpace(int day1, int month1, int year1, int day2, int month2, int year2) {
    int space1 = 0;
    int space2 = 0;
    for (int i = 1; i < month1; i++) {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
            space1 += 31;
        } else if (i == 2) {
            if ((year1 % 4 == 0 && year1 % 100 != 0) || year1 % 400 == 0) {
                space1 += 29;
            } else {
                space1 += 28;
            }
        } else {
            space1 += 30;
        }
    }
    space1 += day1;
    for (int j = year1; j < year2; j++) {
        if ((j % 4 == 0 && j % 100 != 0) || j % 400 == 0) {
            space2 += 366;
        } else {
            space2 += 365;
        }
    }
    for (int j1 = 1; j1 < month2; j1++) {
        if (j1 == 1 || j1 == 3 || j1 == 5 || j1 == 7 || j1 == 8 || j1 == 10 || j1 == 12) {
            space2 += 31;
        } else if (j1 == 2) {
            if ((year2 % 4 == 0 && year2 % 100 != 0) || year2 % 400 == 0) {
                space2 += 29;
            } else {
                space2 += 28;
            }
        } else {
            space2 += 30;
        }
    }
    space2 += day2;
    return space2 - space1;
}

void Library::returnBook(Date today) {
    for (int i = 0; i < numberOfReaders; i++) {
        printf("%s\n", listReader[i].getName());
    }
    printf("PLEASE CHOOSE YOUR NAME (1 TO %d): ", numberOfReaders);
    int choice = 0;
    scanf("%d", &choice);
    while (true) {
        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("|| %-12s  || %-20s  || %-20s  || %-20s  || %-15s  || %-15s ||  %-7s ||   %-7s  ||\n", "ISBN", "NAME", "AUTHOR", "PUBLISHER", "PUBLISHINGYEAR", "TYPE", "BORROW", "RETURN");
        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        int qty = listReader[choice - 1].getQuantityOfBorrowing();
        for (int i = 0; i < qty; i++) {
            Book b = listReader[choice - 1].getBorrowBook(i);
            Date bd = listReader[choice - 1].getBorrowDay(i);
            Date rd = listReader[choice - 1].getReturnDay(i);
            printf("|| %-12s  || %-20s  || %-20s  || %-20s  || %-15d  || %-15s || %d/%d/%d ||  %d/%d/%d  ||\n",
                b.getISBN(), b.getNameOfBook(), b.getNameOfAuthor(), b.getPublisher(),
                b.getPublishingYear(), b.getTypeOfBook(),
                bd.day, bd.month, bd.year, rd.day, rd.month, rd.year);
            printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        }
        printf("PLEASE CHOOSE THE BOOK YOU RETURN (1 TO %d): ", qty);
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
            Date returnDay = today;
            for (int i = 0; i < numberOfBooks; i++) {
                Book b = listReader[choice - 1].getBorrowBook(choose - 1);
                if (strcmp(listBook[i].getISBN(), b.getISBN()) == 0) {
                    listBook[i].increaseQuantity();
                    exportNewFileOfBook("listBook.txt");
                    break;
                }
            }
            Date rd = listReader[choice - 1].getReturnDay(choose - 1);
            int space = calculateSpace(rd.day, rd.month, rd.year, returnDay.day, returnDay.month, returnDay.year);
            listReader[choice - 1].removeBorrowedBook(choose - 1);
            if (space <= 0) {
                printf("YOU DON'T HAVE TO PAY FEE!\n");
            } else {
                printf("YOU HAVE BEEN LATE %d. YOU HAVE TO PAY %d VND", space, space * 5000);
            }
        } else if (select == 1) {
            Book b = listReader[choice - 1].getBorrowBook(choose - 1);
            int fee = b.getPriceOfBook() * 2;
            listReader[choice - 1].removeBorrowedBook(choose - 1);
            printf("THE PRICE OF THIS BOOK IS %ld SO YOU HAVE TO PAY %d VND", b.getPriceOfBook(), fee);
        }
        printf("\nPRESS 1 TO CONTINUE OR 2 TO EXIT: ");
        int execute = 0;
        scanf("%d", &execute);
        if (execute == 2) {
            break;
        }
    }
}

void Library::statistics() {
    do {
        char choice{};
        Menu::printStatisticsMenu();
        printf("                                 \n Which function do you want to choose (a,b,c...): ");
        scanf("\n");
        scanf("%c", &choice);
        system("cls");
        while (choice < 'a' || choice > 'g') {
            printf("                                   \n ERROR. PLEASE FILL AGAIN: ");
            scanf("\n");
            scanf("%c", &choice);
        }
        if (choice == 'a') {
            statNumberOfBooks();
            system("pause");
            system("cls");
        } else if (choice == 'b') {
            statNumberOfBooksByType();
            system("cls");
        } else if (choice == 'c') {
            statNumberOfReaders();
            system("cls");
        } else if (choice == 'd') {
            statGender();
            system("cls");
        } else if (choice == 'e') {
            statBooksBorrowed();
            system("cls");
        } else if (choice == 'f') {
            statReaderMissDl(/*need today*/{0,0,0});
            system("cls");
        } else if (choice == 'g') {
            break;
        }
    } while (true);
}

void Library::statNumberOfBooks() {
    int totalBook = 0;
    for (int i = 0; i < numberOfBooks; i++) {
        totalBook += listBook[i].getTheNumberOfBooks();
    }
    printf("STATISTICS OF NUMBER OF BOOKS IN LIBRARY\n");
    printf("NUMBER OF BOOKS IN LIBRARY NOW: %d \n", totalBook);
}

void Library::statNumberOfBooksByType() {
    int count[100];
    for (int i = 0; i < numberOfBooks; i++) {
        count[i] = 0;
        for (int j = 0; j < numberOfBooks; j++) {
            if (strcmp(listBook[i].getTypeOfBook(), listBook[j].getTypeOfBook()) == 0) {
                if (j < i) {
                    break;
                } else {
                    count[i] += listBook[j].getTheNumberOfBooks();
                }
            }
        }
    }
    printf(" STATISTICS FOR NUMBER OF BOOKS (CATEGORIES)\n");
    for (int i = 0; i < numberOfBooks; i++) {
        if (count[i] != 0) {
            printf("%s: %d\n", listBook[i].getTypeOfBook(), count[i]);
        }
    }
    system("pause");
}

void Library::statNumberOfReaders() {
    printf("STATISTICS OF NUMBER OF READERS IN LIBRARY\n");
    printf("NUMBER OF READERS IN LIBRARY NOW: %d\n ", numberOfReaders);
    system("pause");
}

void Library::statGender() {
    int countMale = 0;
    int countFemale = 0;
    for (int i = 0; i < numberOfReaders; i++) {
        if (strcmp(listReader[i].getGender(), "MALE") == 0) {
            countMale++;
        } else {
            countFemale++;
        }
    }
    printf("NUMBERS OF MALES IN LIBRARY: %d\n", countMale);
    printf("NUMBERS OF FEMALES IN LIBRARY: %d\n", countFemale);
    system("pause");
}

void Library::statBooksBorrowed() {
    int count = 0;
    for (int i = 0; i < numberOfReaders; i++) {
        count += listReader[i].getQuantityOfBorrowing();
    }
    printf("The NUMBER OF BOOKS WHICH ARE BEING BORROWED: %d\n", count);
    system("pause");
}

void Library::statReaderMissDl(Date today) {
    int count = 0;
    for (int i = 0; i < numberOfReaders; i++) {
        for (int j = 0; j < listReader[i].getQuantityOfBorrowing(); j++) {
            Date rd = listReader[i].getReturnDay(j);
            if (today.year < rd.year) continue;
            if (today.year == rd.year && today.month < rd.month) continue;
            if (today.year == rd.year && today.month == rd.month && today.day < rd.day) continue;
            count++;
        }
    }
    printf("THE NUMBER OF READERS WHO ARE MISSING DEADLINE: %d\n", count);
    system("pause");
}

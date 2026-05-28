#include <stdio.h>
#include "Menu.h"

void Menu::printMainMenu() {
    printf  ("                                ===============================================\n");
    printf  ("                                ||              LIBRARY MANAGEMENT           ||\n");
    printf  ("                                ===============================================\n");
    printf  ("                                ||             1. Readers management         ||\n");
    printf  ("                                ===============================================\n");
    printf  ("                                ||             2. Books management           ||\n");
    printf  ("                                ===============================================\n");
    printf  ("                                ||             3. Borrow book                ||\n");
    printf  ("                                ===============================================\n");
    printf  ("                                ||             4. Return book                ||\n");
    printf  ("                                ===============================================\n");
    printf  ("                                ||             5. Statistics                 ||\n");
    printf  ("                                ===============================================\n");
    printf  ("                                ||             6. Exit                       ||\n");
    printf  ("                                ===============================================\n");
    printf  ("                                   \n Which function do you want to choose (1,2,3...): ");
}

void Menu::printReaderManagementMenu() {
    printf  ("                                ===============================================\n");
    printf  ("                                ||              READERS MANAGEMENT           ||\n");
    printf  ("                                ===============================================\n");
    printf  ("                                ||        a. List of readers in library      ||\n");
    printf  ("                                ===============================================\n");
    printf  ("                                ||        b. Add reader                      ||\n");
    printf  ("                                ===============================================\n");
    printf  ("                                ||        c. Adjust information              ||\n");
    printf  ("                                ===============================================\n");
    printf  ("                                ||        d. Delete reader                   ||\n");
    printf  ("                                ===============================================\n");
    printf  ("                                ||        e. Find reader by ID number        ||\n");
    printf  ("                                ===============================================\n");
    printf  ("                                ||        f. Find book by name of reader     ||\n");
    printf  ("                                ===============================================\n");
    printf  ("                                ||        g. Exit                            ||\n");
    printf  ("                                ===============================================\n");
}

void Menu::printBookManagementMenu() {
    printf  ("                                ===============================================\n");
    printf  ("                                ||              BOOKS MANAGEMENT             ||\n");
    printf  ("                                ===============================================\n");
    printf  ("                                ||        a. List of books in library        ||\n");
    printf  ("                                ===============================================\n");
    printf  ("                                ||        b. Add book                        ||\n");
    printf  ("                                ===============================================\n");
    printf  ("                                ||        c. Adjust information              ||\n");
    printf  ("                                ===============================================\n");
    printf  ("                                ||        d. Delete book                     ||\n");
    printf  ("                                ===============================================\n");
    printf  ("                                ||        e. Find book by ISBN               ||\n");
    printf  ("                                ===============================================\n");
    printf  ("                                ||        f. Find book by name of book       ||\n");
    printf  ("                                ===============================================\n");
    printf  ("                                ||        g. Exit                            ||\n");
    printf  ("                                ===============================================\n");
}

void Menu::printStatisticsMenu() {
    printf("                                ===============================================\n");
    printf("                                ||                 STATISTICS                ||\n");
    printf("                                ===============================================\n");
    printf("                                ||     a. NUMBER OF BOOKS IN LIBRARY         ||\n");
    printf("                                ===============================================\n");
    printf("                                ||     b. NUMBER OF BOOKS (CATEGORIES)       ||\n");
    printf("                                ===============================================\n");
    printf("                                ||     c. NUMBER OF READERS                  ||\n");
    printf("                                ===============================================\n");
    printf("                                ||     d. NUMBER OF READERS (GENDER)         ||\n");
    printf("                                ===============================================\n");
    printf("                                ||     e. NUMBER OF BOOKS BORROWED           ||\n");
    printf("                                ===============================================\n");
    printf("                                ||     f. NUMBER OF READERS WHO ARE MISS DL  ||\n");
    printf("                                ===============================================\n");
    printf("                                ||     g. Exit                               ||\n");
    printf("                                ===============================================\n");
}

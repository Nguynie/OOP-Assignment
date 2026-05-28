# OOP Conversion Report — Library Management System

## Overview

This report documents the step-by-step process of converting a procedural C/C++ Library Management System into an Object-Oriented Programming (OOP) paradigm. The original code consisted of flat structs (`book`, `reader`, `Date`) and free functions spread across multiple `.cpp` files that operated on those structs by passing them as parameters. The converted code encapsulates data and behavior into classes, improves modularity, and compiles and runs identically to the original.

The AI assistant used throughout this process was **Google Gemini**.

---

## Step-by-Step Process

### Step 1: Analyze the Procedural Source Code

**Prompt used:**

> I have a C++ library management system written in procedural style. It uses structs like `book` and `reader` with many free functions that take these structs as parameters. The code is spread across multiple files: `book.cpp`, `reader.cpp`, `menu.cpp`, `borrow.cpp`, `return.cpp`, `statistics.cpp`, and `main.cpp`. Can you help me analyze the structure and identify how to convert this to OOP?

**Action taken:**

I read and understood the original code's architecture:

- **Data structures** (`book.h`, `reader.h`): Plain structs with public fields — `book` (ISBN, name, author, publisher, year, type, price, quantity), `reader` (code, name, ID, DOB, email, address, gender, card dates, borrowed books array), `Date` (day, month, year).
- **Free functions**: Each `.cpp` file contained functions operating on these structs — e.g., `readFileOfListReaders(reader[], int&)`, `addBook(book[], int&)`, `borrowingBook(book[], int, reader[], int, Date, int, int&)`.
- **Main flow**: `main.cpp` declared arrays of readers and books, then used a menu-driven loop calling these free functions.

**Key observation:** Data and behavior were completely separated. Functions needed explicit array references and size parameters passed every time.

---

### Step 2: Design the Class Hierarchy

**Prompt used:**

> Based on this procedural code, what would be the ideal OOP class design? I want to create classes that encapsulate the data with their relevant operations. Consider making `Book`, `Reader`, a main `Library` orchestrator class, and a utility `Menu` class. The Library class should hold the arrays of books and readers instead of main.cpp managing them.

**Action taken:**

I designed six types:

| Class / Struct | Purpose |
|---|---|
| `Book` | Encapsulates a single book's data and its operations (validation, display, quantity management). |
| `Reader` | Encapsulates a single reader, their borrowed books, and operations (validation, display, borrowing form, removal). |
| `Library` | Orchestrates everything — holds arrays of `Book[100]` and `Reader[100]`, manages file I/O, CRUD operations, borrowing/returning, and statistics. |
| `Menu` | Static utility class for printing menu screens. |
| `StringUtils` | Static utility class for string validation and case conversion. |
| `Date` | Kept as a simple struct (no behavior needed). |

---

### Step 3: Convert the `book` Struct to a `Book` Class

**Prompt used:**

> Convert the `book` struct into a `Book` class with private attributes and public getter/setter methods. Move the book-specific free functions (`checkValidISBN`, the display functions) into the class as methods. Keep `readFileOfListBook` and `addBook` in the Library class since they manage the collection.

**Action taken:**

**File created:** `Book.h`, `Book.cpp`

**Changes made:**
- Struct `book` → `class Book` with all fields private.
- Added getters/setters for all 8 attributes.
- Moved `checkValidISBN()` into `Book::checkValidISBN()`.
- Moved display logic into `Book::displayHeader()` and `Book::displayRow()`.
- Added `decreaseQuantity()` / `increaseQuantity()` helper methods.
- File I/O and collection-level operations (readFileOfListBook, addBook) were left for the Library class.

---

### Step 4: Convert the `reader` Struct to a `Reader` Class

**Prompt used:**

> Now do the same for the `reader` struct. Create a `Reader` class with private fields, getters/setters, and move reader-specific operations like `checkValidCode`, `checkValidID`, `printForm`, and `removeBorrowedBook` into the class as methods.

**Action taken:**

**File created:** `Reader.h`, `Reader.cpp`

**Changes made:**
- Struct `reader` → `class Reader` with all fields private.
- Added getters/setters for all fields including borrowed book arrays.
- Moved `checkValidCode()` → `Reader::checkValidCode()`.
- Moved `checkValidID()` → `Reader::checkValidID()`.
- Moved `printForm()` → `Reader::printForm()`.
- Added `removeBorrowedBook(int index)` method to encapsulate the shift-left logic.
- The `borrowBook[6]`, `borrowDay[6]`, `returnDay[6]` arrays remain inside Reader.

---

### Step 5: Create the `Library` Orchestrator Class

**Prompt used:**

> Create a `Library` class that holds arrays of Book[100] and Reader[100], plus count variables. Move all the remaining free functions from the original files into this class as methods: file reading/writing, reader management, book management, borrowing, returning, and statistics. The main function should just create a Library object and call `run()`.

**Action taken:**

**File created:** `Library.h`, `Library.cpp`

**Changes from original free functions to methods:**
- `readFileOfListReaders(reader[], int&)` → `Library::readFileOfListReaders(const char*)`
- `exportNewFile(reader[], int)` → `Library::exportNewFileOfReaders(const char*)`
- `readFileOfListBook(book[], int&)` → `Library::readFileOfListBook(const char*)`
- `exportNewFileOfBook(book[], int)` → `Library::exportNewFileOfBook(const char*)`
- `fillDate(int&, int&, int&)` → `Library::inputDate()`
- `addReader(reader[], int&)` → `Library::addReader()`
- `adjustInformation(reader[], int)` → `Library::adjustReader()`
- `deleteInformation(reader[], int&)` → `Library::deleteReader()`
- `findReaderByCitizenIdNumber(reader[], int)` → `Library::findReaderByCitizenId()`
- `findBookByNameOfReader(reader[], int)` → `Library::findBookByNameOfReader()`
- `addBook(book[], int&)` → `Library::addBook()`
- `adjustInformationOfBook(book[], int)` → `Library::adjustBook()`
- `deleteInformationOfBook(book[], int&)` → `Library::deleteBook()`
- `findBookByISBN(book[], int)` → `Library::findBookByISBN()`
- `findBookByName(book[], int)` → `Library::findBookByName()`
- `borrowingBook(...)` → `Library::borrowBookForReader(Date, int)`
- `returnBook(...)` → `Library::returnBook(Date)`
- `calculateReturnDay(...)` → `Library::calculateReturnDay(...)`
- `calculateSpace(...)` → `Library::calculateSpace(...)`
- `statisticsNumberOfBooks(...)` → `Library::statNumberOfBooks()`
- `statisticsNumberOfBooksByType(...)` → `Library::statNumberOfBooksByType()`
- `statisticsNumberOfReaders(...)` → `Library::statNumberOfReaders()`
- `statisticsGender(...)` → `Library::statGender()`
- `statisticsBooksBorrowed(...)` → `Library::statBooksBorrowed()`
- `statisticsReaderMissDl(...)` → `Library::statReaderMissDl(Date)`
- `printListOfReaders(...)` → `Library::printAllReaders()`
- `printListOfBooks(...)` → `Library::printAllBooks()`

**Key improvements:**
- No more passing arrays and counts as parameters — Library accesses `listReader`, `listBook`, `numberOfReaders`, `numberOfBooks` as member variables directly.
- Methods are organized logically: readerManagement, bookManagement, statistics sections.
- Private helper methods (file I/O, date calculations) are hidden from external callers.

---

### Step 6: Create Utility Classes (`Menu` and `StringUtils`)

**Prompt used:**

> Move the menu-printing functions into a `Menu` class with static methods. Also create a `StringUtils` class with static methods for `checkValidCharacter` and `toUpper` since they are used across the application.

**Action taken:**

**File created:** `Menu.h`, `Menu.cpp`, `StringUtils.h`, `StringUtils.cpp`

- `printMenu()` → `Menu::printMainMenu()`
- `printMenuOfFunction1()` → `Menu::printReaderManagementMenu()`
- `printMenuOfFunction2()` → `Menu::printBookManagementMenu()`
- `printMenuOfFunction5()` → `Menu::printStatisticsMenu()`
- `checkValidCharacter(char[])` → `StringUtils::checkValidCharacter(const char[])`
- `toUpper(char[])` → `StringUtils::toUpper(char[])`

The `fillDate` function from the original `menu.cpp` was converted to `Library::inputDate()` since it is only used within Library operations.

---

### Step 7: Simplify `main.cpp`

**Prompt used:**

> Now rewrite main.cpp to simply create a Library object and call its run() method, removing all the procedural code that was previously in main.

**Action taken:**

Original `main.cpp` had 234 lines of menu loop logic. New `main.cpp` is 7 lines:

```cpp
#include "Library.h"

int main() {
    Library lib;
    lib.run();
    return 0;
}
```

All orchestration logic moved into `Library::run()`.

---

### Step 8: Verify Compilation

**Prompt used:**

> Do I need a Makefile to compile the OOP version? List the compilation command for all the .cpp files.

**Action taken:**

Created a build command that compiles all implementation files together:

```bash
g++ -std=c++11 main.cpp Library.cpp Book.cpp Reader.cpp Menu.cpp StringUtils.cpp -o oop_version
```

Verifed that the program compiles and runs without errors.

---

## Classes, Attributes, and Methods

For a complete listing of all classes, attributes, and methods, see the [`CLASSES.md`](./CLASSES.md) file in the same directory. A summary is provided below:

| Class | Attributes | Methods |
|---|---|---|
| `Book` | ISBN, nameOfBook, nameOfAuthor, publisher, publishingYear, typeOfBook, priceOfBook, theNumberOfBooks | Constructor, 8 getters, 8 setters, checkValidISBN, displayHeader, displayRow, decreaseQuantity, increaseQuantity |
| `Reader` | code, name, idNumber, dob, email, address, gender, creatingCardDay, expiringCardDay, borrowBook[6], quantityOfBorrowing, borrowDay[6], returnDay[6] | Constructor, 11 getters, 11 setters, checkValidCode, checkValidID, displayHeader, displayRow, printForm, removeBorrowedBook |
| `Library` | listReader[100], listBook[100], numberOfReaders, numberOfBooks | Constructor, run, file I/O, 4 reader management, 4 book management, borrow/return, 6 statistics, inputDate, calculateReturnDay, calculateSpace |
| `Menu` | *(none — static)* | printMainMenu, printReaderManagementMenu, printBookManagementMenu, printStatisticsMenu |
| `StringUtils` | *(none — static)* | checkValidCharacter, toUpper |
| `Date` (struct) | day, month, year | *(none — plain data)* |

---

## Summary of OOP Benefits Achieved

1. **Encapsulation** — Book and Reader data is private, accessed only through controlled getter/setter interfaces.
2. **Cohesion** — Related data and behavior are now in the same class (e.g., `Book::checkValidISBN()` lives with the ISBN data it validates).
3. **Reduced parameter passing** — Library methods no longer need explicit array and count parameters; they access member data directly.
4. **Single Responsibility** — Each class has a clear purpose: Book represents a book, Reader represents a reader, Library orchestrates operations, Menu handles display, StringUtils handles string utilities.
5. **Simplified main()** — Entry point is reduced from 234 lines of procedural menu logic to 7 lines that instantiate and run a Library object.

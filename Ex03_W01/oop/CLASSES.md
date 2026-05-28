# OOP Class Design - Library Management System

## 1. Class `Book` (Book.h / Book.cpp)
Represents a single book entity.

### Attributes
| Attribute | Type | Description |
|-----------|------|-------------|
| ISBN | char[15] | Book ISBN (10 digits) |
| nameOfBook | char[40] | Book title |
| nameOfAuthor | char[40] | Author name |
| publisher | char[30] | Publisher name |
| publishingYear | int | Year of publication |
| typeOfBook | char[20] | Book category/genre |
| priceOfBook | long | Book price |
| theNumberOfBooks | int | Quantity available |

### Methods
| Method | Return | Description |
|--------|--------|-------------|
| `Book()` | - | Default constructor (initializes all fields to empty/zero) |
| `getISBN()` | const char* | Getter for ISBN |
| `getNameOfBook()` | const char* | Getter for book name |
| `getNameOfAuthor()` | const char* | Getter for author |
| `getPublisher()` | const char* | Getter for publisher |
| `getPublishingYear()` | int | Getter for publishing year |
| `getTypeOfBook()` | const char* | Getter for book type |
| `getPriceOfBook()` | long | Getter for price |
| `getTheNumberOfBooks()` | int | Getter for quantity |
| `setISBN(const char*)` | void | Setter for ISBN |
| `setNameOfBook(const char*)` | void | Setter for book name |
| `setNameOfAuthor(const char*)` | void | Setter for author |
| `setPublisher(const char*)` | void | Setter for publisher |
| `setPublishingYear(int)` | void | Setter for publishing year |
| `setTypeOfBook(const char*)` | void | Setter for book type |
| `setPriceOfBook(long)` | void | Setter for price |
| `setTheNumberOfBooks(int)` | void | Setter for quantity |
| `checkValidISBN()` | bool | Validates ISBN format (all digits, 10 chars) |
| `displayHeader()` | void | Prints table header for book listing |
| `displayRow()` | void | Prints single book row in table format |
| `decreaseQuantity()` | void | Decrements available quantity by 1 |
| `increaseQuantity()` | void | Increments available quantity by 1 |

---

## 2. Class `Reader` (Reader.h / Reader.cpp)
Represents a single reader (library member) entity.

### Attributes
| Attribute | Type | Description |
|-----------|------|-------------|
| code | char[10] | Student/reader code (8 digits) |
| name | char[40] | Full name |
| idNumber | char[13] | Citizen ID number (12 digits) |
| dob | Date | Date of birth |
| email | char[40] | Email address |
| address | char[40] | Home address |
| gender | char[10] | Gender (MALE/FEMALE) |
| creatingCardDay | Date | Library card creation date |
| expiringCardDay | Date | Library card expiry date (creation + 4 years) |
| borrowBook | Book[6] | Array of currently borrowed books (max 6) |
| quantityOfBorrowing | int | Number of books currently borrowed |
| borrowDay | Date[6] | Array of borrow dates for each book |
| returnDay | Date[6] | Array of expected return dates for each book |

### Methods
| Method | Return | Description |
|--------|--------|-------------|
| `Reader()` | - | Default constructor |
| `getCode()` | const char* | Getter for reader code |
| `getName()` | const char* | Getter for name |
| `getIdNumber()` | const char* | Getter for citizen ID |
| `getDob()` | Date | Getter for date of birth |
| `getEmail()` | const char* | Getter for email |
| `getAddress()` | const char* | Getter for address |
| `getGender()` | const char* | Getter for gender |
| `getCreatingCardDay()` | Date | Getter for card creation date |
| `getExpiringCardDay()` | Date | Getter for card expiry date |
| `getQuantityOfBorrowing()` | int | Getter for number of borrowed books |
| `getBorrowBook(int)` | Book | Getter for borrowed book at index |
| `getBorrowDay(int)` | Date | Getter for borrow date at index |
| `getReturnDay(int)` | Date | Getter for return date at index |
| `setCode(const char*)` | void | Setter for code |
| `setName(const char*)` | void | Setter for name |
| `setIdNumber(const char*)` | void | Setter for citizen ID |
| `setDob(Date)` | void | Setter for date of birth |
| `setEmail(const char*)` | void | Setter for email |
| `setAddress(const char*)` | void | Setter for address |
| `setGender(const char*)` | void | Setter for gender |
| `setCreatingCardDay(Date)` | void | Setter for card creation date |
| `setExpiringCardDay(Date)` | void | Setter for card expiry date |
| `setQuantityOfBorrowing(int)` | void | Setter for number of borrowed books |
| `setBorrowBook(int, const Book&)` | void | Setter for borrowed book at index |
| `setBorrowDay(int, Date)` | void | Setter for borrow date at index |
| `setReturnDay(int, Date)` | void | Setter for return date at index |
| `checkValidCode()` | bool | Validates reader code format |
| `checkValidID()` | bool | Validates citizen ID format (all digits) |
| `displayHeader()` | void | Prints table header for reader listing |
| `displayRow()` | void | Prints single reader row in table format |
| `printForm()` | void | Prints borrowing receipt/form for the reader |
| `removeBorrowedBook(int)` | void | Removes a borrowed book entry by shifting array left |

---

## 3. Class `Library` (Library.h / Library.cpp)
Main orchestrator that manages collections of books and readers, handles all library operations.

### Attributes
| Attribute | Type | Description |
|-----------|------|-------------|
| listReader | Reader[100] | Array of all readers (max 100) |
| listBook | Book[100] | Array of all books (max 100) |
| numberOfReaders | int | Current count of readers |
| numberOfBooks | int | Current count of books |

### Methods
| Method | Return | Description |
|--------|--------|-------------|
| `Library()` | - | Constructor (initializes counts to 0) |
| `run()` | void | Main application loop with menus |
| `readFileOfListReaders(const char*)` | void | Reads reader data from file into array |
| `readFileOfListBook(const char*)` | void | Reads book data from file into array |
| `exportNewFileOfReaders(const char*)` | void | Writes reader data from array to file |
| `exportNewFileOfBook(const char*)` | void | Writes book data from array to file |
| `inputDate()` | Date | Reads and validates a date from user input |
| `calculateReturnDay(int, int, int, int&, int&, int&)` | void | Calculates expected return date (borrow + 7 days) |
| `calculateSpace(int, int, int, int, int, int)` | int | Computes days between two dates |
| `printAllReaders()` | void | Displays all readers in table format |
| `addReader()` | void | Adds a new reader with user input |
| `adjustReader()` | void | Modifies an existing reader's information |
| `deleteReader()` | void | Removes a reader from the list |
| `findReaderByCitizenId()` | void | Searches for a reader by citizen ID number |
| `findBookByNameOfReader()` | void | Shows books borrowed by a selected reader |
| `readerManagement()` | void | Reader management submenu loop |
| `printAllBooks()` | void | Displays all books in table format |
| `addBook()` | void | Adds a new book with user input |
| `adjustBook()` | void | Modifies an existing book's information |
| `deleteBook()` | void | Removes a book from the list |
| `findBookByISBN()` | void | Searches for a book by ISBN |
| `findBookByName()` | void | Searches for a book by name |
| `bookManagement()` | void | Book management submenu loop |
| `borrowBookForReader(Date, int)` | void | Handles book borrowing for a specific reader |
| `returnBook(Date)` | void | Handles book returning with late fee calculation |
| `statistics()` | void | Statistics submenu loop |
| `statNumberOfBooks()` | void | Statistics: total number of books |
| `statNumberOfBooksByType()` | void | Statistics: books grouped by category |
| `statNumberOfReaders()` | void | Statistics: total number of readers |
| `statGender()` | void | Statistics: readers by gender |
| `statBooksBorrowed()` | void | Statistics: total books currently borrowed |
| `statReaderMissDl(Date)` | void | Statistics: readers past their return deadline |

---

## 4. Class `Menu` (Menu.h / Menu.cpp)
Static utility class for printing menu screens.

### Methods
| Method | Return | Description |
|--------|--------|-------------|
| `printMainMenu()` | void | Prints the main library management menu |
| `printReaderManagementMenu()` | void | Prints the reader management submenu |
| `printBookManagementMenu()` | void | Prints the book management submenu |
| `printStatisticsMenu()` | void | Prints the statistics submenu |

---

## 5. Class `StringUtils` (StringUtils.h / StringUtils.cpp)
Static utility class for string validation and manipulation.

### Methods
| Method | Return | Description |
|--------|--------|-------------|
| `checkValidCharacter(const char[])` | bool | Checks if string contains only letters and spaces |
| `toUpper(char[])` | void | Converts string to uppercase in-place |

---

## 6. Struct `Date` (Date.h)
Simple data structure for date representation.

### Attributes
| Attribute | Type | Description |
|-----------|------|-------------|
| day | int | Day of month |
| month | int | Month of year |
| year | int | Year |

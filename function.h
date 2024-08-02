#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <iomanip>

using namespace std;

// Define BooksObject structure
struct BooksObject
{
    int id;
    string name;
    string author;
    string originalLanguage;
    int firstPublicationYear;
    int approximateSales;
    string genre;
    int remaining;
};

// Define DateMonthYear structure
struct DateMonthYear
{
    int date;
    int month;
    int year;
};

// Define UsersObject structure
struct UsersObject
{
    int id;
    string name;
    pair<int, DateMonthYear> borrowedBooks[100];
    // max of 100 borrowed books
    int borrowedBooksCount;
};

// Define temple string
string temple1;
string temple2;

// Define csv file in variables
BooksObject books[1000];
int n = 0;

// Define csv file in variables
UsersObject users[1000];
int m = 0;

// Get current date
time_t now = time(nullptr);
tm *ltm = localtime(&now);

// Define overdue date
int overdueDate = 7;

// Define price per one overdue day
int pricePerOneOverdueDay = 10000;

// Center text function
void centerText(const string& text);

// Import Books function
void importBooks();

// Import Users function
void importUsers();

// Check if a string is an integer
bool isInteger(string str);

// Check if leap year
bool isLeapYear(int year);

// Change date month year to date from 2024
int changeDateMonthYearToDate(int date, int month, int year);

// Difference between today and another date
int differenceBetweenTodayAndAnotherDate(int date, int month, int year);

// Check if a book is overdue
bool isBookOverdue(int date, int month, int year);

// Count number of users whose books are overdue
void countNumberOfUsersWhoseBooksAreOverdue(int &numberOfUsersWhoseBooksAreOverdue);

// Print all users whose books are overdue
void printAllUsersWhoseBooksAreOverdue();

// Sort unordered_map by value
void sortUnorderedMapByValue(unordered_map<string, int> &map);

// Statistics about books and users
void statisticsAboutBooksAndUsers();

// Check if the ID of book has been used
bool isIDOfBookUsed(int id);

// Add one book to datastructure
void addOneBookToDatastructure(int id, string name, string author, string originalLanguage, int firstPublicationYear, int approximateSales, string genre, int remaining);

// Delete one book from datastructure
void deleteOneBookFromDatastructure(int id);

// Find one book from datastructure by ID
void findOneBookFromDatastructureByID(int id);

// Find all books from datastructure by name
void findAllBooksFromDatastructureByName(string name);

// Find all books from datastructure by author
void findAllBooksFromDatastructureByAuthor(string author);

// Find all books from datastructure by original language
void findAllBooksFromDatastructureByOriginalLanguage(string originalLanguage);

// Find all books from datastructure by first publication year
void findAllBooksFromDatastructureByFirstPublicationYear(int firstPublicationYear);

// Find all books from datastructure by genre
void findAllBooksFromDatastructureByGenre(string genre);

// Book Management Menu
void bookManagementMenu(string &bookChoice, int &bookChoiceInt);

// Add one user to datastructure
void addOneUserToDatastructure(int id, string name);

// Delete one user from datastructure
void deleteOneUserFromDatastructure(int id);

// Check if the ID has borrowed that ID of book
bool isIDHasBorrowedThatIDOfBook(int mid, int idBook);

// Find one user from datastructure by ID
void findOneUserFromDatastructureByID(int id);

// Find all users from datastructure by name
void findAllUsersFromDatastructureByName(string name);

// Check if the ID of user has been used
bool isIDOfUserUsed(int id);

// User Management Menu
void userManagementMenu(string &userChoice, int &userChoiceInt);

// Data Management And Statistics Menu
void dataManagementAndStatisticsMenu(string &dataChoice, int &dataChoiceInt);

// Setting Menu
void settingMenu(string &settingChoice, int &settingChoiceInt);

// Import all books from datastructre to books_dataset.csv
void exportBooks();

// Import all users from datastructre to users_dataset.csv
void exportUsers();

#endif
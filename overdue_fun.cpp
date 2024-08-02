#include "function.h"

// Check if a book is overdue
bool isBookOverdue(int date, int month, int year)
{
    if (differenceBetweenTodayAndAnotherDate(date, month, year) > overdueDate)
    {
        return true;
    }
    return false;
}

// Count number of users whose books are overdue
void countNumberOfUsersWhoseBooksAreOverdue(int &numberOfUsersWhoseBooksAreOverdue)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < users[i].borrowedBooksCount; j++)
        {
            if (isBookOverdue(users[i].borrowedBooks[j].second.date, users[i].borrowedBooks[j].second.month, users[i].borrowedBooks[j].second.year))
            {
                numberOfUsersWhoseBooksAreOverdue++;
            }
        }
    }
}

// Print all users whose books are overdue
void printAllUsersWhoseBooksAreOverdue()
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < users[i].borrowedBooksCount; j++)
        {
            if (isBookOverdue(users[i].borrowedBooks[j].second.date, users[i].borrowedBooks[j].second.month, users[i].borrowedBooks[j].second.year))
            {
                centerText(to_string(users[i].id) + " - " + users[i].name + " - " + to_string(users[i].borrowedBooks[j].first) + " - " + to_string(users[i].borrowedBooks[j].second.date) + "/" + to_string(users[i].borrowedBooks[j].second.month) + "/" + to_string(users[i].borrowedBooks[j].second.year));
                centerText("Overdue " + to_string(differenceBetweenTodayAndAnotherDate(users[i].borrowedBooks[j].second.date, users[i].borrowedBooks[j].second.month, users[i].borrowedBooks[j].second.year) - overdueDate) + " days");
                centerText("Price : " + to_string(pricePerOneOverdueDay * (differenceBetweenTodayAndAnotherDate(users[i].borrowedBooks[j].second.date, users[i].borrowedBooks[j].second.month, users[i].borrowedBooks[j].second.year) - overdueDate)) + " VND\n");
            }
        }
    }
    cout << "\n";
    system("pause");
}
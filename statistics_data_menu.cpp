#include "function.h"

// Data Management And Statistics Menu
void dataManagementAndStatisticsMenu(string &dataChoice, int &dataChoiceInt)
{
    system("cls");
    centerText("------------------- Data Management And Statistics Menu -------------------\n\n");
    centerText("1. Show all books.\n");
    centerText("2. Show all users.\n");
    centerText("3. Show all statistics about books.\n");
    centerText("4. Return to Main Menu.\n\n");

    centerText("Select one to continue the application.\n");
    centerText("Enter your choice (Choose a number from 1 to 4) : ");
    
    getline(cin, dataChoice);

    while (!isInteger(dataChoice) || stoi(dataChoice) < 1 || stoi(dataChoice) > 4)
    {
        cout << "\n";
        centerText("Warning : Invalid choice!\n");
        centerText("Please enter a number between 1 and 4.\n");
        centerText("Enter your choice (Choose a number from 1 to 4) : ");
        getline(cin, dataChoice);
    }

    cout << "\n";
    system("cls");

    // Layer 2 menu
    dataChoiceInt = stoi(dataChoice);
    if (dataChoiceInt == 1)
    {
        // Show all books
        centerText("------------------- Show all books Menu -------------------\n\n");

        // Print all books from datastructure
        for (int i = 0; i < n; i++)
        {
            cout << books[i].id << " - " << books[i].name << " - " << books[i].author << " - " << books[i].originalLanguage << " - " << books[i].firstPublicationYear << " - " << books[i].approximateSales << " - " << books[i].genre << " - " << books[i].remaining << "\n";
        }
        cout << "\n";
        system("pause");
    }
    else if (dataChoiceInt == 2)
    {
        // Show all users
        centerText("------------------- Show all users Menu -------------------\n\n");

        // Print all users from database and datastructure
        for (int i = 0; i < m; i++)
        {
            cout << "               " << users[i].id << " - " << users[i].name << " : ";
            for (int j = 0; j < users[i].borrowedBooksCount; j++)
            {
                cout << users[i].borrowedBooks[j].first << " - " << users[i].borrowedBooks[j].second.date << "/" << users[i].borrowedBooks[j].second.month << "/" << users[i].borrowedBooks[j].second.year;
                if (j != users[i].borrowedBooksCount - 1)
                {
                    cout << " | ";
                }
            }
            cout << "\n";
        }
        cout << "\n";
        system("pause");
    }
    else if (dataChoiceInt == 3)
    {
        // Shows all statistics about books
        centerText("------------------- Shows all statistics about books Menu -------------------\n\n");

        // Analysis all statistics about books from database and datastructure and show them
        centerText("Total of books : " + to_string(n) + " unique value(s)\n");
        centerText("Total of users : " + to_string(m) + " unique value(s)\n");
        statisticsAboutBooksAndUsers();
    }
}
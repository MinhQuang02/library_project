#include "function.h"

// Add one user to datastructure
void addOneUserToDatastructure(int id, string name)
{
    // Add one user to datastructure
    users[m].id = id;
    users[m].name = name;
    m++;
    sort(users, users + m, [](const UsersObject &a, const UsersObject &b) {
        return a.id < b.id;
    });
}

// Delete one user from datastructure
void deleteOneUserFromDatastructure(int id)
{
    // Delete one user from datastructure
    for (int i = 0; i < m; i++)
    {
        if (users[i].id == id)
        {
            for (int j = i; j < m - 1; j++)
            {
                users[j] = users[j + 1];
            }
            m--;
            break;
        }
    }
}

// Check if the ID has borrowed that ID of book
bool isIDHasBorrowedThatIDOfBook(int mid, int idBook)
{
    for (int i = 0; i < users[mid].borrowedBooksCount; i++)
    {
        if (users[mid].borrowedBooks[i].first == idBook)
        {
            return true;
        }
    }
    return false;
}

// Find one user from datastructure by ID
void findOneUserFromDatastructureByID(int id)
{
    // Binary search to find one user from datastructure by ID
    int left = 0;
    int right = m - 1;
    int mid;

    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (users[mid].id == id)
        {
            centerText("The user you search : " + to_string(users[mid].id) + " - " + users[mid].name);
            for (int i = 0; i < users[mid].borrowedBooksCount; i++)
            {
                centerText("| " + to_string(users[mid].borrowedBooks[i].first) + " - " + to_string(users[mid].borrowedBooks[i].second.date) + "/" + to_string(users[mid].borrowedBooks[i].second.month) + "/" + to_string(users[mid].borrowedBooks[i].second.year));
            }
            cout << "\n";
            system("pause");
            break;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    system("cls");
    cout << "\n";
    centerText("------------------- Edit user information Menu -------------------\n\n");

    centerText("1. User borrowed a book.\n");
    centerText("2. User returned a book.\n");
    centerText("3. Return to User Management menu.\n\n");

    centerText("Select one to continue the application.\n");
    centerText("Enter your choice (Choose a number from 1 to 3) : ");
    string editChoice;
    getline(cin, editChoice);

    while (!isInteger(editChoice) || stoi(editChoice) < 1 || stoi(editChoice) > 3)
    {
        cout << "\n";
        centerText("Warning : Invalid choice!\n");
        centerText("Please enter a number between 1 and 3.\n");
        centerText("Enter your choice (Choose a number from 1 to 3) : ");
        getline(cin, editChoice);
    }

    int editChoiceInt = stoi(editChoice);
    if (editChoiceInt == 1)
    {
        // Enter ID of book to borrow
        centerText("Enter ID of book to borrow (4 digits) : ");
        
        string idBook;
        getline(cin, idBook);
        while (!isInteger(idBook) || stoi(idBook) < 1000 || stoi(idBook) > 9999 || !isIDOfBookUsed(stoi(idBook)))
        {
            cout << "\n";
            centerText("Warning : The ID is not found or you did not enter ID in the correct format!\n");
            centerText("Please enter a number. (In case you don't know ID. Enter \"Exit\" to return).\n");
            centerText("Enter ID of book to borrow (4 digits) : ");
            getline(cin, idBook);
            if (idBook == "Exit")
            {
                return;
            }
        }

        // Check if remaining of book is greater than 0
        int leftT = 0;
        int rightT = n - 1;
        int midT = 0;

        while (leftT <= rightT)
        {
            midT = leftT + (rightT - leftT) / 2;

            if (books[midT].id == stoi(idBook))
            {
                if (books[midT].remaining == 0)
                {
                    cout << "\n";
                    centerText("Warning : The book is out of stock!\n");
                    cout << "\n";
                    system("pause");
                    return;
                }
                break;
            }
            else if (books[midT].id < stoi(idBook))
            {
                leftT = midT + 1;
            }
            else
            {
                rightT = midT - 1;
            }
        }

        // Borrow this book for this user
        users[mid].borrowedBooks[users[mid].borrowedBooksCount].first = stoi(idBook);
        users[mid].borrowedBooks[users[mid].borrowedBooksCount].second.date = ltm->tm_mday;
        users[mid].borrowedBooks[users[mid].borrowedBooksCount].second.month = 1 + ltm->tm_mon;
        users[mid].borrowedBooks[users[mid].borrowedBooksCount].second.year = 1900 + ltm->tm_year;
        users[mid].borrowedBooksCount++;

        // Decrease remaining of book
        books[midT].remaining--;

        cout << "\n";
        centerText("Has been borrowed successfully.\n");
        cout << "\n";
    }
    else if (editChoiceInt == 2)
    {
        // Enter ID of book to return
        centerText("Enter ID of book to return (4 digits) : ");
        string idBook;
        getline(cin, idBook);
        while (!isInteger(idBook) || stoi(idBook) < 1000 || stoi(idBook) > 9999 || !isIDHasBorrowedThatIDOfBook(mid, stoi(idBook)))
        {
            cout << "\n";
            centerText("Warning : The ID is not found or you did not enter ID in the correct format!\n");
            centerText("Please enter a number. (In case you don't know ID. Enter \"Exit\" to return).\n");
            centerText("Enter ID of book to return (4 digits) : ");
            getline(cin, idBook);
            if (idBook == "Exit")
            {
                cout << "\n";
                return;
            }
        }

        // Return this book for this user
        for (int i = 0; i < users[mid].borrowedBooksCount; i++)
        {
            if (users[mid].borrowedBooks[i].first == stoi(idBook))
            {
                for (int j = i; j < users[mid].borrowedBooksCount - 1; j++)
                {
                    users[mid].borrowedBooks[j] = users[mid].borrowedBooks[j + 1];
                }
                users[mid].borrowedBooksCount--;
                break;
            }
        }

        // Increase remaining of book
        int leftT = 0;
        int rightT = n - 1;
        int midT = 0;

        while (leftT <= rightT)
        {
            midT = leftT + (rightT - leftT) / 2;

            if (books[midT].id == stoi(idBook))
            {
                break;
            }
            else if (books[midT].id < stoi(idBook))
            {
                leftT = midT + 1;
            }
            else
            {
                rightT = midT - 1;
            }
        }

        books[midT].remaining++;

        cout << "\n";
        centerText("Has been returned successfully.\n");
        cout << "\n";
    }
}

// Find all users from datastructure by name
void findAllUsersFromDatastructureByName(string name)
{
    // Find all users from datastructure by name
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        if (users[i].name == name)
        {
            centerText("The user you search : " + to_string(users[i].id) + " - " + users[i].name);
            for (int j = 0; j < users[i].borrowedBooksCount; j++)
            {
                centerText("| " + to_string(users[i].borrowedBooks[j].first) + " - " + to_string(users[i].borrowedBooks[j].second.date) + "/" + to_string(users[i].borrowedBooks[j].second.month) + "/" + to_string(users[i].borrowedBooks[j].second.year));
            }
            cout << "\n";
            count++;
        }
    }
    if (count == 0)
    {
        centerText("The user you search is not found!\n");
    }
    cout << "\n";
    system("pause");
}

// Check if the ID of user has been used
bool isIDOfUserUsed(int id)
{
    // Binary search to check if the ID of user has been used
    int left = 0;
    int right = m - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (users[mid].id == id)
        {
            return true;
        }
        else if (users[mid].id < id)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return false;
}
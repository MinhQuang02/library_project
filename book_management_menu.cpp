#include "function.h"

// Book Management Menu
void bookManagementMenu(string &bookChoice, int &bookChoiceInt)
{
    system("cls");
    centerText("------------------- Book Management Menu -------------------\n\n");
    centerText("1. Add a book.\n");
    centerText("2. Delete a book.\n");
    centerText("3. Find a book.\n");
    centerText("4. Return to the main menu.\n\n");

    centerText("Select one to continue the application.\n");
    centerText("Enter your choice (Choose a number from 1 to 4) : ");
    getline(cin, bookChoice);

    while (!isInteger(bookChoice) || stoi(bookChoice) < 1 || stoi(bookChoice) > 4)
    {
        cout << "\n";
        centerText("Warning : Invalid choice!\n");
        centerText("Please enter a number between 1 and 4.\n");
        centerText("Enter your choice (Choose a number from 1 to 4) : ");
        getline(cin, bookChoice);
    }

    cout << "\n";
    system("cls");
    
    // Layer 2 menu
    bookChoiceInt = stoi(bookChoice);
    if (bookChoiceInt == 1)
    {   
        // Add a book
        centerText("------------------- Add a book Menu -------------------\n\n");

        // Add a book
        centerText("Enter information to add a new book.\n\n");

        // Enter ID of book
        centerText("Enter ID of book (4 digits) : ");

        string id;
        getline(cin, id);
        while (!isInteger(id) || stoi(id) < 1000 || stoi(id) > 9999 || isIDOfBookUsed(stoi(id)))
        {
            cout << "\n";
            centerText("Warning : The ID is already used or you did not enter ID in the correct format!\n");
            centerText("Please enter a number. (In case you don't know ID. Enter \"Exit\" to return).\n");
            centerText("Enter ID of book (4 digits) : ");
            getline(cin, id);
            if (id == "Exit")
            {
                cout << "\n";
                return;
            }
        }

        // Enter name of book
        centerText("Enter name of book : ");
        string name;
        getline(cin, name);

        // Enter author of book
        centerText("Enter author of book : ");
        string author;
        getline(cin, author);

        // Enter Original Language of book
        centerText("Enter Original Language of book : ");
        string originalLanguage;
        getline(cin, originalLanguage);

        // Enter First Publication Year of book
        centerText("Enter First Publication Year of book : ");
        string firstPublicationYear;
        getline(cin, firstPublicationYear);
        while (!isInteger(firstPublicationYear) || stoi(firstPublicationYear) < 0)
        {
            cout << "\n";
            centerText("Warning : Invalid year!\n");
            centerText("Please enter a number.\n");
            centerText("Enter First Publication Year of book : ");
            getline(cin, firstPublicationYear);
        }

        // Enter Approximate sales of book in millions
        centerText("Enter Approximate sales of book in millions : ");
        string approximateSales;
        getline(cin, approximateSales);
        while (!isInteger(approximateSales) || stoi(approximateSales) < 0)
        {
            cout << "\n";
            centerText("Warning : Invalid number!\n");
            centerText("Please enter a number.\n");
            centerText("Enter Approximate sales of book in millions : ");
            getline(cin, approximateSales);
        }

        // Enter Genre of book
        centerText("Enter Genre of book : ");
        string genre;
        getline(cin, genre);

        // Enter Remaining of book
        centerText("Enter Remaining of book : ");
        string remaining;
        getline(cin, remaining);
        while (!isInteger(remaining) || stoi(remaining) < 0)
        {
            cout << "\n";
            centerText("Warning : Invalid number!\n");
            centerText("Please enter a number.\n");
            centerText("Enter Remaining of book : ");
            getline(cin, remaining);
        }

        // Import this book to database and datastructure
        addOneBookToDatastructure(stoi(id), name, author, originalLanguage, stoi(firstPublicationYear), stoi(approximateSales), genre, stoi(remaining));

        cout << "\n";
        centerText("Has been added successfully.\n");
        cout << "\n";

        system("pause");
    }
    else if (bookChoiceInt == 2)
    {
        // Delete a book
        centerText("------------------- Delete a book Menu -------------------\n\n");

        // Enter ID of book to delete
        centerText("Enter ID of book to delete (4 digits) : ");
        string id;
        getline(cin, id);
        while (!isInteger(id) || stoi(id) < 1000 || stoi(id) > 9999 || !isIDOfBookUsed(stoi(id)))
        {
            cout << "\n";
            centerText("Warning : The ID is not found or you did not enter ID in the correct format!\n");
            centerText("Please enter a number. (In case you don't know ID. Enter \"Exit\" to return).\n");
            centerText("Enter ID of book to delete (4 digits) : ");
            getline(cin, id);
            if (id == "Exit")
            {
                cout << "\n";
                return;
            }
        }

        // Delete this book from database and datastructure (Restructure the database and data structure)
        deleteOneBookFromDatastructure(stoi(id));
        cout << "\n";
        centerText("Has been deleted successfully.\n");
        cout << "\n";

        system("pause");
    }
    else if (bookChoiceInt == 3)
    {
        // Find a book
        centerText("------------------- Find a book Menu -------------------\n\n");

        centerText("1. Find a book by ID.\n");
        centerText("2. Find a book by name.\n");
        centerText("3. Find a book by author.\n");
        centerText("4. Find a book by original language.\n");
        centerText("5. Find a book by first publication year.\n");
        centerText("6. Find a book by genre.\n\n");

        centerText("Select one to continue the application.\n");
        centerText("Enter your choice (Choose a number from 1 to 6) : ");
        string findChoice;
        getline(cin, findChoice);
        while (!isInteger(findChoice) || stoi(findChoice) < 1 || stoi(findChoice) > 6)
        {
            cout << "\n";
            centerText("Warning : Invalid choice!\n");
            centerText("Please enter a number between 1 and 6.\n");
            centerText("Enter your choice (Choose a number from 1 to 6) : ");
            getline(cin, findChoice);
        }

        cout << "\n";
        system("cls");

        int findChoiceInt = stoi(findChoice);
        if (findChoiceInt == 1)
        {
            // Find a book by ID
            centerText("------------------- Find a book by ID Menu -------------------\n\n");

            // Enter ID of book to find
            centerText("Enter ID of book to find (4 digits) : ");
            string id;
            getline(cin, id);
            while (!isInteger(id) || stoi(id) < 1000 || stoi(id) > 9999 || !isIDOfBookUsed(stoi(id)))
            {
                cout << "\n";
                centerText("Warning : The ID is not found or you did not enter ID in the correct format!\n");
                centerText("Please enter a number. (In case you don't know ID. Enter \"Exit\" to return).\n");
                centerText("Enter ID of book to find (4 digits) : ");
                getline(cin, id);
                if (id == "Exit")
                {
                    cout << "\n";
                    return;
                }
            }

            // Find this book from database and datastructure
            cout << "\n";
            findOneBookFromDatastructureByID(stoi(id));
        }
        else if (findChoiceInt == 2)
        {
            // Find a book by name
            centerText("------------------- Find a book by name Menu -------------------\n\n");

            // Enter name of book to find
            centerText("Enter name of book to find : ");
            string name;
            getline(cin, name);

            // Find this book from database and datastructure
            cout << "\n";
            findAllBooksFromDatastructureByName(name);
        }
        else if (findChoiceInt == 3)
        {
            // Find a book by author
            centerText("------------------- Find a book by author Menu -------------------\n\n");

            // Enter author of book to find
            centerText("Enter author of book to find : ");
            string author;
            getline(cin, author);

            // Find this book from database and datastructure
            cout << "\n";
            findAllBooksFromDatastructureByAuthor(author);
        }
        else if (findChoiceInt == 4)
        {
            // Find a book by original language
            centerText("------------------- Find a book by original language Menu -------------------\n\n");

            // Enter original language of book to find
            centerText("Enter original language of book to find : ");
            string originalLanguage;
            getline(cin, originalLanguage);

            // Find this book from database and datastructure
            cout << "\n";
            findAllBooksFromDatastructureByOriginalLanguage(originalLanguage);
        }
        else if (findChoiceInt == 5)
        {
            // Find a book by first publication year
            centerText("------------------- Find a book by first publication year Menu -------------------\n\n");

            // Enter first publication year of book to find
            centerText("Enter first publication year of book to find : ");
            string firstPublicationYear;
            getline(cin, firstPublicationYear);
            while (!isInteger(firstPublicationYear) || stoi(firstPublicationYear) < 0)
            {
                cout << "\n";
                centerText("Warning : Invalid year!\n");
                centerText("Please enter a number.\n");
                centerText("Enter first publication year of book to find : ");
                getline(cin, firstPublicationYear);
            }

            // Find this book from database and datastructure
            cout << "\n";
            findAllBooksFromDatastructureByFirstPublicationYear(stoi(firstPublicationYear));
        }
        else
        {
            // Find a book by genre
            centerText("------------------- Find a book by genre Menu -------------------\n\n");

            // Enter genre of book to find
            centerText("Enter genre of book to find : ");
            string genre;
            getline(cin, genre);

            // Find this book from database and datastructure
            cout << "\n";
            findAllBooksFromDatastructureByGenre(genre);
        }
        cout << "\n";
    }
}
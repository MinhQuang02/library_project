#include "function.h"

// Import all books from datastructre to books_dataset.csv
void exportBooks()
{
    // Export all books from datastructure to books_dataset.csv
    ofstream file;
    file.open("books_dataset.csv");
    file << temple1 << "\n";
    for (int i = 0; i < n; i++)
    {
        file << books[i].id << ",";
        for (int j = 0; j < books[i].name.size(); j++)
        {
            if (books[i].name[j] == ',')
            {
                books[i].name = "\"" + books[i].name + "\"";
                break;
            }
        }
        file << books[i].name;
        file << ",";
        for (int j = 0; j < books[i].author.size(); j++)
        {
            if (books[i].author[j] == ',')
            {
                books[i].author = "\"" + books[i].author + "\"";
                break;
            }
        }
        file << books[i].author;
        file << ","; 
        for (int j = 0; j < books[i].originalLanguage.size(); j++)
        {
            if (books[i].originalLanguage[j] == ',')
            {
                books[i].originalLanguage = "\"" + books[i].originalLanguage + "\"";
                break;
            }
        }
        file << books[i].originalLanguage;
        file << "," << books[i].firstPublicationYear << "," << books[i].approximateSales << ",";
        for (int j = 0; j < books[i].genre.size(); j++)
        {
            if (books[i].genre[j] == ',')
            {
                books[i].genre = "\"" + books[i].genre + "\"";
                break;
            }
        }
        file << books[i].genre;
        file << "," << books[i].remaining;
        if (i != n - 1)
        {
            file << "\n";
        }
    }
    file.close();
}

// Import all users from datastructre to users_dataset.csv
void exportUsers()
{
    // Export all users from datastructure to users_dataset.csv
    ofstream file;
    file.open("data_users.csv");
    file << temple2 << "\n";
    for (int i = 0; i < m; i++)
    {
        file << users[i].id << "," << users[i].name;
        for (int j = 0; j < users[i].borrowedBooksCount; j++)
        {
            file << "," << users[i].borrowedBooks[j].first << "," << users[i].borrowedBooks[j].second.date << "/" << users[i].borrowedBooks[j].second.month << "/" << users[i].borrowedBooks[j].second.year;
        }
        if (i != m - 1)
        {
            file << "\n";
        }
    }
    file.close();
}
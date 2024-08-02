#include "function.h"

// Check if the ID of book has been used
bool isIDOfBookUsed(int id)
{
    // Binary search to check if the ID of book has been used
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (books[mid].id == id)
        {
            return true;
        }
        else if (books[mid].id < id)
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

// Add one book to datastructure
void addOneBookToDatastructure(int id, string name, string author, string originalLanguage, int firstPublicationYear, int approximateSales, string genre, int remaining)
{
    // Add one book to datastructure
    books[n].id = id;
    books[n].name = name;
    books[n].author = author;
    books[n].originalLanguage = originalLanguage;
    books[n].firstPublicationYear = firstPublicationYear;
    books[n].approximateSales = approximateSales;
    books[n].genre = genre;
    books[n].remaining = remaining;
    n++;
    sort(books, books + n, [](const BooksObject &a, const BooksObject &b) {
        return a.id < b.id;
    });
}

// Delete one book from datastructure
void deleteOneBookFromDatastructure(int id)
{
    // Delete one book from datastructure
    for (int i = 0; i < n; i++)
    {
        if (books[i].id == id)
        {
            for (int j = i; j < n - 1; j++)
            {
                books[j] = books[j + 1];
            }
            n--;
            break;
        }
    }
}

// Find one book from datastructure by ID
void findOneBookFromDatastructureByID(int id)
{
    // Binary search to find one book from datastructure by ID
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (books[mid].id == id)
        {
            centerText("The book you search : " + to_string(books[mid].id) + " - " + books[mid].name + " - " + books[mid].author + " - " + books[mid].originalLanguage + " - " + to_string(books[mid].firstPublicationYear) + " - " + to_string(books[mid].approximateSales) + " - " + books[mid].genre + " - " + to_string(books[mid].remaining));
            cout << "\n\n";
            system("pause");
            return;
        }
        else if (books[mid].id < id)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
}

// Find all books from datastructure by name
void findAllBooksFromDatastructureByName(string name)
{
    // Find all books from datastructure by name
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (books[i].name == name)
        {
            centerText("The book you search : " + to_string(books[i].id) + " - " + books[i].name + " - " + books[i].author + " - " + books[i].originalLanguage + " - " + to_string(books[i].firstPublicationYear) + " - " + to_string(books[i].approximateSales) + " - " + books[i].genre + " - " + to_string(books[i].remaining));
            count++;
        }
    }
    if (count == 0)
    {
        centerText("The book you search is not found!\n");
    }
    cout << "\n";
    system("pause");
}

// Find all books from datastructure by author
void findAllBooksFromDatastructureByAuthor(string author)
{
    // Find all books from datastructure by author
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (books[i].author == author)
        {
            centerText("The book you search : " + to_string(books[i].id) + " - " + books[i].name + " - " + books[i].author + " - " + books[i].originalLanguage + " - " + to_string(books[i].firstPublicationYear) + " - " + to_string(books[i].approximateSales) + " - " + books[i].genre + " - " + to_string(books[i].remaining));
            count++;
        }
    }
    if (count == 0)
    {
        centerText("The book you search is not found!\n");
    }
    cout << "\n";
    system("pause");
}

// Find all books from datastructure by original language
void findAllBooksFromDatastructureByOriginalLanguage(string originalLanguage)
{
    // Find all books from datastructure by original language
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (books[i].originalLanguage == originalLanguage)
        {
            centerText("The book you search : " + to_string(books[i].id) + " - " + books[i].name + " - " + books[i].author + " - " + books[i].originalLanguage + " - " + to_string(books[i].firstPublicationYear) + " - " + to_string(books[i].approximateSales) + " - " + books[i].genre + " - " + to_string(books[i].remaining));
            count++;
        }
    }
    if (count == 0)
    {
        centerText("The book you search is not found!\n");
    }
    cout << "\n";
    system("pause");
}

// Find all books from datastructure by first publication year
void findAllBooksFromDatastructureByFirstPublicationYear(int firstPublicationYear)
{
    // Find all books from datastructure by first publication year
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (books[i].firstPublicationYear == firstPublicationYear)
        {
            centerText("The book you search : " + to_string(books[i].id) + " - " + books[i].name + " - " + books[i].author + " - " + books[i].originalLanguage + " - " + to_string(books[i].firstPublicationYear) + " - " + to_string(books[i].approximateSales) + " - " + books[i].genre + " - " + to_string(books[i].remaining));
            count++;
        }
    }
    if (count == 0)
    {
        centerText("The book you search is not found!\n");
    }
    cout << "\n";
    system("pause");
}

// Find all books from datastructure by genre
void findAllBooksFromDatastructureByGenre(string genre)
{
    // Find all books from datastructure by genre
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (books[i].genre == genre)
        {
            centerText("The book you search : " + to_string(books[i].id) + " - " + books[i].name + " - " + books[i].author + " - " + books[i].originalLanguage + " - " + to_string(books[i].firstPublicationYear) + " - " + to_string(books[i].approximateSales) + " - " + books[i].genre + " - " + to_string(books[i].remaining));
            count++;
        }
    }
    if (count == 0)
    {
        centerText("The book you search is not found!\n");
    }
    cout << "\n";
    system("pause");
}
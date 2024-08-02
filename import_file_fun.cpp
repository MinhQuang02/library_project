#include "function.h"

// Import Books function
void importBooks()
{
    // Import all books from books_dataset.csv to database and datastructure
    ifstream file("books_dataset.csv");

    // Check if the file is opened successfully
    if (!file.is_open())
    {
        centerText("Error: File cannot be opened!\n");
        return;
    }

    // Read the first line
    string line;
    getline(file, temple1);

    // Read the rest of the lines and import to BooksObject
    while (!file.eof())
    {   
        // Read a line
        getline(file, line);

        // Define temp string and count variable
        string temp = "";
        int count = 0;

        // Read each character of the line
        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] == ',')
            {
                count++;
                if (count == 1)
                {
                    books[n].id = stoi(temp);
                }
                else if (count == 2)
                {
                    books[n].name = temp;
                }
                else if (count == 3)
                {
                    books[n].author = temp;
                }
                else if (count == 4)
                {
                    books[n].originalLanguage = temp;
                }
                else if (count == 5)
                {
                    books[n].firstPublicationYear = stoi(temp);
                }
                else if (count == 6)
                {
                    books[n].approximateSales = stoi(temp);
                }
                else if (count == 7)
                {
                    books[n].genre = temp;
                }
                temp = "";
                if (line[i + 1] == '"')
                {
                    i += 2;
                    while (line[i] != '"')
                    {
                        temp += line[i];
                        i++;
                    }
                }
            }
            else
            {
                temp += line[i];
            }
        }
        // Read the last element of the line
        books[n].remaining = stoi(temp);
        n++;
    }
    file.close();
}

// Import Users function
void importUsers()
{
    // Import all users from users_dataset.csv to database and datastructure
    ifstream file("data_users.csv");

    // Check if the file is opened successfully
    if (!file.is_open())
    {
        centerText("Error: File cannot be opened!\n");
        return;
    }

    // Read the first line
    string line;
    getline(file, temple2);

    // Read the rest of the lines and import to UsersObject
    while (!file.eof())
    {   
        // Read a line
        getline(file, line);

        // Define temp string and count variable
        string temp = "";
        int count = 0;

        // Bool variable to check id or date
        bool checkIDOrDate = true;

        // Read each character of the line
        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] == ',' || i == line.size() - 1)
            {   
                if (i == line.size() - 1)
                {
                    temp += line[i];
                }
                count++;
                if (count == 1)
                {
                    users[m].id = stoi(temp);
                }
                else if (count == 2)
                {
                    users[m].name = temp;
                }
                else
                {
                    if (checkIDOrDate)
                    {
                        users[m].borrowedBooks[users[m].borrowedBooksCount].first = stoi(temp);
                        checkIDOrDate = false;
                    }
                    else
                    {
                        // Read date
                        string date = "";
                        string month = "";
                        string year = "";
                        int countDateMonthYear = 0;
                        for (int j = 0; j < temp.size(); j++)
                        {
                            if (temp[j] == '/')
                            {
                                countDateMonthYear++;
                            }
                            else
                            {
                                if (countDateMonthYear == 0)
                                {
                                    date += temp[j];
                                }
                                else if (countDateMonthYear == 1)
                                {
                                    month += temp[j];
                                }
                                else
                                {
                                    year += temp[j];
                                }
                            }
                        }
                        users[m].borrowedBooks[users[m].borrowedBooksCount].second.date = stoi(date);
                        users[m].borrowedBooks[users[m].borrowedBooksCount].second.month = stoi(month);
                        users[m].borrowedBooks[users[m].borrowedBooksCount].second.year = stoi(year);
                        users[m].borrowedBooksCount++;
                        checkIDOrDate = true;
                    }
                }
                temp = "";
            }
            else
            {
                temp += line[i];
            }
        }
        m++;
    }
    file.close();
}
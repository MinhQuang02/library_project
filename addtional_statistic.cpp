#include "function.h"   

// Sort unordered_map by value
void sortUnorderedMapByValue(unordered_map<string, int> &map)
{
    vector<pair<string, int>> vec;
    for (auto &it : map)
    {
        vec.push_back(it);
    }
    sort(vec.begin(), vec.end(), [](const pair<string, int> &a, const pair<string, int> &b) {
        return a.second < b.second;
    });
    map.clear();
    for (auto &it : vec)
    {
        map[it.first] = it.second;
    }
}

// Statistics about books and users
void statisticsAboutBooksAndUsers()
{
    // Define data structure for statistics
    unordered_map<string, int> StAuthor;
    unordered_map<string, int> StOriginalLanguage;
    unordered_map<string, int> StFirstPublicationYear;
    unordered_map<string, int> StGenre;
    unordered_map<string, int> StBorrowedBooksCount;
    int maxSalesBook = 0;

    // Analysis all statistics about books and users from database and datastructure
    for (int i = 0; i < n; i++)
    {
        StAuthor[books[i].author]++;
        StOriginalLanguage[books[i].originalLanguage]++;
        StFirstPublicationYear[to_string(books[i].firstPublicationYear)]++;
        maxSalesBook = max(maxSalesBook, books[i].approximateSales);
        StGenre[books[i].genre]++;
    }

    // Sort all unordered_map by value
    sortUnorderedMapByValue(StAuthor);
    sortUnorderedMapByValue(StOriginalLanguage);
    sortUnorderedMapByValue(StFirstPublicationYear);
    sortUnorderedMapByValue(StGenre);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < users[i].borrowedBooksCount; j++)
        {
            StBorrowedBooksCount[to_string(users[i].borrowedBooks[j].first)]++;
        }
    }

    // Sort all unordered_map by value
    sortUnorderedMapByValue(StBorrowedBooksCount);

    double remainingVal = 100;

    // Print all statistics about books and users
    auto it1 = StAuthor.begin();
    centerText("Author(s) : " + it1->first + " - " + to_string((it1->second * 100.0) / n) + "%");
    remainingVal -= (it1->second * 100.0) / n;
    advance(it1, 1);
    centerText(it1->first + " - " + to_string((it1->second * 100.0) / n) + "%");
    remainingVal -= (it1->second * 100.0) / n;
    centerText("Other - " + to_string(remainingVal) + "%");
    remainingVal = 100;

    auto it2 = StOriginalLanguage.begin();
    centerText("Original Language : " + it2->first + " - " + to_string((it2->second * 100.0) / n) + "%");
    remainingVal -= (it2->second * 100.0) / n;
    advance(it2, 1);
    centerText(it2->first + " - " + to_string((it2->second * 100.0) / n) + "%");
    remainingVal -= (it2->second * 100.0) / n;
    centerText("Other - " + to_string(remainingVal) + "%");
    remainingVal = 100;

    centerText("Year with the highest number of first publications : " + StFirstPublicationYear.begin()->first + " with " + to_string(StFirstPublicationYear.begin()->second) + " book(s)");
    centerText("Books with the highest sales volume in millions : " + to_string(maxSalesBook) + " (m)");

    auto it3 = StGenre.begin();
    centerText("Genre(s) : " + it3->first + " - " + to_string((it3->second * 100.0) / n) + "%");
    remainingVal -= (it3->second * 100.0) / n;
    advance(it3, 1);
    centerText(it3->first + " - " + to_string((it3->second * 100.0) / n) + "%");
    remainingVal -= (it3->second * 100.0) / n;
    centerText("Other - " + to_string(remainingVal) + "%");

    auto it4 = StBorrowedBooksCount.begin();
    int maxValue = it4->second;
    centerText("Book(s) has been borrowed most : ID - " + it4->first + " | " + to_string(it4->second) + " user(s) borrow");
    advance(it4, 1);
    while (maxValue == it4->second)
    {
        centerText("ID - " + it4->first + " | " + to_string(it4->second) + " user(s) borrow");
        advance(it4, 1);
    }

    // Count number of users whose books are overdue
    int numberOfUsersWhoseBooksAreOverdue = 0;
    countNumberOfUsersWhoseBooksAreOverdue(numberOfUsersWhoseBooksAreOverdue);
    centerText("Number of users whose books are overdue : " + to_string(numberOfUsersWhoseBooksAreOverdue) + " user(s)");

    cout << "\n\n";
    system("pause");
}
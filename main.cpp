#include "function.h"

int main() 
{
    // Import all books from books_dataset.csv to database and datastructure
    importBooks();

    // Import all users from users_dataset.csv to database and datastructure
    importUsers();

    // Main menu
    while (true)
    {
        centerText("------------------- Library Menu -------------------\n");
        cout << "\n";
        centerText("1. Book Management.\n");
        centerText("2. User Management.\n");
        centerText("3. Data Management And Statistics.\n");
        centerText("4. Setting.\n");
        centerText("5. Exit.\n");
        cout << "\n";
        
        centerText("Select one to continue the application.\n");
        centerText("Enter your choice (Choose a number from 1 to 5) : ");

        string choice;
        getline(cin, choice);
        
        while (!isInteger(choice) || stoi(choice) < 1 || stoi(choice) > 5)
        {
            cout << "\n";
            centerText("Warning : Invalid choice!\n");
            centerText("Please enter a number between 1 and 5.\n");
            centerText("Enter your choice (Choose a number from 1 to 5) : ");
            getline(cin, choice);
        }

        cout << "\n";
        
        // Layer 1 menu
        int choiceInt = stoi(choice);
        if (choiceInt == 1)
        {
            string bookChoice;
            int bookChoiceInt;
            bookManagementMenu(bookChoice, bookChoiceInt);
            while (bookChoiceInt != 4)
            {
                bookManagementMenu(bookChoice, bookChoiceInt);
            }
        }
        else if (choiceInt == 2)
        {
            // Layer 1 menu
            string userChoice;
            int userChoiceInt;
            userManagementMenu(userChoice, userChoiceInt);
            while (userChoiceInt != 5)
            {
                userManagementMenu(userChoice, userChoiceInt);
            }
        }
        else if (choiceInt == 3)
        {
            // Layer 1 menu
            string dataChoice;
            int dataChoiceInt;
            dataManagementAndStatisticsMenu(dataChoice, dataChoiceInt);
            while (dataChoiceInt != 4)
            {
                dataManagementAndStatisticsMenu(dataChoice, dataChoiceInt);
            }
        }
        else if (choiceInt == 4)
        {
            // Layer 1 menu
            string settingChoice;
            int settingChoiceInt;
            settingMenu(settingChoice, settingChoiceInt);
            while (settingChoiceInt != 4)
            {
                settingMenu(settingChoice, settingChoiceInt);
            }
        }
        else
        {
            // Exit
            centerText("Exitting program.\n");
            centerText("Thank you for using the application!\n");
            cout << "\n";
            system("pause");
            break;
        }
    }
    
    // Export all books from datastructure to books_dataset.csv and data_users.csv
    exportBooks();
    exportUsers();

    return 0;
}
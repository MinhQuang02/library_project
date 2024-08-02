#include "function.h"

// Setting Menu
void settingMenu(string &settingChoice, int &settingChoiceInt)
{   
    system("cls");
    centerText("------------------- Setting Menu -------------------\n\n");
    centerText("1. Change the overdue date of the application.\n");
    centerText("2. Change the price of one overdue day of the application.\n");
    centerText("3. Contact us.\n");
    centerText("4. Return to Main Menu.\n\n");

    centerText("Select one to continue the application.\n");
    centerText("Enter your choice (Choose a number from 1 to 4) : ");
    
    getline(cin, settingChoice);

    while (!isInteger(settingChoice) || stoi(settingChoice) < 1 || stoi(settingChoice) > 4)
    {
        cout << "\n";
        centerText("Warning : Invalid choice!\n");
        centerText("Please enter a number between 1 and 4.\n");
        centerText("Enter your choice (Choose a number from 1 to 4) : ");
        getline(cin, settingChoice);
    }

    cout << "\n";
    system("cls");

    // Layer 2 menu
    settingChoiceInt = stoi(settingChoice);
    if (settingChoiceInt == 1)
    {
        // Change the overdue date of the application
        centerText("------------------- Change the overdue date Menu -------------------\n\n");

        // Print the current overdue date of the application
        centerText("The current overdue date of the application is " + to_string(overdueDate) + " day(s).\n");

        // Enter the new overdue date of the application
        centerText("Enter the new overdue date of the application : ");
        string overdueDateStr;
        getline(cin, overdueDateStr);
        while (!isInteger(overdueDateStr) || stoi(overdueDateStr) < 0)
        {
            cout << "\n";
            centerText("Warning : Invalid number!\n");
            centerText("Please enter a number.\n");
            centerText("Enter the new overdue date of the application : ");
            getline(cin, overdueDateStr);
        }

        // Change to new date
        overdueDate = stoi(overdueDateStr);
        cout << "\n";
        centerText("Has been changed successfully.\n");
        cout << "\n";
        system("pause");
    }
    else if (settingChoiceInt == 2)
    {
        // Change the price of one overdue day of the application
        centerText("------------------- Change the price of one overdue day Menu -------------------\n\n");

        // Print the current price of one overdue day of the application
        centerText("The current price of one overdue day of the application is " + to_string(pricePerOneOverdueDay) + " VND.\n");

        // Enter the new price of one overdue day of the application
        centerText("Enter the new price of one overdue day of the application : ");
        string pricePerOneOverdueDayStr;
        getline(cin, pricePerOneOverdueDayStr);
        while (!isInteger(pricePerOneOverdueDayStr) || stoi(pricePerOneOverdueDayStr) < 0)
        {
            cout << "\n";
            centerText("Warning : Invalid number!\n");
            centerText("Please enter a number.\n");
            centerText("Enter the new price of one overdue day of the application : ");
            getline(cin, pricePerOneOverdueDayStr);
        }

        // Change to new price
        pricePerOneOverdueDay = stoi(pricePerOneOverdueDayStr);
        cout << "\n";
        centerText("Has been changed successfully.\n");
        cout << "\n";
        system("pause");
    }
    else if (settingChoiceInt == 3)
    {
        // Contact us
        centerText("------------------- Contact us Menu -------------------\n\n");

        // Print the contact information
        centerText("Team : Our Team\n");
        centerText("Email : example@gmail.com\n");
        centerText("Phone number : 0123456789\n");
        centerText("Address : 227 Nguyen Van Cu, Ward 4, District 5, Ho Chi Minh City, Viet Nam\n");

        cout << "\n";
        system("pause");
    }
}
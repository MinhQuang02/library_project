#include "function.h"   

// Check if a string is an integer
bool isInteger(string str) 
{
    if (str.empty() || (str[0] != '-' && !isdigit(str[0]))) 
    {
        return false;
    }

    for (int i = 1; i < str.size(); ++i) 
    {
        if (!isdigit(str[i])) 
        {
            return false;
        }
    }

    return true;
}

// Check if leap year
bool isLeapYear(int year) 
{
    if (year % 4 == 0) 
    {
        if (year % 100 == 0) 
        {
            if (year % 400 == 0) 
            {
                return true;
            } 
            else 
            {
                return false;
            }
        } 
        else 
        {
            return true;
        }
    } 
    else 
    {
        return false;
    }
}

// Change date month year to date from 2024
int changeDateMonthYearToDate(int date, int month, int year)
{
    int totalDays = 0;
    for (int i = 2024; i < year; i++)
    {
        if (isLeapYear(i))
        {
            totalDays += 366;
        }
        else
        {
            totalDays += 365;
        }
    }

    int dateInMonth[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = 1; i < month; i++)
    {
        totalDays += dateInMonth[i];
    }

    totalDays += date;

    return totalDays;
}

// Difference between today and another date
int differenceBetweenTodayAndAnotherDate(int date, int month, int year)
{
    int today = changeDateMonthYearToDate(ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year);
    int anotherDate = changeDateMonthYearToDate(date, month, year);
    return today - anotherDate;
}

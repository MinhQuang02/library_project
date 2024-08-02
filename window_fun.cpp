#include "function.h"   

// Center text function
void centerText(const string& text) {
    // Get size of terminal
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;
    
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    // Calculate padding
    int padding = (columns - text.size()) / 2;

    // Print the centered text
    cout << setw(padding + text.size()) << text;
}
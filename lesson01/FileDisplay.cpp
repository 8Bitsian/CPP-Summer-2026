/*
  Imani Hollie 05/15/2026
  Programming Challenge: File Display Program
  Write a program that asks the user for the name of a file. The program should display the
  contents of the file on the screen. If the file's contents won't fit on a single screen,
  the program should display 24 lines of output at a time, then pause. Each time the program
  pauses, it should wait for the user to strike a key before the next 24 lines are displayed.

  NOTE: Using an editor, you should create a simple text file that can be used to test this program.
*/

#include <iostream>  // Allows use of input/output objects (cout, cin)
#include <fstream>   // Allows creation, reading, and writing of files
#include <iomanip>   // Allows use of formatting tools
#include <string>    // Allows use of the string data type
using namespace std; // Allows use of the standard library w/out std:: prefix

// Function prototypes
void displayContent(const string& filename);

int main() {
  string filename;

  cout << "Enter the name of a file: ";
  getline(cin, filename);

  displayContent(filename);

  return 0;
}

void displayContent(const string& filename) {
  ifstream file(filename);
  string line;
  int lineCount = 0;

  if (!file) {
    cout << "ERROR: Invalid Input - Could not open file \"" << filename << "\".\n";
    return;
  }

  cout << "\n --- DISPLAYING FILE ---\n";

  while (getline(file, line) && lineCount < 10) {
    cout << line << endl;
    lineCount++;

    // Pause every 24 lines
    if (lineCount == 24) {
      cout << "\n--- Press ENTER to continue ---";
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      lineCount = 0;
    }
  }

  cout << "\n --- END OF FILE ---\n";
}

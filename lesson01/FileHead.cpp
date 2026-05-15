/*
  Imani Hollie 05/15/2026
  Programming Challenge: File Head Program
  Write a program that asks the user for the name of a file. The program should display
  the first ten lines of the file on the screen (the "head" of the file). If the file has
  fewer than ten lines, the entire file should be displayed, with a message indicating the
  entire file has been displayed.

  NOTE: Using an editor, you should create a simple text file that can be used to test this program.
*/

#include <iostream>  // Allows use of input/output objects (cout, cin)
#include <fstream>   // Allows creation, reading, and writing of files
#include <iomanip>   // Allows use of formatting tools
#include <string>    // Allows use of the string data type
using namespace std; // Allows use of the standard library w/out std:: prefix

// Function prototypes
void displayHead(const string& filename);

int main() {
  // Declare variables
  string filename;

  // Get user input
  cout << "Enter the name of a file: ";
  getline(cin, filename);

  // Call function
  displayHead(filename);

  // End program
  return 0;
}

void displayHead(const string& filename) {
  ifstream file(filename);
  string line;
  int lineCount = 0;

  if (!file) {
    cout << "ERROR: Invalid Input - Could not open file \"" << filename << "\".\n";
    return;
  }

  cout << "\n --- FILE HEADER ---\n";

  while (getline(file, line) && lineCount < 10) {
    cout << line << endl;
    lineCount++;
  }

  // eof() returns true if end of an input stream is encountered
  if (file.eof() && lineCount < 10) {
    cout << "\nThe file had fewer than 10 lines. Entire file displayed.\n";
  }
}

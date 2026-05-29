/*
    Imani Hollie 05/28/2026
    5-Minute Interview: My Information
    Directions: Write your full name followed by the last
    four digits of your cell phone number.
*/

// Header
#include <iostream>   // Provides console input/output
#include <string>     // Enables use of std::string
#include <regex>      // Enables regualr expressions to check text
using namespace std;  // Allows use of standard names without std:: prefix

// Person{} : Person class collects object name and phone
class Person {
  // getName() : Get user input for name
  public string getName() {
    // Declare variable
    string name;
    
    while (true) {
      // Get user input
      cout << "\nEnter Name (-1 to Exit): ";
      getline(cin, name);

      // Check for sentinel
      if (name == "-1") return "-1";

      // Validate input
      if (regex_match(name, regex("[a-zA-Z\\- ]+"))) {
        return name;
      } else {
        cout << "ERROR: Invalid Input - Name must be characters only (a-z or A-Z)\n\n";
      }
    }
  }

  // getPhone() : Get user input for last 4-digit phone number
  public string getPhone() {
    // Declare variable
    string phone;
    
    while (true) {
      // Get user input
      cout << "\nEnter Phone (-1 to Exit): ";
      getline(cin, phone);

      // Check for sentinel
      if (name == "-1") return "-1";

      // Validate input
      if (regex_match(phone, regex("[0-9]{4}"))) {
        return phone;
      } else {
        cout << "ERROR: Invalid Input - Phone must be four digits (0-9)\n\n";
      }
    }
  }
}

// main() : Program execution starts here
int main() {
  // Declare objects
  Person p;

  while (true) {
    // Input & Process
    string name = p.getName();
    if (name == "-1") break;
    string phone = p.getPhone();
    if (phone == "-1") break;

    // Output
    cout << "\nYour name:  " << name << endl;
    cout << "Your phone: " << phone << << endl << endl;
  }

  return 0;      // End program
}

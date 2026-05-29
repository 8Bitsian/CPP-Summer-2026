/*
    Imani Hollie 05/28/2026
    5-Minute Interview: My Information
    Directions: Write your full name followed by the last
    four digits of your cell phone number.
*/

// Header
#include <iostream>   // Provides console input/output
#include <string>     // Enables use of std::string
using namespace std;  // Allows use of standard names without std:: prefix

class Person {
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
      if (regex_match(name, regex("[0-9]+"))) {
        return phone;
      } else {
        cout << "ERROR: Invalid Input - Phone must be four digits only (0-9)\n\n";
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
    cout << "\nYour name: " << name << endl;
    cout << "Your phone: " << phone << << endl << endl;
  }

  return 0;      // End program
}

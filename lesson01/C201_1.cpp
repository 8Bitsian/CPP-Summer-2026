/*
    Imani Hollie 05/28/2026
    5-Minute Interview: My Information
    Directions: Create a file named myInfo.txt and write
    your full name and the last four digits of your phone
    number, then close the file after writing the data.
*/

// HEADER
#include <iostream>     // Provides console input/output
#include <fstream>      // Provides file input/output
#include <string>       // Enables use of std::string
#include <regex>        // Enables regular expressions to check text
using namespace std;    // Enables use of standard names w/out std:: prefix

// CLASSES
// Person{} : Person class collects object name and phone
class Person {
public:
    // getName() : Get user input for full name
    string getName() {
        // Declare variables
        string name;

        while (true) {
            // Get user input
            cout << "Enter Name (-1 to Exit): ";
            getline(cin, name);

            // Check for sentinel (-1)
            if (name == "-1") return "-1";

            // Validate input
            if (regex_match(name, regex("[a-zA-Z\\- ]+"))) {
                return name;
            } else {
                cout << "ERROR: Invalid Input - Name must be characters only (a-z or A-Z)\n\n";
            }
        }
    }

    // getPhone() : Get user input for last four digits of phone number
    string getPhone() {
        // Declare variables
        string phone;

        while (true) {
            // Get user input
            cout << "Enter Phone (-1 to Exit):";
            getline(cin, phone);

            // Check for sentinel (-1)
            if (phone == "-1") return "-1";

            // Validate input
            if (regex_match(phone, regex("[0-9]{4}"))) {
                return phone;
            } else {
                cout << "ERROR: Invalid Input - Phone must be four digits only (0-9)\n\n";
            }
        }
    }
};

// MAIN METHOD : Program execution starts here
int main() {
    // Declare objects
    Person p;

    while (true) {
        // Input/Process
        string name = p.getName();
        if (name == "-1") break;
        string phone = p.getPhone();
        if (phone == "-1") break;

        // Write
        ofstream outFile("myInfo.txt"); // Declare file object "outFile"
        if (outFile.is_open()) {
            outFile << name + " " + phone;
            outFile.close();
            // Output
            cout << "CLEAR: \"myInfo.txt\" file recorded the following...\n\n";
            cout << " Name: " << name << endl;
            cout << "Phone: " << phone << endl << endl;
        } else {
            cout << "ERROR: File Not Found - Unable to open file for writing.\n\n";
        }
    }

    return 0;
}

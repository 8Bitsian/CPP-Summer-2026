/*
    Imani Hollie 05/28/2026
    Lesson 1 Lab: Insert & Replace Text
    Directions: Download the Germany_Brazil.txt file
    and complete the following:
        1) Read the file
        2) Insert your name and the last four digits of
           your phone number at the top of the text
        3) Replace every "Germany" with "Brazil"
        4) Save the new file as your first name and the
           last four digits (e.g. John1234.txt)
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

// FUNCTION PROTOTYPES
void processFiles(string name, string phone);
string getFirstName(string name);
void getOutputFile(const string &filename);
string setOutputFile(string firstName, string phone);
void setHeader(ofstream &outfile, string name, string phone);
string setText(string line);
void modifyFiles(ifstream &infile, ofstream &outfile);

// WRAPPER - processFiles() : Wrapper function to process the input/output files
void processFiles(string name, string phone) {
    // Read "Germany_Brazil.txt" file
    ifstream inFile("Germany_Brazil.txt");

    // Check for "Germany_Brazil.txt" file
    if (!inFile) {   // If fail, print an error message and return to main()
        cout << "ERROR: File Not Found - Unable to open file for reading.\n\n";
        return;
    }

    // Extract first name only (splits at first space)
    string firstName = getFirstName(name);

    // Create output file with first name and last four digits of phone number (e.g., "Imani0123.txt")
    string outFilename = setOutputFile(firstName, phone);
    ofstream outFile(outFilename); // Open for writing

    // Write new header (full name + phone) at the top of the output file
    setHeader(outFile, name, phone);

    // Read the inFile "Germany_Brazil.txt" and modify the outFile "Imani0123.txt" 
    modifyFiles(inFile, outFile);

    // Close both files
    inFile.close();
    outFile.close();

    // Read and Output the outFile "Imani0123.txt"
    getOutputFile(outFilename);
}

// MAIN METHOD - main() : Program execution starts here
int main() {
    // Declare objects
    Person p;

    while (true) {
        // Input/Process
        string name = p.getName();
        if (name == "-1") break;
        string phone = p.getPhone();
        if (phone == "-1") break;

        // Read/Write/Output
        processFiles(name, phone);
    }

    return 0;
}

// HELPER FUNCTIONS (GET & SET)
// getFirstName() : Get first name by getting substring prior first space from the initial user input
string getFirstName(string name) {
    size_t p = name.find(' ');
    return (p==string::npos) ? name : name.substr(0,p);
}

// setOutputFile() : Set the name of the output file to the first name and last four digits (e.g. John1234.txt)
string setOutputFile(string firstName, string phone) {
    string filename = firstName + phone + ".txt";
    ofstream outFile(filename);
    return filename;
}

// setHeader() : Set the header of the output file to the user's full name and last four digits
void setHeader(ofstream &outFile, string name, string phone) {
    outFile << name << endl;
    outFile << phone << endl;
}

// setText() : Set every instance of "Germany" to "Brazil"
string setText(string line) {
    size_t pos = line.find("Germany");
    while (pos != string::npos) {
        line.replace(pos, 7, "Brazil");
        pos = line.find("Germany", pos + 6);
    }
    return line;
}

// modifyFiles() : Reads each line from the inFile, calls setText() and writes to the outFile
void modifyFiles(ifstream &inFile, ofstream &outFile) {
    string line;
    while (getline(inFile, line)) {
        line = setText(line);
        outFile << line << endl;
    }
}

// getOutputFile() : Reopens the outFile for reading and prints the filename, header, and modified body
void getOutputFile(const string &filename) {
    ifstream fin(filename);
    if (!fin) {
        cout << "ERROR: File Not Found - Unable to open file for reading.\n";
        return;
    }

    string line;
    // Output header of output file
    cout << "----- START OF (" << filename << ") -----\n";
    if (getline(fin, line)) cout << line << '\n';
    if (getline(fin, line)) cout << line << "\n";

	 // Output body of output file (and skip first two lines)
    int skip = 0;
    while (skip < 2 && getline(fin, line) && line.empty()) ++skip;
    while (!fin.eof()) {
        if (!line.empty()) cout << line << '\n'; // the first non-blank line we read
        while (getline(fin, line)) cout << line << '\n';
    }

    cout << "----- END OF (" << filename << ") -----\n\n";

    fin.close();
}

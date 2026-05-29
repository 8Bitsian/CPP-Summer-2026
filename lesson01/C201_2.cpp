/*
    Imani Hollie 05/28/2026
    Lab Assignment: Insert Information
    Directions: Read the Germany_Brazil.txt file and put your name
    and last 4 digits of your phone number on the top of the text.
    Replace "Gemrany" to "Brazil" and save the file as your first name
    and the last four digits (ex. Jane1234.txt)
*/

// Header
#include <iostream>  // Allows use of input/output objects (cout, cin)
#include <fstream>   // Allows creation, reading, and writing of files
#include <string>    // Allows use of the string data type
#include <regex>     // Allows use of regualr expressions to check text
using namespace std; // Allows use of the standard library w/out std:: prefix

// Person{} : Get name and last four digit phone number
class Person {
  public:
    string getName() {
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

    string getPhone() {
      // Declare variable
      string phone;
        
      while (true) {
        // Get user input
        cout << "\nEnter Phone (-1 to Exit): ";
        getline(cin, phone);
    
        // Check for sentinel
        if (phone == "-1") return "-1";
    
        // Validate input
        if (regex_match(phone, regex("[0-9]{4}"))) {
          return phone;
        } else {
          cout << "ERROR: Invalid Input - Phone must be four digits (0-9)\n\n";
        }
      }
    }
};

// Function Prototypes
void processFile(string name, string phone);
string getFirstName(string name);
ofstream createOutputFile(string firstName, string phone);
void writeHeader(ofstream &outfile, string name, string phone);
string replaceText(string line);
void copyAndModify(ifstream &infile, ofstream &outfile);

// processFile() : Wrapper function to process the file
void processFile(string name, string phone) {
  // Read file
  ifstream infile("Germany_Brazil.txt");

  // Check for file
  if (!infile) {
    cout << "ERROR: File Not Found - Could not find requested file.\n";
    return;
  }

  // Extract first name only
  string firstName = getFirstName(name);

  // Create output file with first name and phone
  ofstream outfile = setOutputFile(firstName, phone);
  
  // Write new header (name + phone) at top of file
  setHeader(outfile, name, phone);

  // Read and modify file
  copyAndModify(infile, outfile);

  // Close files
  infile.close();
  outfile.close();

  cout << "File created successfully - " << firstName + phone + ".txt\n";
}

// main() : Program execution starts here
int main() {
  // Declare objects
  Person p;

  // Get user input
  string name = p.getName();
  if (name == "-1") return 0;
  string phone = p.getPhone();
  if (phone == "-1") return 0;

  // Process
  processFile(name, phone);

  return 0;
}

// getFirstName() : Get first name from the user input
string getFirstName(string name) {
  return name.substr(0, name.find(" "));
}

// setOutputFile() : Set the new name of the output file
ofstream setOutputFile(string firstName, string phone) {
  ofstream outfile(firstName + phone + ".txt");
  return outfile;
}

// setHeader() : Set the new header of the output file
void setHeader(ofstream &outfile, string name, string phone) {
  outfile << name << endl;
  outfile << phone << endl << endl;
}

// replaceText() : Replace "Germany" with "Brazil"
string replaceText(string line) {
  int pos = line.find("Germany");
  while (pos != string::npos) {
    line.replace(pos, 7, "Brazil");
  }
  return line;
}

// copyAndModify() : Copy and modify the file content
copyAndModify(ifstream & infile, ofstream &outfile) {
  string line;
  while (getline(inline, line)) {
    line = replaceText(line);
    outfile << line << endl;
  }
}

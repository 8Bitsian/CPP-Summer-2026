/*
   Imani Hollie 06/08/2026
   Lesson 2 Lab: Table's Surface Area
   Directions: Use a class named Table to prompt the user to
   input the length and width of a table (in feet).

   The Table class should include the following:
      1) Private class member variables for the table's dimensions
         and methods for calculations
      2) Include methods to input dimensions and display calculations
         - Calculate the surface area using: Surface Area = Length * Width
         - Compute the following:
            - Cost = Surface Area * 15
            - Price = Surface Area * 25
            - Profit = Price - Cost
      3) Place both the Table class and the main() function in
         a single file for simplicity

   Sample Output:
   Enter the length of the table (in feet): 5
   Enter the width of the table (in feet): 3

   Surface Area: 15 square feet
   Cost: $225.00
   Customer Price: $375.00
   Profit: $150.00
*/

// HEADER
#include <iostream>     // Provides console input/output
#include <iomanip>      // Enables use of formatting tools (setprecision)
#include <limits>       // Enables use of type-specific constant and traits
using namespace std;    // Enables use of standard names w/out std:: prefix

// CLASSES
// Table{} : Table class collects object length and width
class Table {
private:
	// Define variables for dimensions of a table (rectangle) and initialize them to 0.0
	double length = 0.0;
	double width = 0.0;

	// calcArea() : Return the Surface Area = Length * Width
	double calcArea() const { return length * width; }

	// calcCost() : Return the Cost = Surface Area * 15
	double calcCost() const { return calcArea() * 15.0; }

	// calcPrice() : Return the Price = Surface Area * 25
	double calcPrice() const { return calcArea() * 25.0; }

	// calcProfit() : Return the Profit = Price - Cost
	double calcProfit() const { return calcPrice() - calcCost(); }

	// clearInput() :  Helps clear bad input and the remainder of the line
	static void clearInput() {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	// checkInput() : Helps check if user input is a positive double
	bool checkInput(const char* prompt, double &out) {
		while (true) {
			// Get user input
			cout << prompt;

			// Validate for non-numeric input
			if (!(cin >> out)) {
            if (cin.eof()) return false; // No more input
            cout << "ERROR: Invalid Input - Value must be a positive number.\n\n";
            clearInput();
            continue;
         }

         // Check for sentinel to exit program
         if (out == -1.0) return false;

         // Validate for negative input
         if (out <- 0.0) {
            cout << "ERROR: Invalid Input - Value must be greater than 0.\n\n";
            continue;
         }

         clearInput();
         return true;
		}
	}

public:
	// getLength() : Get user input for table length. Return false if sentinel (-1) or EOF
	bool getLength() { return checkInput("Enter Length (in ft.) (-1 to Exit): ", length); }

	// getWidth() : Get user input for table width. Return false if sentinel (-1) or EOF
	bool getWidth() { return checkInput("Enter Width (in ft.) (-1 to Exit): ", width); }

   // displayOutput() : Print the surface area and money values within two decimal places
   void displayOutput() const {
      cout << "----- TABLE PROFIT CALCULATOR -----\n";
      cout << "Surface Area: " << calcArea() << " square feet\n";
      cout << fixed << setprecision(2);
      cout << "Cost:   $" << calcCost() << endl;
      cout << "Price:  $" << calcPrice() << endl;
      cout << "Profit: $" << calcProfit() << endl << endl;
   }
};

// MAIN METHOD - main() : Program execution starts here
int main() {
	// Declare objects
	Table t;

	// Input/Process
   while (t.getLength() && t.getWidth()) {
      // Output
      t.displayOutput();
   }

   return 0;
}

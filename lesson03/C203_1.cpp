/*
   Imani Hollie 06/15/2026
   5-Minute Interview: Area of Circles
   Directions: To calculate the area of a circle with radii
   of 1, 10, and 100, write a program that persoms the following:
      1) Create a class called "Circle" with appropriate constructors, getters, and setters
	   2) Use the constructors, getters, and setters in your test code to computer the area of a circle
*/

// HEADER
#include <iostream>     // Provides console input/output
#include <iomanip>      // Enables use of formatting tools (setprecision)
#include <limits>       // Enables use of type-specific constant and traits
using namespace std;    // Enables use of standard names w/out std:: prefix

// CLASSES
// Circle{} : Circle class collects object radius
class Circle {
private:
	// Define variables for dimensions of a circle and initialize them to 0.0
	double radius = 0.0;
	const double PI = 3.14159;

	// calcArea() : Return the Area = PI * radius * radius
	double calcArea() const { return PI * radius * radius; }

	// clearInput() : Helps clear bad input and the remainder of the line
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
         
         // Close input stream and return true
         clearInput();
         return true;
		}
	}

public:
	// getRadius() : Get user input for circle's radius. Return false is sentinel (-1) or EOF
	bool getRadius() { return checkInput("Enter Radius (-1 to Exit): ", radius); }

	// displayOutput() : Print the radius and results of all calculations within two decimal places
   void displayOutput() const {
      cout << "\n----- CIRCLE CALCULATOR -----\n";
      cout << fixed << setprecision(2);
      cout << "Radius: " << radius << " units\n";
      cout << "Area:   " << calcArea() << " units\n\n";
   }
};

// MAIN METHOD - main() : Program execution starts here
int main() {
	// Declare objects
	Circle c;

	// Input/Process
   while (c.getRadius()) {
      // Output
      c.displayOutput();
   }

   return 0;
}

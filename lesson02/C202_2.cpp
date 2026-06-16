/*
   Imani Hollie 06/08/2026
   Lesson 2 Lab: Circle Calculator
   Directions: Use a class named Circle to prompt the user to
   input the radius of the circle.

   The Table class should include the following:
      1) Private class member variables for the circles's dimensions
         - radius: A private member variable to store the circle's radius
         - PI: A private constant initialized to 3.14159
      2) Include methods to input the radius and display calculations
         - Default constructor that initializes the radius to 0.0
         - Setter function to update the radius value
         - Getter function to return the circle's radius
         - Methods to compute and return the following:
            - Area = PI * radius * radius
            - Diameter = radius * 2
            - Circumference = 2 * PI * radius
      3) Place both the Table class and the main() function in
         a single file for simplicity

   Sample Output:
   Radius? 5

   Radius: 5.00
   Area: 78.54 square units
   Diameter: 10.00 units
   Circumference: 31.42 units
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

	// calcArea() : Return the Area = PI * radius * radius
   double calcDiameter() const { return radius * 2; }

   // calcArea() : Return the Area = PI * radius * radius
   double calcCircumference() const { return 2 * PI * radius; }

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

         clearInput();
         return true;
		}
	}

public:
	// getRadius() : Get user input for circle's radius. Return false is sentinel (-1) or EOF
	bool getRadius() { return checkInput("Enter Radius (-1 to Exit): ", radius); }

	// displayOutput() : Print the radius and results of all calculations within two decimal places
   void displayOutput() const {
      cout << "----- CIRCLE CALCULATOR -----\n";
      cout << fixed << setprecision(2);
      cout << "Radius:        " << radius << " units\n";
      cout << "Area:          " << calcArea() << " units\n";
      cout << "Diameter:      " << calcDiameter() << " square units\n";
      cout << "Circumference: " << calcCircumference() << " units\n\n";
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

/*
CSCI 216 Fundamentals of Programming II Spring 2015
Program #2: Complex numbers
Author: Tomas Ochoa
Date Due: 2 February 2015

This file defines is the part of the program that calls the functions in the complex.cpp
file to perform necessary computations.
*/
#include <iostream>
#include "complex.h"
#include <iomanip>

using namespace std;

int main()
{
	// Declare a variable to store the user's choice
	char choice;

	// Have the user decide wether he a complex number with or 
	// without fractions
	do
	{
		cout << "Would you like to compute a complex number with fractions?"  << endl
			 << "Enter y/n: ";
		cin >> choice;

		// A switch case to choose which method to use
		switch (choice)
		{
			// If user decides to compute with fractions:
			case 'y':
			{
				// Clear screen for neatness
				system("CLS");

				//declares three complex number variables
				complexNum a,
						   b,
					       r;

				// Gets the complex numbers and sets to a and b
				cout << "Enter two complex numbers in the form a/c+b/di: ie 2/3-6/7i" << endl
					 << "This form would mean (2/3)+(-6/7)i!"					  << endl;

				cout << "a = ";
				complexRead(a);
				cout << endl;
				cout << "b = ";
				complexRead(b);

				// Clears screen
				system("CLS");

				// Prints user's input
				cout << "Your input:" << endl
					 << "a = ";
				complexPrint(a);

				cout << "b = ";
				complexPrint(b);
				cout << endl;

				// Adds a and b and sets the result to r and prints it
				r = complexAdd(a, b);
				cout << "The sum of a and b is: ";
				complexPrint(r);

				// Subtracts a and b and sets the result to r and prints it
				r = complexSub(a, b);
				cout << "The difference of a and b is: ";
				complexPrint(r);


				// Multiplies a and b and sets the result to r and prints it
				r = complexMul(a, b);
				cout << "The product of a and b is: ";
				complexPrint(r);


				// Divides a and b and sets the result to r and prints it
				r = complexDiv(a, b);
				cout << "The quotient of a and b is: ";
				complexPrint(r);

				// To leave the function after computation is complete
				system("Pause");
				return (0);

			} break;

			// If user decides to compute without fractions:
			case 'n':
			{
				// Clear screen for neatness
				system("CLS");

				// Declares three complex number variables
				simpleComplexNum a,
						         b,
					             r;

				// Gets the complex numbers and sets to a and b
				cout << "Enter two complex numbers in the form a+bi: ie 2-6i" << endl;
				cout << "a = ";
				simpleComplexRead(a);
				cout << endl;
				cout << "b = ";
				simpleComplexRead(b);

				// Clears screen
				system("CLS");

				// Prints user's input
				cout << "Your input:" << endl
					 << "a = ";
				simpleComplexPrint(a);

				cout << endl
					 << "b = ";
				simpleComplexPrint(b);

				cout << endl;

				// Adds a and b and sets the result to r and prints it
				r = simpleComplexAdd(a, b);
				cout << endl 
					 << "The sum of a and b is: ";
				simpleComplexPrint(r);

				// Subtracts a and b and sets the result to r and prints it
				r = simpleComplexSub(a, b);
				cout << endl 
					 << "The difference of a and b is: ";
				simpleComplexPrint(r);


				// Multiplies a and b and sets the result to r and prints it
				r = simpleComplexMul(a, b);
				cout << endl
					 << "The product of a and b is: ";
				simpleComplexPrint(r);


				// Divides a and b and sets the result to r and prints it
				r = simpleComplexDiv(a, b);
				cout << endl
					 << "The quotient of a and b is: ";
				simpleComplexPrint(r);
				cout << endl;

				// To leave main after computation is complete
				system("Pause");
				return (0);

			} break;
		}
	} while (choice != 'y' || 'n');

	return 0;
}

/*
	
--------------------------------OUTPUT-------------------------------

--------------------------WITHOUT FRACTIONS--------------------------

Would you like to compute a complex number with fractions?
Enter y/n: n

*Clears Screen*

Enter two complex numbers in the form a+bi: ie 2-6i
a = 3
+4
i

b = 2
-6
i

*Clears Screen*

Your input:
a = 3+4i
b = 2-6i

The sum of a and b is: 5-2i
The difference of a and b is: 1+10i
The product of a and b is: 30-10i
The quotient of a and b is: -0.45+0.65i
Press any key to continue...
 
----------------------------WITH FRACTIONS----------------------------

Would you like to compute a complex number with fractions?
Enter y/n: y

*Clears Screen*

Enter two complex numbers in the form a/c+b/di: ie 2/3-6/7i
This form would mean (2/3)+(-6/7)i!

a = 3
/
4
+4
/
5
i

b = 2
/
1
-6
/
1
i

*Clears Screen*

Your input:
a = (3/4)+(4/5)i
b = (2/1)+(-6/1)i

The sum of a and b is: (11/4)+(-5.2/1)i
The difference of a and b is: (-1.25/1)+(34/5)i
The product of a and b is: (63/10)+(-2.9/1)i
The quotient of a and b is: (-0.1125/1)+(0.1525/1)i
Press any key to continue...
*/
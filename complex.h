/*
	CSCI 216 Fundamentals of Programming II Spring 2015
	Program #2: Complex numbers
	Author: Tomas Ochoa
	Date Due: 2 February 2015
	
	This header file defines all of the necessary functions and structures
	needed to perform complex arithmetic in this program. 
*/

//defines the headerfile if not already defined
#ifndef complex_cpp
#define complex_cpp

//Structure Definition
struct fraction
{
	double  num,
		    den;
};

//nested structure to compute complex numbers WITH fractions
struct complexNum
{
	char junk,
		 sign,
		 i;

	fraction realNum,
		     imaginaryNum;
};

//structure to compute complex numbers WITHOUT fractions
struct simpleComplexNum
{
	char	junk,
			i;

	double  realNum,
			imaginaryNum;
};
// Definitions of functions that compute complex numbers
// WITH fractions
complexNum complexAdd(complexNum a, complexNum b);
complexNum complexSub(complexNum a, complexNum b);
complexNum complexMul(complexNum a, complexNum b);
complexNum complexDiv(complexNum a, complexNum b);

// Definitions of functions that compute complex numbers 
// WITHOUT fractions
simpleComplexNum simpleComplexAdd(simpleComplexNum a, simpleComplexNum b);
simpleComplexNum simpleComplexSub(simpleComplexNum a, simpleComplexNum b);
simpleComplexNum simpleComplexMul(simpleComplexNum a, simpleComplexNum b);
simpleComplexNum simpleComplexDiv(simpleComplexNum a, simpleComplexNum b);

//Definitions of functions that read and display complex numbers WITH fractions
void complexPrint(complexNum a);
complexNum complexRead(complexNum &a);

//Definistion of functions that read and display complex numbers WITHOUT fractions
void simpleComplexPrint(simpleComplexNum a);
simpleComplexNum simpleComplexRead(simpleComplexNum &a);

//Definition of a function to calculate the greastes common denominator
int gcd(int, int);

//end if
#endif
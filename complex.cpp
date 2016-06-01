/*
CSCI 216 Fundamentals of Programming II Spring 2015
Program #2: Complex numbers
Author: Tomas Ochoa
Date Due: 2 February 2015

This file contains all the functions used in the program to compute the 
addition, subtraction, multiplication and division of complex numbers
*/

#include <iomanip>
#include <iostream>
#include "complex.h"

using namespace std;

//******************** Functions that compute complex numbers WITH fractions*********************

// ADD FUNCTION
complexNum complexAdd(complexNum x, complexNum y)
{
	complexNum result;

	result.realNum.num = (x.realNum.num * y.realNum.den) + (y.realNum.num * x.realNum.den);
	result.realNum.den = (x.realNum.den * y.realNum.den);

	result.imaginaryNum.num = (x.imaginaryNum.num * y.imaginaryNum.den) + (y.imaginaryNum.num * x.imaginaryNum.den);
	result.imaginaryNum.den = (x.imaginaryNum.den * y.imaginaryNum.den);

	result.junk = '/';
	result.i = 'i';

	int realTmp,
		imaginaryTmp;

	realTmp = gcd(result.realNum.num, result.realNum.den);
	result.realNum.num /= realTmp;
	result.realNum.den /= realTmp;

	imaginaryTmp = gcd(result.imaginaryNum.num, result.imaginaryNum.den);
	result.imaginaryNum.num /= imaginaryTmp;
	result.imaginaryNum.den /= imaginaryTmp;

	return result;
}


// SUBTRACTION FUNCTION
complexNum complexSub(complexNum x, complexNum y)
{
	complexNum result;

	result.realNum.num = (x.realNum.num * y.realNum.den) - (y.realNum.num * x.realNum.den);
	result.realNum.den = (x.realNum.den * y.realNum.den);

	result.imaginaryNum.num = (x.imaginaryNum.num * y.imaginaryNum.den) - (y.imaginaryNum.num * x.imaginaryNum.den);
	result.imaginaryNum.den = (x.imaginaryNum.den * y.imaginaryNum.den);

	result.junk = '/';
	result.i = 'i';

	int realTmp,
		imaginaryTmp;

	realTmp = gcd(result.realNum.num, result.realNum.den);
	result.realNum.num /= realTmp;
	result.realNum.den /= realTmp;

	imaginaryTmp = gcd(result.imaginaryNum.num, result.imaginaryNum.den);
	result.imaginaryNum.num /= imaginaryTmp;
	result.imaginaryNum.den /= imaginaryTmp;

	return result;
}

// MULTIPLICATION FUNCTION
complexNum complexMul(complexNum x, complexNum y)
{

	//temporary fraction values to calculate the insides of (ac-bd)+(bc+ad)i
	fraction ac,
		bd,
		bc,
		ad;

	fraction acMINUSbd,
		bcPLUSad;

	// Calculate ac
	ac.num = (x.realNum.num * y.realNum.num);
	ac.den = (x.realNum.den * y.realNum.den);

	// calculate bd
	bd.num = (x.imaginaryNum.num * y.imaginaryNum.num);
	bd.den = (x.imaginaryNum.den * y.imaginaryNum.den);

	//calculate bc
	bc.num = (x.imaginaryNum.num * y.realNum.num);
	bc.den = (x.imaginaryNum.den * y.realNum.den);

	//calculate ad
	ad.num = (x.realNum.num * y.imaginaryNum.num);
	ad.den = (x.realNum.den * y.imaginaryNum.den);

	// Continue on calculating the inside fractions

	acMINUSbd.num = (ac.num * bd.den) - (bd.num * ac.den);
	acMINUSbd.den = (ac.den * bd.den);

	bcPLUSad.num = (bc.num * ad.den) + (ad.num * bc.den);
	bcPLUSad.den = (bc.den * ad.den);

	//calculate the final result of the prouct of the two complex numbers
	complexNum	result;

	result.realNum.num = acMINUSbd.num;
	result.realNum.den = acMINUSbd.den;

	result.imaginaryNum.num = bcPLUSad.num;
	result.imaginaryNum.den = bcPLUSad.den;

	result.junk = '/';
	result.i = 'i';

	int realTmp,
		imaginaryTmp;

	realTmp = gcd(result.realNum.num, result.realNum.den);
	result.realNum.num /= realTmp;
	result.realNum.den /= realTmp;

	imaginaryTmp = gcd(result.imaginaryNum.num, result.imaginaryNum.den);
	result.imaginaryNum.num /= imaginaryTmp;
	result.imaginaryNum.den /= imaginaryTmp;

	return result;
}

// DIVISION FUNCTION
complexNum complexDiv(complexNum x, complexNum y)
{
	//temporary fraction values to calculate the insides of (ac-bd)+(bc+ad)i
	fraction ac,
		bd,
		bc,
		ad,
		c2,
		d2;

	fraction acPLUSbd,
		c2PLUSd2,
		bcMINUSad;

	// Calculate ac
	ac.num = (x.realNum.num * y.realNum.num);
	ac.den = (x.realNum.den * y.realNum.den);

	// calculate bd
	bd.num = (x.imaginaryNum.num * y.imaginaryNum.num);
	bd.den = (x.imaginaryNum.den * y.imaginaryNum.den);

	//calculate bc
	bc.num = (x.imaginaryNum.num * y.realNum.num);
	bc.den = (x.imaginaryNum.den * y.realNum.den);

	//calculate ad
	ad.num = (x.realNum.num * y.imaginaryNum.num);
	ad.den = (x.realNum.den * y.imaginaryNum.den);

	//calculate c^2
	c2.num = (y.realNum.num * y.realNum.num);
	c2.den = (y.realNum.den * y.realNum.den);

	//calculate d^2
	d2.num = (y.imaginaryNum.num * y.imaginaryNum.num);
	d2.den = (y.imaginaryNum.den * y.imaginaryNum.den);

	// Continue on calculating the inside fractions
	acPLUSbd.num = (ac.num * bd.den) + (bd.num * bd.den);
	acPLUSbd.den = (ac.den * bd.den);

	bcMINUSad.num = (bc.num * ad.den) - (ad.num * bc.den);
	bcMINUSad.den = (bc.den * ad.den);

	c2PLUSd2.num = ((c2.num * d2.den) + (d2.num	* c2.den));
	c2PLUSd2.den = (c2.den * d2.den);

	//calculate the final result of the quotient of two 
	//complex numbers with fractions

	complexNum	result;

	result.realNum.num = acPLUSbd.num * c2PLUSd2.den;
	result.realNum.den = acPLUSbd.den * c2PLUSd2.num;

	result.imaginaryNum.num = (bcMINUSad.num * c2PLUSd2.den);
	result.imaginaryNum.den = (bcMINUSad.den * c2PLUSd2.num);

	result.junk = '/';
	result.i = 'i';

	int realTmp,
		imaginaryTmp;

	realTmp = gcd(result.realNum.num, result.realNum.den);
	result.realNum.num /= realTmp;
	result.realNum.den /= realTmp;

	imaginaryTmp = gcd(result.imaginaryNum.num, result.imaginaryNum.den);
	result.imaginaryNum.num /= realTmp;
	result.imaginaryNum.den /= realTmp;

	return result;
}

// PRINT FUNCTION
void complexPrint(complexNum z)
{
	//since we use parenthesis notation it doesnt matter if sign stays as + because 
	//the negatives will still be in the paranthesis
	z.sign = '+';
	cout << "(" << z.realNum.num << z.junk << z.realNum.den << ")" << z.sign << "(" << z.imaginaryNum.num << z.junk << z.imaginaryNum.den << ")" << z.i << endl;
	return;
}

// READ FUNCTION 
complexNum complexRead(complexNum &z)
{
	cin >> z.realNum.num;
	cin >> z.junk;
	cin >> z.realNum.den;
	//cin >> z.sign;
	cin >> z.imaginaryNum.num;
	cin >> z.junk;
	cin >> z.imaginaryNum.den;
	cin >> z.i;

	return z;
}

//******************** Functions that compute complex numbers WITHOUT fractions *********************

// SIMPLE ADDITION FUNCTION
simpleComplexNum simpleComplexAdd(simpleComplexNum x, simpleComplexNum y)
{
	simpleComplexNum result;

	result.realNum = (x.realNum + y.realNum);
	result.imaginaryNum = (x.imaginaryNum + y.imaginaryNum);
	result.i = 'i';

	return result;
}

// SIMPLE SUNTRACTION FUNCTION
simpleComplexNum simpleComplexSub(simpleComplexNum x, simpleComplexNum y)
{
	simpleComplexNum result;

	result.realNum = (x.realNum - y.realNum);
	result.imaginaryNum = (x.imaginaryNum - y.imaginaryNum);
	result.i = 'i';

	return result;
}

// SIMPLE MULTIPLACTION FUNCTION
simpleComplexNum simpleComplexMul(simpleComplexNum x, simpleComplexNum y)
{
	simpleComplexNum result;

	result.realNum = ((x.realNum * y.realNum) - (x.imaginaryNum * y.imaginaryNum));
	result.imaginaryNum = ((x.imaginaryNum * y.realNum) + (x.realNum * y.imaginaryNum));
	result.i = 'i';

	return result;
}

// SIMPLE DIVISION FUNCTION
simpleComplexNum simpleComplexDiv(simpleComplexNum x, simpleComplexNum y)
{
	simpleComplexNum result;

	result.realNum = ((x.realNum * y.realNum) + (x.imaginaryNum * y.imaginaryNum)) / ((y.realNum * y.realNum) + (y.imaginaryNum * y.imaginaryNum));
	result.imaginaryNum = ((x.imaginaryNum * y.realNum) - (x.realNum * y.imaginaryNum)) / ((y.realNum * y.realNum) + (y.imaginaryNum * y.imaginaryNum));
	result.i = 'i';

	return result;
}

// SIMPLE PRINT FUNCTIOn
void simpleComplexPrint(simpleComplexNum z)
{
	if (z.imaginaryNum >= 0)
	{
		z.junk = '+';
		cout << z.realNum << z.junk << z.imaginaryNum << z.i;
	}
	else
		cout << z.realNum << z.imaginaryNum << z.i;
	return;
}

// SIMPLE READ FUNCTION
simpleComplexNum simpleComplexRead(simpleComplexNum &z)
{
	cin >> z.realNum;
	cin >> z.imaginaryNum;
	cin >> z.i;

	return z;
}

//******************** Greatest common denominator function ************************

// GREATEST COMMON DENOMINATOR FUNCTION
int gcd(int x, int y)
{
	int rem;

	if (y == 0)
	{
		cerr << "divisr = 0!" << endl;
		exit(10);
	}

	rem = x % y;
	while (rem > 0)
	{
		x = y;
		y = rem;
		rem = x % y;
	}
	return y;
}

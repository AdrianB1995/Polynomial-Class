//Adrian Borrego Assignment 4: COP3331
#include <iostream>
#include "polynomial.h"

using namespace std;

int main()
{
	Polynomial a, b, c;
	//Setting terms for each Polynomial (A,B,C)
	cout << "Set terms for polynomial A: \n";
	a.setTerms();
	cout << "\nSet terms for polynomial B: \n";
	b.setTerms();
	cout << "\nSet terms for polynomail C: \n";
	c.setTerms();
	
	//Testing set, get functions on Polynomial A
	cout << "\nSetting coefficient one at term one.\n";
	a.setCoefficient(1, 1);
	cout << "Setting exponent one at term one.\n";
	a.setExponent(1, 1);
	cout << "\nCoefficient in A at term [1]: " << a.getCoefficient(1);
	cout << "\nExponent in A at term [1]: " << a.getExponent(1) << endl;
	
	//Polynomials before operations.
	cout << "\n1st Polynomial: \n";
	a.printPolynomial();
	cout << "\n2nd Polynomial: \n";
	b.printPolynomial();
	cout << "\n3rd Polynomial: \n";
	c.printPolynomial();
	
	//Add two Polynomials using + , += operators.
	cout << "\nPolynomial A + B: \n";
	a = a + b;
	a.printPolynomial();
	cout << "\nPolynomial B += C: \n";
	b += c;
	b.printPolynomial();
	
	//Subtract two Polynomials using -, -= operators.
	cout << "\nPolynomial A - B: \n";
	a = a - b;
	a.printPolynomial();
	cout << "\nPolynomial B -= C: \n";
	b -= c;
	c.printPolynomial();
	
	//Assigning Polynomial A to B using = operator.
	cout << "\nPolynomial A = B: \n";
	cout << "\nPolynomial A: \n";
	a.printPolynomial();
	cout << "\nPolynomial B: \n";
	b.printPolynomial();
	cout << "\nA = B: \n";
	a = b;
	a.printPolynomial();
	
	//Multiply two Polynomial using *, *= operators.
	cout << "\nPolynomial A * B: \n";
	a = a * b;
	a.printPolynomial();
	cout << "\nPolynomial B *= C: \n";
	b *= c;
	b.printPolynomial();
	
	return 0;
}


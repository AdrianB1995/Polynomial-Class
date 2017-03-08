//Adrian Borrego Assignment 4: COP3331
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
using namespace std;

class Polynomial {
	private:
		int numberOfTerms;
		int coefficient [100];
		int exponent [100];
	
	public:
		Polynomial();
		~Polynomial(void);
		void setTerms(); //Set Polynomial terms.
		
		void setCoefficient(int, int); //Set certain term's coefficient.
		void setExponent(int, int); //Set certain term's exponent.
		
		int getCoefficient(int); //Get term's coefficient.
		int getExponent(int); //Get term's exponent.
		
		void printPolynomial(); //Print all Polynomial terms.
		
		//Overloaded Operators
		Polynomial operator+(const Polynomial& ) const;
		Polynomial operator-(const Polynomial& ) const;
		const Polynomial operator=(const Polynomial& );
		Polynomial operator*(const Polynomial& );
		Polynomial operator+=(const Polynomial& );
		Polynomial operator-=(const Polynomial& );
		Polynomial operator*=(const Polynomial& );

};

#endif
//Adrian Borrego Assignment 4: COP3331
#include <iostream>
#include <iomanip>
#include "polynomial.h"

using namespace std;

//Constructor.
Polynomial::Polynomial()
{
	for(int i = 0; i < 100; i++)
	{
		coefficient[i] = 0;
		exponent[i] = 0;
	}
	
	numberOfTerms = 0;
}

//Destructor.
Polynomial::~Polynomial(void)
{
	
}

//Set terms for Polynomial objects.
void Polynomial::setTerms()
{
	bool test = false;
	int coe, exp, term;
	cout << "\nEnter number of terms: ";
	cin >> numberOfTerms;
	//Get terms from user using for loop.
	for(int i = 1; i <= numberOfTerms; i++)
	{
		cout << "Enter coefficient: ";
		cin >> coe;
		cout << "Enter exponent: ";
		cin >> exp;
		
		if(coe != 0)
		{	//If exponents are zero they are forced to be the 1st element of the array.
			if( exp == 0)
			{
				coefficient[0] += coe;
				continue;
			}
			
			for(term = 1; (term < 100) && (coefficient[term] != 0); term++)
				//If user exponent equals term exponent, coefficient at term is added to user coefficient, existing exponent is updated.
				if( exp == exponent[term])
				{
					coefficient[term] += coe;
					exponent[term] = exp;
					test = true;
				}
			if( !test )
			{
				coefficient[term] += coe;
				exponent [term] = exp;
			}
	    }
	}	
}

//Set specific term's coefficient.
void Polynomial::setCoefficient(int term, int coe)
{
	if(coefficient[term] == 0)
	{	
		cout << "\nNo term at this location, set fail. ";
	}
	else
	{
		coefficient[term] = coe;
	}	
}

//Set specific term's exponent.
void Polynomial::setExponent(int term, int exp)
{
	if(exponent[term] == 0)
	{	
		cout << "\nNo term at this location, set fail. ";
	}	
	else
	{
		exponent[term] = exp;
	}
}

//Get specific term's coefficient.
int Polynomial::getCoefficient(int term)
{
	return coefficient[term];
}

//Get specific term's exponent.
int Polynomial::getExponent(int term)
{
	return exponent[term];
}

//Print each term of Polynomial.
void Polynomial::printPolynomial()
{
	int start;
	bool test = false;
	//Output constants at index zero.
	if( coefficient[0] )
	{
		cout << coefficient[0];
		start = 1;
		test = true; //One term exists.
	}
	else
	{	//Constants at index one.
		if(coefficient[1])
		{
			cout << coefficient[1] << 'x';
			if((exponent[1] != 0) && (exponent[1] != 1))
			{
				cout << '^' << exponent[1];
			}	
			test = true; //One term exists.
		}
		start = 2;
	}	
	//Print out remaining terms of the array.
	for(int i = start; i < 100; i++)
	{
		if(coefficient[i] != 0)
		{
			cout << showpos << coefficient[i] << noshowpos << 'x';
			
			if((exponent[i] != 0) && (exponent[i] != 1))
			{
				cout << "^" << exponent[i];
				test = true; //One term exists.
			}
		}
	}
	if(!test) //If no term exists in array.
	{
		cout << '0' << endl;
	}
}

Polynomial Polynomial::operator+(const Polynomial& poly) const
{
	Polynomial temp;
	bool expExist;
	int i;
	
	temp.coefficient[0] = coefficient[0] + poly.coefficient[0];
	//Process elements of Polynomial into temp instance of Polynomial.
	for(i = 1; (i < 100) && (poly.exponent[i] != 0); i++)
	{
		temp.coefficient[i] = poly.coefficient[i];
		temp.exponent[i] = poly.exponent[i];
	}
	
	for(int a = 1; a < 100; a++)
	{	//Condition for no exponent existing.
		expExist = false;
		for(int b = 1; (b < 100) && (!expExist); b++)
			
			if(exponent[a] == poly.exponent[b])
			{
				temp.coefficient[b] += coefficient[a];
				expExist = true; //Exponent exists.
			}
		//If exponent did not exist.
		if(!expExist)
		{
			temp.exponent[i] = exponent[a];
			temp.coefficient[i] += coefficient [a];
			i++;
		}			
	}
	return temp;
}

const Polynomial Polynomial::operator=(const Polynomial& poly)
{
	//Copy Polynomial's exponent and coefficient.
	exponent[0] = poly.exponent[0];
	coefficient[0] = poly.coefficient[0];
	//For loop to process all available terms.
	for(int i = 1; (i < 100); i++)
	{
		if(poly.exponent[i] != 0)
		{
			exponent[i] = poly.exponent[i];
			coefficient[i] = poly.coefficient[i];
		}
		else
		{
			if(exponent[i] == 0)
				break;
			
			exponent[i] = 0;
			coefficient[i] = 0;
		}
	}
	return *this;
}

Polynomial Polynomial::operator-(const Polynomial& poly) const
{
	Polynomial temp;
	bool expExist;
	int i;
	
	temp.coefficient[0] = coefficient[0] - poly.coefficient[0];
	//Process elements of Polynomial into temp instance of Polynomial.
	for(i = 1; (i < 100) && (poly.exponent[i] != 0); i++)
	{
		temp.coefficient[i] = poly.coefficient[i];
		temp.exponent[i] = poly.exponent[i];
	}
	
	for(int a = 1; a < 100; a++)
	{	//Condition for no exponent existing.
		expExist = false;
		for(int b = 1; (b < 100) && (!expExist); b++)
			
			if(exponent[a] == poly.exponent[b])
			{
				temp.coefficient[b] -= coefficient[a];
				expExist = true; //Exponent exists.
			}
		//If exponent did not exist.
		if(!expExist)
		{
			temp.exponent[i] = exponent[a];
			temp.coefficient[i] -= coefficient [a];
			i++;
		}			
	}
	return temp;
}

Polynomial Polynomial::operator*(const Polynomial& poly)
{
	Polynomial temp;
	int i = 1;
	
	for(int x = 0; (x < 100) && (x == 0 || coefficient[x] != 0); x++)
	{		
		for(int y = 0; (y < 100) && (y == 0 || poly.coefficient[y] != 0); y++)
		{	
			if(coefficient[x] * poly.coefficient[y])
			{	
				if((exponent[x] == 0) && (poly.exponent[y] == 0))
				{	
					temp.coefficient[0] += coefficient[x] * poly.coefficient[y];
				}	
				else
				{
					temp.coefficient[i] = coefficient[x] * poly.coefficient[y];
					temp.exponent[i] = exponent[x] + poly.exponent[y];
					i++;
				}
			}
		}
	}	
	return temp;			
}

Polynomial Polynomial::operator+=(const Polynomial& poly)
{
	*this = *this + poly;
	return *this;
}

Polynomial Polynomial::operator-=(const Polynomial& poly)
{
	*this = *this - poly;
	return *this;
}

Polynomial Polynomial::operator*=(const Polynomial& poly)
{
	*this = *this + poly;
	return *this;
}


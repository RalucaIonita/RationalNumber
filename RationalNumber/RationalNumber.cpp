
#include "pch.h"
#include<fstream>
#include "RationalNumber.hpp"

#include<string>


//Constructors
RationalNumber::RationalNumber()
{
	m_numerator = 0;
	m_denominator = 1;
}

RationalNumber::RationalNumber(int numerator, int denominator)
{
	m_numerator = numerator;
	m_denominator = denominator;
	CanonicalForm();

	if (m_denominator == 0)
		throw("Denominator cannot be 0.");
}

RationalNumber::RationalNumber(const RationalNumber& x)
{
	m_numerator = x.m_numerator;
	m_denominator = x.m_denominator;
} 




//Destructor


/*RationalNumber*/ RationalNumber::~RationalNumber()
{
	//tba
}





//Setters


void RationalNumber::SetRationalValue(RationalNumber x)
{
	x.CanonicalForm();
	m_denominator = x.m_denominator;
	m_numerator = x.m_numerator;
	//return *this;
}

void RationalNumber::SetNumeratorValue(int x)
{
	m_numerator = x;
	//CanonicalForm();
	//return *this;
}

void RationalNumber::SetDenominatorValue(int x)
{
	m_denominator = x;
	//CanonicalForm();
	//return *this;
}




//Getters


int RationalNumber::GetNumeratorValue()
{
	return m_numerator;
}

int RationalNumber::GetDenominatorValue()
{
	return m_denominator;
}



//Unary operators
RationalNumber operator+(RationalNumber x)
{
	return x;
}

RationalNumber operator-(RationalNumber x)
{
	x.m_numerator = (-1) * x.m_numerator;
	return x;
}


//------------------------------------this block of code needs rework-------------------------------------------------------//

//Attribution operators


	// +=


RationalNumber operator+=(RationalNumber x, RationalNumber y)
{
	x.m_numerator = x.m_numerator * y.m_denominator + y.m_numerator*x.m_denominator;
	x.m_denominator = x.m_denominator * y.m_denominator;
	x.CanonicalForm();
	return x;
}

RationalNumber operator+=(RationalNumber x, int y)
{
	x.m_numerator = x.m_numerator + y * x.m_denominator;
	x.CanonicalForm();
	return x;
}


// -=


RationalNumber operator-=(RationalNumber x, RationalNumber y)
{
	x.m_numerator = x.m_numerator * y.m_denominator - y.m_numerator*x.m_denominator;
	x.m_denominator = x.m_denominator * y.m_denominator;
	x.CanonicalForm();
	return x;
}

RationalNumber operator-=(RationalNumber x, int y)
{
	x.m_numerator = x.m_numerator + y * x.m_denominator;
	x.CanonicalForm();
	return x;
}


// *=


RationalNumber operator*=(RationalNumber x, RationalNumber y)
{
	x.m_numerator = x.m_numerator * y.m_numerator;
	x.m_denominator = x.m_denominator * y.m_denominator;
	x.CanonicalForm();
	return x;
}

RationalNumber operator*=(RationalNumber x, int y)
{
	x.m_numerator = x.m_numerator * y;
	x.CanonicalForm();
	return x;
}


// /=


RationalNumber operator/=(RationalNumber x, RationalNumber y)
{
	x.m_numerator = x.m_numerator * y.m_denominator;
	x.m_denominator = x.m_denominator * y.m_numerator;
	x.CanonicalForm();
	return x;
}

RationalNumber operator/=(RationalNumber x, int y)
{
	x.m_numerator = x.m_numerator * y;
	x.CanonicalForm();
	return x;
}

//------------------------------------------------------------------------------------------------------------//


//Arithmentic operators


	// +


RationalNumber operator+(RationalNumber x, RationalNumber y)
{
 	RationalNumber result;
	result.m_numerator = x.m_numerator*y.m_denominator + y.m_numerator*x.m_denominator;
	result.m_denominator = x.m_denominator*y.m_denominator;
	result.CanonicalForm();
	return result;
}


RationalNumber operator+(RationalNumber x, int y)
{
	RationalNumber result;
	result.m_numerator = x.m_numerator + y * x.m_denominator;
	result.m_denominator = x.m_denominator;
	result.CanonicalForm();
	return result;
}


RationalNumber operator+(int x, RationalNumber y)
{
	RationalNumber result;
	result.m_numerator = x * y.m_denominator + y.m_numerator;
	result.m_denominator = y.m_denominator;
	result.CanonicalForm();
	return result;
}


// -


RationalNumber operator-(RationalNumber x, RationalNumber y)
{
	RationalNumber result;
	result.m_numerator = x.m_numerator*y.m_denominator - y.m_numerator*x.m_denominator;
	result.m_denominator = x.m_denominator*y.m_denominator;
	result.CanonicalForm();
	return result;
}



RationalNumber operator-(RationalNumber x, int y)
{
	RationalNumber result;
	result.m_numerator = x.m_numerator - y * x.m_denominator;
	result.m_denominator = x.m_denominator;
	result.CanonicalForm();
	return result;
}



RationalNumber operator-(int x, RationalNumber y)
{
	RationalNumber result;
	result.m_numerator = x * y.m_denominator - y.m_numerator;
	result.m_denominator = y.m_denominator;
	result.CanonicalForm();
	return result;
}


// *


RationalNumber operator*(RationalNumber x, RationalNumber y)
{
	RationalNumber result;
	result.m_numerator = x.m_numerator*y.m_numerator;
	result.m_denominator = x.m_denominator*y.m_denominator;
	result.CanonicalForm();
	return result;
}

RationalNumber operator*(RationalNumber x, int y)
{
	RationalNumber result;
	result.m_numerator = x.m_numerator * y;
	result.m_denominator = x.m_denominator;
	result.CanonicalForm();
	return result;
}


RationalNumber operator*(int x, RationalNumber y)
{
	RationalNumber result;
	result.m_numerator = x * y.m_numerator;
	result.m_denominator = y.m_denominator;
	result.CanonicalForm();
	return result;
}


// /


RationalNumber operator/(RationalNumber x, RationalNumber y)
{
	RationalNumber result;
	result.m_numerator = x.m_numerator*y.m_denominator;
	result.m_denominator = x.m_denominator*y.m_numerator;
	result.CanonicalForm();
	return result;
}


RationalNumber operator/(RationalNumber x, int y)
{
	RationalNumber result;
	result.m_numerator = x.m_numerator;
	result.m_denominator = x.m_denominator*y;
	result.CanonicalForm();
	return result;
}


RationalNumber operator/(int x, RationalNumber y)
{
	RationalNumber result;
	result.m_numerator = x*y.m_denominator;
	result.m_denominator = y.m_numerator;
	result.CanonicalForm();
	return result;
}


// ^


RationalNumber operator^(RationalNumber x, int y)
{
	RationalNumber result;
	int c = 1, a = x.m_numerator, b = x.m_denominator;
	if (y == 0)
	{
		result.m_denominator = 1;
		result.m_numerator = 1;

	}
	else
	{
		while (c != y)
		{
			x.m_numerator = x.m_numerator * a;
			x.m_denominator = x.m_denominator * b;
			c++;
		}
		result.SetRationalValue(x);
		return result;
	}
}



//Relational operators


	//==


bool operator==(RationalNumber x, RationalNumber y)
{
	if (x.m_numerator*y.m_denominator == x.m_denominator * y.m_denominator)
		return true;
	else
		return false;

}

bool operator==(RationalNumber x, int y)
{
	if (x.m_numerator == x.m_denominator * y)
		return true;
	else
		return false;

}

bool operator==(int x, RationalNumber y)
{
	if (x*y.m_denominator == y.m_denominator)
		return true;
	else
		return false;
}


	//!=


bool operator!=(RationalNumber x, RationalNumber y)
{
	if (x.m_numerator*y.m_denominator != x.m_denominator * y.m_denominator)
		return true;
	else
		return false;

}

bool operator!=(RationalNumber x, int y)
{
	if (x.m_numerator != x.m_denominator * y)
		return true;
	else
		return false;

}

bool operator!=(int x, RationalNumber y)
{
	if (x*y.m_denominator != y.m_denominator)
		return true;
	else
		return false;
}


	//>


bool operator>(RationalNumber x, RationalNumber y)
{
	if (x.m_numerator*y.m_denominator > x.m_denominator * y.m_denominator)
		return true;
	else
		return false;

}

bool operator>(RationalNumber x, int y)
{
	if (x.m_numerator > x.m_denominator * y)
		return true;
	else
		return false;

}

bool operator>(int x, RationalNumber y)
{
	if (x*y.m_denominator > y.m_denominator)
		return true;
	else
		return false;
}


	//>=


bool operator>=(RationalNumber x, RationalNumber y)
{
	if (x.m_numerator*y.m_denominator >= x.m_denominator * y.m_denominator)
		return true;
	else
		return false;

}

bool operator>=(RationalNumber x, int y)
{
	if (x.m_numerator >= x.m_denominator * y)
		return true;
	else
		return false;

}

bool operator>=(int x, RationalNumber y)
{
	if (x*y.m_denominator >= y.m_denominator)
		return true;
	else
		return false;
}


	//<


bool operator<(RationalNumber x, RationalNumber y)
{
	if (x.m_numerator*y.m_denominator < x.m_denominator * y.m_denominator)
		return true;
	else
		return false;

}

bool operator<(RationalNumber x, int y)
{
	if (x.m_numerator == x.m_denominator * y)
		return true;
	else
		return false;

}

bool operator<(int x, RationalNumber y)
{
	if (x*y.m_denominator == y.m_denominator)
		return true;
	else
		return false;
}


	//<=


bool operator<=(RationalNumber x, RationalNumber y)
{
	if (x.m_numerator*y.m_denominator <= x.m_denominator * y.m_denominator)
		return true;
	else
		return false;

}

bool operator<=(RationalNumber x, int y)
{
	if (x.m_numerator <= x.m_denominator * y)
		return true;
	else
		return false;

}

bool operator<=(int x, RationalNumber y)
{
	if (x*y.m_denominator <= y.m_denominator)
		return true;
	else
		return false;
}





//Reading and writing operators


	//console


		//>>



std::istream& operator>>(std::istream& in, RationalNumber& x)
{
	in >> x.m_numerator>> x.m_denominator;
	x.CanonicalForm();
	return in;
}


		//<<


std::ostream& operator<<(std::ostream& out, RationalNumber& x)
{
	x.CanonicalForm();
	if (x.m_denominator == 1)
		out << x.m_numerator;
	else
		out << x.m_numerator << "/" << x.m_denominator;
	return out;
}

//-------------------------------------------this block of code doesn't work----------------------------------------------//
	//file


		//>>


std::ifstream& operator>>(std::ifstream& infile, RationalNumber& x)
{
	infile >> x.m_numerator;
//	infile.ignore (1024, "/");
	infile>> x.m_denominator;
	x.CanonicalForm();
	return infile;
}


//--------------------------------------------------------------------------------------------------------------------------//


//<<


std::ofstream& operator<<(std::ofstream& outfile, RationalNumber& x)
{
	//outfile.open("*.txt");
	x.CanonicalForm();
	outfile << x.m_numerator << "/" << x.m_denominator;
	//outfile.close();
	return outfile;
}



//To string

std::string RationalNumber::ToString(RationalNumber& x)
{
	std::string s;
	if (x.m_denominator == 1)
		s=std::to_string(x.m_numerator);
	else
	{
		s = std::to_string(x.m_numerator) + "/" + std::to_string(x.m_denominator);
	}
	return s;
}




//Conversion operators

RationalNumber::operator double() const
{
	return (double) m_numerator / m_denominator;
}

RationalNumber::operator int() const
{
	return (int) m_numerator / m_denominator;
}


RationalNumber::operator std::string()
{
	return ToString(*this);
}


//Canonical form


RationalNumber RationalNumber::CanonicalForm()
{
	int a, b;
	int ok = 1;
	a = m_numerator;
	b = m_denominator;
	if (a == 0)
	{
		m_denominator = 1;
		return *this;
	}
	if (a < 0)
		a = a * (-1);
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	if (m_numerator < 0)
	{
		m_numerator *= -1;
		m_numerator /= a;
		m_numerator *= -1;
	}
	else
		m_numerator = m_numerator / a;
	m_denominator = m_denominator / a;


	return *this;

}

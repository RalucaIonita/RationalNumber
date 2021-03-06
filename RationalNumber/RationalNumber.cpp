
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

RationalNumber::RationalNumber(const int& numerator, const int& denominator)
{
	m_numerator = numerator;
	m_denominator = denominator;
	CanonicalForm();

}

RationalNumber::RationalNumber(const RationalNumber& x)
{
	m_numerator = x.m_numerator;
	m_denominator = x.m_denominator;
} 




//Destructor


RationalNumber::~RationalNumber() {}





//Setters


void RationalNumber::SetRationalValue(RationalNumber& x)
{
	x.CanonicalForm();
	m_denominator = x.m_denominator;
	m_numerator = x.m_numerator;
}

void RationalNumber::SetNumeratorValue(const int& x)
{
	m_numerator = x;
}

void RationalNumber::SetDenominatorValue(const int& x)
{
		m_denominator = x;
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

RationalNumber operator-(RationalNumber& x)
{
	x.m_numerator = (-1) * x.m_numerator;
	return x;
}



//Attribution operators


	// +=


RationalNumber operator+=(RationalNumber& x, const RationalNumber& y)
{
	x.m_numerator = x.m_numerator * y.m_denominator + y.m_numerator*x.m_denominator;
	x.m_denominator = x.m_denominator * y.m_denominator;
	x.CanonicalForm();
	return x;
}

RationalNumber operator+=(RationalNumber& x, const int& y)
{
	x.m_numerator = x.m_numerator + y * x.m_denominator;
	x.CanonicalForm();
	return x;
}


// -=


RationalNumber operator-=(RationalNumber& x, const RationalNumber& y)
{
	x.m_numerator = x.m_numerator * y.m_denominator - y.m_numerator*x.m_denominator;
	x.m_denominator = x.m_denominator * y.m_denominator;
	x.CanonicalForm();
	return x;
}

RationalNumber operator-=(RationalNumber& x, const int& y)
{
	x.m_numerator = x.m_numerator + y * x.m_denominator;
	x.CanonicalForm();
	return x;
}


// *=


RationalNumber operator*=(RationalNumber& x, const RationalNumber& y)
{
	x.m_numerator = x.m_numerator * y.m_numerator;
	x.m_denominator = x.m_denominator * y.m_denominator;
	x.CanonicalForm();
	return x;
}

RationalNumber operator*=(RationalNumber& x, const int& y)
{
	x.m_numerator = x.m_numerator * y;
	x.CanonicalForm();
	return x;
}


// /=


RationalNumber operator/=(RationalNumber& x, const RationalNumber& y)
{
	x.m_numerator = x.m_numerator * y.m_denominator;
	x.m_denominator = x.m_denominator * y.m_numerator;
	x.CanonicalForm();
	return x;
}

RationalNumber operator/=(RationalNumber& x, const int& y)
{
	x.m_numerator = x.m_numerator * y;
	x.CanonicalForm();
	return x;
}



//Arithmentic operators


	// +


RationalNumber operator+(const RationalNumber& x, const RationalNumber& y)
{
 	RationalNumber result;
	result.m_numerator = x.m_numerator*y.m_denominator + y.m_numerator*x.m_denominator;
	result.m_denominator = x.m_denominator*y.m_denominator;
	result.CanonicalForm();
	return result;
}


RationalNumber operator+(const RationalNumber& x, const int& y)
{
	RationalNumber result;
	result.m_numerator = x.m_numerator + y * x.m_denominator;
	result.m_denominator = x.m_denominator;
	result.CanonicalForm();
	return result;
}


RationalNumber operator+(const int& x, const RationalNumber& y)
{
	RationalNumber result;
	result.m_numerator = x * y.m_denominator + y.m_numerator;
	result.m_denominator = y.m_denominator;
	result.CanonicalForm();
	return result;
}


// -


RationalNumber operator-(const RationalNumber& x, const RationalNumber& y)
{
	RationalNumber result;
	result.m_numerator = x.m_numerator*y.m_denominator - y.m_numerator*x.m_denominator;
	result.m_denominator = x.m_denominator*y.m_denominator;
	result.CanonicalForm();
	return result;
}



RationalNumber operator-(const RationalNumber& x, const int& y)
{
	RationalNumber result;
	result.m_numerator = x.m_numerator - y * x.m_denominator;
	result.m_denominator = x.m_denominator;
	result.CanonicalForm();
	return result;
}



RationalNumber operator-(const int& x, const RationalNumber& y)
{
	RationalNumber result;
	result.m_numerator = x * y.m_denominator - y.m_numerator;
	result.m_denominator = y.m_denominator;
	result.CanonicalForm();
	return result;
}


// *


RationalNumber operator*(const RationalNumber& x, const RationalNumber& y)
{
	RationalNumber result;
	result.m_numerator = x.m_numerator*y.m_numerator;
	result.m_denominator = x.m_denominator*y.m_denominator;
	result.CanonicalForm();
	return result;
}

RationalNumber operator*(const RationalNumber& x, const int& y)
{
	RationalNumber result;
	result.m_numerator = x.m_numerator * y;
	result.m_denominator = x.m_denominator;
	result.CanonicalForm();
	return result;
}


RationalNumber operator*(const int& x, const RationalNumber& y)
{
	RationalNumber result;
	result.m_numerator = x * y.m_numerator;
	result.m_denominator = y.m_denominator;
	result.CanonicalForm();
	return result;
}


// /


RationalNumber operator/(const RationalNumber& x, const RationalNumber& y)
{
	RationalNumber result;
	result.m_numerator = x.m_numerator*y.m_denominator;
	result.m_denominator = x.m_denominator*y.m_numerator;
	result.CanonicalForm();
	return result;
}


RationalNumber operator/(const RationalNumber& x, const int& y)
{
	RationalNumber result;
	result.m_numerator = x.m_numerator;
	result.m_denominator = x.m_denominator*y;
	result.CanonicalForm();
	return result;
}


RationalNumber operator/(const int& x, const RationalNumber& y)
{
	RationalNumber result;
	result.m_numerator = x*y.m_denominator;
	result.m_denominator = y.m_numerator;
	result.CanonicalForm();
	return result;
}


// ^


RationalNumber operator^(RationalNumber x, const int& y)
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


bool operator==(const RationalNumber& x, const RationalNumber& y)
{
	if (x.m_numerator*y.m_denominator == x.m_denominator * y.m_denominator)
		return true;
	else
		return false;

}

bool operator==(const RationalNumber& x, const int& y)
{
	if (x.m_numerator == x.m_denominator * y)
		return true;
	else
		return false;

}

bool operator==(const int& x, const RationalNumber& y)
{
	if (x*y.m_denominator == y.m_denominator)
		return true;
	else
		return false;
}


	//!=


bool operator!=(const RationalNumber& x, const RationalNumber& y)
{
	if (x.m_numerator*y.m_denominator != x.m_denominator * y.m_denominator)
		return true;
	else
		return false;

}

bool operator!=(const RationalNumber& x, const int& y)
{
	if (x.m_numerator != x.m_denominator * y)
		return true;
	else
		return false;

}

bool operator!=(const int& x, const RationalNumber& y)
{
	if (x*y.m_denominator != y.m_denominator)
		return true;
	else
		return false;
}


	//>


bool operator>(const RationalNumber& x, const RationalNumber& y)
{
	if (x.m_numerator*y.m_denominator > x.m_denominator * y.m_denominator)
		return true;
	else
		return false;

}

bool operator>(const RationalNumber& x, const int& y)
{
	if (x.m_numerator > x.m_denominator * y)
		return true;
	else
		return false;

}

bool operator>(const int& x, const RationalNumber& y)
{
	if (x*y.m_denominator > y.m_denominator)
		return true;
	else
		return false;
}


	//>=


bool operator>=(const RationalNumber& x, const RationalNumber& y)
{
	if (x.m_numerator*y.m_denominator >= x.m_denominator * y.m_denominator)
		return true;
	else
		return false;

}

bool operator>=(const RationalNumber& x, const int& y)
{
	if (x.m_numerator >= x.m_denominator * y)
		return true;
	else
		return false;

}

bool operator>=(const int& x, const RationalNumber& y)
{
	if (x*y.m_denominator >= y.m_denominator)
		return true;
	else
		return false;
}


	//<


bool operator<(const RationalNumber& x, const RationalNumber& y)
{
	if (x.m_numerator*y.m_denominator < x.m_denominator * y.m_denominator)
		return true;
	else
		return false;

}

bool operator<(const RationalNumber& x, const int& y)
{
	if (x.m_numerator == x.m_denominator * y)
		return true;
	else
		return false;

}

bool operator<(const int& x, const RationalNumber& y)
{
	if (x*y.m_denominator == y.m_denominator)
		return true;
	else
		return false;
}


	//<=


bool operator<=(const RationalNumber& x, const RationalNumber& y)
{
	if (x.m_numerator*y.m_denominator <= x.m_denominator * y.m_denominator)
		return true;
	else
		return false;

}

bool operator<=(const RationalNumber& x, const int& y)
{
	if (x.m_numerator <= x.m_denominator * y)
		return true;
	else
		return false;

}

bool operator<=(const int& x, const RationalNumber& y)
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



	//file


		//>>


std::ifstream& operator>>(std::ifstream& infile, RationalNumber& x)
{
	infile >> x.m_numerator;
	infile.ignore (1024, '/');
	infile>> x.m_denominator;
		x.CanonicalForm();
		return infile;
}




//<<


std::ofstream& operator<<(std::ofstream& outfile, RationalNumber& x)
{
	x.CanonicalForm();
	outfile << x.m_numerator << "/" << x.m_denominator;
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

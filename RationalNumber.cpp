
#include "pch.h"
#include<fstream>
#include "RationalNumber.hpp"

#include<string>


//Constructors
RationalNumber::RationalNumber(int numerator, int denominator)
{
	if (denominator == 0)
		throw std::runtime_error("Denominator cannot be 0.");
	m_numerator = numerator;
	m_denominator = denominator;
	
	CanonicalForm();
}

RationalNumber::RationalNumber(const RationalNumber& x)
{
	if (x.m_denominator == 0)
		throw std::runtime_error("Denominator cannot be 0.");
	m_numerator = x.m_numerator;
	m_denominator = x.m_denominator;
} 




//Destructor


RationalNumber::~RationalNumber() {}



//Setters


void RationalNumber::SetRationalValue(RationalNumber& x)
{
	m_denominator = x.m_denominator;
	m_numerator = x.m_numerator;
}

void RationalNumber::SetNumeratorValue(const int& x)
{
	m_numerator = x;
	CanonicalForm();
}

void RationalNumber::SetDenominatorValue(const int& x)
{
	if (x == 0)
		throw std::runtime_error("Denominator cannot be 0.");
	m_denominator = x;

	CanonicalForm();
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
RationalNumber operator+(const RationalNumber& x)
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


RationalNumber& operator+=(RationalNumber& x, const RationalNumber& y)
{
	x.m_numerator = x.m_numerator * y.m_denominator + y.m_numerator*x.m_denominator;
	x.m_denominator = x.m_denominator * y.m_denominator;
	x.CanonicalForm();
	return x;
}

RationalNumber& operator+=(RationalNumber& x, const int& y)
{
	x.m_numerator = x.m_numerator + y * x.m_denominator;
	x.CanonicalForm();
	return x;
}


// -=


RationalNumber& operator-=(RationalNumber& x, const RationalNumber& y)
{
	x.m_numerator = x.m_numerator * y.m_denominator - y.m_numerator*x.m_denominator;
	x.m_denominator = x.m_denominator * y.m_denominator;
	x.CanonicalForm();
	return x;
}

RationalNumber& operator-=(RationalNumber& x, const int& y)
{
	x.m_numerator = x.m_numerator - y * x.m_denominator;
	x.CanonicalForm();
	return x;
}


// *=


RationalNumber& operator*=(RationalNumber& x, const RationalNumber& y)
{
	x.m_numerator = x.m_numerator * y.m_numerator;
	x.m_denominator = x.m_denominator * y.m_denominator;
	x.CanonicalForm();
	return x;
}

RationalNumber& operator*=(RationalNumber& x, const int& y)
{
	x.m_numerator = x.m_numerator * y;
	x.CanonicalForm();
	return x;
}


// /=


RationalNumber& operator/=(RationalNumber& x, const RationalNumber& y)
{
	x.m_numerator = x.m_numerator * y.m_denominator;
	x.m_denominator = x.m_denominator * y.m_numerator;
	x.CanonicalForm();
	return x;
}

RationalNumber& operator/=(RationalNumber& x, const int& y)
{
	if (y == 0)
		throw std::runtime_error("Cannot devide by 0.");
	x.m_denominator = x.m_denominator * y;
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
	if (y == 0)
		result.m_denominator = 1;
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
		return result;

	}
	if (y < 0)
	{
		x.m_numerator = b;
		x.m_denominator = a;
		a = x.m_denominator;
		b = x.m_numerator;
	}
	while (c != y)
	{
		x.m_numerator = x.m_numerator * a;
		x.m_denominator = x.m_denominator * b;
		c++;
	}
		result.SetRationalValue(x);
		return result;
	}



//Relational operators


	//==


bool operator==(const RationalNumber& x, const RationalNumber& y)
{
	return x.m_numerator*y.m_denominator == x.m_denominator * y.m_denominator;
}

bool operator==(const RationalNumber& x, const int& y)
{
	return x.m_numerator == x.m_denominator * y;
}

bool operator==(const int& x, const RationalNumber& y)
{
	return x*y.m_denominator == y.m_denominator;
}


	//!=


bool operator!=(const RationalNumber& x, const RationalNumber& y)
{
	return x.m_numerator*y.m_denominator != x.m_denominator * y.m_denominator;
}

bool operator!=(const RationalNumber& x, const int& y)
{
	return x.m_numerator != x.m_denominator * y;
}

bool operator!=(const int& x, const RationalNumber& y)
{
	return x * y.m_denominator != y.m_denominator;
}


	//>


bool operator>(const RationalNumber& x, const RationalNumber& y)
{
	return x.m_numerator*y.m_denominator > x.m_denominator * y.m_denominator;
}

bool operator>(const RationalNumber& x, const int& y)
{
	return x.m_numerator > x.m_denominator * y;
}

bool operator>(const int& x, const RationalNumber& y)
{
	return x*y.m_denominator > y.m_denominator;
}


	//>=


bool operator>=(const RationalNumber& x, const RationalNumber& y)
{
	return x.m_numerator*y.m_denominator >= x.m_denominator * y.m_denominator;
}

bool operator>=(const RationalNumber& x, const int& y)
{
	return x.m_numerator >= x.m_denominator * y;
}

bool operator>=(const int& x, const RationalNumber& y)
{
	return x*y.m_denominator >= y.m_denominator;
}


	//<


bool operator<(const RationalNumber& x, const RationalNumber& y)
{
	return x.m_numerator*y.m_denominator < x.m_denominator * y.m_denominator;
}

bool operator<(const RationalNumber& x, const int& y)
{
	return x.m_numerator == x.m_denominator * y;
}

bool operator<(const int& x, const RationalNumber& y)
{
	return x*y.m_denominator == y.m_denominator;
}


	//<=


bool operator<=(const RationalNumber& x, const RationalNumber& y)
{
	return x.m_numerator*y.m_denominator <= x.m_denominator * y.m_denominator;

}

bool operator<=(const RationalNumber& x, const int& y)
{
	return x.m_numerator <= x.m_denominator * y;

}

bool operator<=(const int& x, const RationalNumber& y)
{
	return x * y.m_denominator <= y.m_denominator;
}





//Reading and writing operators


	//console


		//>>



std::istream& operator>>(std::istream& in, RationalNumber& x)
{
	in >> x.m_numerator;
	in.ignore (1024, '/');
	in>> x.m_denominator;
	if (x.m_denominator == 0)
		throw std::runtime_error("Denominator cannot be 0.");
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



//To string

std::string RationalNumber::ToString(const RationalNumber& x)
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
	if (a <0 && b < 0)
	{
		m_numerator = (-1)*m_numerator;
		m_denominator = (-1)*m_denominator;
		a = (-1) *a;
		b = (-1) * b;
	}
	if (a < 0)
		a = a * (-1);
	if (b < 0)
		b = b * (-1);
	if (a == 0)
	{
		m_denominator = 1;
		return *this;
	}
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
	if (m_denominator < 0)
	{
		m_denominator *= -1;
		m_denominator /= a;
		m_denominator *= -1;
	}
	else
	{
		m_numerator = m_numerator / a;
		m_denominator = m_denominator / a;
	}
	return *this;
}

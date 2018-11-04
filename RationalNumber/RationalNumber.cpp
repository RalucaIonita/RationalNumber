
#include "pch.h"
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
}

void RationalNumber::SetNumeratorValue(int x)
{
	m_numerator = x;
	CanonicalForm();
}

void RationalNumber::SetDenominatorValue(int x)
{
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
RationalNumber operator+(RationalNumber x)
{
	return x;
}

RationalNumber operator-(RationalNumber x)
{
	x.m_numerator = (-1) * x.m_numerator;
	return x;
}



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
	int c = 1, a=x.m_numerator, b=x.m_denominator;
	if (y == 0)
	{
		x.SetDenominatorValue(1);
		x.SetNumeratorValue(1);
	}
	else 
		while (c != y)
		{
			x.m_numerator = x.m_numerator * a;
			x.m_denominator = x.m_denominator * b;
			c++;
		}
	return result;
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


	//>>



std::istream& operator>>(std::istream& in, RationalNumber& x)
{
	in >> x.m_numerator >> x.m_denominator;
	x.CanonicalForm();
	return in;
}


	//<<


std::ostream& operator<<(std::ostream& out, RationalNumber& x)
{
	out << x.m_numerator << "/" << x.m_denominator;
	x.CanonicalForm();
	return out;
}



//To string
std::string RationalNumber::toString(const RationalNumber& x)
{
	std::string s;
	if (x.m_numerator == 1)
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
	/*double a;
	a = (double)this->m_numerator / this->m_denominator;*/
	return (double) m_numerator / m_denominator;
}

RationalNumber::operator int() const
{
	/*int a;
	a = (int)m_numerator%m_denominator;*/
	return (int) m_numerator / m_denominator;
}

RationalNumber::operator std::string() const
{
	return toString(*this);
}



//Canonical form


RationalNumber RationalNumber::CanonicalForm()
{
	int a, b;
	a = m_numerator;
	b = m_denominator;
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	m_numerator = m_numerator / a;
	m_denominator = m_denominator / a;
	return *this;

}

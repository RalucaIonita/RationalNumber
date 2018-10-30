
#include "pch.h"
#include "RationalNumber.hpp"
#include <iostream>

void RationalNumber::SetRationalValue(RationalNumber x)
{
	m_denominator = x.m_denominator;
	m_numerator = x.m_numerator;
}

void RationalNumber::SetNumeratorValue(int x)
{
	m_numerator = x;
}

void RationalNumber::SetDenominatorValue(int x)
{
	m_denominator = x;
}

RationalNumber RationalNumber::GetNumeratorValue()
{
	return m_numerator;
}

RationalNumber RationalNumber::GetDenominatorValue()
{
	return m_denominator;
}

/*RationalNumber*/ RationalNumber::RationalNumber(int numerator = 0, int denominator = 1)
{
	m_numerator = numerator;
	m_denominator = denominator;
}

/*RationalNumber*/ RationalNumber::RationalNumber(const RationalNumber& x)
{
	m_numerator = x.m_numerator;
	m_denominator = x.m_denominator;
}





int main()
{
    std::cout << "Hello World!\n"; 
}


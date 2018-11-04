#pragma once
/*#ifndef RATIONALNUMBER_HPP
#define RATONALNUMBER_HPP*/

#include<string>


class RationalNumber
{
private:
	int m_numerator, m_denominator;
	RationalNumber CanonicalForm();



public:

	//Set
	void SetRationalValue(RationalNumber x);
	void SetNumeratorValue(int x);
	void SetDenominatorValue(int x);

	//Get
	int GetNumeratorValue();
	int GetDenominatorValue();

	//Constructors
	RationalNumber();
	RationalNumber(int numerator, int denominator);
	RationalNumber(const RationalNumber& x);

	//Destructor
	~RationalNumber();

	//Unary operators
	friend RationalNumber operator+(RationalNumber x);
	friend RationalNumber operator-(RationalNumber x);



	//Attribution operators
	friend RationalNumber operator+=(RationalNumber x, RationalNumber y);
	friend RationalNumber operator+=(RationalNumber x, int y);

	friend RationalNumber operator-=(RationalNumber x, RationalNumber y);
	friend RationalNumber operator-=(RationalNumber x, int y);

	friend RationalNumber operator*=(RationalNumber x, RationalNumber y);
	friend RationalNumber operator*=(RationalNumber x, int y);

	friend RationalNumber operator/=(RationalNumber x, RationalNumber y);
	friend RationalNumber operator/=(RationalNumber x, int y);

	//Arithmentic operators
	friend RationalNumber operator+(RationalNumber x, RationalNumber y);
	friend RationalNumber operator+(RationalNumber x, int y);
	friend RationalNumber operator+(int x, RationalNumber y);

	friend RationalNumber operator-(RationalNumber x, RationalNumber y);
	friend RationalNumber operator-(RationalNumber x, int y);
	friend RationalNumber operator-(int x, RationalNumber y);

	friend RationalNumber operator*(RationalNumber x, RationalNumber y);
	friend RationalNumber operator*(RationalNumber x, int y);
	friend RationalNumber operator*(int x, RationalNumber y);

	friend RationalNumber operator/(RationalNumber x, RationalNumber y);
	friend RationalNumber operator/(RationalNumber x, int y);
	friend RationalNumber operator/(int x, RationalNumber y);

	friend RationalNumber operator^(RationalNumber x, int y);

	//Relational operators
	friend bool operator==(RationalNumber x, RationalNumber y);
	friend bool operator==(RationalNumber x, int y);
	friend bool operator==(int x, RationalNumber y);

	friend bool operator!=(RationalNumber x, RationalNumber y);
	friend bool operator!=(RationalNumber x, int y);
	friend bool operator!=(int x, RationalNumber y);

	friend bool operator<(RationalNumber x, RationalNumber y);
	friend bool operator<(RationalNumber x, int y);
	friend bool operator<(int x, RationalNumber y);

	friend bool operator<=(RationalNumber x, RationalNumber y);
	friend bool operator<=(RationalNumber x, int y);
	friend bool operator<=(int x, RationalNumber y);

	friend bool operator>(RationalNumber x, RationalNumber y);
	friend bool operator>(RationalNumber x, int y);
	friend bool operator>(int x, RationalNumber y);

	friend bool operator>=(RationalNumber x, RationalNumber y);
	friend bool operator>=(RationalNumber x, int y);
	friend bool operator>=(int x, RationalNumber y);


	//To string
	std::string toString(const RationalNumber& x);


	//Conversion operators
	operator double() const;
	operator int() const;
	operator std::string() const;




	//Reading and writing operators
	friend std::istream& operator >>(std::istream& in, RationalNumber& x);
	friend std::ostream& operator <<(std::ostream& out, RationalNumber& x);


};

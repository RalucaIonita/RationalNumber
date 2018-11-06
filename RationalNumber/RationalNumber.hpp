#pragma once

#include<fstream>
#include<string>


class RationalNumber
{
private:
	int m_numerator, m_denominator;
	RationalNumber CanonicalForm();



public:

	//Set
	void SetRationalValue(RationalNumber& x);
	void SetNumeratorValue(const int& x);
	void SetDenominatorValue(const int& x);

	//Get
	int GetNumeratorValue();
	int GetDenominatorValue();

	//Constructors
	RationalNumber();
	RationalNumber(const int& numerator, const int& denominator);
	RationalNumber(const RationalNumber& x);

	//Destructor
	~RationalNumber();

	//Unary operators
	friend RationalNumber operator+(const RationalNumber& x);
	friend RationalNumber operator-(RationalNumber& x);



	//Attribution operators
	friend RationalNumber operator+=(RationalNumber& x, const RationalNumber& y);
	friend RationalNumber operator+=(RationalNumber& x, const int& y);

	friend RationalNumber operator-=(RationalNumber& x, const RationalNumber& y);
	friend RationalNumber operator-=(RationalNumber& x, const int& y);

	friend RationalNumber operator*=(RationalNumber& x, const RationalNumber& y);
	friend RationalNumber operator*=(RationalNumber& x, const int& y);

	friend RationalNumber operator/=(RationalNumber& x, const RationalNumber& y);
	friend RationalNumber operator/=(RationalNumber& x, const int& y);

	//Arithmentic operators
	friend RationalNumber operator+(const RationalNumber& x, const RationalNumber& y);
	friend RationalNumber operator+(const RationalNumber& x, const int& y);
	friend RationalNumber operator+(const int& x, const RationalNumber& y);

	friend RationalNumber operator-(const RationalNumber& x, const RationalNumber& y);
	friend RationalNumber operator-(const RationalNumber& x, const int& y);
	friend RationalNumber operator-(const int& x, const RationalNumber& y);

	friend RationalNumber operator*(const RationalNumber& x, const RationalNumber& y);
	friend RationalNumber operator*(const RationalNumber& x, const int& y);
	friend RationalNumber operator*(const int& x, const RationalNumber& y);

	friend RationalNumber operator/(const RationalNumber& x, const RationalNumber& y);
	friend RationalNumber operator/(const RationalNumber& x, const int& y);
	friend RationalNumber operator/(const int& x, const RationalNumber& y);

	friend RationalNumber operator^(RationalNumber x, const int& y);

	//Relational operators
	friend bool operator==(const RationalNumber& x, const RationalNumber& y);
	friend bool operator==(const RationalNumber& x, const int& y);
	friend bool operator==(const int& x, const RationalNumber& y);

	friend bool operator!=(const RationalNumber& x, const RationalNumber& y);
	friend bool operator!=(const RationalNumber& x, const int& y);
	friend bool operator!=(const int& x, const RationalNumber& y);

	friend bool operator<(const RationalNumber& x, const RationalNumber& y);
	friend bool operator<(const RationalNumber& x, const int& y);
	friend bool operator<(const int& x, const RationalNumber& y);

	friend bool operator<=(const RationalNumber& x, const RationalNumber& y);
	friend bool operator<=(const RationalNumber& x, const int& y);
	friend bool operator<=(const int& x, const RationalNumber& y);

	friend bool operator>(const RationalNumber& x, const RationalNumber& y);
	friend bool operator>(const RationalNumber& x, const int& y);
	friend bool operator>(const int& x, const RationalNumber& y);

	friend bool operator>=(const RationalNumber& x, const RationalNumber& y);
	friend bool operator>=(const RationalNumber& x, const int& y);
	friend bool operator>=(const int& x, const RationalNumber& y);


	//To string
	std::string ToString(RationalNumber& x);


	//Conversion operators
	operator double() const;
	operator int() const;
	operator std::string();




	//Reading and writing operators
		//console
	friend std::istream& operator >>(std::istream& in, RationalNumber& x);
	friend std::ostream& operator <<(std::ostream& out, RationalNumber& x);
	   //file
	friend std::ifstream& operator >>(std::ifstream& in, RationalNumber& x);
	friend std::ofstream& operator <<(std::ofstream& out, RationalNumber& x);



};

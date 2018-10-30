#pragma once

//smth
class RationalNumber
{
private:
	int m_numerator, m_denominator;


public:

	//Set
	RationalNumber SetRationalValue(RationalNumber x);
	RationalNumber SetNumeratorValue(int x);
	RationalNumber SetDenominatorValue(int x);

	//Get
	void GetNumeratorValue();
	void GetDenominatorValue();

	//Constructors
	RationalNumber(int numerator = 0, int denominator = 1);
	RationalNumber&(const RationalNumber& x);

	//Destructor
	~RationalNumber();


	//Attribution operators
	RationalNumber operator+=(RationalNumber x);
	RationalNumber operator+=(int x);

	RationalNumber operator-=(RationalNumber x);
	RationalNumber operator-=(int x);

	RationalNumber operator*=(RationalNumber x);
	RationalNumber operator*=(int x);

	RationalNumber operator/=(RationalNumber x);
	RationalNumber operator/=(int x);

	//Arithmentic operators
	RationalNumber operator+(RationalNumber x);
	RationalNumber operator+(double x);
	RationalNumber operator+(int x);
	
	RationalNumber operator-(RationalNumber x);
	RationalNumber operator-(double x);
	RationalNumber operator-(int x);
	
	RationalNumber operator*(RationalNumber x);
	RationalNumber operator*(double x);
	RationalNumber operator*(int x);
	
	RationalNumber operator/(RationalNumber x);
	RationalNumber operator/(double x);
	RationalNumber operator/(int x);





	







private:
	RationalNumber CanonicalForm();











};
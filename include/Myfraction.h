#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimetr "\n------------------------------------\n"
class Fraction;
std::ostream& operator<<(std::ostream& os, const Fraction& obj);
std::istream& operator >>(std::istream& is, Fraction& obj);
Fraction operator *(Fraction left, Fraction right);
Fraction operator /(const Fraction& left, const Fraction& right);
Fraction operator+(const Fraction& left, const Fraction& right);
Fraction operator-(const Fraction& left, const Fraction& right);
class Fraction
{
	int integer;//целочисленное
	int numerator;//чеслитель
	int denominator;//знаминатель
public:
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);
	/*Construction*/
	Fraction();
	explicit Fraction(int integer);

	Fraction(double decimal);

	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();
	/*Operators*/
	Fraction& operator=(const Fraction& other);
	Fraction& operator *=(const Fraction& other);
	Fraction& operator /=(const Fraction& other);
	Fraction& operator +=(const Fraction& other);
	Fraction& operator -=(const Fraction& other);
	/*Increment and Decrement*/
	Fraction& operator ++();
	Fraction& operator --();
	Fraction operator++(int);
	Fraction operator--(int);
	/*Methods*/
	Fraction& to_improper();
	Fraction& to_proper();
	Fraction inverted()const;
	int gcd(int numerator, int denominator)const;
	void simplify();
	Fraction& reduce();

	void Print()const;
};
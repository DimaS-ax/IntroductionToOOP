#include<iostream>
using namespace std;

class Fraction
{
	int numerator;//числитель
	int denominator;//знаминатель

public:
	/*Getters*/
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	/*Setters*/
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		this->denominator = denominator;
	}
	/*Constructor*/
	Fraction(int numerator = 0, int denominator = 0)
	{
		this->numerator = numerator;
		this->denominator = denominator;
	}
	/*CopyConstructor*/
	Fraction(const Fraction& other)
	{
		this->numerator = other.numerator;
		this->denominator = other.denominator;
	}
	void print()const
	{
		cout << "NUMERATOR = " << get_numerator() << "\tDENOMINATOR = " << get_denominator() << endl;
	}
	/*Arithmetic operators*/
	Fraction operator +(const Fraction& other)
	{
		Fraction result;
		result.numerator = this->numerator + other.numerator;
		result.denominator = this->denominator + other.denominator;
		return result;
	}
	Fraction operator -(const Fraction& other)
	{
		Fraction result;
		result.numerator = this->numerator - other.numerator;
		result.denominator = this->denominator - other.denominator;
		return result;
	}
	Fraction operator *(const Fraction& other)
	{
		Fraction result;
		result.numerator = this->numerator * other.numerator;
		result.denominator = this->denominator * other.denominator;
		return result;
	}
	Fraction operator /(const Fraction& other)
	{
		if (other.numerator != 0 && other.denominator != 0)
		{
			return Fraction(this->numerator / other.numerator, this->denominator / other.denominator);
		}
		else
		{
			cout << "~ERROR~" << endl;
			return *this;
		}
	}
	/*Increment and decrement*/
	Fraction& operator ++()
	{
		this->numerator++;
		this->denominator++;
		return *this;
	}
	Fraction& operator --()
	{
		this->numerator--;
		this->denominator--;
		return *this;
	}
	Fraction& operator ++(int)
	{
		this->numerator++;
		this->denominator++;
		return *this;
	}
	Fraction& operator --(int)
	{
		this->numerator--;
		this->denominator--;
		return *this;
	}
	/*Compound assignments*/
	Fraction& operator+=(const Fraction& other)
	{
		this->numerator += other.numerator;
		this->denominator += other.denominator;
		return *this;
	}
	Fraction& operator-=(const Fraction& other)
	{
		this->numerator -= other.numerator;
		this->denominator -= other.denominator;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		this->numerator *= other.numerator;
		this->denominator *= other.denominator;
		return *this;
	}
	/*Fraction& operator/=(const Fraction& other)
	{
		this->numerator /= other.numerator;
		this->denominator /= other.numerator;
		return *this;
	}*/
	Fraction& operator/=(const Fraction& other)
	{
		if (other.numerator != 0 && other.denominator != 0)
		{
			this->numerator /= other.numerator;
			this->denominator /= other.denominator;
		}
		else
		{
			cout << "!~ERROR~!" << endl;
		}
		return *this;
	}

	/*Comparison operator*/
	bool operator ==(const Fraction& other) const
	{
		return this->numerator == other.numerator && this->denominator == other.denominator;
		/*if (this->numerator == other.numerator && this->denominator == other.denominator)
		{
			return true;
		}
		else
		{
			return false;
		}*/
	}
	bool operator !=(const Fraction& other) const
	{
		return !(this->numerator == other.numerator && this->denominator == other.denominator);
	}
	bool operator <=(const Fraction& other) const
	{
		return this->numerator <= other.numerator && this->denominator <= other.denominator;
	}
	bool operator >=(const Fraction& other) const
	{
		return this->numerator >= other.numerator && this->denominator >= other.denominator;
	}
	bool operator >(const Fraction& other) const
	{
		return this->numerator > other.numerator && this->denominator > other.denominator;
	}
	bool operator <(const Fraction& other) const
	{
		return this->numerator < other.numerator && this->denominator < other.denominator;
	}
	/*Assignment operator*/
	void operator =(const Fraction& other)
	{
		this->numerator = other.numerator;
		this->denominator = other.denominator;
	}
	/*Destructor*/
	~Fraction()
	{
		//cout << "~Destructor~" << endl;
	}
};


void main()
{
	setlocale(LC_ALL, "ru");

	Fraction A(10, 8);
	Fraction B(5, 4);
	Fraction C = A + B;
	C.print();
}
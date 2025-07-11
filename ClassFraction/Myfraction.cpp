#include"Myfraction.h"

/*Overload Operators*/
Fraction operator *(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());*/
	/*Fraction result
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);
	return result;*/
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
Fraction operator /(const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}
Fraction operator+(const Fraction& left, const Fraction& right)
{
	int commonDenominator = left.get_denominator() * right.get_denominator();
	int newNumerator = left.get_denominator() * right.get_numerator() +
		left.get_numerator() * right.get_denominator();
	Fraction result(newNumerator, commonDenominator);
	result.simplify();
	return result;
}
Fraction operator-(const Fraction& left, const Fraction& right)
{
	int commonDenominator = left.get_denominator() * right.get_denominator();
	int newNumerator = left.get_numerator() * right.get_denominator() -
		left.get_denominator() * right.get_numerator();

	Fraction result(newNumerator, commonDenominator);
	result.simplify();
	return result;
}
/*Comparison Operators*/
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() ==
		right.get_numerator() * left.get_denominator();
}
bool operator !=(const Fraction left, const Fraction right)
{
	return !(left == right);
}
bool operator >(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}
bool operator <(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();
}
bool operator >=(Fraction left, Fraction right)
{
	return !(left < right);
}
bool operator <=(Fraction left, Fraction right)
{
	return !(left > right);
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}
std::istream& operator >>(std::istream& is, Fraction& obj)
{
	/*int integer;
	int numerator;
	int denominator;
	is >> integer >> numerator >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);*/
	const int SIZE = 32;
	char sz_input[SIZE] = {};// sz_ - String Zero строка заканчивающаяся нулем
	/*is >> sz_input;*/
	is.getline(sz_input, SIZE);//Ввод строки с пробелом
	const char delimeters[] = { '/','(',')','.',',',' ',0 };
	int numbers[3] = {};
	int n = 0;
	for (char* pch = strtok(sz_input, delimeters); pch; pch = strtok(NULL, delimeters))
		numbers[n++] = atoi(pch);
	/*for (int i = 0; i < n; i++)cout << numbers[i] << "\t"; cout << endl;*/
	switch (n)
	{
	case 1:obj = (Fraction)numbers[0]; break;
	case 2:obj = Fraction(numbers[0], numbers[1]); break;
	case 3:obj = Fraction(numbers[0], numbers[1], numbers[2]); break;
	}
	return is;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////


int Fraction::get_integer()const
{
	return integer;
}
int Fraction::get_numerator()const
{
	return numerator;
}
int Fraction::get_denominator()const
{
	return denominator;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0)denominator = 1;
	this->denominator = denominator;
}
/*Construction*/
Fraction::Fraction() :integer(0), numerator(0), denominator(1)
{
	cout << "DefaultConstruction:\t" << this << endl;
}
Fraction::Fraction(int integer) :integer(integer), numerator(0), denominator(1)
{
	cout << "SingleArgConstruction:\t" << this << endl;
}

Fraction::Fraction(double decimal)
{
	//decimal - десятичный
	decimal += 1e-10; /*.0000000001;*/
	integer = decimal;//неявное преобразование типов из double в int
	decimal -= integer;
	denominator = 1e+9; /*1000000000*/// максимально возможное значение чеслителя 9 десятичных разрядов
	//e - Exponent (основание системы счисления)
	numerator = decimal * denominator;
	reduce();
}

Fraction::Fraction(int numerator, int denominator)
{
	set_integer(0);
	set_numerator(numerator);
	set_denominator(denominator);
	cout << "Construction:\t\t" << this << endl;
}
Fraction::Fraction(int integer, int numerator, int denominator)
{
	set_integer(integer);
	set_numerator(numerator);
	set_denominator(denominator);
	cout << "Construction:\t\t" << this << endl;
}
Fraction::Fraction(const Fraction& other) :integer(other.integer), numerator(other.numerator), denominator(other.denominator)
{
	cout << "CopyConstructor:\t" << this << endl;
}
Fraction::~Fraction()
{
	cout << "Destruction:\t\t" << this << endl;
}
/*Operators*/
Fraction& Fraction::operator=(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}
Fraction& Fraction::operator *=(const Fraction& other)
{
	return *this = *this * other;
}
Fraction& Fraction::operator /=(const Fraction& other)
{
	return *this = *this / other;
}
Fraction& Fraction::operator +=(const Fraction& other)
{
	return *this = *this + other;
}
Fraction& Fraction::operator -=(const Fraction& other)
{
	return *this = *this - other;
}
/*Increment and Decrement*/
Fraction& Fraction::operator ++() //Prefix increment
{
	integer++;
	return *this;
}
Fraction& Fraction::operator --() //Prefix increment
{
	integer--;
	return *this;
}
Fraction Fraction::operator++(int)//Postfix increment
{
	Fraction old = *this;
	integer++;
	return old;
}
Fraction Fraction::operator--(int)//Postfix increment
{
	Fraction old = *this;
	integer--;
	return old;
}
/*Methods*/
Fraction& Fraction::to_improper()
{
	//Перевод дроби в неправильную
	numerator += integer * denominator;
	integer = 0;
	return *this;
}
Fraction& Fraction::to_proper()
{
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}
Fraction Fraction::inverted()const
{
	Fraction inverted = *this;
	inverted.to_improper();
	swap(inverted.numerator, inverted.denominator);
	return inverted;
}
int Fraction::gcd(int numerator, int denominator)const
{
	while (denominator != 0)
	{
		int bufer = denominator;
		denominator = numerator % denominator;
		numerator = bufer;
	}
	return numerator;
}
void Fraction::simplify()
{
	int buffer = gcd(numerator, denominator);
	numerator /= buffer;
	denominator /= buffer;
	if (denominator < 0)
	{
		denominator = -denominator;
		numerator = -numerator;
	}
}
Fraction& Fraction::reduce()
{
	int more, less, rest;
	if (numerator < denominator)
	{
		less = numerator;
		more = denominator;
	}
	else
	{
		more = numerator;
		less = denominator;
	}
	do
	{
		rest = more % less;
		more = less;
		less = rest;
	} while (rest);
	int GCD = more;// GCD - Greatest Common Divisor
	numerator /= GCD;
	denominator /= GCD;
	return *this;
}

void Fraction::Print()const
{
	if (integer)cout << integer;
	if (numerator)
	{
		if (integer)cout << "(";
		cout << numerator << "/" << denominator;
		if (integer)cout << ")";
	}
	else if (integer == 0)cout << 0;
	cout << endl;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
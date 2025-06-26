#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimetr "\n------------------------------------\n"
class Fraction;
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
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	/*Construction*/
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstruction:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgConstruction:\t" << this << endl;
	}

	Fraction(double num)
	{
		int NUM = (int)num;
		double res = num - NUM;
		int denominator = 10000;
		int numerator = res * denominator;
		int commonDenominator = gcd(numerator, denominator);
		numerator /= commonDenominator;
		denominator /= commonDenominator;
		this->integer = NUM;
		this->numerator = numerator;
		this->denominator = denominator;
	}

	Fraction(int numerator, int denominator)
	{
		set_integer (0);
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "Construction:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "Construction:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destruction:\t\t" << this << endl;
	}
	/*Operators*/
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	Fraction& operator *=(const Fraction& other)
	{
		return *this = *this*other;
	}
	Fraction& operator /=(const Fraction& other)
	{
		return *this = *this / other;
	}
	Fraction& operator +=(const Fraction& other)
	{
		return *this = *this + other;
	}
	Fraction& operator -=(const Fraction& other)
	{
		return *this = *this - other;
	}
	/*Increment and Decrement*/
	Fraction& operator ++() //Prefix increment
	{
		integer++;
		return *this;
	}
	Fraction& operator --() //Prefix increment
	{
		integer--;
		return *this;
	}
	Fraction operator++(int)//Postfix increment
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction operator--(int)//Postfix increment
	{
		Fraction old = *this;
		integer--;
		return old;
	}
	/*Methods*/
	Fraction& to_improper()
	{
		//Перевод дроби в неправильную
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	int gcd(int numerator, int denominator)const
	{
		while (denominator != 0)
		{
			int bufer = denominator;
			denominator = numerator % denominator;
			numerator = bufer;
		}
		return numerator;
	}
	void simplify()
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

	void Print()const
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
};
/*Overload Operators*/
Fraction operator *( Fraction left, Fraction right)
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

std::istream& operator >>(std::istream& is,  Fraction& obj)
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
	switch(n)
	{
		case 1:obj = (Fraction)numbers[0]; break;
		case 2:obj = Fraction(numbers[0], numbers[1]); break;
		case 3:obj = Fraction(numbers[0], numbers[1], numbers[2]); break;
	}
	return is;
}

//#define CONSTRACTION_CHECK
//#define ASSIGNMENT_CHECK
//#define ARITHMETICAL_OPERATORS
//#define INCREMENT_DECREMENT
//#define COMPARISON_OPERATOR
//#define OSTREAM_OPERATOR
//#define ISTREAM_OPERATORS
//#define CONVERSION_BASICS
//#define CONVERSION_FROM_OTHER_TO_CLASS
#define DECIMAL_TO_FRACTION
void main()
{
	setlocale(LC_ALL, "ru");
#ifdef CONSTRACTION_CHECK
	Fraction A;//Default constructor
	A.Print();
	Fraction B = 5;//Single argument constructor
	B.Print();
	Fraction C(1, 2);//Constructor
	C.Print();
	Fraction D(2, 3, 4);//Constructor
	D.Print();

	Fraction E = D;//CopyConstructor
	E.Print();

	Fraction F;//CopyAssignment
	F = E;
	F.Print();
#endif // CONSTRACTION_CHECK

#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;
	Fraction A, B, C;
	cout << delimetr;
	A = B = C = Fraction(2, 3, 4);
	//Fraction(2,3,4);//Явный вызов конструктора, создает временный безымянный обьект
	//Временные безымянные обьекты существуют в пределах одного выражения

	cout << delimetr;
	A.Print();
	B.Print();
	C.Print();
#endif // ASSIGNMENT_CHECK

#ifdef ARITHMETICAL_OPERATORS
	Fraction A(1, 2);
	Fraction B(2, 3, 4);
	Fraction C = A / B;
	A.Print();
	B.Print();
	C.Print();
	cout << delimetr;
	A /= B;
	A.Print();
	B.Print();
#endif // ARITHMETICAL_OPERATORS

#ifdef INCREMENT_DECREMENT
	Fraction A(1, 2);
	Fraction B = A--;
	A.Print();
	B.Print();
#endif // INCREMENT_DECREMENT

#ifdef COMPARISON_OPERATOR
	cout << (Fraction(1, 2) != Fraction(5, 11)) << endl;
#endif // COMPARISON_OPERATOR

#ifdef OSTREAM_OPERATOR
	Fraction A(1, 2, 3);
	Fraction B(2, 3, 4);

	cout << A << endl;
#endif // OSTREAM_OPERATOR

#ifdef ISTREAM_OPERATORS
	Fraction A;
	cout << "Введите простую дробь: "; cin >> A;
	cout << A << endl;
#endif // ISTREAM_OPERATORS

#ifdef CONVERSION_BASICS
	int a = 2;// No conversions
	double b = 3;// Implicit conversion from less to more('int' to 'double')
	int c = b;//Implicit conversion from more to less without data loss
	int d = 4.5;//Implicit conversion from more to less with data loss  
#endif // CONVERSION_BASICS

#ifdef CONVERSION_FROM_OTHER_TO_CLASS
	Fraction A = (Fraction)5; // Implicit conversion from less to more
	cout << A << endl;

	Fraction B;
	cout << delimetr;
	B = Fraction(8);
	cout << delimetr;
	cout << B << endl;
#endif // CONVERSION_FROM_OTHER_TO_CLASS

#ifdef DECIMAL_TO_FRACTION

	Fraction A = 2.75;
	cout << A << endl;
	cout << delimetr;
	Fraction B = 5.5;
	cout << B << endl;

#endif // DECIMAL_TO_FRACTION


}
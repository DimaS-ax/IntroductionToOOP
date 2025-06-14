#include<iostream>
using namespace std;
#define delimetr "\n------------------------------------\n"

class Fraction;
Fraction operator *(Fraction left, Fraction right);
Fraction operator /(const Fraction& left, const Fraction& right);
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
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "Construction:\t\t" << this << endl;
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

	/*Increment and Decrement*/

	Fraction& operator ++() //Prefix increment
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)//Postfix increment
	{
		Fraction old = *this;
		integer++;
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


//#define CONSTRACTION_CHECK
//#define ASSIGNMENT_CHECK
//#define ARITHMETICAL_OPERATORS
//#define INCREMENT_DECREMENT

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
	Fraction B = A++;
	A.Print();
	B.Print();
#endif // INCREMENT_DECREMENT



}
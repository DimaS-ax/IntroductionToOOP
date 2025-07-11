#include"Myfraction.h"

//#define CONSTRACTION_CHECK
//#define ASSIGNMENT_CHECK
//#define ARITHMETICAL_OPERATORS
//#define INCREMENT_DECREMENT
//#define COMPARISON_OPERATOR
//#define OSTREAM_OPERATOR
//#define ISTREAM_OPERATORS
//#define CONVERSION_BASICS
//#define CONVERSION_FROM_OTHER_TO_CLASS
//#define DECIMAL_TO_FRACTION
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

	/*Fraction A = 2.76;
	cout << A << endl;*/


	Fraction A(5);
	cout << A << endl;
	Fraction B = A;
	cout << B << endl;

}
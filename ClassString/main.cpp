#include"String.h"


//#define CONSTRUCTOR_CHECK
//#define OPERATOR_PLUS
#define ISTREAM_OPERATOR
//#define CALLING_CONSTRUCTOR

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTOR_CHECK
	String str1(5);// excplisit - constructor нельзя вызвать оператором присвоить, можно вызвать круглых скобок
	str1.info();
	cout << str1 << endl;

	String str2 = "Hello";
	str2 = str2;
	cout << str2 << endl;

	String str3 = str2;  // CopyConstructor
	cout << str3 << endl;

	String str4;
	str4 = str3;
	cout << str4 << endl;
#endif // CONSTRUCTOR_CHECK

#ifdef OPERATOR_PLUS
	String str1 = "Hello";
	String str2 = "World";
	cout << delimetr << endl;
	String str3;
	str3 = str1 + str2;
	cout << delimetr << endl;
	cout << str3 << endl;
	cout << delimetr << endl;
	String str4 = str3;
	cout << str4 << endl;
	cout << delimetr << endl;

#endif // OPERATOR_PLUS

#ifdef ISTREAM_OPERATOR
	String str;
	cout << "Введите строку: ";
	SetConsoleCP(1251);
	//cin >> str;
	//cin.getline(str.get_str(), str.get_size());
	getline(cin, str);
	SetConsoleCP(866);
	cout << str << endl;

#endif // ISTREAM_OPERATOR

#ifdef CALLING_CONSTRUCTOR
	String str1;   //Default constructor
	str1.info();

	String str2(8);  // Single-argument constructor ('int')
	str2.info();

	String str3 = "Hello"; //Singe-argument constructor ('const char')
	str3.info();
	cout << typeid("Hello").name() << endl;

	String str4(); // Default constructor
	/*Не вызывается ни какой конструктор, ни создается ни какой обьект
	Здесь происходит обьявление функции, которая ничего не принимает
	и возвращает обьект типа 'String'
	Пустые круглые скобки не вызывают конструктор*/
	//str4.
	/*Если нужно явно вызвать Default-constructor,это можно сделать {} */
	String str5(8); //Создается строка длиной 8 байт
	String str6{ 8 }; //Создается строка длиной 8 байт,т. е. {} вызывают конструктор.
	String str7{}; //Явный вызов конструктора по умолчанию
	/*{} Следует использовать с осторожностью */

	String str9 = str3; //Коструктор копирования
	str9.info();
#endif // CALLING_CONSTRUCTOR


}
#pragma once
#include<Windows.h>
#include<iostream>
using namespace std;
using std::cout;
using std::endl;
using std::cin;
#define delimetr "--------------------------"


/*Обьявление Класса - Class Declaration*/
class String;
String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);
std::istream& operator>>(std::istream& cin, String& obj);
std::istream& getline(std::istream& cin, String& obj);
class String
{
	int size;
	char* str;
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	// Constructors
	explicit String(int size = 80);
	String(const char str[]);
	String(const String& other);
	String(String&& other);
	~String();
	//Operators
	String& operator=(const String& other);
	String& operator=(String&& other);
	String& operator+=(const String& other);
	//Methods
	const char& operator[](int i)const;
	char& operator[](int i);
	void info()const;
};
/*Конец обьявления класса - Class Declaration end*/

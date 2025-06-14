#include<iostream>
using namespace std;
using std::sin;
using std::cout;
using std::endl;
#define delimetr "_______________________________\n"

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	// Constructors;
	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(int x)
	{
		this->x = x;
		this->y = 0;
		cout << "Constructor\t\t" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor\t\t" << this << endl;
	}


	//Point(const Point& other) = delete;// запрет копирования объектов

	//CopyConstructor;
	Point(const Point& other)
	{
		//this - этот объект
		//other - тот объект
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	                             //Operators:
	void operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
	}
	Point& operator++()
	{
		this->x++;
		this->y++;
		return *this;
	}
	                             // Methods:
	double distance(const Point& other)const
	{
		//other.x *= 100;
		//this->x *= 100;
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const
	{
		cout << "X = " << get_x() << "\tY = " << get_y() << endl;
	}
};

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);
}

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}


//#define STRUCT_POINT
//#define CONSTRACTOR_CHEK
//#define DISTANCE_CHECK
//#define ASSIGMANT_CHECK

void main()
{
	setlocale(LC_ALL, "ru");
#ifdef STRUCT_POINT
	int a; // обьявление типа 'int';
	Point A;  // обьявление переменной 'A' типа 'Point';
	// Создание обьекта 'А' структуры 'Point';
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;
	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;

#endif // STRUCT_POINT

#ifdef CONSTRACTOR_CHEK
	Point A; // Здесь не явно вызывается конструктор по умолчанию;
	/*A.set_x(2);
	A.set_y(3);*/
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();


	Point B = 5;
	//cout << B.get_x() << "\t" << B.get_y() << endl;
	B.print();


	Point C(7, 8);
	C.print();

	Point D = C; // CopyConstructor
	D.print();

	Point E; //Default constructor
	E = D;   //CopyAssignment
	E.print();

#endif // CONSTRACTOR_CHEK

#ifdef DISTANCE_CHECK

	Point A(2, 3);
	Point B(7, 8);
	A.print();
	B.print();
	cout << delimetr << endl;
	cout << "Расстояние от точки А до точки B :" << A.distance(B) << endl;
	cout << delimetr << endl;
	cout << "Расстояние от точки B до точки A :" << B.distance(A) << endl;
	cout << delimetr << endl;
	cout << "Расстояние между точками А и B: " << distance(A, B) << endl;
	cout << delimetr << endl;
	cout << "Расстояние между точками B и A: " << distance(B, A) << endl;
	cout << delimetr << endl;
	

#endif // DISTANCE_CHECK

#ifdef ASSIGMANT_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	//cout << Point(2, 3).distance(Point(7, 8)) << endl;

	Point A, B, C;
	//A = B = C = Point(2, 3);
	A.print();
	B.print();
	C.print();
#endif // ASSIGMANT_CHECK


	Point A(2, 3);
	Point B(4, 5);
	Point C = A + B;
	C.print();

	for (Point i(2, 3); i.get_x() < 10; ++i)
	{
		i.print();
	}


}
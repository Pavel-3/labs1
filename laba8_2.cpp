#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

double Sx(double, int);
double error(double, int);
double Yx(double);

template <typename T>
void prov(T m)
{
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(INT16_MAX, '\n');
		cout << "Error" << endl;
		cout << "Введите другое значение" << endl;
		cin >> m;
	}
}

void Out_Rez(double (*f)(double), double, double, double);
void Out_Rez(double (*f)(double, int), double, double, double, int);

int main()
{
	setlocale(LC_ALL, "ru");
	double a, b, h;
	int n;
	cout << "введите a = ";    cin >> a;	prov(a);
	cout << "введите b = ";    cin >> b;	prov(b);
	cout << "введите h = ";    cin >> h;	prov(h);
	cout << "введите n = ";    cin >> n;	prov(n);
	cout << "Выберите функцию :\n\t1) Y(x) \n\t2) S(x)\n\t3) |S(x) - Y(x)| \n";
	printf("%s\n", "x      f(x)");
	switch (_getch())
	{
	case '1':
		Out_Rez(Yx, a, b, h);
		break;
	case '2':
		Out_Rez(Sx, a, b, h, n);
		break;
	default : 
		Out_Rez(error, a, b, h, n);
		break;
	}
	system("pause");
}

double error(double x, int n)
{
	return fabs(Yx(x) - Sx(x, n));
}

double Sx(double x, int n)
{

	double sum = 1, w = 1;
	for (int i = 1; i <= n; ++i)
	{
		w *= i;
		sum += cos(i * x) / w;
	}
	return sum;
}

double Yx(double x)
{
	return  exp(cos(x)) * cos(sin(x));
}

void Out_Rez(double (*f)(double), double a, double b, double h)
{
	for (double x = a; x < b; x += h)
	{
		printf("%4.2f  %9.6f\n", x, f(x));
	}
}

void Out_Rez(double (*f)(double, int), double a, double b, double h, int n)
{
	for (double x = a; x < b; x += h)
	{
		printf("%4.2f  %9.6f\n", x, f(x, n));
	}
}
void Out_Rez(double (*f)(double), double (*g)(double, int), double a, double b, double h, int n)
{
	for (double x = a; x < b; x += h)
	{
		printf("%4.2f  %9.6f\n", x, fabs(f(x) - g(x, n)));
	}
}

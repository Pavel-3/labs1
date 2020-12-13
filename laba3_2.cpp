#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

double s(double x, int n);
double y(double x);

void prov(double m);
void prov(int m);

int main()
{
	setlocale(LC_CTYPE, "rus");

	double a, b, h, x;
	int n;
	bool p=false;
	while (!p)
	{
		cout << "введите a = ";    cin >> a;	prov(a);
		cout << "введите b = ";    cin >> b;	prov(b);
		cout << "введите h = ";    cin >> h;	prov(h);
		cout << "введите n = ";    cin >> n;	prov(n);
		if (a < b && h > 0 || a > b && h < 0)
			p = true;
		else
			cout << "Невохможно вычислить результат\nВведите другие значения\n";
	}
	cout << "  x      S(x)      Y(x)     |S(x)-Y(x)| \n";
	for (x = a; x <= b && h > 0 || x < b && h < 0; x += h)
		printf("%4.2lf  %9.6lf  %9.6lf  %9.6lf\n", x, s(x, n), y(x), fabs(s(x, n) - y(x)));
}

double s(double x, int n)
{
	double sum = 1, w = 1;
	for (int i = 1; i <= n; ++i)
	{
		w *= i;
		sum += cos(i * x) / w;
	}
	return sum;
}

double y(double x)
{
	return  exp(cos(x)) * cos(sin(x));
}

void prov(double m)
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
void prov(int m)
{
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(INT16_MAX, '\n');
		cout << "error" << endl;
		cout << "Введите другое значение" << endl;
		cin >> m;
	}
}
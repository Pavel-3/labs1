#include <iostream>
#include <math.h>

using namespace std;

int Fact(int n);
void prov(double m);
void prov(int m);
double Sum(double x/*x*/ , int n/*конечное значение*/);
double Vich(double x);

int main()
{
    setlocale(LC_CTYPE, "rus");
    int n=1;
    double a = 0.1, b = 1, h = 0.1, Yx = 0, Sx = 0, mod=0, x, err;
    bool p = false;
    cout << "Введитe погрешность\n";
    cin >> err;
    /*while(p == false)
    {
        cout << "введите a" << endl;    cin >> a;   prov(a); 
        cout << "введите b" << endl;    cin >> b;   prov(b);
        cout << "введите h" << endl;    cin >> h;   prov(h);
        if (a > b && h>0)
        {
            p = false;
            cout << "Переменая a не может быть меньше b \n";
        }
        else {
            p = true;
        }
    }*/
    //cout << "введите n" << endl;    cin >> n;   prov(a);
    do
    {
        if (mod <= err && err != 0)
            cout << "x" << "\t" << "S(x)" << " " << '\t' << "Y(x)" << '\t' << '\t' << " " << "|Y(x)-S(x)|" << endl;
        while (a < b)
        {
            x = a;
            Sx = 0;
            Sx = Sum(x, n);
            Yx = Vich(x); /*Yx = exp(cos(a))*cos(sin(a));*/
            mod = abs(Yx - Sx);
            if (x == 0.7)
                cout << x << "\t" << Sx << '\t' << " " << Yx << "         " << '\t' << mod << endl;
            else
                cout << x << "\t" << Sx << '\t' << " " << Yx << " " << '\t' << mod << endl;
            a += h;
        }
        n++;
        cout << '\n' << "S(x)=" << Sx << "\t" << "Y(x)=" << Yx << '\t' << '\t' << " " << "S(x)+|Y(x)-S(x)|" << mod << "\t   " << "|Y(x)-S(x)|=" << abs(Yx - Sx);
    } while (mod >= err);
    cout<< "\n\nn=" << --n <<"\n\n";
}

int Fact(int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    if (n > 0)
        return n * Fact(n - 1);
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
double Sum (double x, int n)
{
    double Fx=0;
    for (int i = 0; i <= n; ++i)
    {
        Fx += cos(i * x) / Fact(i);
    }
    return Fx;
}
double Vich(double x)
{
    double Fx=0;
    Fx = exp(cos(x)) * cos(sin(x));
    return Fx;
}
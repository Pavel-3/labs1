#include <iostream>
#include <math.h>
using namespace std;

void prov(double m);

double Max(double a, double b);
double Min(double a, double b);
double Min(double a, double b, double c);
double Max(double a, double b, double c);

int main()
{
    setlocale(LC_CTYPE, "rus");
    double m, x, y, z;
    bool p = true;
        while (p)
        {
            cout << "Введите х = ";    cin >> x;   prov(x);
            cout << "Введите y = ";    cin >> y;   prov(y);
            cout << "Введите z = ";    cin >> z;   prov(z);
            if (Max(x, y, z) == 0)
                cout << "Ошибка максимальное значение не должно быть равно 0\n";
            else
                p = false;
        }
    m = (Min(z, x) + Min(x, y)) / pow(Max(x, y, z), 2);
    cout << "m=" << m<<endl;

}
void prov(double m)
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
double Max(double a, double b)
{
    return a > b ? a : b;
}
double Min(double a, double b)
{
    return a < b ? a : b;
}
double Min(double a, double b, double c)
{
    return Min(a, b) < c ? Min(a, b) : c;
}
double Max(double a, double b, double c)
{
    return Max(a, b) > c ? Min(a, b) : c;
}
#include <iostream>
#include <math.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

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

int main()
{
    setlocale(LC_CTYPE, "rus");

   
    srand(time(NULL));
    int n, i, num_1, num_2, col = 0, p = 1;
    cout << "n = ";   cin >> n;
    int *a = new int[n];
    for (i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    for (i = 0; i < n; i++)
        if (a[i] == 0)
        {
            col++;
            if (col == 1)   num_1 = i;
            if (col == 2)   num_2 = i;
        }
    if (col == 0)        cout << "Нет нулей";
    else if (col == 1)        cout << "Только один ноль";
    else if (num_2 == num_1 + 1)        cout << "Между первыми нулями ничего не находиться\n";
    else
    {
        for (i = num_1 + 1; i < num_2; i++)     p *= a[i];
        cout << "Произведение между нулями = " << p << endl;
    }

    delete[]a;

    system("pause");
    return 0;
}


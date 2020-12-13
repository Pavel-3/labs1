#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

template <typename T>
void prov(T m)
{
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(INT16_MAX, '\n');
        cout << "Error \n Введите другое число\n";
        cin >> m;
    }
}

void fill_array(int *, const int);
void solution(int *&, int &);

int main()
{
    setlocale(LC_CTYPE, "rus");
    int ary_size;
    cout << "Ведите размер массива = ";  cin >> ary_size ;
    int* ary = new int[ary_size];

    srand(time(NULL));
    fill_array(ary, ary_size);
    solution(ary, ary_size);
    cout << endl;

    if (ary_size == 0)  cout << "Массив пуст\n";
    else
    {
        for (int i = 0; i < ary_size; i++)
            cout << ary[i] << "  ";
        cout << endl;
    }
    delete[] ary;

    cout << endl;
    system("pause");
    return 0;
}

void fill_array(int* const ary, const int SIZE)
{
    cout << "Ведите '1' для случайного заполнения массива\n";
    if (_getch() == '1')
    {
        for (int i = 0; i < SIZE; i++)
        {
            ary[i] = rand() % 10;
            cout << ary[i] << '\t';
        }
        cout << endl;
    }
    else
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << "Введите " << i + 1 << "-й элемент массива: ";      cin >> ary[i];      prov(ary[i]);
        }
    }
}

void solution(int *&ary, int &ar_size)
{
    int ary_ed_size = 0;
    bool repeat = false; 

    int* new_ary = new int[ar_size];

    for (int i = 0; i < ar_size; i++)
    {
        repeat = false;
        
        for (int j = 0; j < ar_size; j++)
        {
            if (ary[i] == ary[j] && j != i)
                repeat = true;
        }
        if (!repeat)
        {
            new_ary[ary_ed_size] = ary[i];
            ary_ed_size++;
        }
    }
    delete[] ary;

    ar_size = ary_ed_size;
    ary = new int[ar_size];

    for (int i = 0; i < ar_size; i++)
        ary[i] = new_ary[i];
    delete[] new_ary;
}
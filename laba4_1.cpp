#include <iostream>
#include <math.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int random()
{
    if (rand() % 2 == 1)
        return -rand();
    else
        return rand();
}

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

void fill_array(int* const ary, const int SIZE);
double solution(int* const ary, const int SIZE);

int main()
{
    setlocale(LC_CTYPE, "rus");
    int arr_size;
    double average;
    bool k = false;
    while (!k)
    {
        cout << "Введите размер массива (от 1 до 20): ";    cin >> arr_size;    prov(arr_size);
        if (arr_size < 1 || arr_size > 20)
            cout << "Error\nЗначение должно быть в диапазоне от 1 до 20\n";
        else
            k = true;
    }
    srand(time(NULL));

    int* ary = new int[arr_size];
    fill_array(ary, arr_size);
    average = solution(ary, arr_size);
    if (average)
        cout << "Среднее арифметическое отрицательных элементов массива: " << average << endl;
    else
        cout << "В массиве отсутствуют отрицательные элементы\n";

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
            ary[i] = random() % 100;
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

double solution(int* const ary, const int SIZE)
{
    int counter = 0, neg_elem = 0;

    for (int i = 0; i < SIZE; i++)
    {
        if (ary[i] < 0)
        {
            counter++;
            neg_elem += ary[i];
        }
    }
    if (counter > 0)
        return (double)neg_elem / counter;
    else
        return 0;
}
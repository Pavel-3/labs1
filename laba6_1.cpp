#include <iostream>

using namespace std;

string fiures(std::string);

int main()
{
    setlocale(LC_ALL, "Russian");
    bool p = true;
    std::string str;
    cout << "Введите текст\n";      cin >> str;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] > 47 && str[i] < 58)
        {
            cout << str[i];
            p = false;
        }
    if (p)
        cout << "Нет цифр" << endl;
    cout << endl;
    system("pause");
    return 0;
}


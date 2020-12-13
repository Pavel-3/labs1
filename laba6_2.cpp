#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int solution(string);

int main()
{
    setlocale(LC_ALL, "ru");
    string str;

    cout << "Введите " << endl;
    getline(cin, str);

    cout << solution(str) << endl;
}

int solution(string str)
{
    int count_of_symbol = 0, count_of_one = 0;

    for (int i = 0; i == 0 || str[i - 1] != '\0'; i++)
    {
        if (str[i] == '1')
            count_of_symbol++;
        else if ((count_of_symbol % 2) == 1)
        {
            count_of_one += count_of_symbol;
            count_of_symbol = 0;
        }
        else
            count_of_symbol = 0;
    }
    return count_of_one;
}
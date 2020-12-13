#include <iostream>
#include <string>

using namespace std;

int count_of_words(string);

void output_words(string, int);

int main()
{
    setlocale(LC_ALL, "ru");
    string str;
    
    cout << "Enter words " << endl;
    getline(cin, str);
    int counter = count_of_words(str);
    cout << "The number of words is " << counter << endl;
    
    output_words(str, counter);
    system("pause");
    return 0;
}

int count_of_words(string str)
{
    int counter = 0;
    bool p = true;
    for (int i = 0; i == 0 || str[i - 1] != '\0'; i++)
    {
        if (str[i] != ' ' && str[i] != '\0')
        {
            p = false;
        }
        else if (!p || str[i] == '\0' && str[i - 1] != ' ')
        {
            counter++;
            p = true;
        }
    }

    return counter;
}

void output_words(string str, int counter)
{
    int counter_2 = 1;
    bool p = false;
    cout << "\nWord 1: ";
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != ' ')
        {
            cout << str[i];
            p = false;
        }
        else if (!p && counter_2 < counter)
        {
            counter_2++;
            p = true;
            cout << "\nWord " << counter_2 << ": ";
        }
    cout << endl << endl;
}
#include <iostream>

using namespace std;

double solution(int n, int i = 0)
{
    if (i < n)
        return 1 / (1 + solution(n, i + 1));
    else
        return 1;
}


int main()
{
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Введите n: ";  cin >> n;
    cout << solution(n);
}
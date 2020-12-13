#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

template <typename T>
void prove(T a)
{
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(INT16_MAX, '\t');
		cout << "Error\nВведите другое значение";
		cin >> a;
	}
}

void fill_array(int** const ary, const int M, const int N);
int solution(int** ary, const int M, const int N);

int main()
{
	setlocale(LC_CTYPE, "rus");
	int n, m;
	cout << "Введите n = ";		cin >> n;	prove(n);//строки
	cout << "Введите m = ";		cin >> m;	prove(m);//столбцы
	cout << endl;

	int** matrix = new int*[n];
	for (int i = 0; i < n; i++)
		matrix[i] = new int [m];
	srand(time(NULL));

	fill_array(matrix, m, n);

	if (m <= 2)
		cout << "Количество таких элементов вычислить невозможно\n";
	else if (solution(matrix, m, n))
		cout << "количество таких элементов: " << solution(matrix, m, n) << endl;
	else
		cout << "Таких элементов нет \n";

	for (int i = 0; i < n; i++)
		delete[] matrix[i];
	delete[] matrix;

	cout << endl;
	system("pause");
	return 0;
}

void fill_array(int** const ary, const int M, const int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << "Строка " << i + 1 << endl;
		for (int j = 0; j < M; j++)
		{
			cout << "array[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> ary[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			printf("%5i", ary[i][j]);
		cout << endl;
	}
}
int solution(int** ary, const int M, const int N)
{
	int count_of_elements = 0;
	for (int i = 0; i < N; i++)
		for (int j = 1; j < M - 1; j++)
			if (ary[i][j - 1] > ary[i][j] && ary[i][j + 1] < ary[i][j])
				count_of_elements++;
	return count_of_elements;
}
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

int random()
{
	if (rand() % 2 == 1)
		return -rand();
	else
		return rand();
}

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

void fill_array(int** ary, const int N, const int M, bool& pos_elem);

int solution(int** ary, const int N, const int M);
bool check_for_pos(int** ary, const int N, const int M);

int main()
{
	setlocale(LC_CTYPE, "rus");

	int n, m;
	bool pos_elem = true;

	cout << "Введите n = ";	cin >> n;	prove(n);
	cout << "Введите m = ";	cin >> m;	prove(m);

	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
		matrix[i] = new int[m];

	srand(time(NULL));

	fill_array(matrix, n, m, pos_elem);

	if (check_for_pos(matrix, n, m))
		cout << endl << "Сумма таких элеметов равна: " << solution(matrix, n, m);
	else
		cout << "Нет таких столбцов, в которых не было бы хотя бы одного отрицательного числа\n";

	for (int i = 0; i < n; i++)
		delete[] matrix[i];
	delete[] matrix;

	cout << endl;
	system("pause");
	return 0;
}

void fill_array(int** ary, const int N, const int M, bool& pos_elem)
{
	cout << "Ведите '1' для случайного заполнения массива\n";
	if (_getch() == '1')
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				ary[i][j] = random() % 100;
				printf("%4i", ary[i][j]);
			}
			cout << endl;
		}
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cout << "array[" << i + 1 << "][" << j + 1 << "] = ";
				cin >> ary[i][j];
			}
			cout << endl;
		}
	}

}
int solution(int** ary, const int N, const int M)
{
	bool neg_elem;
	int sum = 0;
	for (int j = 0; j < M; j++)
	{
		neg_elem = false;
		for (int i = 0; i < N; i++)
			if (ary[i][j] < 0)
				neg_elem = true;
		if (!neg_elem)
			for (int i = 0; i < N; i++)
				sum += ary[i][j];
	}
	return sum;
}
bool check_for_pos(int** ary, const int N, const int M)
{
	bool neg = false, pos = false;
	for (int j = 0; j < M; j++)
	{
		neg = false;
		for (int i = 0; i < N; i++)
			if (ary[i][j] < 0)
				neg = true;
		if (!neg)
			pos = true;
	}
	return pos;
}
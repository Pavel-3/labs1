#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

template <typename T>
void prove(T a);

void fill_array(int** ary, const int N, const int M);

void solution(int** ary, const int N, const int M);

int main()
{
	setlocale(LC_CTYPE, "rus");
	srand(time(NULL));
	int n, m, sum = 0;
	cout << "Введите n: ";	cin >> n;	prove(n);
	cout << "Введите m: ";	cin >> m;	prove(m);

	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
		matrix[i] = new int[m];

	fill_array(matrix, n, m);
	
	solution(matrix, n, m);

	cout << endl;

	for (int i = 0; i < n; i++)
		delete[] matrix[i];
	delete[] matrix;

	system("pause");
	return 0;
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

void fill_array(int** ary, const int N, const int M)
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
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%5i", ary[i][j]);
		}
		cout << endl;
	}
}

void solution(int** ary, const int N, const int M)
{
	bool col = true, row = true, p = true;

	for (int i = 0; i < N; i++)
	{
		
		for (int j = 0; j < M; j++)
		{
			col = true, row = true;
			for (int i1 = 0; i1 < N; i1++)
				if (ary[i][j] < ary[i1][j])
					col = false;
			for (int j1 = 0; j1 < M; j1++)
				if (ary[i][j] > ary[i][j1])
					row = false;

			if (row && col)
			{
				cout << '[' << i + 1 << "][" << j + 1 << ']' << '\t';
				p = false;
			}

			col = true, row = true;
			for (int i1 = 0; i1 < N; i1++)
				if (ary[i][j] > ary[i1][j])
					col = false;
			for (int j1 = 0; j1 < M; j1++)
				if (ary[i][j] < ary[i][j1])
					row = false;

			if (row && col)
			{
				cout << '[' << i + 1 << "][" << j + 1 << ']' << '\t' << endl;
				p = false;
			}
		}
	}
	if (p)
		cout << "\nТаких элемениов нет\n";
}
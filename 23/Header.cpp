#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include "Header.h"

using namespace std;

bool file_matrix(int mat[][500], const int N, int &n, int &m)
{
	char filename[30];

	cout << "Enter file name: " << endl;
	cin >> filename;

	ifstream fin(filename);

	if (!fin)
	{
		cout << "Problems with file!" << endl;

		return 0;
	}
	else
	{
		n = 0;
		m = 0;

		if (fin >> n >> m)
		{

			if (n != m || n > N)
			{
				cout << "Incorrect range of matrix" << endl;
				return 0;
			}

			int i = 0, j = 0;

			while (fin >> mat[i][j])
			{
				if (fin.fail() && !fin.eof())
				{
					cout << "Wrong input! " << endl;
					fin.close();
					return 0;
				}
				j++;
				if (j == n)
				{
					j = 0;
					i++;
				}
			}

			fin.close();

			if (i != n && j != n)
			{
				cout << "<<<K16-gavryliuk-23/" << filename << ": INPUT ERROR>>> " << endl;
				return 0;
			}

			return 1;
		}
		else
		{
			cout << "File is empty! " << endl;
			return 0;
		}
	}
}
void edit_matrix(int mat[][500], const int N, int n, int m)
{
	bool arr[501] = {};
	int k = 0, i, j;
	bool ok = 1;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			if (mat[i][j] > n || mat[i][j] < 1)
			{
				ok = 0;
				break;
			}
			else
				if (arr[mat[i][j]] == 0)
					arr[mat[i][j]] = 1;
				else
				{
					ok = 0;
					break;
				}

		if (ok)
		{
			k++;
			out_vector(mat[i], i, n);
		}

		memset(arr, 0, sizeof(arr));
		ok = 1;
	}
	if (k == 0)
		cout << "There aren't any lines which have numbers 1, .., n only once" << endl;

}
void out_vector(int mat[], int i, int n)
{
	cout << "Line number " << i << ": " << endl;
	for (int j = 0; j < n; j++)
	{
		cout << mat[j] << ' ';
	}
	cout << endl;
}
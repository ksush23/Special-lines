#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	cout << "Gavryliuk Oksana\n" << "Program will identify numbers of lines which have numbers 1, .., n only once\n";
	
	const int N = 500;
	int mat[N][N];
	int n, m;

	if (file_matrix(mat, N, n, m))
		edit_matrix(mat, N, n, m);

	system("pause");

	return 0;
}
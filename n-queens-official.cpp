# backtracking_pepcoding#include<bits/stdc++.h>
using namespace std;

bool queen_safe(int** a, int row, int col, int n)
{
	for (int i = row,  j = col - 1; j >= 0; j--)
	{
		if (a[i][j] == 1)
		{
			return false;
		}
	}

	for (int i = row - 1,  j = col - 1; i >= 0 and j >= 0; i--, j--)
	{
		if (a[i][j] == 1)
		{
			return false;
		}
	}

	for (int i = row - 1,  j = col + 1; i >= 0 and j < n; i--, j++)
	{
		if (a[i][j] == 1)
		{
			return false;
		}
	}

	for (int i = row - 1, j = col; i >= 0; i--)
	{
		if (a[i][j] == 1)
		{
			return false;
		}
	}

	return true;
}

void nqueens(int **a, int n, string qsf, int row)
{
	if (row == n)
	{
		cout << qsf << endl;
		return;
	}
	for (int col = 0; col < n; col++)
	{
		if (queen_safe(a, row, col, n))
		{
			a[row][col] = 1;
			nqueens(a, n, qsf + to_string(row) + "-" + to_string(col) + ",", row + 1);
			a[row][col] = 0;
		}
	}
}

int main()
{
#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int** a = new int*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}
	nqueens(a, n, "", 0);
}

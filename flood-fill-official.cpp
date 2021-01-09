#include<bits/stdc++.h>
using namespace std;

void floodfill(int **a, int sr, int sc, int dr, int dc, string path, bool** visited)
{

	if (sr == dr and sc == dc)
	{
		cout << path << " ";
		return;
	}

	if (sr<0 or sr>dr or sc<0 or sc>dc or a[sr][sc] == 1 or visited[sr][sc] == true )
	{
		return;
	}
	visited[sr][sc] = true;
	floodfill(a, sr - 1, sc, dr, dc, path + "t", visited);
	floodfill(a, sr, sc - 1, dr, dc, path + "l", visited);
	floodfill(a, sr + 1, sc, dr, dc, path + "d", visited);
	floodfill(a, sr, sc + 1, dr, dc, path + "r", visited);

	visited[sr][sc] = false;
}


int main()
{
#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	int m;
	cin >> n >> m;
	int ** a = new int*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	bool** visited = new bool*[n];
	for (int i = 0; i < n; i++)
	{
		visited[i] = new bool[m];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = false;
		}
	}
	floodfill(a, 0, 0, n - 1, m - 1, " ", visited);
}

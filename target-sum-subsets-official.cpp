# backtracking_pepcoding#include<bits/stdc++.h>
using namespace std;

void subset_sum(int a[], int i, int n, string path, int sum, int tar)
{
	if (i == n)
	{
		//cout << path << endl;
		if (sum == tar)
		{
			cout << path << endl;
		}
		return;
	}
	subset_sum(a, i + 1, n, path + to_string(a[i]) + ",", sum + a[i],  tar);
	subset_sum(a, i + 1, n, path, sum,  tar);
}


int main()
{
#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int tar;
	cin >> tar;
	subset_sum(a, 0, n , "", 0, tar);
}

#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 2167 2차원 배열의 합
int main() {
	int nm[300][300];
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> nm[i][j];
	int k;
	cin >> k;
	while (k--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int max = 0;
		for (a--; a < c; a++)
			for (int j=b-1; j < d; j++)
				max += nm[a][j];
		cout << max << endl;
	}
}
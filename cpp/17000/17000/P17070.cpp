#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 파이프 옮기기
int n;
int home[16][16];
int answer = 0;
void dfs(int i,int j,int w) {
	
	if (i < 0 || i >= n || j<0 || j >= n || home[i][j] == 1)
		return;
	if (w==1&&(home[i][j - 1] == 1 || home[i - 1][j] == 1))
		return;
	if (i == n - 1 && j == n - 1)
		answer++;



	if (w == 0) {
		dfs(i, j + 1, 0);
		dfs(i + 1, j + 1, 1);
	}
	else if (w == 1) {
		dfs(i, j + 1, 0);
		dfs(i + 1, j + 1, 1);
		dfs(i + 1, j, 2);
	}
	else if (w == 2) {
		dfs(i + 1, j, 2);
		dfs(i + 1, j + 1, 1);
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> home[i][j];
	dfs(0, 1, 0);
	cout << answer;
}
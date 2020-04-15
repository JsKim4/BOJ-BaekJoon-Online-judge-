#include<iostream>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
// 11058 크리보드
long long dp[110][4] = { {1,0,0,0},{2,1,0,0},{3,2,1,0}};
int n;
void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}
void solve(int i) {
	if (i > n) return;
	long long m = max(max(dp[i - 1][0], dp[i - 1][1]), max(dp[i - 1][2], dp[i - 1][3]));
	dp[i][0] = m+1;
	dp[i][1] = m;
	dp[i][2] = dp[i - 1][1];
	dp[i][3] = max(max(dp[i - 1][2] * 2, dp[i - 2][2] * 3), dp[i - 3][2] * 4);
	solve(i + 1);
}
int main() {
	cin >> n;
	solve(3);
	cout << max(max(dp[n - 1][0], dp[n - 1][1]), max(dp[n - 1][2], dp[n - 1][3]));
}
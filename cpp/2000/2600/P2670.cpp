#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 2670 연속부분최대곱
double n[10001];
double dp[10001];
int main() {
	int m;
	cin >> m;
	for (int i = 0; i < m;i++) {
		cin >> n[i];
	}
	for (int i = 0; i < m;i++) {
		double ans = n[i]; dp[i] = n[i];
		for (int j = i+1; j < m;j++) {
			ans *= n[j];
			if (ans > dp[i])
				dp[i] = ans; 
		}
	}
	double mx = dp[0];
	for (int i = 1; i < m; i++) {
		if (mx < dp[i])
			mx = dp[i];
	}
	printf("%.3lf",mx);
}
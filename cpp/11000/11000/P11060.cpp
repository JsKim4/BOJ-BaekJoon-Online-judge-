#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 11060 점프 점프
int bridge[1200];
int dp[1200];
int n;
void solve(int i) {
	if (i == n)
		return;
	for (int j = 1; j <= bridge[i];j++) {
		if (dp[i + j] == -1 || dp[i + j] > dp[i] + 1) {
			dp[i + j] = dp[i] + 1;
			solve(i + j);
		}
	}
}
int main() {
	scanf("%d",&n);
	for (int i = 0; i < n;i++) {
		scanf("%d",&bridge[i]);
		dp[i] = -1;
	}
	dp[0] = 0;
	solve(0);
	printf("%d\n",dp[n-1]);
}
#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 2294 동전2
int coin[100];
int dp[20000];
int n,k;
void solve(int i) {
	if (i > k) {
		return;
	}
	for (int j = 0; j < n; j++) {
		if (dp[i + coin[j]] == -1 || dp[i + coin[j]] > (dp[i] + 1)) {
			dp[i + coin[j]] = dp[i] + 1;
			solve(i + coin[j]);
		}
	}
}
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
		if (coin[i] > k) {
			i--; n--;
		}
	}
	for (int i = 0; i < k+100; i++) 
		dp[i] = -1;
	dp[0] = 0;
	solve(0);
	printf("%d\n", dp[k]);
}
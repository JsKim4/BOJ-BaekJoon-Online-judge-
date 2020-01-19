#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 10835 카드게임
int m[2000];
int R[2000]; int L[2000];
int n;
int c = 0;
void dp(int l,int r, int num) {
	c++;
	if (l == n || r == n)
		return;
	if (R[r] < L[l]) {
		if (num + R[r] > m[l]) {
			m[l] = num + R[r];
			dp(l, r + 1, num + R[r]);
		}
		else
			return;
	}
	else {
		if (m[l+1] == -1) {
			if(m[l]<num)
				m[l] = num;
			dp(l + 1, r, num);
			dp(l + 1, r + 1, num);
		}
	}
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;
// 10835 카드게임
int dp[2000][2000];
int R[2000]; int L[2000];
int n;
int c = 0;
int solve(int l, int r) {
	c++;
	//printf("%d %d %d\n",l,r,dp[l][r]);
	if (l == n || r == n)
		return 0;
	if (dp[l][r] != -1)
		return dp[l][r];
	dp[l][r] = max(solve(l+1,r),solve(l+1,r+1));
	if (L[l] > R[r]) 
		dp[l][r] = max(dp[l][r],R[r]+solve(l,r+1));
	return dp[l][r];
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &L[i]);
	for (int i = 0; i < n; i++) scanf("%d", &R[i]);
	for (int i = 0; i < n; i++) m[i] = -1;
	dp(0, 0, 0);
	int mx = 0;
	for (int i = 0; i < n;i++)
		if (mx < m[i])
			mx = m[i];        
	printf("%d", mx);
}              
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n;j++) {
			dp[i][j] = -1;
		}
	printf("%d", solve(0, 0));
}

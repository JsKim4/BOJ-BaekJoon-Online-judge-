#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 14501 퇴사
int dp[30];
int num[15][2];
int n;
void solve(int i,int nn) {
	if (i > n) 
		return;
	if (dp[i] < nn) {
		dp[i] = nn;
		solve(i + num[i][0], nn + num[i][1]);
		solve(i + 1, nn);
	}

}
int main() {
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &num[i][0], &num[i][1]);
		dp[i] = -1;
	}
	int m = 0;
	solve(0, 0);
	for (int i = 0; i < n+1; i++) {
		if (dp[i] > m)
			m = dp[i];
	}
	printf("%d",m);
}
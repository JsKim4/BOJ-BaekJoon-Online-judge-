#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 2240 자두나무
int t, w;
int dp[30][1000];
int fruit[1000];
void solve(int i, int j, bool now) {

	printf("print %d %d %d\n", i, j, now);
	if (j>t) return;
	if (now + 1 == fruit[j]) {
		if (dp[i][j + 1] == -1 || dp[i][j + 1] < dp[i][j] + 1) {
			printf("stand eat %d %d %d\n",i,j,now);
			dp[i][j + 1] = dp[i][j] + 1;
			solve(i, j + 1, now);
		}
	}
	else {
		if (dp[i][j + 1] == -1 || dp[i][j + 1] < dp[i][j] + 1) {
			printf("stand dont %d %d %d\n", i, j, now);
			dp[i][j + 1] = dp[i][j];
			solve(i, j + 1, now);
		}
		if (i<w&&(dp[i + 1][j + 1] == -1 || dp[i + 1][j + 1] < dp[i][j] + 1)) {
			printf("move eat %d %d %d\n", i, j, now);
			dp[i + 1][j + 1] = dp[i][j] + 1;
			solve(i + 1, j + 1, !now);
		}
	}
	printf("close %d %d %d\n", i, j, now);
}
int main() {
	scanf("%d %d",&t,&w);
	for (int i = 0; i < t; i++)
		scanf("%d",&fruit[i]);
	for (int i = 0; i <= t; i++)
		for (int j = 0; j <= w; j++)
			dp[i][j] = -1;
	solve(0,0,0);
	for (int i = 0; i <= t; i++) {
		for (int j = 0; j <= w; j++)
			printf("%d ", dp[i][j]);
		printf("\n");
	}
	
}
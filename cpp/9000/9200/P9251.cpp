#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 9251 LCS
int dp[1000][1000];
char s[2][1001];
int n;
int m = 0;
void solve(int i,int j,int num) {
	if (s[0][i] == 0 || s[1][j] == 0)
		return;
	//printf("%c %c\n",s[0][i], s[0][j]);
	if (s[0][i]==s[1][j]) {
		if (dp[i][j] < num + 1) {
			dp[i][j] = num +1;
			if (m < num + 1)
				m = num + 1;
			solve(i+1,j+1,num +1);
		}
	}
	else {
		if (dp[i][j] < num) {
			dp[i][j] = num;
			if (m < num)
				m = num;
			solve(i, j + 1, num);
			solve(i + 1, j, num);
		}
	}

}
int main() {
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			dp[i][j] = -1;
		}
	}
	scanf("%s %s", &s[0], &s[1]); solve(0, 0, 0);
	printf("%d",m);

}
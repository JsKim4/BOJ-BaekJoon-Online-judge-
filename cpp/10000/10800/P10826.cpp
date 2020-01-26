#include<iostream>
#include<cstring>
#pragma warning (disable:4996)
using namespace std;
// 10826 피보나치 수 4
int num[10001][2091];
void solve(int i) {
	int j;
	for (j=0; num[i - 2][j]!=-1;j++) {
		num[i][j + 1] = (num[i - 2][j] + num[i - 1][j] + num[i][j]) / 10;
		num[i][j] = (num[i - 2][j] + num[i - 1][j] + num[i][j]) % 10;
	}
	if (num[i - 1][j] == -1) {
		if (num[i][j] == 0)
			num[i][j] = -1;
		else
			num[i][j + 1] = -1;
	}
	else {
		num[i][j+1] = (num[i][j] + num[i - 1][j]) / 10;
		num[i][j] = (num[i][j] + num[i - 1][j])%10;
		if (num[i][j + 1] == 0)
			num[i][j + 1] = -1;
		else
			num[i][j + 2] = -1;

	}
}
int main() {
	num[0][0] = 0;
	num[0][1] = -1;
	num[1][0] = 1;
	num[1][1] = -1;
	for (int i = 2; i <= 10000;i++) {
		solve(i);
	}
	int n;
	scanf("%d",&n);
	int i;
	for (i = 0; num[n][i] != -1; i++);
	i--;
	while (i >= 0)
		printf("%d",num[n][i--]);
}
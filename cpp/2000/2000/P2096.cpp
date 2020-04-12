#include<iostream>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
// 2096 내려가기
int n;
int dp[4][3];
int arr[3];
void solve(int i) {
}
int main(){
	cin >> n;
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < 3;j++) {
			scanf("%d",&arr[j]);
		}
		dp[0][0] = min(dp[2][0], dp[2][1])+arr[0];
		dp[0][1] = min(dp[2][0], min(dp[2][1], dp[2][2]))+arr[1];
		dp[0][2] = min(dp[2][1], dp[2][2])+arr[2];

		dp[1][0] = max(dp[3][0], dp[3][1])+arr[0];
		dp[1][1] = max(dp[3][0], max(dp[3][1], dp[3][2]))+arr[1];
		dp[1][2] = max(dp[3][1], dp[3][2])+arr[2];


		dp[2][0] = dp[0][0];
		dp[2][1] = dp[0][1];
		dp[2][2] = dp[0][2];

		dp[3][0] = dp[1][0];
		dp[3][1] = dp[1][1];
		dp[3][2] = dp[1][2];
	}
	cout << max(dp[1][0], max(dp[1][1], dp[1][2])) << " "<< min(dp[0][0], min(dp[0][1], dp[0][2]));
}
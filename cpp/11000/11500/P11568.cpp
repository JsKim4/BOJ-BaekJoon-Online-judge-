#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 11568 민균이의 계략
int arr[1001];
int dp[1001];
int main(){
	for (int i = 0; i < 1000;i++) {
		dp[i] = 1;
	}
	int n;
	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> arr[i];
	}
	int answer=0;
	for (int i = 1; i <= n;i++) {
		int m = 0;
		for (int j = i - 1; j >= 0;j--) {
			if (arr[i] > arr[j]) {
				if (m < dp[j]) {
					m = dp[j];
				}
			}
		}
		dp[i] += m;
		if (answer < dp[i])
			answer = dp[i];
		//cout << i << " " << dp[i] << endl;
	}
	cout << answer;
}
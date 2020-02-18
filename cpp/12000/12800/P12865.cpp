#include<iostream>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
// 12865 평범한 배낭
int dp[100][100000];
int item[100][2];

int n, k;
int solve(int pos,int cap) {
	if (pos == n)
		return 0;
	int ret = dp[pos][cap];
	if (ret != -1)return ret;
	if (item[pos][0]<=cap)
		ret = solve(pos+1,cap-item[pos][0])+item[pos][1];
	dp[pos][cap] = max(ret, solve(pos + 1, cap));
	return dp[pos][cap];
}
int main(){
	cin >> n >> k;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= k; j++)
			dp[i][j] = -1;
	for (int i = 0; i < n; i++) cin >> item[i][0] >> item[i][1];
	cout << solve(0, k);
}
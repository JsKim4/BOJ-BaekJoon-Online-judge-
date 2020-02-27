#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#pragma warning (disable:4996)
using namespace std;
// 2023 신기한 소수
bool num[10010] = {true,true};
vector<int>dml;
bool ckDecimal(int n) {
	for (int i = 0; dml[i] * dml[i] <= n;i++) {
		if (n % dml[i] == 0)
			return false;
	}
	return true;
}
int main()
{
	vector<int>q[8];
	for (int i = 2; i <= 100; i++){
		if (!num[i]){
			for (int j = i*2; j <= 10000; j += i){
				num[j] = true;
			}
		}
	}

	for (int i = 0; i < 10010;i++) {
		if(!num[i])
			dml.push_back(i);
	}
	q[0].push_back(2); q[0].push_back(3); q[0].push_back(5); q[0].push_back(7);
	int k = 0;
	for (int i = 0; i < 7;i++) {
		for (int j = 0; j < q[i].size();j++) {
			for (int t = 1; t < 10;t++) {
				int testTmp = q[i][j]*10+t;
				if (ckDecimal(testTmp)) {
					q[i + 1].push_back(testTmp);
				}
			}
		}
	}
	int n;
	cin >> n;
	for (int i = 0; i < 8; i++)
		sort(q[i].begin(), q[i].end());
	for (int i = 0; i < q[n-1].size();i++) {
		cout << q[n - 1][i]<<endl;
	}
}
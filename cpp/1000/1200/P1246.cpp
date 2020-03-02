#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 1246 온라인 판매
int main(){
	long long answer = 0,a2;
	int n, m;
	int p[1000];
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> p[i];

	for (int i = 0; i < m;i++) {
		long long mo = p[i]; long long c = 0;
		for (int j = 0; j < m;j++) {
			if (mo <= p[j]) {
				c++;
			}
		}
		if (c > n)
			c = n;
		if (answer < mo * c) {
			a2 = mo;
			answer = mo * c;
		}
	}
	cout << a2 << "\n" << answer;
}
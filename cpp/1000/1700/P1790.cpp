#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#pragma warning (disable:4996)
using namespace std;
// 1790 수 이어쓰기2
long long num[10];
int main() {
	long long g = 9;
	for (int i = 0; i < 10; i++) {
		num[i] = g * (i + 1);
		g *= 10;
	}
	long long n, k, i;
	cin >> n >> k;
	long long ns = 0;

	long long s = num[0];
	for (i = 1; s < k; i++) {
		s += num[i];
	}
	i--;
	for (int j = 0; j < i; j++) {
		k -= num[j];
	}
	int t = pow(10, i);
	t == 1 ? 0 : t;
	int r = t + (k - 1) / (i + 1);
	if (r > n) {
		cout << -1;
		return 0;
	}
	int tt = pow(10, i);
	int ans = r / t;
	for (int j = 0; j <= (k - 1) % (i + 1); j++) {
		ans = (r % (tt * 10)) / tt;
		tt /= 10;
	}
	cout << ans;

}
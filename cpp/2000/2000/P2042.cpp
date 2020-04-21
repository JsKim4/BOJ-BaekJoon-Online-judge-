#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 2042 구간 합 구하기
long long arr[1000001];
long long num[1000001];
void update(long long i, long long n, long long m) {
	long long ii = i & (-i);
	long long c = n - arr[i];
	arr[i] = n;
	num[i] += c;
	for (long long j = i + ii; j <= m; j += (j & -j)) {
		num[j] += c;
	}
}
long long sum_f(int i) {
	long long sum = 0;
	for (int j = i; j > 0; j -= (j & -j)) {
		sum += num[j];
	}
	return sum;
}
int main() {
	long long n, m, k;
	scanf("%lld %lld %lld", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		long long num;
		scanf("%lld", &num);
		update(i, num, n);
	}
	while (m || k) {
		int a, b, c;
		cin >> a >> b >> c;
		if ((a - 1)) {
			k--;
			printf("%lld\n", sum_f(c) - sum_f(b) + arr[b]);
		}
		else {
			m--;
			update(b, c, n);
		}
	}
}
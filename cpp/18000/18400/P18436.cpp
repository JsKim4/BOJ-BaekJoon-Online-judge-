#include<iostream>
#include<queue>
#include<vector>
#include<map>
#pragma warning (disable:4996)
using namespace std;
long long arr[100001][2];
long long num[100001][2];
// 18436 수열과 쿼리 37
void update(long long i, long long n, long long m) {
	long long ii = i & (-i);
	long long c = arr[i][n] == 1 ? 0 : 1;
	arr[i][n] = 1;
	num[i][n] += c;
	for (long long j = i + ii; j <= m; j += (j & -j)) {
		num[j][n] += c;
	}

	c = arr[i][!n] == 1 ? -1 : 0;
	arr[i][!n] = 0;
	num[i][!n] += c;
	for (long long j = i + ii; j <= m; j += (j & -j)) {
		num[j][!n] += c;
	}
}
long long sum_f(long long i, long long n) {
	long long sum = 0;
	for (long long j = i ; j >0; j -= (j & -j)) {
		sum += num[j][n];
	}
	return sum;
}
void print(int m) {
	for (int i = 1; i <= m; i++) {
		cout << i << " " << num[i][0] <<" " <<num[i][1]<<endl;
	}
}
int main() {
	long long n, m;
	scanf("%lld", &n); 
	for (int i = 1; i <= n;i++) {
		long long num;
		scanf("%lld", &num);
		update(i, num%2,n);
	}
	//print(n);
	scanf("%lld", &m);
	while (m--) {
		long long  a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 1) {
			update(b, c % 2, n);
			//print(n);
		}
		else {
			printf("%lld\n", sum_f(c,a-2)-sum_f(b,a-2)+arr[b][a-2]);
		}
	}
}
#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 11658 구간 합 구하기 3
long long arr[1030][1030];
long long sum[1030][1030];
void update(long long i, long long j, long long c, long long n) {
	long long num = c - arr[i][j];
	arr[i][j] = c;
	for (long long u = i; u <= n; u += (u & -u)) {
		for (long long v = j; v <= n;v+=(v&-v)) {
			sum[u][v] += num;
		}
	}
}
long long sum_t(int i, int j) {
	long long result = 0;
	for (int u = i; u > 0; u -= (u & -u)) {
		for (int v = j; v > 0;v-=(v&-v)) {
			result += sum[u][v];
		}
	}
	return result;
}
void print(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", sum[i][j]);
		}
		cout << endl;
	}cout << endl; cout << endl;
}
int main() {
	long long n, m, w;
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int num;
			scanf("%d", &num);
			update(i, j, num, n);
		}
	}
	//print(n);
	while (m--) {

		//print(n);
		int w, x, y, z, q;
		scanf("%d %d %d %d", &w, &x, &y, &z);
		if (w) {
			scanf("%d", &q);
			long long answer = 0;
			//printf("%lld %lld %lld %lld\n",sum_t(z, q) , sum_t(x-1, y-1) , sum_t(x-1, q) , sum_t(z, y-1));
			answer = (sum_t(z, q)+sum_t(x-1,y-1)-sum_t(x-1,q)-sum_t(z,y-1));
			printf("%lld\n", answer);
		}
		else {
			update(x, y, z, n);
		}
	}
}
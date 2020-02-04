#include<iostream>
#include<vector>
#pragma warning (disable:4996)
using namespace std;
// 한글
int n, m;
vector<long long> A[500010];
long long a[500010];
void mi(int i,int money) {
	for (int j = 0; j < A[i].size(); j++) {
		a[A[i][j]] += money;
		mi(A[i][j], money);
	}
}
int main() {
	scanf("%d %d", &n, &m);
	scanf("%lld",&a[1]);
	long long x;
	for (int i = 2; i <= n;i++) {
		scanf("%lld %lld", &a[i], &x);
		A[x].push_back(i);
	}
	char order;
	int ord;
	while (m--) {
		cin >> order >> ord;
		if (order == 'u') {
			printf("%lld\n",a[ord]);
		}
		else {
			int money;
			scanf("%d",&money);
			mi(ord, money);
		
		}
	}
}
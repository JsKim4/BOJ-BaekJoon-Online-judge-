#include<iostream>
#pragma warning (disable:4996)
using namespace std;

int chk[20000001];
int answer[500001];
// 10816
int main() {
	int n;
	scanf("%d", &n);
	int na;
	for (int i = 0; i < n; i++) {
		scanf("%d", &na);
		chk[na + 10000000]++;
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &answer[i]);
		printf("%d ", chk[answer[i] + 10000000]);
	}

}

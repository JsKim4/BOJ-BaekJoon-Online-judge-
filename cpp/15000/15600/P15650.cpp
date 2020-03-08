#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 15650 N과 M (2)
int nm[8];
void solve(int i, int j, int n, int m) {
	if (i == n) {
		for (int x = 0; x < n; x++)
			printf("%d ", nm[x] + 1);
		printf("\n");
		return;
	}
	for (int w = j; w < m; w++) {
		nm[i] = w;
		solve(i + 1, w+1, n, m);
	}
}
int main() {
	int n, m;
	scanf("%d %d", &m, &n);
	solve(0,0, n, m);
}
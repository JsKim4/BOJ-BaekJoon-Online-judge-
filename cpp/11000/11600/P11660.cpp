#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 11660 구간 합 구하기 5
int arr[1025][1025];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a;
			scanf("%d", &a);
			arr[i][j] = arr[i - 1][j]+ arr[i][j-1]-arr[i-1][j-1] + a;
		}
	}
	while (m--) {
		int a, b,c,d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		printf("%d\n", arr[c][d] + arr[a - 1][b-1]-arr[a-1][d]-arr[c][b-1]);
	}
}
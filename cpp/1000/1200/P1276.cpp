#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 1276 교각 놓기
bool wor[10010][10010];
int n;
int main() {
	cin >> n;
	queue<pair<int, int>>q;
	for (int i = 0; i < 10010;i++) {
		wor[0][i] = 1;
	}
	for (int i = 0; i < n;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		q.push({ a,b });
		q.push({ a,c-1 });
		for (int j = b; j < c;j++) {
			wor[a][j] = 1;
		}
	}
	long long sum = 0;
	while (!q.empty()) {
		int y = q.front().first, x = q.front().second; q.pop();
		int s = 1;
		if (y == 0)
			continue;
		y -= 1;
		while (wor[y--][x] != 1) s++;
		sum += s;
	}
	cout << sum;
}
#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 1913 달팽이
int m[999][999];
int way[][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int n,nn;
int a, b;
bool avail(int i, int j) {
	if (i >= 0 && i < n && j >= 0 && j < n)
		return true;
	return false;
}
void solve(int i,int j,int w,int c) {
	m[i][j] = c;
	if (nn == c) {
		a = i + 1;
		b = j + 1;
	}
	if (c == 1)
		return;
	int ti = i + way[w][0], tj =j+ way[w][1];
	if (avail(ti, tj) && m[ti][tj] == 0)
		solve(ti, tj, w,c-1);
	else
		solve(i, j, (w + 1) % 4,c);
}
void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}
int main(){
	cin >> n >> nn;
	solve(0, 0, 0, n * n);
	print();
	cout << a << " " << b << endl;
}
#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 10157 자리배정
int m[1000][1000];
int way[][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int n, nn,nnn;
int a=-1, b=-1;
bool avail(int i, int j) {
	if (i >= 0 && i < n && j >= 0 && j < nnn)
		return true;
	return false;
}
void solve(int i, int j, int w, int c) {
	//cout << i << j << w << c << endl;
	m[i][j] = c;
	if (nn == c) {
		a = i + 1;
		b = j + 1;
	}
	if (c == n*nnn)
		return;
	int ti = i + way[w][0], tj = j + way[w][1];
	if (avail(ti, tj) && m[ti][tj] == 0)
		solve(ti, tj, w, c + 1);
	else
		solve(i, j, (w + 1) % 4, c);
}
void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {
	cin >> nnn >>n>> nn;
	solve(0, 0, 0, 1);
	//print();
	if (a != -1) {
		cout << b << " " << a << endl;
	}
	else {
		cout << 0 << endl;
	}
}
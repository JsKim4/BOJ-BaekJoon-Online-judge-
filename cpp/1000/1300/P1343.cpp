#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 1343 폴리오미노
int main(){
	char p[501];
	queue<char>q;
	cin >> p;
	int cnt = 0;
	for (int i = 0; p[i] != 0;i++) {
		if (p[i] == 'X') {
			cnt++;
		}
		else {
			if (cnt % 2 != 0) {
				cout << -1;
				return 0;
			}
			for (; cnt >= 4; cnt -= 4) {
				q.push('A'); q.push('A'); q.push('A'); q.push('A');
			}
			for (; cnt >= 2; cnt -= 2) {
				q.push('B'); q.push('B');
			}
			q.push('.');
		}
	}
	if (cnt % 2 != 0) {
		cout << -1;
		return 0;
	}
	for (; cnt >= 4; cnt -= 4) {
		q.push('A'); q.push('A'); q.push('A'); q.push('A');
	}
	for (; cnt >= 2; cnt -= 2) {
		q.push('B'); q.push('B');
	}
	while (!q.empty()) {
		char a = q.front(); q.pop();
		cout << a;
	}
}
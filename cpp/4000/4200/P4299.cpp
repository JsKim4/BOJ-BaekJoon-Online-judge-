#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 4299 AFC 윔블던
int main() {
	int a, b;
	cin >> a >> b;
	if ((a + b) % 2 == 1) {
		cout << -1;
	}
	else {
		int c = (a + b) / 2;
		int d = c - b;
		if (c < 0 || d < 0)
			cout << -1;
		else
			cout << c << " " << d;
	}
}
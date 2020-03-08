#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 2455 지능형 기차
int main() {
	int m = 0, n=0;
	for (int i = 0; i < 4; i++) {
		int a, b;
		cin >> a >> b;
		n += (b - a);
		if (n > m)
			m = n;
	}
	cout << m;
}
#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 2576 홀수
int main() {
	int a=-1, b=100;
	for (int i = 0; i < 7; i++) {
		int n; cin >> n;
		if (n % 2 == 1) {
			a += n;
			if (b > n)
				b = n;
		}
	}
	if (a == -1)
		cout << a;
	else
		cout << a+1 << "\n" << b;
}
#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 5596 시험 점수
int main() {
	int a = 0, b = 0;
	for (int i = 0; i < 4; i++) {
		int t; cin >> t;
		a += t;
	}
	for (int i = 0; i < 4; i++) {
		int t; cin >> t;
		b += t;
	}
	cout << (a > b ? a : b);

}
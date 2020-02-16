#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 5522 카드게임
int main() {
	int k, s = 0;
	for (int i = 0; i < 5; i++) {
		cin >> k;
		s += k;
	}
	cout << s;
}
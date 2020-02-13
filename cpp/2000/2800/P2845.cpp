#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 2845 파티가 끝나고 난 뒤
int main() {
	int a, b;
	cin >> a >> b;
	a *= b;
	for (int i = 0; i < 5; i++) {
		cin >> b;
		cout << b - a << " ";
	}
}
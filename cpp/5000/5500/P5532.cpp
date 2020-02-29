#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 5532 방학숙제
int main() {
	int l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;
	int x = a / c + (a % c != 0);
	int y = b / d + (b % d != 0);
	cout << ((l - y) > (l - x) ? l - x : l - y);
}
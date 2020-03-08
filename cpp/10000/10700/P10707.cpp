#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 10707 수도요금
int main() {
	int a, b, c, d, p;
	cin >> a >> b >> c >> d >> p;
	int n = a * p, m = (p <= c ? b : b + (p - c) * d);
	cout << (n > m ? m : n);
}
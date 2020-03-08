#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 10162 전자레인지
int main() {
	int n; cin >> n;
	if (n % 10 == 0)
		cout << n / 300 << " " << (n % 300) / 60 << " " << (n % 60) / 10;
	else
		cout << -1;
}
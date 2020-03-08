#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 15873 공백 없는 A+B
int main() {
	int n; cin >> n;
	if (n < 100)
		cout << n / 10 + n % 10;
	else if (n < 1000)
		if ((n % 100) / 10 == 0)
			cout << 10 + n % 10;
		else
			cout << 10 + n / 100;
	else
		cout << 20;

}
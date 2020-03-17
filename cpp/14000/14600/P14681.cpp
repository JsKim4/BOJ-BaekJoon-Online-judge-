#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 14681 사분면 고르기
int main() {
	int a, b;
	cin >> a >> b;
	cout << (a > 0 ? b > 0 ? 1 : 4 : b > 0 ? 2 : 3);
}
#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 9659 돌 게임2
int main() {
	int n;
	cin >> n;
	cout << (n % 2 == 0?"SK" : "CY");
}
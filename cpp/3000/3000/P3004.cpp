#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 3004 체스판 조각
int main() {
	int n;
	cin >> n;
	cout << (n / 2 + 1) * (1 + n / 2 + n % 2);
}
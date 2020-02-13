#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 3003 킹, 퀸, 룩, 비숍, 나이트, 폰
int main() {
	int n[] = { 1,1,2,2,2,8 };
	int k;
	for (int i = 0; i < 6; i++) {
		cin >> k;
		cout << n[i] - k<<" ";
	}
}
#include<iostream>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
// 11948 과목선택
int main() {
	int n[6];
	for (int i = 0; i < 6; i++)
		cin >> n[i];
	sort(n, n + 4);
	sort(n + 4, n + 6);
	cout << n[1] + n[2] + n[3] + n[5];
}
#include<iostream>
#include<algorithm>
#include<cmath>
#pragma warning (disable:4996)
using namespace std;
// 13866 팀 나누기
int main() {
	int n[4];
	for (int i = 0; i < 4;)
		cin >> n[i++];
	sort(n, n + 4);
	cout << abs(n[0] + n[3] - n[2] - n[1]);
}
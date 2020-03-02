#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 9658 돌 게임4
int N[1010];
int main() {
	int n;
	cin >> n;
	N[n] = true;
	bool win = false;
	for (int i = n; i >= 1; i--) {
		if (N[i + 1] == true || N[i + 3] == true || N[i + 4] == true)
			N[i] = false;
		else
			N[i] = true;
	}
	cout << (N[1] ? "CY" : "SK");
}
#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 16396 선 그리기
bool arr[10010];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n;i++) {
		int a, b;
		cin >> a >> b;
		for (; a < b;a++) {
			arr[a] = true;
		}
	}
	int m = 0;
	for (int i = 0; i <= 10000;i++) {
		if (arr[i] == 1)
			m++;
	}
	cout << m;

}
#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 10219 Meats On The Grill
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		char p[12][12];
		cin >> n >> m;
		for (int i = 0; i < n;i++) {
			cin >> p[i];
		}
		for (int i = 0; i < n;i++) {
			for (int j = m - 1; j >= 0;j--) {
				cout << p[i][j];
			}
			cout << endl;
		}
	}
}
#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 5587 카드 캡터 상근이
int n;
bool s[201];
bool g[201];
int main() {
	cin >> n;
	int ss = n, gg = n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		s[a] = true;
	}
	for (int i = 1; i <= n*2; i++) {
		if (!s[i]) {
			g[i] = true;
		}
	}
	int now = 0;
	while (ss>0&&gg>0) {
		//상근
		bool sb = true, gb = true;
		for (int i = now; i <= n*2;i++) {
			if (s[i] == true) {
				ss--; now = i; sb = false; s[i] = false;
				break;
			}
		}
		if (ss == 0)
			break;
		if (sb) {
			now = 0;
		}
		sb = true, gb = true;
		//근상
		for (int i = now; i <= n * 2; i++) {
			if (g[i] == true ) {
				gg--; now = i; gb = false; g[i] = false;
				break;
			}
		}
		if (gb) {
			now = 0;
		}

	}
	cout << gg << " " << ss;
}
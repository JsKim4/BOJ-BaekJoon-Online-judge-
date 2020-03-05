#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 2661 좋은수열
int answer[80];
int n;
bool solve(int m) {
	if (m == n) {
		for (int i = 0; i < n;i++){
			cout << answer[i];
		}
		return 1;
	}
	for (int k = 1; k <= 3;k++) {
		bool tf = true;
		answer[m] = k;
		for (int i = 1; i <= (m + 1)/2; i++) {
			int cnt = 0;
			for (int j = 0; j < i;j++) {
				if (answer[m-j]==answer[m-j-i]) {
					cnt++;
				}
			}
			if (cnt == i) {
				tf = false;
				break;
			}
		}
		if (tf) {
			if (solve(m + 1)) {
				return 1;
			}
			else {
				continue;
			}
		}
	}
	return 0;
}
int main() {
	cin >> n; 
	solve(0);

}
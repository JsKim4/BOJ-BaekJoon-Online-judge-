#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 10571 다이아몬드
int memo[220];
double dia[220][2];
int n=200;
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> dia[i][0] >> dia[i][1];
		}
		memo[0] = 1;
		for (int i = 0; i < n;i++) {
			int max = 0;
			for (int j = 0; j < i;j++) {
				if (dia[i][0] > dia[j][0] && dia[i][1] < dia[j][1]) {
					if (max < memo[j])
						max = memo[j];
				}
			}
			memo[i] = max + 1;
		}
		int max = 0;
		for (int i = 0; i < n;i++) {
			if (max < memo[i]) {
				 max= memo[i];
			}
		}
		cout << max << endl;
	}
}
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
// 엘리베이터
char s[5][36];
int ns[9];
queue<long long>avN[10];

int num[] = {
	0b111101101101111,
	0b001001001001001,
	0b111001111100111,
	0b111001111001111,
	0b101101111001001,
	0b111100111001111,
	0b111100111101111,
	0b111001001001001,
	0b111101111101111,
	0b111101111001111};
int n;
int main() {
	cin >> n;
	for (int i = 0; i < 5;i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n;i++) {
		for (int y = 0; y < 5;y++) {
			for (int x = 0; x < 3;x++) {
				ns[i] *= 2;
				if (s[y][x + i * 4] == '.')
					ns[i] += 0;
				else
					ns[i] += 1;
				
			}
		}
	}
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < 10;j++) {
			if ((ns[i] | num[j]) == num[j]) {
				avN[i].push(j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (avN[i].size() == 0) {
			cout << -1;
			return 0;
		}
	}
	double sum = 0;
	long long nnn = 0;
	for (int i = 0; i < n;i++) {
		sum *= 10;
		double s = 0; int j = avN[i].size();
		while (!avN[i].empty()) {
			s += avN[i].front(); avN[i].pop();
		}
		s /= j;
		sum += s;
	}
	//solve(0,0);
	cout << sum;
}
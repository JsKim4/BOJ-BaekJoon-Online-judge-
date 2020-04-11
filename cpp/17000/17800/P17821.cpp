#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 17281 ⚾
int N;
int nnn[] = { 0b000000001,0b000000010,0b000000100,0b000001000,0b000010000,0b000100000,0b001000000,0b010000000,0b100000000 };
int mmm[] = { 0b111111110,0b111111101,0b111111011,0b111110111,0b111101111,0b111011111,0b110111111,0b101111111,0b011111111 };
int n[50][9];
int now = 0;
int ns[9];
int ground[4];
int _max = 0;
void bruteForce(int i) {
	if (i == 9) {
		int m[50][9];
		int K = 0;
		int out = 0;
		int	score = 0;
		int nt = 0;
		for (int ii = 0;ii < N;ii++) {
			for (int jj = 0; jj < 9;jj++) {
				m[ii][jj] = n[ii][ns[jj]];
			}
		}
		while (K!=N) {
			int num = m[K][nt++];
			if (num == 0) {
				out++;
			}
			else {
				for (int g = 3; g > 0;g--) {
					if (ground[g] > 0) {
						ground[g] += num;
						if (ground[g] >= 4) {
							score++;
						}
						else {
							ground[ground[g]]=ground[g];
						}
					}
					ground[g] = 0;
				}
				if (num != 4) {
					ground[num] = num;
				}
				else {
					score++;
				}
			}

			if (nt == 9) {
				nt = 0;
			}
			if (out == 3) {
				out = 0;
				for (int g = 3; g >= 0; g--)
					ground[g] = 0;
				K++;
			}
		}
		if (score > _max) {
			_max = score;
		}
		return;
	}
	if (i == 3) {
		ns[i] = 0;
		now |= nnn[0];
		bruteForce(i + 1);
		now &= mmm[0];
	}
	for (int j = 1; j < 9; j++) {
		if ((now | nnn[j]) != now) {
			ns[i] = j;
			now |= nnn[j];
			bruteForce(i + 1);
			now &= mmm[j];
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < 9;j++) {
			cin >> n[i][j];
		}
	}

	bruteForce(0);
	cout << _max;
}
#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 1063 킹
int way[][2] = { {0,1},{0,-1},{-1,0},{1,0},{1,1},{1,-1},{-1,1},{-1,-1} };
int avail(int i, int j) {
	if (i >= 0 && i < 8 && j >= 0 && j < 8)
		return true;
	return false;
}
int main() {
	char t[3];
	cin >> t;	int kx = t[0] - 'A', ky = t[1] - '1';
	cin >> t;	int sx = t[0] - 'A', sy = t[1] - '1';
	int T;
	t[1] = 0; cin >> T;
	while (T--) {
		cin >> t;
		int ord = 0;
		if (t[0] == 'R') ord += 0;
		if (t[0] == 'L') ord += 1;
		if (t[0] == 'B') ord += 2;
		if (t[0] == 'T') ord += 3;
		if (t[1] == 'T') ord += 4;
		if (t[1] == 'B') ord += 6;
		int tky = ky + way[ord][0], tkx = kx + way[ord][1];
		int tsy = sy + way[ord][0], tsx = sx + way[ord][1];


		//cout << (char)(tkx + 'A') << (char)(tky + '1') << " " << (char)(sx + 'A') << (char)(sy + '1') << endl;
		if (avail(tky, tkx)) {
			if (tky == sy && tkx == sx) {
				if (avail(tsy, tsx)) {
					ky = tky; kx = tkx;
					sy = tsy; sx = tsx;
				}
			}
			else {
				ky = tky; kx = tkx;
			}
		}
		//cout << (char)(kx + 'A') << (char)(ky + '1') << " " << (char)(sx + 'A') << (char)(sy + '1') << endl;
	}
	cout << (char)(kx + 'A') << (char)(ky + '1') << "\n" << (char)(sx + 'A') << (char)(sy + '1');
}
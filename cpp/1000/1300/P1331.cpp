#include<iostream>
#include<cmath>
#pragma warning (disable:4996)
using namespace std;
// 1331 나이트 투어
bool m[6][6];
int main(){
	char t[3];
	cin >> t;
	int y = t[0] - 'A', x = t[1] - '1';
	int sy = y, sx = x;
	if(y>=0&&y<6&&x>=0&&x<6)
		m[y][x] = true;
	for (int i = 0; i < 35;i++) {
		cin >> t;
		int ty = t[0] - 'A', tx = t[1] - '1';
		if (ty < 0 || ty >= 6 || tx < 0 || tx >= 6)
			continue;
		if ((abs(ty - y) == 2 && abs(tx - x) == 1) || (abs(ty - y) == 1 && abs(tx - x) == 2)) {
			m[ty][tx] = true;
			y = ty; x = tx;
		}
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			//cout << m[i][j];
			if (!m[i][j]) {
				cout << "Invalid";
				return 0;
			}
		}
		//cout << endl;
	}
	if((abs(sy - y) == 2 && abs(sx - x) == 1)||(abs(sy - y) == 1 && abs(sx - x) == 2))
		cout << "Valid";
	else
		cout << "Invalid";
}
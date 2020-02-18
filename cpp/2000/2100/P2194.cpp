#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 2194 유닛 이동시키기
int n, m, a, b;
int MAP[500][500];
int way[][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int avail(int y, int x) {
	if (y < n && y >= 0 && x < m && x >= 0)
		return true;
	return false;
}
bool moveAvail(int y, int x, int i) {
	if (i == 0) {
		for (int j = 0; j < b; j++) {
			if (avail(y, x + j) && MAP[y][x + j] != -10)
				continue;
			else
				return false;
		}
	}
	else if (i == 1) {
		for (int j = 0; j < a; j++) {
			if (avail(y + j, x) && MAP[y + j][x] != -10)
				continue;
			else
				return false;
		}
	}
	return true;
}
void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%3d", MAP[i][j]);
		cout << "\n";
	}
	cout << "\n\n";
}
int main() {
	int sy, sx, ey, ex;
	queue<pair<int, int>>q;
	int k;
	cin >> n >> m >> a >> b >> k;
	int ty, tx;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			MAP[i][j] = -1;
	for (int i = 0; i < k; i++) {
		cin >> ty >> tx;
		ty--; tx--;
		MAP[ty][tx] = -10;
	}
	cin >> sy >> sx >> ey >> ex;
	q.push(make_pair(sy - 1, sx - 1));
	int c = 0;
	MAP[sy - 1][sx - 1] = c++;
	while (!q.empty()) {
		int len = q.size();
		//print();
		for (int i = 0; i < len; i++) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			bool tf = false;
			for (int w = 0; w < 4; w++) {
				int ny = y + way[w][0], nx = x + way[w][1];
				if (w == 1)
					tf = moveAvail(ny + a - 1, nx, w / 2);
				else if (w == 2)
					tf = moveAvail(ny, nx + b - 1, w / 2);
				else
					tf = moveAvail(ny, nx, w / 2);
				if (tf && MAP[ny][nx] == -1) {
					MAP[ny][nx] = c;
					q.push(make_pair(ny, nx));
				}
			}
		}
		c++;
	}
	cout << MAP[ey - 1][ex - 1];
}
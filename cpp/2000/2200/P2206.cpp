#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 2206 벽 부수고 이동하기
#define WALL -2
#define SPACE -1
#define MAX 2100000000
int way[][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int n, m;
int MAP[1000][1000];
int TMAP[1000][1000];
bool avail(int i, int j) {
	if (i >= 0 && i < n && j >= 0 && j < m)
		return true;
	return false;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &MAP[i][j]);
			if (MAP[i][j] == 1)
				MAP[i][j] = WALL;
			else
				MAP[i][j] = SPACE;
		}
	}
	queue<pair<int, int>>q;
	MAP[0][0] = 1;
	q.push(make_pair(0, 0));
	int count = 2;
	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			int y = q.front().first, x = q.front().second; q.pop();
			for (int w = 0; w < 4; w++) {
				int wy = y + way[w][0], wx = x + way[w][1];
				if (avail(wy, wx) && MAP[wy][wx] == SPACE) {
					MAP[wy][wx] = count;
					q.push(make_pair(wy, wx));
				}
			}
		}
		count++;
	}
	int answer = MAP[n-1][m-1];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (MAP[i][j] == WALL) {
				int min = MAX;
				for (int tw = 0; tw < 4; tw++) {
					int wy = i + way[tw][0], wx = j + way[tw][1];
					if (avail(wy, wx) && MAP[wy][wx]>=0 && min>MAP[wy][wx]) {
						min = MAP[wy][wx];
					}
				}
				if (min != MAX) {
					//cout << i << j<<endl;
					queue<pair<int, int>>tq;
					TMAP[i][j] = 1+min;
					min += 2;
					q.push(make_pair(i,j));
					tq.push(make_pair(i,j));
					while (!q.empty()) {
						int len = q.size();
						for (int ti = 0; ti < len; ti++) {
							int y = q.front().first, x = q.front().second; q.pop();
							for (int w = 0; w < 4; w++) {
								int wwy = y + way[w][0], wwx = x + way[w][1];
								if (avail(wwy, wwx)&&TMAP[wwy][wwx]==0&&((MAP[wwy][wwx] != WALL && MAP[wwy][wwx] > min)||MAP[wwy][wwx]==SPACE)) {
									TMAP[wwy][wwx] = min;
									q.push(make_pair(wwy, wwx));
									tq.push(make_pair(wwy, wwx));
								}
							}
						}
						min++;
					}
					if (TMAP[n - 1][m - 1] != 0 && (TMAP[n - 1][m - 1] < answer || answer == -1))
						answer = TMAP[n - 1][m - 1];
					while (!tq.empty()) {
						TMAP[tq.front().first][tq.front().second] = 0;
						tq.pop();
					}
				}
			}
		}
	}
	cout << answer;

}
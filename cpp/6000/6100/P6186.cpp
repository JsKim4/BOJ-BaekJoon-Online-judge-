#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 6186 Best Grass
int way[][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int n, m;
bool avail(int i,int j) {
	if (i >= 0 && i < n && j >= 0 && j < m)
		return true;
	return false;
}
int main() {
	cin >> n >> m;
	char mp[101][101];
	queue<pair<int, int>>q;
	for (int i = 0; i < n;i++) {
		cin >> mp[i];
	}
	int count = 0;
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m;j++) {
			if (mp[i][j]=='#') {
				count++;
				q.push({i,j});
				mp[i][j] = '.';
				while (!q.empty()) {
					int len = q.size();
					for (int p = 0;  p< len; p++) {
						int y = q.front().first, x = q.front().second; q.pop();
						for (int w = 0; w < 4;w++) {
							int wy = y + way[w][0], wx = x + way[w][1];
							if (avail(wy, wx) && mp[wy][wx] == '#') {
								mp[wy][wx] = '.';
								q.push({ wy,wx });
							}
						}
					}
				}
			}
		}
	}
	cout << count;

}
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
// 2583 영역 구하기
int n, m, c;
bool arr[100][100];
int way[][2] = { {1,0},{-1,0},{0,-1},{0,1} };
vector<int>v;
bool avail(int i,int j) {
	if (i >= 0 && i < n && j >= 0 && j < m)
		return true;
	return false;
}
int main(){
	cin >> n >> m >> c;
	while (c--) {
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		for (;sy<ey;sy++) {
			for (int ss=sx; ss < ex;ss++) {
				arr[sy][ss] = true;
			}
		}
	}
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m;j++) {
			if (arr[i][j] == 0) {
				queue<pair<int, int>>q;
				q.push({ i,j });
				arr[i][j] = true;
				int count = 1;
				while (!q.empty()) {
					int y = q.front().first, x = q.front().second; q.pop();
					for (int w = 0; w < 4;w++) {
						int wy = way[w][0] + y, wx = way[w][1] + x;
						if (avail(wy, wx) && arr[wy][wx] == false) {
							q.push({ wy,wx });
							arr[wy][wx] = true;
							count++;
						}
					}
				}
				v.push_back(count);
			}
		}
	}
	cout << v.size() << endl;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size();i++) {
		cout << v[i]<<" ";
	}
}
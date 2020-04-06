#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 2110 숫자판 점프
int arr[5][5];
bool answer[1000000];
int ans = 0;
int way[][2] = { {0,-1},{0,1} ,{-1,0},{1,0} };
bool avail(int i,int j) {
	if (i >= 0 && i < 5 && j >= 0 && j < 5)
		return true;
	return false;
}
int main(){
	for (int i = 0; i < 5;i++) {
		for (int j = 0; j<5;j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			queue<pair<pair<int, int>,int>>q;
			q.push({ { i,j }, arr[i][j]});
			for (int k = 0; k < 5;k++) {
				int len = q.size();
				for (int z = 0; z < len; z++) {
					int y = q.front().first.first, x = q.front().first.second;
					int num = q.front().second; q.pop();
					for (int w = 0; w < 4; w++) {
						int wy = y + way[w][0], wx = x + way[w][1];
						if (avail(wy, wx)) {
							q.push({ {wy,wx},num * 10 + arr[wy][wx] });
						}
					}

				}
			}
			while (!q.empty()) {
				if (answer[q.front().second] == 0) {
					answer[q.front().second] = true;
					ans++;
				}
				q.pop();
			}
		}
	}
	cout << ans;
}
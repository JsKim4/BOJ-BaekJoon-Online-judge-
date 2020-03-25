#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
// 2468 안전 영역
int n;
bool arr[100][100];
int temp[100][100];
int way[][2] = { {1,0},{-1,0},{0,-1},{0,1} };
bool avail(int i, int j) {
	if (i >= 0 && i < n && j >= 0 && j < n)
		return true;
	return false;
}
int main() {
	int answer = 1;
	cin >> n ;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp[i][j];
		}
	}
	for (int e = 1; e < 100;e++) {
		for (int i = 0; i < n;i++) {
			for (int j = 0; j < n;j++) {
				if (e >= temp[i][j])
					arr[i][j] = 1;
				else
					arr[i][j] = 0;
			}
		}
		vector<int>v;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 0) {
					queue<pair<int, int>>q;
					q.push({ i,j });
					arr[i][j] = true;
					int count = 1;
					while (!q.empty()) {
						int y = q.front().first, x = q.front().second; q.pop();
						for (int w = 0; w < 4; w++) {
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
		if (v.size() == 0)
			break;
		if (answer < v.size())
			answer = v.size();
	}
	cout << answer;
}
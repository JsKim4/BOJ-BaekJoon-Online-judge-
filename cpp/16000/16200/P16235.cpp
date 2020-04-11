#include<iostream>
#include<deque>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
// 16235 나무 재테크
int n, m, k;
deque<int> earth[10][10];
deque<int> die[10][10];
deque<pair<int,int>> breeding;
int food[10][10];
int nowFood[10][10];
int way[][2] = { {1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1} };
bool avail(int i, int j) {
	if (i >= 0 && i < n && j >= 0 && j < n)
		return true;
	return false;
}
int main(){
	cin >> n >> m >> k;
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			nowFood[i][j] = 5;
			cin >> food[i][j];
		}
	}
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		earth[a-1][b-1].push_back(c);
	}
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			if (earth[i][j].empty())
				continue;
			sort(earth[i][j].begin(),earth[i][j].end() ,greater<int>());
		}
	}
	while (k--) {
		//spring
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int len = earth[i][j].size();
				while (len--) {
					int num = earth[i][j].front(); earth[i][j].pop_front();
					if (num <= nowFood[i][j]) {
						nowFood[i][j] -= num;
						earth[i][j].push_back(num + 1);
						if ((num + 1) % 5 == 0)
							breeding.push_back({ i,j });
					}
					else {
						die[i][j].push_back(num);
					}
				}
			}
		}
		// summer
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				while (!die[i][j].empty()) {
					nowFood[i][j] += die[i][j].front() / 2;
					die[i][j].pop_front();
				}
			}
		}
		// fall
		while (!breeding.empty()) {
			int y = breeding.front().first;
			int x = breeding.front().second;
			breeding.pop_front();
			for (int w = 0; w < 8;w++) {
				int wy = way[w][0] + y, wx = way[w][1]+x;
				if (avail(wy, wx)) {
					earth[wy][wx].push_front(1);
				}
			}
		}
		// winter
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				nowFood[i][j] += food[i][j];
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += earth[i][j].size();
		}
	}
	cout << sum;
}
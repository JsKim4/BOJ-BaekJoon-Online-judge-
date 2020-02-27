#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 3055 탈출
char loc_c[51][51];
int loc[50][50];
int n, m;
int way[][2] = { {0,1},{0,-1},{1,0},{-1,0} };
bool avail(int i,int j) {
	if (i >= 0 && i < n && j >= 0 && j < m)
		return true;
	return false;
}
void print() {
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m;j++) {
			if (loc[i][j] == -1)
				cout << '*';
			else if (loc[i][j] == -2)
				cout << 'D';
			else if (loc[i][j] == 0)
				cout << '.';
			else
				cout << loc[i][j];
		}
		cout << endl;
	}cout << endl; cout << endl;
}
int main(){
	queue<pair<int, int>>water;
	queue<pair<int, int>>g;
	int ey, ex;
	cin >> n >> m;
	for (int i = 0; i < n;i++) {
		cin >> loc_c[i];
		for (int j = 0; j < m; j++) {
			if (loc_c[i][j] == 'D') {
				ey = i; ex = j;
				loc[i][j] = -2;
			}
			else if (loc_c[i][j] == 'S') {
				g.push(make_pair(i, j));
			}
			else if (loc_c[i][j] == '*') {
				loc[i][j] = -1;
				water.push(make_pair(i,j));
			}else if(loc_c[i][j]=='X')
				loc[i][j] = -1;
		}
	}
	int count = 1;
	while (!g.empty()) {
		//print();
		int len = water.size();
		for (int i = 0; i < len;i++) {
			int y = water.front().first, x = water.front().second;
			water.pop();
			for (int w = 0; w < 4;w++) {
				int wy = y + way[w][0], wx = x + way[w][1];
				if (avail(wy, wx) && loc[wy][wx] >= 0) {
					water.push(make_pair(wy,wx));
					loc[wy][wx] = -1;
				}
			}
		}
		len = g.size();
		for (int i = 0; i < len; i++) {
			int y = g.front().first, x = g.front().second;
			g.pop();
			for (int w = 0; w < 4; w++) {
				int wy = y + way[w][0], wx = x + way[w][1];
				if (avail(wy, wx)) {
					if (loc[wy][wx]==-2) {
						cout << count << endl;
						return 0;
					}
					if (loc[wy][wx] == 0) {
						g.push(make_pair(wy,wx));
						loc[wy][wx] = count;
					}
				}
			}
		}
		count++;
	}
	cout << "KAKTUS" << endl;
	return 0;
}
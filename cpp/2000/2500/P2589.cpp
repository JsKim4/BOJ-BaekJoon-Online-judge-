#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 2589 보물섬
int way[][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int n, m;
char arr[100][100];
int sea[50][50];
bool visited[50][50];
bool avail(int i,int j) {
	if (i >= 0 && i < n && j >= 0 && j < m)
		return true;
	return false;
}
void print() {
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m;j++) {
			printf("%2d",sea[i][j]);
		}
		cout << endl;
	}
	cout << endl << endl;
}
int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'W')
				sea[i][j] = -2;
			else
				sea[i][j] = -1;
		}
	}

	int ma = 0;
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m;j++) {
			if (sea[i][j] == -1) {
				queue<pair<int, int>>q;
				queue<pair<int, int>>tq;
				q.push({ i,j });
				tq.push({ i,j });
				int count = 0;
				visited[i][j] = true;
				while (!q.empty()) {
					count++;
					int len = q.size();
					for (int i = 0; i < len;i++) {
						int y = q.front().first, x = q.front().second; q.pop();
						for (int w = 0; w < 4;w++) {
							int wy = way[w][0] + y, wx = way[w][1] + x;
							if (avail(wy, wx) && sea[wy][wx] == -1&&visited[wy][wx]==false) {
								visited[wy][wx] = true;
								q.push({ wy,wx });
								tq.push({ wy,wx });
							}
						}
					}
				}
				if (ma < count - 1)
					ma = count - 1;
				while (!tq.empty()) {
					visited[tq.front().first][tq.front().second] = false;
					tq.pop();
				}
			}
		}
	}
	cout << ma;
}
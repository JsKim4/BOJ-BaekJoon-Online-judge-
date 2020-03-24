#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 14503 로봇청소기
int room[50][50];
int n, m;
int a, b, c;
int way[][2] = { {-1,0}, {0,-1}, {1,0}, {0,1} };
int answer = 1;
bool avail(int i, int j) {
	if (i >= 0 && i < n && j >= 0 && j < m)
		return true;
	return false;
}
void print() {
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m;j++) {
			printf("%2d", room[i][j]);
		}
		cout << endl;
	}
	cout << endl << endl;
}
bool dfs(int w,int i,int j) {
	//print();
	room[i][j] = -1;
	for (int x = 1; x <= 4;x++) {
		int wi = i + way[(w + x) % 4][0], wj = j + way[(w + x) % 4][1];
		//cout << wi << " " << wj << endl;
		if (room[wi][wj] == 0) {
			answer++;
			return dfs((w + x)%4, wi, wj);
		}
	}
	if (room[i-way[w][0]][j-way[w][1]] != 1) {
		return dfs(w, i - way[w][0], j - way[w][1]);
	}
	return false;
}


int main() {
	cin >> n >> m;
	queue<pair<int, int>>q;
	cin >> a >> b >> c;
	c = (4 - c) % 4;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> room[i][j];
	room[a][b] = -1;
	dfs(c, a, b);
	cout << answer;
}
#include<iostream>
#include<queue>
#include<tuple> 
#pragma warning (disable:4996)
using namespace std;
// 14502 연구소
int M[8][8];
int way[][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int w[3][2];
int n, m;
queue<tuple<int,int,int,int,int,int>> qWall;
bool avail(int i,int j) {
	if (i >= 0 && i < n && j >= 0 && j < m && M[i][j] == 0)
		return true;
	return false;
}
void wall(int i,int j,int wa) {
	if (wa == 3) {
		qWall.push(make_tuple(w[0][0],w[0][1], w[1][0], w[1][1], w[2][0], w[2][1]));
		return;
	}
	for (int y = i; y < n; y++) {
		for (int x = j; x < m; x++) {
			if (M[y][x] == 0) {
				M[y][x] = 1;
				w[wa][0] = y;
				w[wa][1] = x;
				wall(y, x + 1, wa + 1);
				M[y][x] = 0;
			}
		}
		j = 0;
	}
}
int main() {
	int ck = 0;
	int mx = 0;
	scanf("%d %d",&n,&m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &M[i][j]);
			if (M[i][j] == 0)
				ck++;
		}
	wall(0, 0, 0);
	//printf("%d\n", qWall.size());
	while (!qWall.empty()) {
		int tw[][2] = { {get<0>(qWall.front()),get<1>(qWall.front())},{get<2>(qWall.front()),get<3>(qWall.front())},{get<4>(qWall.front()),get<5>(qWall.front())} };
		qWall.pop();
		for (int i = 0; i < 3; i++)
			M[tw[i][0]][tw[i][1]] = 1;
		queue<pair<int, int>>q;
		queue<pair<int, int>>tq;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (M[i][j] == 2)
					q.push(make_pair(i,j));
		while (!q.empty()) {
			int len = q.size();
			for (int i = 0; i < len; i++) {
				int y = q.front().first; int x = q.front().second;
				q.pop();
				for (int k = 0; k < 4; k++) {
					if (avail(y + way[k][0], x + way[k][1])) {
						M[y + way[k][0]][x + way[k][1]] = 2;
						q.push(make_pair(y + way[k][0], x + way[k][1]));
						tq.push(make_pair(y + way[k][0], x + way[k][1]));
						//printf("%d\n",tq.size());
					}
				}
			}
			if (ck - 3 - tq.size() < mx)
				break;
		}
		//printf("%d %d %d %d %d %d ...%d\n", tw[0][0], tw[0][1], tw[1][0], tw[1][1], tw[2][0], tw[2][1],tq.size());
		if (mx < ck -3 - tq.size())
			mx = ck -3 - tq.size();
		while (!tq.empty()) {
			int y = tq.front().first; int x = tq.front().second;
			tq.pop();
			M[y][x] = 0;
		}

		for (int i = 0; i < 3; i++)
			M[tw[i][0]][tw[i][1]] = 0;
	}
	printf("%d", mx);
}
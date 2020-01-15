#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;

// 7562 나이트의 이동
static const int way[][2] = { {-2,-1},{-2,1},{-1,-2},{-1,2},
								{2,-1},{2,1},{1,-2},{1,2} };
int board[300][300];
int n,cnt = 1;
int avail(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < n ) {
		if (board[y][x] == 0) {
			return 1;
		}
		else if (board[y][x] == -1) {
			return 2;
		}
	}
	return 0;
}
void init() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			board[i][j] = 0;
	cnt = 1;
}
int main() {
	int T;
	queue<pair<int, int>>q;
	scanf("%d",&T);
	int len;
	while (T--) {
		scanf("%d",&n);
		int y, x ,a,b; 
		scanf("%d %d", &y, &x); board[y][x] = 1;
		q.push(make_pair(y,x));
		scanf("%d %d", &a, &b); board[a][b] = -1;
		if (y == a && b == x) {
			printf("0\n");
			init();
			while (!q.empty()) q.pop();
			continue;
		}
		while (!q.empty()) {
			len = q.size();
			bool chk = false;
			for (int i = 0; i < len; i++) {
				//printf("%d %d\n", len, cnt);
				int y = q.front().first;
				int x = q.front().second;
				q.pop();
				for (int j = 0; j < 8; j++) {
					//printf("%d %d %d\n", y + way[j][0], x + way[j][1], avail(y + way[j][0], x + way[j][1]));
					if (avail(y + way[j][0], x + way[j][1]) == 1) {
						q.push(make_pair(y + way[j][0], x + way[j][1]));
						board[y + way[j][0]][x + way[j][1]] = cnt;
					}
					else if (avail(y + way[j][0], x + way[j][1]) == 2) {
						//printf("true %d %d\n", y + way[j][0], x + way[j][1]);
						chk = true;
						break;
					}
				}
				if (chk) {
					printf("%d\n", cnt);
					break;
				}
			}
			cnt++;
			if (chk)
				break;
		}
		init();
		while (!q.empty()) q.pop();
	}
}
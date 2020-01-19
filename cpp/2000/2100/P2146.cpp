#include<iostream>
#include<queue>
#include <tuple>
#pragma warning (disable:4996)
using namespace std;
// 2146 다리만들기
int island[100][100];
int n;
queue<tuple<int, int, int>> q;
const int way[][2] = { {1,0},{-1,0},{0,-1},{0,1} };
bool lenAvail(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < n)
		return true;
	return false;
}bool numAvail(int y, int x, int c) {
	if (island[y][x] == c)
		return true;
	return false;
}
bool avail(int y, int x, int c) {
	if (lenAvail(y, x) && numAvail(y, x, c))
		return true;
	return false;
}
void dfs(int y, int x, int c) {
	bool a = true;
	for (int i = 0; i < 4; i++) {
		if (avail(y + way[i][0], x + way[i][1], 1)) {
			island[y + way[i][0]][x + way[i][1]] = c;
			bool a = false;
			dfs(y + way[i][0], x + way[i][1], c);
		}
	}
	if (a) {
		q.push(make_tuple(y, x, c));
	}
}
void print() {
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d", island[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &island[i][j]);
	int c = 2;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (island[i][j] == 1) {
				island[i][j] = c;
				dfs(i, j, c++);
			}
		}
	int cnt = 0;
	bool r = false;
	int re;
	//print();
	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			int num = get<2>(q.front());
			int y = get<0>(q.front()), x = get<1>(q.front());
			//printf("%d %d %d\n",y,x,num);
			q.pop();
			for (int j = 0; j < 4; j++) {
				if (lenAvail(y + way[j][0], x + way[j][1])) {
					if (numAvail(y + way[j][0], x + way[j][1], 0)) {
						island[y + way[j][0]][x + way[j][1]] = num;
						//print();
						q.push(make_tuple(y + way[j][0], x + way[j][1], num));
					}
					else if (!numAvail(y + way[j][0], x + way[j][1], num)) {
						if (num < island[y + way[j][0]][x + way[j][1]]) {
							printf("%d\n",cnt);
							return 0;
						}
						else {
							r = true;
						}
					}
				}
			}
			if (r) {
				printf("%d\n", cnt + 1);
				return 0;
			}
		}
		cnt += 2;
	}
	printf("%d\n",0);

}
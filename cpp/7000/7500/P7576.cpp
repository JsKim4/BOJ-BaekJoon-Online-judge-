#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 7576 Åä¸¶Åä

int **tomato;
int n, m;
static const int way[][2] = { {1,0},{-1,0},{0,1},{0,-1} };
bool avail(int y,int x) {
	if (y >= 0 && y < m && x >= 0 && x < n && tomato[y][x] == 0)
		return true;
	return false;
}
int main() {
	queue<pair<int, int>>q;
	scanf("%d %d", &n, &m);
	tomato = new int*[m];
	for (int i = 0; i < m;i++)
		tomato[i] = new int[n];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			scanf("%d",&tomato[i][j]);
	int len = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (tomato[i][j] == 1)
				q.push(make_pair(i, j));
	int count = 1;
	while (!q.empty()) {
		count++;
		//printf("\n\n\n\ncount : %d\n\n",count);
		len = q.size();
		for (int i = 0; i < len;i++) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int j = 0; j < 4;j++)
				if (avail(y + way[j][0], x + way[j][1])) {
					q.push(make_pair(y + way[j][0], x + way[j][1]));
					tomato[y + way[j][0]][x + way[j][1]] = count;
					//printf("push : %d %d\n",y+way[j][0],x+way[j][1]);
				}
		}
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (tomato[i][j] == 0) {
				printf("-1");
				return 0;
			}
	printf("%d",count-2);
}
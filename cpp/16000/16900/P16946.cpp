#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 16946 벽 부수고 이동하기 4
class Point {
public:
	int count;
	int id;
};
Point Map[1500][1500];
int n, m;
int way[][2] = { {1,0},{-1,0},{0,1},{0,-1} };
bool availLength(int y,int x) {
	if (y >= 0 && y < n && x >= 0 && x < m )
		return true;
	return false;
}
bool availValue(int y,int x,int id,int count) {
	if (Map[y][x].id==id && Map[y][x].count == count) {
		return true;
	}
	return false;
}
bool avail(int y, int x, int id, int count) {
	if (availLength(y, x) && availValue(y, x, id, count)) {
		return true;
	}
	return false;
}
int main() {
	char num[1011];
	scanf("%d %d",&n,&m);
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m;j++) {
			scanf("%1d", &Map[i][j].count);
			Map[i][j].id = 0;
		}
	}
	int k = 1;
	queue<pair<int, int>>q; queue<pair<int, int >> nq;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (Map[i][j].count==0&&Map[i][j].id==0) {
				q.push(make_pair(i,j));
				Map[i][j].id = k;
				int y,  x;
				while (!q.empty()) {
					int len = q.size();
					y = q.front().first; x = q.front().second;q.pop();
					nq.push(make_pair(y, x));
					for (int w = 0; w < len;w++) {
						for (int z = 0; z < 4; z++) {
							if (avail(y + way[z][0], x + way[z][1], 0, 0)) {
								q.push(make_pair(y + way[z][0], x + way[z][1]));
								Map[y + way[z][0]][x + way[z][1]].id = k;
							}
						}
					}
				}
				int count = nq.size();
				while (!nq.empty()) {
					y = nq.front().first; x = nq.front().second; nq.pop();
					Map[y][x].count = count;
				}
				k++;
			}
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d",Map[i][j].id);
		}
		printf("\n");
	}*/
	int s; int sl[4];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (Map[i][j].id == 0) {
				//printf("\n%d %d\n",i,j);
				s = 0; bool t = false;
				for (int w = 0; w < 4; w++) {
					if (!availLength(i + way[w][0], j + way[w][1])) {
						//printf("LENGTH ERROR\n");
						continue;
					}
					if (Map[i + way[w][0]][j + way[w][1]].id == 0) {
						//printf("MAP ERROR\n");
						continue;
					}
					for (int z = 0; z < s; z++) {
						if (Map[i + way[w][0]][j + way[w][1]].id == sl[z]) {
							//printf("중복 ERROR\n");
							t = true;
							break;
						}
					}
					if (t)
						continue;
					Map[i][j].count += Map[i + way[w][0]][j + way[w][1]].count;
					//printf("count : %d\n", Map[i][j].count);
					sl[s++] = Map[i + way[w][0]][j + way[w][1]].id;
				}
				printf("%d", Map[i][j].count % 10);
			}
			else
				printf("0");
		}
		printf("\n");
	}
}
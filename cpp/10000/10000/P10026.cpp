#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 10026 적록색약
#define  R 'R'
#define  G 'G'
#define  B 'B'
int N;
char picture[100][101];
char temp[100][101];
const static int way[][2] = { {0,1},{0,-1},{1,0},{-1,0} };
bool avail(int y,int x,char c) {
	if (y >= 0 && y < N&&x >= 0 && x < N&&picture[y][x]==c)
		return true;
	return false;
}
void dfs(int y,int x,char c) {
	picture[y][x] = 0;
	for (int i = 0; i < 4;i++) {
		if (avail(y+way[i][0], x + way[i][1], c)) {
			dfs(y+way[i][0],x+way[i][1],c);
		}
	}
}
int main() {
	scanf("%d",&N);
	for (int i = 0; i < N; i++) {
		scanf("%s", &temp[i]);
		for (int j = 0; j <= N;j++) 
			picture[i][j] = temp[i][j];
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (picture[i][j]!=0) {
				dfs(i,j,picture[i][j]);
				cnt++;
			}
		}
	}
	printf("%d ",cnt);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= N; j++)
			if (temp[i][j] == R)
				picture[i][j] = G;
			else
				picture[i][j] = temp[i][j];
	}
	cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (picture[i][j] != 0) {
				dfs(i, j, picture[i][j]);
				cnt++;
			}
		}
	}
	printf("%d", cnt);
}
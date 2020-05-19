#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 7569 토마토
int r, c, h;
int arr[100][100][100];
int way[][3] = { {0,0,1} ,{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0} };
bool avail(int z,int i,int j) {
	if (z >= 0 && z < h && i >= 0 && i < r && j >= 0 && j < c)
		return true;
	return false;
}
int main(){
	scanf("%d %d %d",&c,&r,&h);
	queue<pair<int, pair<int, int>>> tomato;
	int answer = c * r * h;
	for (int k = 0; k < h;k++) {
		for (int i = 0; i < r;i++) {
			for (int j = 0; j < c;j++) {
				scanf("%d",&arr[k][i][j]);
				if (arr[k][i][j] == 1) {
					tomato.push({ k,{i,j} });
					answer--;
				}
				else if (arr[k][i][j] == -1)
					answer--;
			}
		}
	}
	int cnt = 1;
	while (!tomato.empty()) {
		int len = tomato.size();
		while (len--) {
			int z = tomato.front().first;
			int i = tomato.front().second.first;
			int j = tomato.front().second.second;
			tomato.pop();
			for (int w = 0; w < 6;w++) {
				int zw = z + way[w][0];
				int iw = i + way[w][1];
				int jw = j + way[w][2];
				if (avail(zw, iw, jw) && arr[zw][iw][jw] == 0) {
					arr[zw][iw][jw] = cnt;
					tomato.push({ zw,{iw,jw} });
					answer--;
				}
			}
		}
		if (!tomato.empty())
			cnt++;
	}
	if (!answer)
		cout << cnt-1;
	else
		cout << -1;
}
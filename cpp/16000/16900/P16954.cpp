#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 16954 움직이는 미로 탈출
int arr[8][8];
int way[][2] = { {0,1},{0,-1} ,{1,0},{-1,0},{1,1},{-1,-1} ,{1,-1},{-1,1},{0,0} };
bool avail(int i,int j) {
	if (i >= 0 && i < 8 && j >= 0 && j < 8)
		return true;
	return false;
}
int main(){
	char a[9];
	queue<pair<int, int>>wall;
	for (int i = 0; i < 8;i++) {
		cin >> a;
		for (int j = 0; j < 8;j++) {
			if (a[j] == '.') {
				arr[i][j] = 0;
			}
			else {
				arr[i][j] = -1;
				wall.push({ i,j });
			}
		}
	}
	queue <pair<int, int>>aLoc;
	arr[7][0] = 1;
	while (!wall.empty()) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (arr[i][j] == 1) {
					aLoc.push({ i,j });
				}
			}
		}
		int len = aLoc.size();
		while (len--) {
			int y = aLoc.front().first;
			int x = aLoc.front().second;
			aLoc.pop();
			for (int w = 0; w < 9; w++)  {
				int wx = x + way[w][1];
				int wy = y + way[w][0];
				if (avail(wy, wx)&&arr[wy][wx]!=-1) {
					arr[wy][wx] = 1;
				}
			}
		}
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (arr[i][j] != 1) {
					arr[i][j] = 0;
				}
			}
		}
		len = wall.size();
		while (len--) {
			int y = wall.front().first;
			int x = wall.front().second;
			if (y != 7){
				wall.push({y+1,x});
				arr[y + 1][x] = -1;
			}
			wall.pop();
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (arr[i][j] == 1) {
				printf("1");
				return 0;
			}
		}
	}
	printf("0");

}
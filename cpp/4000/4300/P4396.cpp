#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 4396 지뢰
char p[10][11];
char c[10][11];
int mm[10][10];
int n;
int way[][2] = { {1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1},{-1,-1} };
bool avail(int i,int j) {
	if (i >= 0 && i < n && j >= 0 && j < n)
		return true;
	return false;
}
int main(){
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> p[i];
	for (int i = 0; i < n; i++) 
		cin >> c[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(mm[i][j]==0)
				mm[i][j] = -1;
			if (c[i][j] == 'x' && p[i][j] == '*') {
				for (int ii = 0; ii < n; ii++) {
					for (int jj = 0; jj < n; jj++) {
						if (p[ii][jj] == '*') {
							mm[ii][jj] = -2;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			if (c[i][j] == 'x'&&p[i][j]=='.') {
				int cnt = 0;
				for (int w = 0; w < 8; w++) {
					if (avail(i + way[w][0], j + way[w][1]) && p[i + way[w][0]][j + way[w][1]] == '*') {
						cnt++;
					}
				}
				mm[i][j] = cnt;
			}
		}
	}
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n; j++) {
			if (mm[i][j] >= 0)
				cout << mm[i][j];
			else if (mm[i][j] == -1)
				cout << '.';
			else
				cout << '*';
		}
		cout << endl;
	}
}
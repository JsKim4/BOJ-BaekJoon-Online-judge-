#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 11048 이동하기
int n,m;
int arr[1000][1000];
int answer[1000][1000];
int way[][2] = { {-1,-1},{-1,0},{0,-1} };
bool avail(int i,int j) {
	if (i>=0&&i<n&&j>=0&&j<m) {
		return true;
	}
	return false;
}
int main(){
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m;j++) {
			scanf("%d",&arr[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int mm = 0;
			for (int w = 0; w < 3;w++) {
				int ii = i + way[w][0], jj = j + way[w][1];
				if (avail(ii,jj) && mm < answer[ii][jj]) {
					mm = answer[ii][jj];
				}
			}
			answer[i][j] = mm + arr[i][j];
		}
	}
	cout << answer[n - 1][m - 1];
}
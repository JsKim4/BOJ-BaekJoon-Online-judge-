#include<iostream>
#include<vector>
#pragma warning (disable:4996)
using namespace std;
// 15684 사다리 조작
int arr[30][10][2];
int n, m, h;
vector<pair<int, int>>v;
/*
	사다리 이동 조작

*/
int move(int i,int j) {
	if (i==h) {
		return j;
	}
	if (arr[i][j][0] == 1) {
		return move(i + 1, j + 1);
	}
	else if (arr[i][j][1] == 1) {
		return move(i + 1, j - 1);
	}
	else {
		return move(i + 1, j);
	}
}
bool solve(int i,int N,int M) {
	if (i == M) {
		int cnt = 0;
		for (int k = 0; k < n;k++) {
			int a = move(0, k);
			if (a != k) {
				return false;
			}
		}
		return true;
	}
	/*
		놓을 수 없으며 continue
		놓을 수 있으면 depth+
	*/
	for (int j = N; j < v.size();j++) {
		int y = v[j].first, x = v[j].second;
		if (arr[y][x][0] == 1 || arr[y][x][1] == 1)
			continue;
		if (arr[y][x + 1][0] == 0) {
			arr[y][x][0] = 1;
			arr[y][x + 1][1] = 1;
			if (solve(i + 1, j + 1, M)) {
				return true;
			}
			arr[y][x][0] = 0;
			arr[y][x + 1][1] = 0;
		}
	}
	return false;
}

/*
	좌 우측으로 관리
*/
int main(){
	cin >> n >> m >> h;
	for (int i = 0; i < m;i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		arr[a][b][0] = 1;
		arr[a][b + 1][1] = 1;
	}
	/*
		사다리로 가능한 좌표 모음(왼쪽 선 기준)
	*/
	for (int i = 0; i < h;i++) {
		for (int j = 0; j < n-1;j++) {
			if (arr[i][j][0] == 0 && arr[i][j][1] == 0) {
				if (arr[i][j+1][1]!=1) {
					v.push_back({ i,j });
				}
			}
		}
	}
	for (int x = 0; x <= 3;x++) {
		if (solve(0, 0, x)==true) {
			cout << x << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}
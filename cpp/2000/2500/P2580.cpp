#include<iostream>
#include<vector>
#pragma warning (disable:4996)
using namespace std;
// 2580 스도쿠
vector<int> arr[9][9];
vector<pair<int, int>>v;
int pan[9][9];
bool avail(int i,int j) {
	int num = pan[i][j];
	int ii = (i / 3)*3;
	int jj = (j / 3) * 3;
	int cnt = 0;
	for (int iii = 0; iii < 9; iii++) {
		if (num == pan[iii][j])
			cnt++;
	}
	if (cnt > 1)
		return false;
	for (int jjj = 0; jjj < 9; jjj++) {
		if (num == pan[i][jjj])
			cnt++;
	}
	if (cnt > 2)
		return false;
	for (int iii = ii; iii < ii + 3;iii++) {
		for (int jjj = jj; jjj < jj + 3;jjj++) {
			if (pan[iii][jjj] == num)
				cnt++;
		}
	}
	return cnt == 3;
}
void print() {
	for (int i = 0; i < 9;i++) {
		for (int j = 0; j < 9;j++) {
			cout << pan[i][j]<<" ";
		}
		cout << endl;
	}
}
bool solve(int n) {
	if (n == v.size()) {
		print();
		return true;
	}
	int i = v[n].first, j = v[n].second;
	for (int k = 0; k < arr[i][j].size(); k++) {
		pan[i][j] = arr[i][j][k];
		if(avail(i,j))
			if (solve(n + 1))
				return true;
	}
	pan[i][j] = 0;
	return false;
}
int main(){
	for (int i = 0; i < 9;i++) {
		for (int j = 0; j < 9;j++) {
			cin >> pan[i][j];
			if (pan[i][j] == 0) {
				v.push_back({ i,j });
			}
		}
	}
	for (int n = 0; n < v.size();n++) {
		int i = v[n].first,j=v[n].second;
		for (int m = 1; m <= 9;m++) {
			pan[i][j] = m;
			if (avail(i, j)) 
				arr[i][j].push_back(m);
		}
		pan[i][j] = 0;
	}

	if (solve(0)) {
		return 0;
	}
	else
		cout << -1;
}
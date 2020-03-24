#include<iostream>
#include<vector>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 17142 연구소 3
int n, v;
int arr[50][50];
int selectV[10];
int way[][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int answer = -1;
int s = 0;
vector<pair<int, int>>varr;
bool avail(int i,int j) {
	if (i >= 0 && i < n && j >= 0 && j < n)
		return true;
	return false;
}
void print() {
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n; j++) {
			printf("%2d", arr[i][j]);
		}
		cout << endl;
	}
	cout << endl << endl;
}
int infect() {
	queue<pair<int, int>>q;
	queue<pair<int, int>>tq;
	for (int i = 0; i < v;i++) {
		q.push({ varr[selectV[i]].first ,varr[selectV[i]].second });
		arr[q.back().first][q.back().second] = 0;
	}
	int count = 0;
	while (!q.empty()) {
		int len = q.size();
		if (tq.size() == s)
			break;
		count++;
		for (int i = 0; i < len;i++) {
			int y = q.front().first, x = q.front().second; q.pop();
			for (int w = 0; w < 4;w++) {
				int wy = y + way[w][0], wx = way[w][1] + x;
				if (avail(wy, wx) ) {
					if (arr[wy][wx] == -2) {
						arr[wy][wx] = count;
						q.push({ wy,wx });
						tq.push({ wy, wx });

					}
					else if (arr[wy][wx] == -3) {
						arr[wy][wx] = 0;
						q.push({ wy,wx });
					}
				}
			}
		}
	}

	//cout << "count : "<< count << endl;
	//print();
	if(tq.size()==s)
		if (count  < answer || answer==-1) 
			answer = count ;
	while (!tq.empty()) {
		arr[tq.front().first][tq.front().second]=-2;
		tq.pop();
	}
	for (int i = 0; i < varr.size();i++) {
		arr[varr[i].first][varr[i].second] = -3;
	}
	return answer;
}
void select(int i,int j) {
	if (i == v) {
	/*	for (int i = 0; i < v;i++) {
			cout << selectV[i]<<" ";
		}
		cout << endl;*/
		infect();
		return;
	}
	for (j; j < varr.size();j++) {
		selectV[i] = j;
		select(i + 1, j + 1);
	}

}
int main(){
	cin >> n >> v;
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				varr.push_back({ i,j });
			}
			if (arr[i][j] == 1)
				arr[i][j] = -1;
			else if (arr[i][j] == 0) {
				arr[i][j] = -2;
				s++;
			}
			else {
				arr[i][j] = -3;
			}
		}
	}
	select(0, 0);
	cout << answer;
}
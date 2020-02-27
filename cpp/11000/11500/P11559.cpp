#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
#define N 12
#define M 6 
// 11559 Puyo Puyo
int way[][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int pan[N][M];
char panc[N][M + 1];
bool avail(int i,int j) {
	if (i >= 0 && i < N && j >= 0 && j < M)
		return true;
	return false;
}
void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%3d", pan[i][j]);
		}
		cout << endl;
	}
	cout << endl; cout << endl;
}
bool boomb() {
	bool boom = false;
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < M; j++) {
			if (pan[i][j] > 99) {
				pan[i][j] = 0;
				boom = true;
			}
			else if (pan[i][j] > 9)
				pan[i][j] /= 10;
		}
	}
	return boom;
}
void gravity() {
	for (int j = 0; j < M; j++) {
		int now = 11;
		for (int i = 11; i >=0 ; i--) {
			if (pan[i][j] != 0) {
				int temp = pan[i][j];
				pan[i][j] = 0;
				pan[now--][j] = temp;
			}
		}
	}
}
void ck(int y, int x, int k) {
	queue<pair<int, int>>q;
	int count = 1;
	q.push(make_pair(y, x));
	pan[y][x] = k * 10;
	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			int ty = q.front().first, tx = q.front().second;
			q.pop();
			for (int w = 0; w < 4; w++) {
				int wy = ty + way[w][0], wx = tx + way[w][1];
				if (avail(wy, wx) && pan[wy][wx] == k) {
					pan[wy][wx] = k * 10;
					q.push(make_pair(wy, wx));
					count++;
				}
			}
		}
	}
	if (count < 4 || k>9)
		return;
	ck(y, x, k * 10);
}
int main(){
	for (int i = 0; i < N;i++) {
		cin >> panc[i];
		for (int j = 0; j < M;j++) {
			if (panc[i][j] == '.')
				pan[i][j] = 0;
			if (panc[i][j] == 'R')
				pan[i][j] = 1;
			if (panc[i][j] == 'G')
				pan[i][j] = 2;
			if (panc[i][j] == 'B')
				pan[i][j] = 3;
			if (panc[i][j] == 'P')
				pan[i][j] = 4;
			if (panc[i][j] == 'Y')
				pan[i][j] = 5;
		}
	}
	int answer = 0;
	while (true) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (pan[i][j] != 0 && pan[i][j] < 10) {
					ck(i,j,pan[i][j]);
					//print();
				}
			}
		}
		if (boomb())
			answer++;
		else
			break;

		gravity();
		
	}
	cout << answer;
}
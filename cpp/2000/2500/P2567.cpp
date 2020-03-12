#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 2567 색종이 - 2
int way[][2] = { {0,1},{0,-1},{1,0},{-1,0} };
bool avail(int i,int j) {
	if (i >= 0 && i <= 100 && j >= 0 && j <= 100)
		return true;
	return false;
}
int paper[110][110];
void print() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++)
			cout << paper[i][j];
		cout << endl;
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n;i++) {
		int a, b;
		cin >> a >> b;
		for (int y = 0; y < 10;y++) {
			for (int x = 0; x < 10; x++) {
				paper[y + a][x + b] = 1;
			}
		}
	}
	//print();
	int count = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (paper[i][j] == 1) {
				if (avail(i, j - 1) && paper[i][j - 1] == 0)
					count++;
				else if (avail(i, j + 1) && paper[i][j + 1] == 0)
					count++;
			}
		}
	}
	for (int j = 0; j <= 100; j++) {
		for (int i = 0; i <= 100; i++) {
			if (paper[i][j] == 1) {
				if (avail(i-1, j) && paper[i-1][j] == 0)
					count++;
				else if (avail(i+1, j) && paper[i+1][j] == 0)
					count++;
			}
		}
	}
	cout << count;
}
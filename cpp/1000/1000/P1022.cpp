#include<iostream>
#include<queue>
#define CNT 8
#pragma warning (disable:4996)
using namespace std;
// 1022 소용돌이 예쁘게 출력하기
int row[10001];
int col[10001];
int answer[200][200];
int m = 0;
int t_len(int num) {
	int i = 0;
	while (num /= 10 )i++;
	return i;
}
int solve(int i,int j) {
	if (j > 0) {
		if (i > 0) {
			if (i<j) {
				return col[5000 + j] - i;
			}
			else {
				return row[5000 + i] + j;
			}
		}
		else {
			if (abs(i)<j) {
				return col[5000 + j] - i;
			}
			else {
				return row[5000 + i] - j;
			}
		}
	}
	else {
		if (i > 0) {
			if (abs(j)>i) {
				return col[5000 + j] + i;
			}
			else {
				return row[5000 + i] + j;
			}
		}
		else {
			if (abs(i)>abs(j)) {
				return row[5000 + i] - j;
			}
			else {
				return col[5000 + j] + i;
			}
		}
	}
}
int main(){

	row[5000] = 1;
	int r_up = 3;
	for (int i = 4999; i >= 0; i--) {
		row[i] = r_up + row[i + 1];
		r_up += CNT;

	}
	int r_down = 7;
	for (int i = 5001; i <= 10000; i++) {
		row[i] = r_down + row[i - 1];
		r_down += CNT;
	} 
	int c_left = 5;
	col[5000] = 1;
	for (int i = 4999; i >= 0; i--) {
		col[i] = c_left + col[i + 1];
		c_left += CNT;

	}
	int c_right = 1;
	for (int i = 5001; i <= 10000; i++) {
		col[i] = c_right + col[i - 1];
		//cout << col[i] << endl;
		c_right += CNT;
	}
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	int mi = r2 - r1 + 1;
	int mj = c2 - c1+1;
	for (int i = 0; i < mi; i++) {
		for (int j = 0; j < mj; j++) {
			answer[i][j] = solve(i + r1, j + c1);
			int tlen = t_len(answer[i][j]);
			if (tlen> m) {
				m = tlen;
			}
			//printf("%d ", answer[i][j]);
		}
		//printf("\n");
	}

	for (int i = 0; i < mi; i++) {
		for (int j = 0; j < mj; j++) {
			for (int s=0; s < m - t_len(answer[i][j]);s++) {
				cout << " ";
			}
			cout << answer[i][j] << " ";

		}
		cout <<endl;
	}
	
}
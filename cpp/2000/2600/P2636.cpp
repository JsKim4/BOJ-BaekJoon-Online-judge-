#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 2636 치즈
int cheeze[102][102];
int way[][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int n, m;
bool avail(int y,int x) {
	if (y >= 0 && y <= n && x >= 0 && x <= m) 
		return true;
	return false;
}
/*void print() {
	for (int i = 0; i <= n;i++) {
		for (int j = 0; j <= m;j++) {
			cout << cheeze[i][j];
		}
		cout << endl;
	}cout << endl;
}*/
int main() {
	queue<pair<int, int>>eq;
	queue<pair<int, int>>cq;
	cin >> n >> m;
	int ch = 0;
	int x = 0;
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m; j++) {
			cin >> cheeze[i + 1][j + 1];
			if (cheeze[i + 1][j + 1] == 1)
				ch++;
		}
	}
	eq.push(make_pair(0, 0));
	int count=0;
	while (!eq.empty()) {
		//cout << count;
		while (!eq.empty()) {
			int len = eq.size();
			//print();
			for (int i = 0; i < len; i++) {
				int y = eq.front().first; int x = eq.front().second; eq.pop();
				for (int w = 0; w < 4;w++) {
					int wy = y + way[w][0], wx = x + way[w][1];
					if (avail(wy, wx)) {
						if (cheeze[wy][wx] == 0) {
							cheeze[wy][wx] = 2;
							eq.push({ wy,wx });
						}
						else if (cheeze[wy][wx] == 1) {
							cheeze[wy][wx] = 2;
							cq.push({ wy,wx });
						}
					}
				}
			}
		}
		if (!cq.empty()) {
			ch -= x;
			x = cq.size();
			count++;
		}
		while (!cq.empty()) {
			int y = cq.front().first,x=cq.front().second;
			cheeze[y][x] = 0;
			eq.push({y,x});cq.pop();
		}
		
	}
	cout << count <<"\n"<<ch;
}
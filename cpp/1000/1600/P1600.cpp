#include<iostream>
#include<tuple>
#include<queue>
#pragma warning (disable:4996)
#define MAX 210000000
using namespace std;
// 1600 말이 되고픈 원숭이
int k, h, w;
int zoo[31][200][200];
int way[][3] = { {0,1,0},{0,-1,0}, {1,0,0},{-1,0,0},
{-1,-2,1},{-2,-1,1},{1,-2,1},{2,-1,1},
{1,2,1},{2,1,1},{-1,2,1},{-2,1,1} };
bool avail(int i,int j,int m) {
	if (i >= 0 && i < h && j >= 0 && j < w&&m<=k)
		return true;
	return false;
}
void print(){
	for (int i = 0; i < h; i++) {
		for (int l = 0; l <= k; l++) {
			for (int j = 0; j < w; j++) {
				cout << zoo[l][i][j];
			}
			cout << "    ";
		}
		cout << endl;
	}
	cout << endl;
}
int main() {
	queue<tuple<int, int, int>>q;
	cin >> k >> w >> h;
	for (int i = 0; i < h;i++) {
		for (int j = 0; j < w;j++) {
			cin >> zoo[0][i][j];
			for (int l = 0; l <= k;l++) {
				zoo[l][i][j] = zoo[0][i][j];
			}
		}
	}
	if (h == 1 && w == 1) {
		cout << 0;
		return 0;
	}
	int count = 1;
	q.push(make_tuple(0,0,0));
	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i < len;i++) {
			int l = get<0>(q.front()), y = get<1>(q.front()), x = get<2>(q.front()); q.pop();
			for (int w = 0; w < 12;w++) {
				int wy = y + way[w][0], wx = x + way[w][1],wl=l+way[w][2];
				if (avail(wy,wx,wl)) {
					if (zoo[wl][wy][wx] == 0) {
						zoo[wl][wy][wx] = count;
						q.push(make_tuple(wl,wy, wx));
					}
				}
			}
		}
		//print();
		for (int j = 0; j <= k; j++) {
			if (zoo[j][h - 1][w - 1] != 0) {
				cout << count;
				return 0;
			}
		}
		count++;
	}
	cout << -1;

}
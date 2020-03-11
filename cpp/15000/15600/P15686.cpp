#include<iostream>
#include<vector>
#include<cmath>
#pragma warning (disable:4996)
#define INF 2100000000
using namespace std;
// 15686 치킨 배달
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
int city[50][50];
int mine = INF;
int chkck[13];
// i 몇번째 j 시작점 n치킨집 개수 m 폐업안시킴 
void noOut(int i,int j,int m) {
	if (i == m) {
		int minl[100];
		for (int i = 0; i < home.size(); i++)
			minl[i] = INF;
		for (int p = 0; p < m;p++) {
			int cy = chicken[chkck[p]].first, cx = chicken[chkck[p]].second;
			for (int q = 0; q < home.size(); q++) {
				int hy = home[q].first,hx = home[q].second;
				int len = abs(hy-cy)+abs(hx-cx);
				if (minl[q] > len)
					minl[q] = len;
			}
		}
		int sum = 0;
		for (int i = 0; i < home.size();i++) {
			sum += minl[i];
		}
		if (sum < mine)
			mine = sum;
	}
	for (int w = j; w < chicken.size();w++) {
		chkck[i] = w;
		noOut(i + 1, w + 1, m);
	}
}
int main() {
	int  l, m,n=0;
	cin >> l >> m;
	for (int i = 0; i < l;i++) {
		for (int j = 0; j < l;j++) {
			cin >> city[i][j];
			if (city[i][j] == 1)
				home.push_back({ i,j });
			else if(city[i][j]==2)
				chicken.push_back({ i,j });
		}
	}
	noOut(0,0,m);
	cout << mine;
}
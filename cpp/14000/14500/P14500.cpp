#include<iostream>
#pragma warning (disable:4996)
using namespace std;
#define way_length 19
// 14500 테트로미노
int way[][3][2] = {
//ㅗ모양 4
{{0,1},{0,-1},{1,0}},
{{0,1},{0,-1},{-1,0}},
{{0,-1},{1,0},{-1,0}},
{{0,1},{1,0},{-1,0}},
//1모양 2
{{0,1},{0,2},{0,3}},
{{1,0},{2,0},{3,0}},
//ㅁ모양 1
{{1,0},{0,1},{1,1}},
//ㄱ자모양 8
{{-1,0},{0,-1},{0,-2}},
{{-1,0},{0,1},{0,2}},
{{1,0},{0,-1},{0,-2}},
{{1,0},{0,1},{0,2}},
{{1,0},{2,0},{0,1}},
{{1,0},{2,0},{0,-1}},
{{-1,0},{-2,0},{0,-1}},
{{-1,0},{-2,0},{0,1}},
//z모양 4
{{0,-1},{-1,0},{-1,1}},
{{0,1},{-1,0},{-1,-1}},
{{0,1},{-1,1},{1,0}},
{{0,-1},{-1,-1},{1,0}} 
};
int n, m;
int pan[500][500];
int avail(int i, int j) {
	if (i >= 0 && i < n && j >= 0 && j < m)
		return pan[i][j];
	return 0;
}
int maxValue(int i,int j) {
	int mvalue = 0;
	for (int w = 0; w < way_length;w++) {
		int value = pan[i][j];
		for (int nw = 0; nw < 3; nw++) {
			int v = avail(i + way[w][nw][0],j + way[w][nw][1]);
			if (v == 0)
				break;
			value += v;
		}
		if (value > mvalue)
			mvalue = value;
	}
	return mvalue;
}
int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> pan[i][j];
	int mvalue = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int value = maxValue(i,j);
			mvalue = mvalue > value ? mvalue : value;
			//printf("%3d",value);
		}
		//cout << "\n";
	}
	cout << mvalue;
}
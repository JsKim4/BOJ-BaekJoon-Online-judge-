#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 16395 파스칼 삼각형
int tri[30][30] = { {1} };
int main(){
	for (int i = 1; i < 30;i++) {
		tri[i][0] = 1;
		//cout << tri[i][0];
		for (int j = 1; j < i;j++) {
			tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j];
		//	cout << tri[i][j];
		}
		tri[i][i] = 1;
		//cout << tri[i][i] << endl;;
	}
	int n, k;
	cin >> n >> k;
	cout << tri[n - 1][k - 1];
}
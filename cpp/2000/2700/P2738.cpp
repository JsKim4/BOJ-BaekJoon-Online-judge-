#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 2738 행렬 덧셈
int a1[100][100], a2[100][100];
int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a1[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a2[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a1[i][j] + a2[i][j]<<" ";
		}
		cout << endl;
	}
}
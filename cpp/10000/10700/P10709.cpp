#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 기상캐스터 
int arr[101][101];
int main(){
	int n, m;
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = -1;
		}
	}
	for (int i = 0; i < n;i++) {
		cin >> s;
		for (int j = 0; j < m;j++) {
			if (s[j] == 'c') {
				arr[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		int now = -1;
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != -1) {
				now = arr[i][j];
			}
			else if (now != -1) {
				arr[i][j] = ++now;
			}
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
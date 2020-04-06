#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 1051 숫자 정사각형
int arr[50][50];
int n, m;
int avail(int t, int l, int b, int r){
	if (t >= 0&&t<n && b < n && l >= 0 && l <m && r < m)
		return true;
	return false;
}
int main(){
	cin >> n >> m;
	int mx = n > m ? m : n;
	mx--;
	for (int i = 0; i < n;i++) {
		char chn[51]; cin >> chn;
		for (int j = 0; j < m;j++) {
			arr[i][j] = chn[j];
		}
	}
	for (; mx >= 0;mx--) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int t = i; int l = j;
				int b = i + mx; int r = j + mx;
				if (avail(t, l, b, r)) {
					if (arr[t][l] == arr[t][r] && arr[t][l] == arr[b][l] && arr[t][l] == arr[b][r]) {
						cout << (mx + 1) * (mx + 1);
						return 0;
					}
				}
				else {
					break;
				}
			}
		}
	}
	cout << 1;
}
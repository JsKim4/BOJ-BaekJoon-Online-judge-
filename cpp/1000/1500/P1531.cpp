#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 1531 투명
int pic[100][100];
int main(){
	int n, m;
	cin >> n >> m;
	for (int t = 0; t < n;t++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		for (int i = a-1; i < c;i++) {
			for (int j = b - 1; j < d;j++) {
				pic[i][j]++;
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (pic[i][j] > m)
				answer++;
		}
	}
	cout << answer;
}

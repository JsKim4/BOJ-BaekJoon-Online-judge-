#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 5533 유니크
int num[101][3];
int player[200][3];
int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < 3;j++) {
			int x;
			cin >> x;
			player[i][j] = x;
			if (num[x][j] == 0)
				num[x][j] = x;
			else
				num[x][j] = -1;
		}
	}
	for (int i = 0; i < n;i++) {
		int sum = 0;
		for (int j = 0; j < 3;j++) {
			if (num[player[i][j]][j] != -1)
				sum += num[player[i][j]][j];
		}
		cout << sum << endl;
	}
}
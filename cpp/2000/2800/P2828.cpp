#include<iostream>
#include<cmath>
#pragma warning (disable:4996)
using namespace std;
// 2828 사과 담기 게임
int arr[20];
int n, m, j;
int get(int i,int lx,int rx) {
	if (i == j)
		return 0;
	if (arr[i] >= lx && arr[i] <= rx) {
		return get(i + 1, lx, rx) ;
	}
	else {
		if (arr[i] > rx) {
			return get(i + 1, lx + (arr[i] - rx), arr[i]) + (arr[i] - rx);
		}
		else if (arr[i] < lx) {
			return get(i + 1, arr[i], rx- (lx - arr[i])) + (lx - arr[i]);
		}
	}
}
int main(){
	cin >> n >> m >> j;
	for (int i = 0; i < j; i++) {
		cin >> arr[i];
	}
	cout << get(0, 1, m );
}
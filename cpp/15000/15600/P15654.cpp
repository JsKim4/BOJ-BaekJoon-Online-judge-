#include<iostream>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
// P15654 N과 M (5)
int n, m;
int now = 0b00000000;
int nnn[] = { 0b00000001 ,0b00000010 ,0b00000100 ,0b00001000 ,0b00010000 ,0b00100000 ,0b01000000 ,0b10000000 };
int mmm[] = { 0b11111110 ,0b11111101 ,0b11111011 ,0b11110111 ,0b11101111 ,0b11011111 ,0b10111111 ,0b01111111 };
int nnmm[8];
int arr[8];
int answer[40320][8];
int aa = 0;
void nm(int i,int j) {
	if (i == m) {
		if (aa == 0) {
			for (int x = 0; x < m; x++) 
				answer[aa][x] = nnmm[x];
			aa++;
			return;
		}
		bool tf = false;
		for (int x = 0; x < m; x++) {
			if (answer[aa - 1][x] != nnmm[x]) {
				tf = true;
				break;
			}
		}
		for (int x = 0; x < m&&tf; x++) {
			answer[aa][x] = nnmm[x];
		}
		if (tf)
			aa++;
		return;
	}
	for (int k = 0; k < n;k++) {
		if (i == 0) {
			nnmm[i] = arr[k];
			now |= nnn[k];
			nm(i + 1, k + 1);
			now &= mmm[k];
			continue;
		}
		if ((now|nnn[k])!=now) {
			now |= nnn[k];
			nnmm[i] = arr[k];
			nm(i + 1, k + 1);
			now &= mmm[k];
		}
	}
}
int main(){
	cin >> n >> m;
	for (int i = 0; i < n;i++) 
		cin >> arr[i];

	sort(arr, arr + n);
	nm(0, 0);
	for (int i = 0; i < aa;i++) {
		for (int j = 0; j < m;j++) {
			printf("%d ",answer[i][j]);
		}
		printf("\n");
	}
}
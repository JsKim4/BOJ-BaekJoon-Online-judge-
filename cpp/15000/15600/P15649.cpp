#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 15649 N과 M (1)
int nm[8];
int now = 0b00000000;
int nnn[] = { 0b00000001 ,0b00000010 ,0b00000100 ,0b00001000 ,0b00010000 ,0b00100000 ,0b01000000 ,0b10000000 };
int mmm[] = { 0b11111110 ,0b11111101 ,0b11111011 ,0b11110111 ,0b11101111 ,0b11011111 ,0b10111111 ,0b01111111 };
void solve(int i,int n,int m) {
	if (i == n) {
		for (int x = 0; x < n; x++)
			printf("%d ",nm[x]+1);
		printf("\n");
		return;
	}
	for (int j = 0; j < m;j++) {
		if ((now & nnn[j]) == 0) {
			//now |= nnn[j];
			nm[i] = j;
			solve(i + 1, n, m);
			//now &= mmm[j];
		}
	}
}
int main() {
	int n, m;
	scanf("%d %d",&m,&n);
	solve(0, n, m);
}
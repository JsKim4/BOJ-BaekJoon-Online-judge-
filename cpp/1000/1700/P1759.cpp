#include<iostream>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;
// 1759 암호 만들기
char c[20];
int use[20];
void solve(int i,int j, int n, int m,int co,int ko) {
	if (i == n) {
		if (co < 1 || ko < 2)
			return;
		for (int k = 0; k < n;k++) {
			printf("%c",c[use[k]]);
		}
		printf("\n");
		return;
	}
	for (; j < m; j++) {
		use[i] = j;
		if (c[use[i]] == 'a' || c[use[i]] == 'e' || c[use[i]] == 'i' || c[use[i]] == 'o' || c[use[i]] == 'u')
			co++;
		else 
			ko++;
		solve(i + 1,j+1, n, m,co,ko);
		if (c[use[i]] == 'a' || c[use[i]] == 'e' || c[use[i]] == 'i' || c[use[i]] == 'o' || c[use[i]] == 'u')
			co--;
		else
			ko--;
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> c[i];
	sort(c, c + m);
	solve(0,0, n, m,0,0);
}
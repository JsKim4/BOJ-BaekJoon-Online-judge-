#include<iostream>
#include<queue>
#include<stack>
#pragma warning (disable:4996)
using namespace std;
// 9019 DSLR
#define D 'D'
#define S 'S'
#define L 'L'
#define R 'R'
#define B 'B'
#define E 'E'
int num[10000][2]; //B = ½ÃÀÛ E = ³¡
int avail(int y) {
	if (y >= 0 && y < 10000) {
		if (num[y][1] == E)
			return 2;
		if(num[y][1] == 0)
			return 1;
	}
	return 0;
}
int d(int n) {
	return (n * 2) % 10000;
}
int s(int n) {
	return n ==0 ? 9999 : n-1;
}
int l(int n) {
	return (n % 1000) * 10 + n / 1000;
}
int r(int n) {
	return	(n % 10) * 1000 + n / 10;
}
void init() {
	for (int i = 0; i < 10000; i++) {
		num[i][0] = 0; num[i][1] = 0;
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		init();
		int a, b;
		scanf("%d %d", &a, &b);
		num[a][1] = B;
		num[b][1] = E;
		queue<int> q;
		q.push(a);
		while (!q.empty()) {
			int len = q.size();
			bool ck = false;
			for (int i = 0; i < len; i++) {
				int n = q.front();
				q.pop();
				if (avail(d(n)) == 1) {
					num[d(n)][0] = n;
					num[d(n)][1] = D;
					q.push(d(n));
				}
				else if (avail(d(n)) == 2) {
					num[d(n)][0] = n;
					num[d(n)][1] = D;
					ck = true;
					break;
				}
				if (avail(s(n))==1) {
					num[s(n)][0] = n;
					num[s(n)][1] = S;
					q.push(s(n));
				}
				else if (avail(s(n)) == 2) {
					num[s(n)][0] = n;
					num[s(n)][1] = S;
					ck = true;
					break;
				}
				if (avail(l(n))==1) {
					num[l(n)][0] = n;
					num[l(n)][1] = L;
					q.push(l(n));
				}
				else if (avail(l(n)) == 2) {
					num[l(n)][0] = n;
					num[l(n)][1] = L;
					ck = true;
					break;
				}
				if (avail(r(n))==1) {
					num[r(n)][0] = n;
					num[r(n)][1] = R;
					q.push(r(n));
				}
				else if (avail(r(n)) == 2) {
					num[r(n)][0] = n;
					num[r(n)][1] = R;
					ck = true;
					break;
				}
			}
			if (ck) {
				break;
			}
		}
		int x = b;
		stack<char> st;
		while (x!=a) {
			st.push(num[x][1]);
			x = num[x][0];
		}
		while (!st.empty()) {
			printf("%c",st.top());
			st.pop();
		}
		printf("\n");

	}
}
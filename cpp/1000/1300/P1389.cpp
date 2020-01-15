#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 1389 케빈 베이컨의 6단계 법칙
bool relate[100][100];
int person[100];
int result[100];
void init() {
	for (int i = 0; i < 100; i++)
		person[i] = 0;
}
bool avail(int i) {
	if (person[i] == 0)
		return true;
	return false;
}
int main() {
	int n, m;
	scanf("%d %d",&n,&m);
	int y, x;
	for (int i = 0; i < m;i++) {
		scanf("%d %d",&y,&x);
		relate[y-1][x-1] = true;
		relate[x-1][y-1] = true;
	}
	for (int i = 0; i < n;i++) {
		init();
		person[i] = -1;
		queue<int> q;
		q.push(i);
		int sum = 0;
		int cnt = 0;
		while (!q.empty()) {
			cnt++;
			int len = q.size();
			for (int k = 0; k < len;k++) {
				int t = q.front();
				q.pop();
				for (int j = 0; j < n; j++) {
					if (relate[t][j]&&avail(j)) {
						sum += cnt;
						person[j] = cnt;
						q.push(j);
					}
				}
			}
		}
		result[i] = sum;
		//printf("%d\n", sum);
	}
	int min = 210000000;
	int minI;
	for (int i = 0; i < n; i++) {
		if (result[i] < min) {
			minI = i;
			min = result[i];
		}
	}
	printf("%d\n",minI+1);


}
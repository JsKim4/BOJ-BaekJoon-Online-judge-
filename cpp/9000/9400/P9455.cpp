#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 9455 박스

int arr[100][100];
int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		int n, m;;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n;i++) {
			for (int j = 0; j < m;j++) {
				scanf("%d",&arr[i][j]);
			}
		}
		int answer = 0;
		for (int i = 0; i < m;i++) {
			int now_j = 0;
			for (int j = 0; j < n; j++) {
				if (arr[n-1-j][i] == 1) {
					answer += (j - now_j);
					now_j++;
				}
			}
		}
		cout << answer << endl;
	}
}
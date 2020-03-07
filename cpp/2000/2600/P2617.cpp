#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 2617 구슬 찾기
int marble[110][110];
int n, m;
bool ck[100];
void ck_init() {
	for (int i = 0; i < n;i++) {
		ck[i] = 0;
	}
}
void print() {
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++)
			cout << marble[i][j];
		cout << endl;
	}
}
int main(){
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		marble[a-1][b-1] = 1;
		marble[b-1][a-1] = 2;
	}
	//print();
	int answer = 0;
	for (int i = 0; i < n; i++) {
		queue<int>q;
		q.push(i);
		ck[i] = true;
		int h = 0;
		while (!q.empty()) {
			int len = q.size();
			while (len--) {
				int x = q.front(); q.pop();
				for (int j = 0; j < n; j++) {
					if (marble[x][j] == 1 && ck[j] == 0) {
						h++;
						q.push(j);
						ck[j] = true;
					}
				}
			}
		}
		q.push(i);
		int l = 0;
		while (!q.empty()) {
			int len = q.size();
			while (len--) {
				int x = q.front(); q.pop();
				for (int j = 0; j < n; j++) {
					if (marble[x][j] == 2 && ck[j] == 0) {
						l++;
						q.push(j);
						ck[j] = true;
					}
				}
			}
		}
		ck_init();
		//cout << i << " " << h << " " << l << " "<< (n / 2 + n % 2) <<endl;
		if (h>=(n/ 2 + n % 2)||l>= (n / 2 + n % 2)) {
			answer++;
			//cout << "answer++" << answer<<endl;
		}
	}
	cout << answer;
}
#include<iostream>
#include<queue>
#include<vector>
#include<map>
#pragma warning (disable:4996)
using namespace std;
// 17071 숨박꼭질5
int line[500100][2];
bool avail(int i) {
	if (i >= 0 && i <= 500000)
		return true;
	return false;
}
int main(){
	for (int i = 0; i < 500001;i++) {
		line[i][0] = -1;
		line[i][1] = -1;
	}
	int n, k;
	cin >> n >> k;
	int j = 0;
	if (n == k) {
		cout << 0 << endl;
		return 0;
	}
	queue<int>q;
	q.push(n);
	line[n][0] = 0;
	int cnt = 1;
	while (!q.empty()) {
		int len = q.size();
		//cout << cnt<<" "<<len << endl;
		while (len--) {
			int num = q.front(); q.pop();
			if (avail(num - 1) && line[num - 1][cnt % 2]==-1) {
				q.push(num - 1);
				line[num - 1][cnt % 2] = cnt;
			}
			if (avail(num + 1) && line[num + 1][cnt % 2]==-1) {
				q.push(num + 1);
				line[num + 1][cnt % 2] = cnt;
			}
			if (avail(num *2) && line[num * 2][cnt % 2]==-1) {
				q.push(num *2);
				line[num * 2][cnt % 2] = cnt;
			}
		}
		cnt++;
	}
	j = 0;
	int mmin = 5000000;

	for (; k <=500000;k+=++j) {
		if (j>=line[k][j%2]&&mmin>j) {
			mmin = j;
		}
	}
	cout << (mmin == 5000000 ? -1 : mmin);

}
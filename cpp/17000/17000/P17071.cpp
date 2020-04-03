#include<iostream>
#include<queue>
#include<vector>
#pragma warning (disable:4996)
using namespace std;
// 17071 숨박꼭질5
int line[1001][500001];
bool avail(int i) {
	if (i >= 0 && i <= 500000)
		return true;
	return false;
}
int main(){
	int n, k;
	cin >> n >> k;
	int j = 0;
	for (; k <= 500000; k += j) {
		line[j][k] = j;
		queue<int>q;
		if (avail(j + 1))
			q.push(j + 1);
		if (avail(j - 1))
			q.push(j - 1);
		if (j != 0 && j % 2 == 0) 
			q.push(j / 2);
		for (int cnt = 0; cnt < j; cnt++) {
			while (!q.empty()) {
				int num = q.front(); q.pop();
				if (avail(num + 1) && line[j - cnt][num + 1] != 0) {
					line[j - cnt][num + 1] = k;
					q.push(num + 1);
				}
				if (avail(num - 1) && line[j - cnt][num - 1] != 0) {
					line[j - cnt][num - 1] = k;
					q.push(num - 1);
				}
				if ((num != 0 && num % 2 == 0) && line[j - cnt][num / 2] != 0) {
					line[j - cnt][num /2] = k;
					q.push(num / 2);
				}
			}
		}
	}
	cout << "finish";
}
#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 13549 숨박꼭질 3
int N[300001];
int main(){
	for (int i = 0; i <= 100000; i++) { N[i] = -1; }
	int n, k;
	cin >> n >> k;
	queue<int>q;
	N[n] = 0;
	q.push(n);
	int c = 0;
	for (int i =n * 2; i < 100001; i *= 2) {
		if (N[i] != -1)
			break;
		N[i] = c;
		q.push(i);
	}
	while (!q.empty()) {
		int len = q.size();
		len = q.size();
		c++;
		while (len--) {
			int num = q.front(); q.pop();
			if (num + 1 < 100001 && N[num+1] == -1) {
				N[num + 1] = c;
				q.push(num + 1);

				for (int i = (num + 1) * 2; i < 100001; i *= 2) {
					if (N[i] != -1)
						break;
					N[i] = c;
					q.push(i);
				}

			}
			if (num - 1 >= 0 && N[num - 1] == -1) {
				N[num - 1] = c;
				q.push(num - 1);

				for (int i = (num - 1) * 2; i < 100001; i *= 2) {
					if (N[i] != -1)
						break;
					N[i] = c;
					q.push(i);
				}
			}
		}
	}
	cout << N[k];
}

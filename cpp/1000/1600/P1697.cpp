#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 1697 숨박꼭질
#define MX 100000
#define MN 0
int n, m;
int s[100001];
int main() {
	cin >> n >> m;
	s[n] = MX+1;
	int count = 1;
	queue<int>q;
	q.push(n);
	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			int num = q.front(); q.pop();
			if (num-1>=MN&&!s[num - 1]) {
				s[num - 1] = count;
				q.push(num - 1);
			}
			if (num+1<=MX&&!s[num + 1]) {
				s[num + 1] = count;
				q.push(num + 1);
			}
			if (num *2 <= MX&&!s[num * 2]) {
				s[num * 2] = count;
				q.push(num * 2);
			}
		}
		count++;
	}
	cout << s[m]%(MX+1);
}
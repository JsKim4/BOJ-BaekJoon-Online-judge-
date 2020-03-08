#include<iostream>
#include<queue>
#pragma warning (disable:4996)
#define INF 1000000000
using namespace std;
// 16953 A → B 
int main() {
	queue<long long>q;
	int n, m;
	int answer = 0;
	cin >> n >> m;
	q.push(n);
	while (!q.empty()) {
		answer++;
		int len = q.size();
		for (int i = 0; i < len; i++) {
			long long x = q.front();
			q.pop();
			if (x == m) {
				cout << answer;
				return 0;
			}
			if (x * 2 <= INF)
				q.push(x * 2);
			if (x * 10 + 1 <= INF)
				q.push(x * 10 + 1);

		}
	}
	cout << -1 << endl;
}
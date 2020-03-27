#include<iostream>
#include<queue>
#define INF 2147483648
#pragma warning (disable:4996)
using namespace std;
// 2014 소수의 곱
int sq[100];
int main() {
	int k, n;
	priority_queue<long long>answer;
	queue<pair<long long, int>>tq;
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> sq[i];
		tq.push({ sq[i],i });
		answer.push(sq[i]);
	}
	while (!tq.empty()) {
		long long tnum = tq.front().first;
		int j = tq.front().second; tq.pop();
		for (; j < k; j++) {
			long long nn = tnum * sq[j];
			if (nn < INF) {
				if (answer.size() <= n) {
					answer.push(nn);
					tq.push({ nn,j });
					//cout << nn << endl;
				}
				else {
					if (nn < answer.top()) {
						answer.pop();
						answer.push(nn);
						tq.push({ nn,j });
						//cout << nn << endl;
					}
				}
			}
		}
	}
	while (answer.size() > n)answer.pop();
	cout << answer.top();
}
#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 1927 최소힙
int main() {
	priority_queue<long long,vector<long long>,greater<long long>>q;
	int n;
	cin >> n;
	while (n--) {
		long long a;
		scanf("%lld", &a);
		if (a == 0) {
			if (q.empty())
				printf("0\n");
			else {
				printf("%lld\n", q.top());
				q.pop();
			}
		}
		else {
			q.push(a);
		}
	}
}
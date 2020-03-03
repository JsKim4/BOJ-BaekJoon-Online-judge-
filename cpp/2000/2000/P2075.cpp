#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 2075 N번째 큰 수
int main() {
	priority_queue<int,vector<int>,greater<int>>pq;
	int n;
	cin >> n;
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			int a;
			scanf("%d", &a);
			pq.push(a);
			//cout << pq.top()<<endl;
		}
		for (int j = pq.size(); j > n;j--) {
			pq.pop();
		}

	}
	cout << pq.top();
}
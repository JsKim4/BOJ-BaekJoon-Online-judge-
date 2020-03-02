#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#pragma warning (disable:4996)
using namespace std;
// 세준세비
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		priority_queue<int, vector<int>, greater<int>>sq;
		priority_queue<int, vector<int>, greater<int>>bq;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			sq.push(a);
		}
		for (int i = 0; i < m; i++) {
			int a;
			cin >> a;
			bq.push(a);
		}
		while (!sq.empty() && !bq.empty()) {
			if (sq.top() < bq.top())
				sq.pop();
			else
				bq.pop();
		}
		if (sq.empty()) 
			cout << "B" << endl;
		else
			cout << "S" << endl;
	}
}
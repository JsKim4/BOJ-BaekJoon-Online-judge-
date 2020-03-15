#include<iostream>
#include<queue>
#include<stack>
#pragma warning (disable:4996)
using namespace std;
// 1로 만들기2
int v[1000001];
int main() {
	int n;
	queue<int>q;
	cin >> n;
	q.push(n);
	while (!q.empty()) {
		int i = q.front(); q.pop();
		if (i>0) {
			if (i % 3 == 0&& v[i / 3] == 0) {
				q.push(i / 3);
				v[i / 3] = i;
			}
			if (i % 2 == 0 && v[i / 2] == 0) {
				q.push(i / 2);
				v[i / 2]=i;
			}
			if (v[i - 1]== 0) {
				q.push(i-1);
				v[i - 1] = i;
			}
		}
	}
	stack<int>s; s.push(1);
	while (s.top()!=0) {
		s.push(v[s.top()]);
	}
	s.pop();
	cout << s.size() - 1 << endl;
	while (!s.empty()) {
		cout << s.top()<<" ";
		s.pop();
	}

}
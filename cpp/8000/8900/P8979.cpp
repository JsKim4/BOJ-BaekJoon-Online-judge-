#include<iostream>
#include<queue>
#include<tuple>
#pragma warning (disable:4996)
using namespace std;
typedef tuple<int, int, int, int> P;
// 8979 올림픽
int main() {
	priority_queue<P, vector<P>, less<P>>pq;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		pq.push(make_tuple(b, c, d, a));
	}
	int a, b, c, d;
	tie(a, b, c, d) = pq.top(); pq.pop();
	if (d == m) {
		cout << 1;
		return 0;
	}
	int rang = 1;
	int nr = 1;
	for (int i = 0; i < n - 1; i++) {
		int e, f, g, h;
		tie(e, f, g, h) = pq.top(); pq.pop();
		if (a == e && f == b && g == c)
			rang++;
		else {
			rang++;
			a = e; b = f; c = g;
			nr = rang;
		}
		if (h == m) {
			cout << nr;
			return 0;
		}

	}
	cout << nr;

}

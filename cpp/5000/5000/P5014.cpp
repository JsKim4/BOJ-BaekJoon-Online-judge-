#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 5014 스타트링크
#define MX 1000000
#define MN 1
int f, s, g, u, d;
int layer[1000001];
int main() {
	cin >> f >> s >> g >> u >> d;
	layer[s] = MX + 1;
	int count = 1;
	queue<int>q;
	q.push(s);
	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			int num = q.front(); q.pop();
			if (num - d >= MN && !layer[num - d]) {
				layer[num - d] = count;
				q.push(num - d);
			}
			if (num + u <= MX && !layer[num + u]) {
				layer[num + u] = count;
				q.push(num + u);
			}
		}
		count++;
	}
	if (layer[g] == 0)
		cout << "use the stairs";
	else
		cout << layer[g] % (MX + 1);
}
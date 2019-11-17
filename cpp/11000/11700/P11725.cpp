#include<iostream>
#include<vector>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 11725
vector<int>node[100001];
int n;
int parent[100001];
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n;i++) {
		int a, b;
		scanf("%d %d",&a,&b);
		node[a].push_back(b);
		node[b].push_back(a);
	}
	queue<int>q;
	q.push(1);
	parent[1] = 1;
	while (!q.empty()) {
		int p= q.front();
		while (!node[p].empty()) {
			int child = node[p].back();
			if (parent[child] == 0) {
				q.push(child);
				parent[child] = p;
			}
			node[p].pop_back();
		}
		q.pop();
	}
	for (int i = 2; i <= n;i++) {
		printf("%d\n",parent[i]);
	}
}
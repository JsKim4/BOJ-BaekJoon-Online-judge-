#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
#define MAX_INT 2100000000
// 1504 특정한 최단경로
vector<pair<int, int>>graph[810];
int graph_len[810];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int v, e;
	int u, vv, w;
	int p1, p2;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	
	cin >> v >> e;
	while (e--) {
		cin >> u >> vv >> w;
		u--; vv--;
		graph[u].push_back(make_pair(w, vv));
		graph[vv].push_back(make_pair(w, u));
	}
	cin >> p1 >> p2;
	for (int i = 0; i < v; i++) graph_len[i] = MAX_INT;
	pq.push(make_pair(0, 0));
	while (!pq.empty()) {
		int w = pq.top().first;
		int i = pq.top().second;
		pq.pop();
		if (graph_len[i] > w) {
			graph_len[i] = w;
			for (int j = 0; j < graph[i].size(); j++) {
				if (w + graph[i][j].first < graph_len[graph[i][j].second]) {
					pq.push(make_pair(w + graph[i][j].first, graph[i][j].second));
				}
			}
		}
	}
	long long otop1 = graph_len[p1 - 1];
	long long otop2 = graph_len[p2 - 1];

	for (int i = 0; i < v; i++) graph_len[i] = MAX_INT;
	pq.push(make_pair(0, p1-1));
	while (!pq.empty()) {
		int w = pq.top().first;
		int i = pq.top().second;
		pq.pop();
		if (graph_len[i] > w) {
			graph_len[i] = w;
			for (int j = 0; j < graph[i].size(); j++) {
				if (w + graph[i][j].first < graph_len[graph[i][j].second]) {
					pq.push(make_pair(w + graph[i][j].first, graph[i][j].second));
				}
			}
		}
	}
	long long p1top2 = graph_len[p2 - 1];
	long long p1ton = graph_len[v - 1];

	for (int i = 0; i < v; i++) graph_len[i] = MAX_INT;
	pq.push(make_pair(0, p2 - 1));
	while (!pq.empty()) {
		int w = pq.top().first;
		int i = pq.top().second;
		pq.pop();
		if (graph_len[i] > w) {
			graph_len[i] = w;
			for (int j = 0; j < graph[i].size(); j++) {
				if (w + graph[i][j].first < graph_len[graph[i][j].second]) {
					pq.push(make_pair(w + graph[i][j].first, graph[i][j].second));
				}
			}
		}
	}
	long long p2top1 = graph_len[p1 - 1];
	long long p2ton = graph_len[v - 1];


	long long ans1 = otop1 + p1top2 + p2ton;
	long long ans2 = otop2 + p2top1 + p1ton;
	if (ans1 >= MAX_INT && ans2 >= MAX_INT)
		cout << -1;
	else {
		cout << ((ans1 > ans2) ? ans2 : ans1);
	}

}
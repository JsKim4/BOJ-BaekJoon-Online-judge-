#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
#define MAX_INT 2100000000
// 1753 최단경로
vector<pair<int,int>>graph[20000];
int graph_len[20000];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int v, e, k;
	int u, vv, w;
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
	cin >> v >>e >> k;
	k--;
	while (e--) {
		cin >> u >> vv >> w;
		u--; vv--;
		//cout << "push : " << u << " " << vv << " " << w << endl;
		graph[u].push_back(make_pair(w, vv));
	}
	for (int i = 0; i < v; i++) graph_len[i] = MAX_INT;
	pq.push(make_pair(0,k));
	while (!pq.empty()) {
		int w = pq.top().first;
		int i = pq.top().second;
		pq.pop();
		if (graph_len[i] > w) {
			graph_len[i] = w;
			for (int j = 0; j < graph[i].size();j++) {
				if (w+graph[i][j].first<graph_len[graph[i][j].second]) {
					//cout << "push : " << graph[i][j].second<<" "<<w+graph[i][j].first<<endl;
					pq.push(make_pair(w + graph[i][j].first,graph[i][j].second));
				}
			}
		}
		//cout << "\n\n";
	}
	for (int i = 0; i < v;i++) {
		if (graph_len[i] == MAX_INT)
			cout << "INF";
		else
			cout << graph_len[i];
		cout << "\n";
	}

}
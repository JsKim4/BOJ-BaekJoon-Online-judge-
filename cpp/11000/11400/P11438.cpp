#include<iostream>
#include<vector>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 11438 LCA2
int n;
vector <int> arr[100001];
int visited[100001];
vector <int> N[100001];
int main(){
	scanf("%d", &n);
	for (int i = 1; i < n;i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		N[a].push_back(b);
		N[b].push_back(a);
	}
	queue<int>q;
	q.push(1);
	int depth = 1;
	visited[1] = true;
	while (!q.empty()) {
		int len = q.size();
		while (len--) {
			int num = q.front(); q.pop();
			while (!N[num].empty()) {
				int i = N[num].back(); N[num].pop_back();
				if (!visited[i]) {
					q.push(i);
					arr[i].push_back(num);
					visited[i] = depth;
				}
			}
		}
		depth++;
	}
	int i = 0;
	for (int i = 2; i <= n; i++)
		q.push(i);
	while (!q.empty()) {
		int len = q.size();
		while (len--) {
			int num = q.front(); q.pop();
			int parent = arr[num][i];
			if (arr[parent].size() > i) {
				arr[num].push_back(arr[parent][i]);
				q.push(num);
			}
		}
		i++;
	}
	for (int i = 1; i <= n; i++)
		cout << visited[i] << endl;
}
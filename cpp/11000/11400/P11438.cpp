#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#pragma warning (disable:4996)
using namespace std;
// 11438 LCA2
int n;
vector <int> arr[100001];
int visited[100001];
vector <int> N[100001];

int goDepth(int num,int goal_depth) {
	int i = arr[num].size() - 1;
	int depth = visited[num];
	if (depth == goal_depth)
		return num;
	while (i>=0) {
		if (depth - pow(2, i) >= goal_depth) {
			return goDepth(arr[num][i], goal_depth);
		}
		i--;
	}
}
int getFather(int a,int b) {
	int len = arr[a].size();
	if (a == b)
		return a;
	for (int i = 0; i < len;i++) {
		if (arr[a][i] == arr[b][i]) {
			if (i == 0) {
				return getFather(arr[a][i], arr[b][i]);
			}
			else {
				return getFather(arr[a][i-1], arr[b][i-1]);
			}
		}
	}
	return getFather(arr[a][len - 1], arr[b][len - 1]);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		N[a].push_back(b);
		N[b].push_back(a);
	}
	queue<int>q;
	q.push(1);
	int depth = 1;
	visited[1] = depth;
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
	visited[1] = 0;
	for (int i = 2; i <= n; i++)
		q.push(i);

	int i = 0;
	while (!q.empty()) {
		int len = q.size();
		while (len--) {
			int num = q.front(); q.pop();
			int parent = arr[num][i];
			if (!arr[parent].empty() &&arr[parent].size() > i) {
				arr[num].push_back(arr[parent][i]);
				q.push(num);
			}
		}
		i++;
	}
	int m;
	scanf("%d", &m);
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		int a_depth = visited[a];
		int b_depth = visited[b];
		int goal_depth = a_depth > b_depth ? b_depth : a_depth;
		a = goDepth(a, goal_depth);
		b = goDepth(b, goal_depth);
		printf("%d\n", getFather(a,b));
	}
}
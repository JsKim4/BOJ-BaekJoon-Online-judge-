#include<iostream>
#include<vector>
#pragma warning (disable:4996)
using namespace std;
// 11375 열혈강호
int n, m;
vector<int>q[1001];
bool visited[1001];
int nowVisited[1001];
bool dfs(int i) {
	if (visited[i]) return false;
	visited[i] = true;
	for (int j = 0; j < q[i].size();j++) {
		int next = q[i][j];
		if (!nowVisited[next] || dfs(nowVisited[next])) {
			nowVisited[next] = i;
			return true;
		}
	}
	return false;
}

int main(){
	cin >> n >> m;
	for (int i = 1; i <= n;i++) {
		int j; scanf("%d",&j);
		for (int _j = 0; _j < j; _j++) {
			int a; scanf("%d",&a);
			q[i].push_back(a);
		}
	}
	int answer = 0;
	for (int i = 1; i <= n;i++) {
		for (int j = 0; j < 1001;j++) {
			visited[j] = 0;
		}
		if (dfs(i))
			answer++;
	}
	cout << answer;
}
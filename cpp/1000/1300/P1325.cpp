#include<iostream>
#include<vector>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 1325 효율적인 해킹
int _max = 0;
bool visited[10001];
vector<int> relation[10001];
int answer[10001];
queue<int>vis;

int dfs(int j) {
	int result = 1;
	for (int i = 0; i < relation[j].size();i++) {
		if (visited[relation[j][i]] == false) {
			visited[relation[j][i]] = true;
			vis.push(relation[j][i]);
			result += dfs(relation[j][i]);
		}
	}
	return result;
}

int main(){
	int n, m;
	cin >>n >> m;
	for (int i = 0; i < m;i++) {
		int a, b;
		scanf("%d %d",&a,&b);
		relation[b].push_back(a);
	}
	for (int i = 0; i <= n; i++) {
		visited[i] = true;
		vis.push(i);
		answer[i] = dfs(i);
		if (answer[i] > _max)
			_max = answer[i];
		while (!vis.empty()) {
			visited[vis.front()] = false;
			vis.pop();
		}
		//cout<<_max;
	}
	for (int i = 1; i <= n; i++) {
		if (answer[i] == _max)
			printf("%d ", i);
	}


}
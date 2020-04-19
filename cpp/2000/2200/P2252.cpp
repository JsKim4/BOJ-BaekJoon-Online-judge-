#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 2252 줄 세우기
queue<int> N[32001];
bool visited[32001];
int n, m;
void print(int i) {
	if (!N[i].empty()) {
		visited[i] = true;
		while (!N[i].empty()) {
			if (visited[N[i].front()] == 0) {
				print(N[i].front());
			}
			N[i].pop();
		}
		printf("%d ", i);
	}
	else if (!visited[i]) {
		visited[i] = true;
		printf("%d ",i);
	}

}
int main(){
	cin >> n >> m;
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		N[b].push(a);
	}
	for (int i = 1; i <= n;i++) {
		print(i);
	}
}
#include<iostream>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 2982 국왕의 방문
int road[1001][1001][3];
bool visited[1001];
int main(){
	int n, m;
	scanf("%d %d",&n,&m);
	int A, B, K, G;
	scanf("%d %d %d %d", &A, &B, &K, &G);
	int a,b,c;
	queue<int>q;
	for (int i = 0; i < G;i++) {
		scanf("%d",&a);
		q.push(a);
	}
	for (int i = 0; i < m;i++) {
		scanf("%d %d %d", &a, &b, &c);
		road[a][b][0] = c;
		road[b][a][0] = c;
	}
	a = 0;
	while (!q.empty()) {
		b = q.front(); q.pop();
		road[a][b][1];
	}
}
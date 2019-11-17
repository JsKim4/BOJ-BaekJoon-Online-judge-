#include<iostream>
#include<vector>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 1167
vector<pair<int, int>>node[100001];
int n;
int length[100001];
bool parent[100001];
void lenBfs(int i, int num) {
	parent[i] = true;
	length[i] = num;
	for (int j = 0; j < node[i].size(); j++) {
		if (parent[node[i][j].first])
			continue;
		//	printf("%d -> %d\n",i,node[i][j].first);
		lenBfs(node[i][j].first, num + node[i][j].second);
	}
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		while (true) {
			int b, c;
			scanf("%d", &b);
			if (b == -1)
				break;
			scanf("%d", &c);
			node[a].push_back(make_pair(b, c));
		}
	}
	int max = 0;
	int mi = 1;
	lenBfs(1, 0);
	for (int i = 1; i <= n; i++) {
		parent[i] = false;
		//	printf("%d length %d \n",i,length[i]);
		if (max < length[i]) {
			mi = i;
			max = length[i];
		}
	}
	//printf("mi %d\n",mi);
	lenBfs(mi, 0);
	max = 0;
	mi = 1;
	for (int i = 1; i <= n; i++) {
		//		printf("%d length %d \n", i, length[i]);
		if (max < length[i]) {
			mi = i;
			max = length[i];
		}
	}
	printf("%d\n", max);
}
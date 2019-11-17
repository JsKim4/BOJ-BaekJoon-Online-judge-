#include<iostream>
#include<vector>
#include<queue>
#pragma warning (disable:4996)
using namespace std;
// 1167
vector<pair<int,int>>node[100001];
int n;
int length[100001];
bool parent[100001];
int lenBfs(int i) {
	int bm = 0;
	int am = 0;
	if (parent[i]==false&&node[i].size()==1) {
		//printf("node last %d\n",i);
		return 0;
	}
	parent[i] = true;
	for (int j = 0; j < node[i].size();j++) {
		if (parent[node[i][j].first] == true)
			continue;
		int l = lenBfs(node[i][j].first);
		if (am<l+node[i][j].second) {
			bm = am;
			am = l + node[i][j].second;
		}
	}
	length[i] = am+bm;
	//printf("%d length %d \n",i,length[i]);
	return am;
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d",&a);
		while (true) {
			int b,c;
			scanf("%d",&b);
			if (b == -1)
				break;
			scanf("%d",&c);
			node[a].push_back(make_pair(b,c));
		}
	}
	parent[1] = true;
	lenBfs(1);
	int max = 0;
	for (int i = 1; i <= n; i++) {
		printf("%d ",length[i]);
		if (length[i] > max)
			max = length[i];
	}
	printf("%d\n", max);
	
}
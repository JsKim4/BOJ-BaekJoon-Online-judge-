#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
vector<int> eArray[20000];
vector<int> vArray;
int v, e;
// 1707
bool dfs(int n, int p) {
	vArray[n] = p;
	p = p == 1 ? 2 : 1;
	while(eArray[n].empty()!=true){
		int i= eArray[n].back();
		eArray[n].pop_back();
		if (i == n) {
			continue;
		}
		if (vArray[i] == 0) {
			if (!dfs(i, p))
				return false;
		}else if (vArray[i] !=p) {
			return false;
		}
	}
	return true;
}
void init(int v) {
	for (int i = 0; i < v;i++) {
		eArray[i].clear();
	}
}
int main() {
	int T;
	int a, b;
	scanf("%d",&T);
	while (T--) {
		scanf("%d %d", &v, &e);
		vArray.clear();
		vArray.resize(v, 0);
		for (int i = 0; i < e;i++) {
			scanf("%d %d",&a,&b);
			eArray[a-1].push_back(b-1);
			eArray[b-1].push_back(a-1);
		}
		for (int i = 0; i < v;i++) {
			sort(eArray[i].begin(), eArray[i].end());
		}
		bool answer=true;
		for (int i = 0; i < v;i++) {
			if (!eArray[i].empty()) {
					answer = dfs(i, 1);
			}
			if (!answer)
				break;
		}
		if (answer)
			printf("YES\n");
		else
			printf("NO\n");
		init(v);
	}
}
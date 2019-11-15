#include<iostream>
#include<vector>
#pragma warning (disable:4996)
using namespace std;
int list[100001];
vector<int> passCount;
vector<int> passLoad;
// 9466
int check(int nowN,int count) {
	//printf("%d %d\n",nowN,count);
	passLoad.push_back(nowN);
	if (passCount[nowN] > 0) {
		return count +1 - passCount[nowN];
	}
	if (list[nowN] == 0&&passCount[nowN]<=0)
		return 0;
	int num = list[nowN];
	passCount[nowN] = count + 1;
	list[nowN] = 0;
	return check(num,count+1);
}

int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		int n;
		scanf("%d",&n);
		int count = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &list[i]);
			if (i == list[i]) {
				count++;
				list[i] = 0;
			}
		}
		passCount.resize(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			if (list[i] == 0)
				continue;
			count += check(i,0);
			for (int i = 0; i < passLoad.size();i++) {
				passCount[passLoad[i]] = 0;
			}
			passLoad.clear();
		}
		printf("%d\n", n-count);
	}

} 
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
// 2357 최솟값과 최댓값
int n, m;
vector<pair<int,int>>min_num[131072];
vector<pair<int, int>>max_num[131072];
int getMin(int l,int r) {
	//cout << l << r << endl;
	int min_n = 2100000000;
	int c = min_num[l].size() - 1;
	for (; l<r&&r >= min_num[l][c].first;) {
		if (min_n > min_num[l][c].second)
			min_n = min_num[l][c].second;
		l = min_num[l][c].first+1;
		if (l >= r) {
			break;
		}
		c = min_num[l].size() - 1;
	}
	if (l >= r)
		return min(min_n, min_num[r][0].second);
	for (; c >= 0;) {
	//	cout << l << " : " << min_n << endl;
		if (r < min_num[l][c].first) {
			c--;
		}
		else {
			if (min_n > min_num[l][c].second)
				min_n = min_num[l][c].second;
			l = min_num[l][c].first + 1;
		}
	}
	//cout << l << " : " << min_n << endl;

	return min(min_n,min_num[r][0].second);
}
int getMax(int l,int r) {
	int max_n = 0;
	int c = max_num[l].size() - 1;
	for (; l < r && r >= max_num[l][c].first;) {
		
		if (max_n < max_num[l][c].second)
			max_n = max_num[l][c].second;
		l = max_num[l][c].first + 1;
		if (l >= r)
			break;
		c = max_num[l].size() - 1;
	}
	if (l >= r)
		return max(max_n, max_num[r][0].second);
	for (; c >= 0;) {
		if (r < max_num[l][c].first) {
			c--;
		}
		else {
			if (max_n < max_num[l][c].second)
				max_n = max_num[l][c].second;
			l = max_num[l][c].first + 1;
		}
	}
	return max(max_n, max_num[r][0].second);
}
int main(){
	cin >> n >> m;
	for (int i = 0; i < n;i++) {
		int num;
		scanf("%d",&num);
		max_num[i].push_back({ i,num });
		min_num[i].push_back({ i,num });
	}
	for (int t = 1; pow(2,t) <= n;t++) {
		int tn = pow(2, t);
		for (int j = 0; j+tn-1 < n;j+=tn) {
			int jn = j + tn;
			max_num[j].push_back({ j+tn-1,max(max_num[j][t - 1].second, max_num[j + tn / 2][t - 1].second) });
			min_num[j].push_back({ j+tn-1,min(min_num[j][t - 1].second, min_num[j + tn / 2][t - 1].second) });
		}
	}
	/*for (int i = 0; i < n;i++) {
		cout << "i : " << i << endl;
		for (int j = 0; j < min_num[i].size(); j++) {
			printf("%3d",min_num[i][j].first);
		}
		printf("\n");
		for (int j = 0; j < min_num[i].size();j++) {
			printf("%3d", min_num[i][j].second);
		}
		printf("\n");
	}*/
	for (int i = 0; i < m;i++) {
		int a, b;
		scanf("%d %d",&a,&b);
		printf("%d ", getMin(a - 1, b - 1));
		printf("%d\n", getMax(a - 1, b - 1));
	}
}
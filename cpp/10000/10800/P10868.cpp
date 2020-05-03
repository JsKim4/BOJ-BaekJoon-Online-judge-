#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
// 10868 최솟값
vector<int>arr[100000];
int n, m;
void set(int j) {
	int tt = pow(2, j);
	if (n - tt < 0)
		return;
	for (int i = 0; i <= n-tt;i+=tt) {
		arr[i].push_back(min(arr[i][j-1],arr[i+tt/2][j-1]));
	}
	set(j + 1);
}
int get(int min,int i,int j) {
	if (i > j)
		return min;

	int v = arr[i].size()-1;
	int u = i + pow(2, v);
	while (v>=0) {
		if (u <= j+1) {
			min = min < arr[i][v] ? min : arr[i][v];
			return get(min, u, j);
		}
		v--;
		u -= pow(2, v);
	}
	return min;
}
int main(){
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		arr[i].push_back(a);
	}
	set(1);
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}*/
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		printf("%d\n",get(1000000001,a,b));
	}
}
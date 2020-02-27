#include<iostream>
#include<vector>
#pragma warning (disable:4996)
using namespace std;
// 한글
int n, m;
long long A[500010];//상사
long long a[500010];//월급
long long mo[500010];//월급조정
vector<int>mm[500010];// mm
void init(long long i,long long j) {
	if (A[j] == 0) {
		mm[i].push_back(1);
		return;
	}
	mm[i].push_back(j); init(i,A[j]);
	if(mm[j].size()==0)
		init(j, A[j]);
}
int main() {
	scanf("%d %d", &n, &m);
	scanf("%lld",&a[1]);
	for (int i = 2; i <= n;i++) {
		scanf("%lld %lld", &a[i],&A[i]);
		
	}
	char order;
	int ord;
	mm[1].push_back(0);
	while (m--) {
		cin >> order >> ord;
		if (order == 'u') {
			if (mm[ord].size() == 0) {
				init(ord,A[ord]);
			}
			long long c = a[ord];
			for (int i = 0; i<mm[ord].size();i++) {
				c += mo[mm[ord][i]];
			}
			printf("%lld\n",c);
		}
		else {
			scanf("%lld",&mo[ord]);
			
		}
	}
}
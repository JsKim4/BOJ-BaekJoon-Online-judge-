#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 1280 나무 심기
long long length[200001][2];
int location[200001];
int main() {
	int n,a;
	scanf("%d",&n);
	for (int i = 0; i < n;i++) {
		scanf("%d",&a);
		location[a]++;
	}
	long long nn=0,bn=-1,wt=0;
	for (int i = 0; i < 200000;i++) {
		if (location[i]) {
			if (bn == -1) {
				length[nn][0] = 0;
				length[nn++][1] = location[i];
				bn = i;
				wt+=location[i];
			}
			else {
				wt += location[i];
				length[nn][0] = i - bn;
				length[nn++][1] = location[i];
				bn = i;
			}
		}
	}
	long long result = 1;
	long long now = 0;
	wt = length[0][1];
	long long temp;
	for (long long i = 1; i < nn; i++) {
		temp= (wt * length[i][0])% 1000000007;
		temp += now;
		temp %= 1000000007;
		now = temp;
		wt += length[i][1];
		while (length[i][1]--) {
			result *= now;
			result %= 1000000007;
		}
;	}
	if (nn == 1)
		result = 0;
	printf("%lld", result);
}
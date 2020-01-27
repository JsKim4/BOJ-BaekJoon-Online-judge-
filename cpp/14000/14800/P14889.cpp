#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 14889 스타트와 링크
int n;
bool memo[20];
int sl[22][22];
int mmin = 210000000;
int abs(int num) {
	return num > 0 ? num : num * (-1);
}
int returnSum(bool tf) {
	//printf("%s checknum:  ",tf?"Y":"N");
	int result = 0;
	for (int i = 0; i < n ; i++) {
		if (memo[i] == tf) {
			//printf("%d ",i);
			for (int j = 0; j < n; j++) {
				if (memo[j] == tf)
					result += sl[i][j];
			}
		}
	}
	//printf("\n");
	return result;
}
void select(int i, int s) {
	if (s == n/2) {
		int rs = returnSum(true);
		int es = returnSum(false);
		//printf("%d %d\n", rs, es);
		if (abs(rs - es) < mmin) {
			//printf("****************\n min %d \n****************\n",abs(rs-es));
			mmin = abs(rs - es);
		}

		return;
	}
	for (int y = i; y < s+n/2+1; y++) {
		if (memo[y] == 0) {
			memo[y] = 1;
			select(y+1,s+1);
			memo[y] = 0;
		}
	}
}
int main() {
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d",&sl[i][j]);
	select(0,0);
	printf("%d", mmin);
}
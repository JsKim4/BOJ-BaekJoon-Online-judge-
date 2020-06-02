#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 14899 스타트와 링크
int n;
int arr[20][20];
int nm[20];
int answer = 2100000000;
int absolute(int num) {
	return num > 0 ? num : num * (-1);
}
int returnSum(bool ck) {
	int sum = 0;
	for (int i = 0; i < n;i++) {
		if (nm[i]==ck) {
			for (int j = 0; j < n; j++) {
				if (nm[j]==ck) {
					sum += arr[i][j];
				}
			}
		}
	}
	return sum;
}
void solve(int i,int j) {
	if (i == n / 2) {
		int left = returnSum(1);
		int right = returnSum(0);
		int dif = absolute(left - right);
		if (dif < answer)
			answer = dif;
		return;
	}
	for (int x = j; x < i + n / 2 + 1;x++) {
		nm[x] = 1;
		solve(i+1,x+1);
		nm[x] = 0;
	}
}
int main(){
	scanf("%d",&n);
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	solve(0,0);
	printf("%d",answer);
}
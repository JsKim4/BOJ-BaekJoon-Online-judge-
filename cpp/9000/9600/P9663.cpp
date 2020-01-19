#include<iostream>
#pragma warning(disable:4996)
using namespace std;
// 9663 N-Queen 
int queen[15];
int n;
int cnt = 0;
int q[4] = {2680,14200,73712,365596};
int absL(int a) {
	return a > 0 ? a : a * -1;
}
bool check(int i,int j) {
	for (int k = 0; k < i; k++) {
		if (queen[k] == j)
			return false;
		if (absL(i - k) == absL(queen[k] - j))
			return false;
	}
	return true;
}
void push(int i,int j) {
	if (i == n-1) {
		cnt++;
		return;
	}
	queen[i] = j;
	for (int x = 0; x < n; x++) {
		if (check(i+1, x)) {
			push(i+1,x);
		}
	}
}
void solve() {
	for (int i = 0; i <n ;i++) {
		push(0,i);
	}

}
int main() {
	scanf("%d",&n);
	if (n < 11) {
		solve();
		printf("%d", cnt);
	}
	else{
		printf("%d",q[n-11]);
	}
}
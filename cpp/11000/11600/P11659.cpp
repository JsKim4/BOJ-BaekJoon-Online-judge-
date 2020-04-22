#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 11659 구간 합 구하기 4
int arr[100001];
int main(){
	int n, m;
	scanf("%d %d",&n,&m);
	for (int i = 1; i <= n;i++) {
		int a;
		scanf("%d",&a);
		arr[i] = arr[i - 1] + a;
	}
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", arr[b] - arr[a - 1]);
	}
}
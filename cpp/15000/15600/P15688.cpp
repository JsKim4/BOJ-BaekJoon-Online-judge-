#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 15688 수 정렬하기 5
int arr[2000001];
int main(){
	int T;
	scanf("%d",&T);
	while (T--) {
		int a;
		scanf("%d",&a);
		arr[a + 1000000]++;
	}
	for (int i = 0; i <= 2000000;i++) {
		while (arr[i]--) {
			printf("%d\n",i-1000000);
		}
	}
}
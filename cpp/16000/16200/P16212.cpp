#include<iostream>
#pragma warning (disable:4996)
using namespace std;
//// 16212 정렬적인 정렬
int num[4000001];
int main() {
	int n;
	int t;
	scanf("%d",&n);
	for (int i = 0; i < n;i++) {
		scanf("%d", &t);
		num[t + 2000000]++;
	}
	for (int i = 0; i < 4000001; i++) {
		if (num[i]) {
			while(num[i]--)
				printf("%d ", i - 2000000);
		}
	}
}
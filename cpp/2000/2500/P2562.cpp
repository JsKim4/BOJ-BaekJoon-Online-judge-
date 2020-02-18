#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 2562 최댓값
int main(){
	int a=0, b=0;
	for (int i = 1; i < 10;i++) {
		int k;
		scanf("%d",&k);
		if (a < k) {
			a = k;
			b = i;
		}
	}
	printf("%d\n%d",a,b);
}
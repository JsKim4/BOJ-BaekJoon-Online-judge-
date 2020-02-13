#include<iostream>
#pragma warning (disable:4996)
// 2475 검증수
int main(){
	int a; int s = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &a);
		s += (a * a);
	}
	printf("%d",s%10);
}
#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 2588 곱셈
int main() {
	int a, b; scanf("%d %d",&a,&b);
	printf("%d\n%d\n%d\n%d",a*(b % 10),a*(b%100/10),a*(b/100),a*b);
}
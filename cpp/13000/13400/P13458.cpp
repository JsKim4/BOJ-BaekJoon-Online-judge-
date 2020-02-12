#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 13458 시험감독
int main(){
	int A[10000];
	long long n, b, c;
	scanf("%lld",&n);
	for (int i = 0; i < n;i++) 
		scanf("%d",&A[i]);
	scanf("%lld %lld",&b,&c);
	long long answer=0;
	for (int i = 0; i < n;i++) {
		answer++; A[i] -= b;
		if (A[i] > 0) 
			answer += A[i] / c;
		if (A[i] % c != 0)
			answer++;
	}
	printf("%lld",answer);

}
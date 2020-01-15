#include<iostream>
#pragma warning (disable:4996)
using namespace std;
typedef long long ll;
ll fib[1500000] = {0,1};
// 2749 피보나치 수 3
int main() {
	for (int i = 2; i < 1500000; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		fib[i] %= 1000000;
	}
	ll n;
	scanf("%lld",&n);
	printf("%lld",fib[n%1500000]);
}
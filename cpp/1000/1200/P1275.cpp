#include<iostream>
#include<cmath>
#pragma warning (disable:4996)
using namespace std;
// 1275 커피숍2
long long arr[100001];
long long answer[100001];
long long n, q;
void set(long long i, long long num) {
	long long tn = num - arr[i];
	arr[i] = num;
	for (long long j = i; j <= n;j+=(j&-j)) {
		answer[j] += tn;
	}
}
long long get(long long right) {
	long long result = 0;
	for (long long i = right; i > 0; i -=  (i & -i))
		result += answer[i];

	return result;
}
int main(){
	scanf("%lld %lld", &n, &q);
	for (int i = 1; i <= n; i++) {
		long long a;
		scanf("%lld", &a);
		set(i, a);

	}
	while (q--) {
		long long a, b, c, d;
		scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
		long long x = a > b ? b : a; x--;
		long long y = a > b ? a : b;
		printf("%lld\n",get(y)-get(x));
		set(c, d);
	}

}
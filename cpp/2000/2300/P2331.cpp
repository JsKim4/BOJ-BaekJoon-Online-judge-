#include<iostream>
#include<cmath>
#pragma warning(disable:4996)
using namespace std;
int dp[300000];
// 2231
int cal(int n,int p){
	int result = 0;
	result += pow(n % 100000 / 10000, p);
	result += pow(n % 10000 / 1000, p);
	result += pow(n % 1000 / 100, p);
	result += pow(n % 100 / 10, p);
	result += pow(n % 10, p);
	return result;
}
int main() {
	int n, p;
	scanf("%d %d",&n,&p);
	int count = 1;
	dp[n] = 1;
	while (true) {
		n = cal(n, p);
		if (dp[n])
			break;
		count++;
		dp[n] = count;
	}
	printf("%d",dp[n]-1);
}
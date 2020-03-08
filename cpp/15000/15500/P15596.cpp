#include<iostream>
#pragma warning (disable:4996)
using namespace std;
// 15596 정수 N개의 합
int a[3000000];
long long sum(int* a,int n) {
	long long answer = 0;
	for (int i = 0; i < n;i++) {	
		answer += a[i];
	}
	return answer;
}
int main() {
}